#include <iostream>
#include <any>
int main()
{
    std::any  a = 1;
    if (a.has_value()) {
        std::cout << a.type().name()<<std::endl;
    }

    a = "hello";
    std::cout << a.type().name() << std::endl;

    a = std::string{"word"};
    std::cout << a.type().name() << std::endl;

    auto s = std::make_any<std::string>("hello world");
    if (s.type() == typeid(std::string)) {
        auto a = std::any_cast<std::string>(s);
        std::cout << a << std::endl;
    }

    //要访问包含的值，必须使用std::any_cast<>将其转换为其类型。
    //auto b = s;
    //std::cout << b << std::endl;//错误

}

