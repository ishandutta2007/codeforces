#include<bits/stdc++.h>
using LL = long long;

void solve(void) {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> arr(k);
    for (int i = 0; i < k; i++) {
        std::cin >> arr[i];
    }
    auto check = [&](int n, int m) {
        LL r = 0;
        bool odd = false;
        for (auto v : arr) {
            LL x = v / n;
            if (x >= 2) {
                r += x;
                if (x > 2) {
                    odd = true;
                }
            }
        }
        return (r >= m) && (m % 2 == 0 || odd);
    };
    if (check(n, m) || check(m, n)) {
        puts("Yes");
    } else {
        puts("No");
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}