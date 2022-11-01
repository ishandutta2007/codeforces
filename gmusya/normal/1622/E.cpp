#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

using ll = long long;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> e(n);
        for (int i = 0; i < n; ++i) {
            cin >> e[i];
        }
        vector<vector<char>> table(n, vector<char>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> table[i][j];
            }
        }
        vector<int> masks;
        for (int j = 0; j < m; ++j) {
            int val = 0;
            for (int i = 0; i < n; ++i) {
                val += (1 << i) * (table[i][j] - '0');
            }
            masks.push_back(val);
        }
        vector<int> p(m);
        iota(p.begin(), p.end(), 0);
        ll res = -INF;
        int best_mask = 0;
        vector<ll> f_mask(1 << n);
        for (int mask = 0; mask < (1 << n); ++mask) {
            ll sum = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    sum -= e[i];
                } else {
                    sum += e[i];
                }
            }
            for (int i : masks) {
                f_mask[i] = 0;
                for (int j = 0; j < n; ++j) {
                    if (i & (1 << j)) {
                        if (mask & (1 << j)) {
                            ++f_mask[i];
                        } else {
                            --f_mask[i];
                        }
                    }
                }
            }
            sort(p.begin(), p.end(), [&](int i, int j) {
                return f_mask[masks[i]] < f_mask[masks[j]];
            });
            for (int i = 0; i < masks.size(); ++i) {
                int v = i + 1;
                for (int j = 0; j < n; ++j) {
                    if (masks[p[i]] & (1 << j)) {
                        if (mask & (1 << j)) {
                            sum += v;
                        } else {
                            sum -= v;
                        }
                    }
                }
            }
            if (sum > res) {
                res = sum;
                best_mask = mask;
            }
        }
        for (int i = 0; i < (1 << n); ++i) {
            f_mask[i] = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    if (best_mask & (1 << j)) {
                        ++f_mask[i];
                    } else {
                        --f_mask[i];
                    }
                }
            }
        }
        sort(p.begin(), p.end(), [&](int i, int j) {
            return f_mask[masks[i]] < f_mask[masks[j]];
        });
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            ans[p[i]] = i;
        }
        for (int x : ans) {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
1
4 4
6 2 0 10
1001
0010
0110
0101

 */