#include <iostream>

using LL = long long;

const int N = 30;

int n, c[N];

bool get(LL budget, int m)
{
    for (int i = n - 1; i >= 0; -- i) {
        LL cnt = budget / c[i];
        budget %= c[i];
        if ((m >> i) < cnt) {
            return true;
        }
        m -= cnt << i;
        if (m <= 0) {
            return true;
        }
    }
    return false;
}

int main()
{
    int m;
    while (std::cin >> n >> m) {
        for (int i = 0; i < n; ++ i) {
            std::cin >> c[i];
        }
        for (int i = 1; i < n; ++ i) {
            if (c[i] > c[i - 1] * 2) {
                c[i] = c[i - 1] * 2;
            }
        }
        LL low = 0;
        LL high = 1000000000000000000;
        while (low < high) {
            LL middle = low + high >> 1;
            if (get(middle, m)) {
                high = middle;
            } else {
                low = middle + 1;
            }
        }
        std::cout << high << std::endl;
    }
}