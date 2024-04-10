//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        vector<vector<ll>> v(2 * n, vector<ll>(2 * n));
        for (int i = 0; i < 2 * n; ++i) {
            for (int j = 0; j < 2 * n; ++j) {
                cin >> v[i][j];
            }
        }
        ll ans = 1e18;
        for (int swapHor = 0; swapHor < 2; ++swapHor) {
            for (int swapVer = 0; swapVer < 2; ++swapVer) {
                for (int transpose = 0; transpose < 2; ++transpose) {
                    auto u = v;
                    ll cur = 0;
                    for (int i = 0; i < 2 * n; ++i) {
                        for (int j = 0; j < 2 * n; ++j) {
                            if (i >= n && j >= n) {
                                cur += u[i][j];
                                u[i][j] = 0;
                            }
                            if (j > 0)
                                u[i][j] += u[i][j - 1];
                        }
                    }
                    ans = min(ans, cur + min(u[n - 1][n], u[n][n - 1]));

                    for (int i = 0; i < 2 * n; ++i) {
                        for (int j = i + 1; j < 2 * n; ++j) {
                            swap(v[i][j], v[j][i]);
                        }
                    }
                }

                reverse(all(v));
                rotate(v.begin(), v.begin() + n, v.end());
            }

            for (int i = 0; i < 2 * n; ++i) {
                reverse(all(v[i]));
                rotate(v[i].begin(), v[i].begin() + n, v[i].end());
            }
        }
        cout << ans << '\n';
    }
}