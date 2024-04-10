#pragma GCC optimize("O3")

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
    vvi old_dp(n, vi(n));
    vector<pair<int, int>> pairs_back;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i + j) == (n + m) / 2 - 1) {
                pairs_back.emplace_back(i, j);
            }
        }
    }
    if ((n + m) % 2 == 0) {
        for (auto& [r, c] : pairs_back) {
            old_dp[r][r] = 1;
        }
    } else {
        for (auto& [r, c] : pairs_back) {
            if (r + 1 < n && arr[r][c] == arr[r + 1][c]) {
                old_dp[r][r + 1] += 1;
            }
            if (c + 1 < m && arr[r][c] == arr[r][c + 1]) {
                old_dp[r][r] += 1;
            }
        }
    }
    function<bool(int, int)> Check = [&](int i, int j) {
        return (0 <= i && i < n && 0 <= j && j < m);
    };
    for (int sum = (n + m) / 2 - 1; sum >= 1; --sum) {
        vvi new_dp(n, vi(n));
        for (int r = 0; r < n; ++r) {
            int c = sum - r;
            if (!Check(r, c)) {
                continue;
            }
            for (int x = 0; x < n; ++x) {
                int y = n + m - x - 2 - r - c;
                for (int dr = -1, dc = 0; dr <= 0; ++dr, --dc) {
                    for (int dx = 1, dy = 0; dx >= 0; --dx, ++dy) {
                        int new_r = r + dr;
                        int new_c = c + dc;
                        int new_x = x + dx;
                        int new_y = y + dy;
                        if (Check(new_r, new_c) && Check(new_x, new_y)) {
                            if (arr[new_r][new_c] == arr[new_x][new_y]) {
                                new_dp[new_r][new_x] += old_dp[r][x];
                                if (new_dp[new_r][new_x] >= MOD) {
                                    new_dp[new_r][new_x] -= MOD;
                                }
                            }
                        }
                    }
                }
            }
        }
        swap(old_dp, new_dp);
    }
    cout << old_dp[0][n - 1];
    return 0;
}