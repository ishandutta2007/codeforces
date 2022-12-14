#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    auto print = [&](int a, int b) { cout << a << ' ' << b << '\n'; };
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m; j++) {
            print(i + 1, j + 1);
            print(n - i, m - j);
        }
    }

    if (n & 1) {
        for (int j = 0; j < m / 2; j++) {
            print(n / 2 + 1, j + 1);
            print(n / 2 + 1, m - j);
        }

        if (m & 1) {
            print(n / 2 + 1, m / 2 + 1);
        }
    }
}