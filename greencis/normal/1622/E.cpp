#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n);
        for (int i = 0; i < n; ++i)
            cin >> x[i];
        vector<string> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        ll ans = -1e18;
        vector<int> ansp;

        vector<int> coeff;
        vector<int> assignment;
        vector<vector<int>> counter(2 * n + 1);
        for (int mask = 0; mask < (1 << n); ++mask) {
            ll sum = 0;
            coeff.assign(m, 0);
            assignment.assign(m, 0);
            for (int i = 0; i <= 2 * n; ++i)
                counter[i].clear();
            for (int i = 0; i < n; ++i) {
                bool inv = (mask & (1 << i));
                sum += inv ? x[i] : -x[i];
                for (int j = 0; j < m; ++j) {
                    if (v[i][j] == '1') {
                        coeff[j] += inv ? -1 : 1;
                    }
                }
            }
            for (int j = 0; j < m; ++j)
                counter[coeff[j] + n].push_back(j);
            int permi = 0;
            for (int i = 0; i <= 2 * n; ++i) {
                for (int j : counter[i]) {
                    assignment[j] = ++permi;
                    sum += coeff[j] * (ll)permi;
                }
            }
            if (sum > ans)
                ans = sum, ansp = assignment;
        }
        for (int i : ansp) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}