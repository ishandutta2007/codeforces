#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
#include <numeric>
#include <vector>
#include <array>

#define all(a) a.begin(), a.end()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        vector<vector<vector<int>>> dp(i + 1, vector<vector<int>> (i + 1, vector<int> (n + 1)));
        vector<vector<vector<pair<int, int>>>> last(i + 1, vector<vector<pair<int, int>>> (i + 1, vector<pair<int, int>> (n + 1, make_pair(-1, -1))));
        dp[0][i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            for (int k = i; k >= j; --k) {
                for (int p = k; p <= i; ++p) {
                    for (int q = 0; q + 1 + 2 * (k - j) <= n; ++q) {
                        if (dp[j - 1][p][q]) {
                            dp[j][k][q + 1 + 2 * (k - j)] = 1;
                            last[j][k][q + 1 + 2 * (k - j)] = {p, q};

                            if (q + 1 + 2 * (k - j) == n) {
                                cout << i << '\n';
                                vector<vector<char>> ans(i, vector<char> (i, '.'));
                                int a1 = j, a2 = k, cnt = n;
                                while (a1 > 0) {
                                    // cout << a1 << ' ' << a2 << ' ' << cnt << '\n';
                                    for (int o = 0; o < a2; ++o) {
                                        ans[i - a1][o] = 'o';
                                        ans[i - 1 - o][a1 - 1] = 'o';
                                    }
                                    auto z = last[a1][a2][cnt];
                                    a2 = z.first, cnt = z.second;
                                    --a1;
                                }
                                for (auto i : ans) {
                                    for (auto j : i)
                                        cout << j;
                                    cout << '\n';
                                }
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << -1 << '\n';
}