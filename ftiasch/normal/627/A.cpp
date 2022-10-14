#include <iostream>

using Long = long long;

Long solve(Long a, Long x)
{
    if (a < 0 || a & 1) {
        return 0;
    }
    a >>= 1;
    Long aa = a;
    Long result = 1;
    while (a || x) {
        if (a & 1) {
            if (x & 1) {
                return 0;
            }
        } else if (x & 1) {
            result *= 2;
        }
        a >>= 1;
        x >>= 1;
    }
    if (!aa) {
        result -= 2;
    }
    return result;
}

int main()
{
    Long s, x;
    std::cin >> s >> x;
    std::cout << solve(s - x, x) << std::endl;
    return 0;
}