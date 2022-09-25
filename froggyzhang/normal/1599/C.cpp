#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    double p;
    std::cin >> p;
    int tot = n * (n - 1) * (n - 2) / 6;
    for (int m = 0; m <= n; ++m) {
        double q = 1.0 / 2 * (m * (n - m) * (n - m - 1) / 2) / tot
                 + 1.0 * (m * (m - 1) * (n - m) / 2) / tot
                 + 1.0 * (m * (m - 1) * (m - 2) / 6) / tot;
        if (q > p - 1e-9) {
            std::cout << m << "\n";
            return 0;
        }
    }
}