#include <iostream>
#include <vector>

int main()
{
    int64_t p;
    int k;
    std::cin >> p >> k;
    std::vector<int> poly;
    while (p) {
        auto r = p % k;
        if (r < 0) {
            r += k;
        }
        poly.push_back(r);
        p = (p - r) / (-k);
    }
    printf("%d\n", static_cast<int>(poly.size()));
    for (size_t i = 0; i < poly.size(); ++ i) {
        printf("%d%c", poly.at(i), " \n"[i + 1 == poly.size()]);
    }
}