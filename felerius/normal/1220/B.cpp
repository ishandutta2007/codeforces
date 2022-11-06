#include <bits/stdc++.h>

// Contest: Codeforces Round #586 (Div. 1 + Div. 2) (https://codeforces.com/contest/1220)
// Problem: B: Multiplication Table (https://codeforces.com/contest/1220/problem/B)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<ll>> mat(n, vector<ll>(n));
    for (auto& row : mat)
        for (auto& i : row)
            cin >> i;

    auto g = gcd(mat[0][1], mat[0][2]);
    for (int k = 3; k < n; ++k)
        g = gcd(g, mat[0][k]);

    for (ll i = 1; i * i <= g; ++i) {
        if (g % i)
            continue;

        for (auto j : {i, g / i}) {
            bool pos = true;
            for (int k = 1; k < n - 1; ++k) {
                if (mat[0][k] * mat[0][k + 1] / j / j != mat[k][k + 1]) {
                    pos = false;
                    break;
                }
            }

            if (pos) {
                cout << j << ' ';
                for (int k = 1; k < n; ++k)
                    cout << (mat[0][k] / j) << ' ';
                cout << '\n';
                return 0;
            }
        }
    }

    return 0;
}