#include <iostream>
#include <map>

using Long = long long;

int main()
{
    int q;
    std::cin >> q;
    std::map<Long, Long> cost;
    while (q --) {
        int op;
        Long u, v, w;
        std::cin >> op >> u >> v;
        if (op == 1) {
            std::cin >> w;
            while (u != v) {
                if (u < v) {
                    std::swap(u, v);
                }
                cost[u] += w;
                u >>= 1;
            }
        } else {
            Long result = 0;
            while (u != v) {
                if (u < v) {
                    std::swap(u, v);
                }
                result += cost[u];
                u >>= 1;
            }
            std::cout << result << std::endl;
        }
    }
}