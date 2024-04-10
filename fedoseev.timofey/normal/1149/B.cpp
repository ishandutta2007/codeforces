#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 251;

int dp[N][N][N];
const int Inf = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector <vector <int>> nxt(n, vector <int> (26, Inf));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            if (s[i] - 'a' == j) {
                nxt[i][j] = i;
            }
            else if (i + 1 < n) {
                nxt[i][j] = nxt[i + 1][j];
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                dp[i][j][k] = Inf;
            }
        }
    }

    dp[0][0][0] = 0;

    vector <string> a(3);

    auto relax = [&] (int i, int j, int k) {
        dp[i][j][k] = Inf;
        if (i == 0 && j == 0 && k == 0) {
            dp[i][j][k] = 0;
        }
        if (i > 0) {
            int y = dp[i - 1][j][k];
            if (y < n) {
                dp[i][j][k] = min(dp[i][j][k], nxt[y][a[0][i - 1] - 'a'] + 1);
            } 
        }  
        if (j > 0) {
            int y = dp[i][j - 1][k];
            if (y < n) {
                dp[i][j][k] = min(dp[i][j][k], nxt[y][a[1][j - 1] - 'a'] + 1);
            }
        }
        if (k > 0) {
            int y = dp[i][j][k - 1];
            if (y < n) {
                dp[i][j][k] = min(dp[i][j][k], nxt[y][a[2][k - 1] - 'a'] + 1);
            }
        }
    };


    for (int t = 0; t < q; ++t) {
        char c;
        cin >> c;
        if (c == '+') {
            int id; char cr;
            cin >> id >> cr;
            --id;
            a[id] += cr;
            if (id == 0) {
                vector <pair <int, int>> kek;
                int x = a[id].size();
                for (int sum = 0; sum <= a[1].size() + a[2].size(); ++sum) {
                    for (int j = 0; j <= a[1].size(); ++j) {
                        int k = sum - j;
                        if (0 <= k && k <= a[2].size()) {
                            kek.emplace_back(j, k);
                            relax(x, j, k);
                        }
                    }
                }
            }
            else if (id == 1) {
                int x = a[id].size();
                for (int sum = 0; sum <= a[0].size() + a[2].size(); ++sum) {
                    for (int i = 0; i <= a[0].size(); ++i) {
                        int k = sum - i;
                        if (0 <= k && k <= a[2].size()) {
                            relax(i, x, k);
                        }
                    }
                }
            }
            else {
                int x = a[id].size();
                for (int sum = 0; sum <= a[0].size() + a[1].size(); ++sum) {
                    for (int i = 0; i <= a[0].size(); ++i) {
                        int j = sum - i;
                        if (0 <= j && j <= a[1].size()) {
                            relax(i, j, x);
                        }
                    }
                }
            }
        }
        else {
            int id;
            cin >> id;
            --id;
            int x = a[id].size();
            a[id].pop_back();
            if (id == 0) {
                for (int j = 0; j <= a[1].size(); ++j) {
                    for (int k = 0; k <= a[2].size(); ++k) {
                        dp[x][j][k] = Inf;
                    }
                }
            }
            else if (id == 1) {
                for (int i = 0; i <= a[0].size(); ++i) {
                    for (int k = 0; k <= a[2].size(); ++k) {
                        dp[i][x][k] = Inf;
                    }
                }
            }
            else {
                for (int i = 0; i <= a[0].size(); ++i) {
                    for (int j = 0; j <= a[1].size(); ++j) {
                        dp[i][j][x] = Inf;
                    }
                }
            }
        }
        cout << (dp[a[0].size()][a[1].size()][a[2].size()] <= n ? "YES" : "NO") << '\n';
    }
}