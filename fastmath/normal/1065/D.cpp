#include <bits/stdc++.h>

using namespace std;

const int MAXN = 11;

int n;
int a[MAXN][MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    }
}

const int INF = 1e9 + 7;
const int MAXANS = MAXN * MAXN * 2;

int dp[MAXANS][MAXN * MAXN][MAXN][MAXN][3];

bool ch(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

inline bool check(int i, int j, int ni, int nj, int k) {
    if (k == 0) {
        return (abs(i - ni) == 1 && abs(j - nj) == 2) || (abs(i - ni) == 2 && abs(j - nj) == 1);
    }
    else if (k == 1) {
        return abs(i - ni) == abs(j - nj);
    }
    else {
        return (i == ni || j == nj);
    }   
}

pair <int, int> ans = {INF, INF};
pair <int, int> pos[MAXN * MAXN];

vector <pair <int, int> > go[MAXN][MAXN][3];

void solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pos[a[i][j]] = {i, j};
        }
    }
    for (int i = 0; i < MAXANS; ++i) {
        for (int j = 0; j < MAXN * MAXN; ++j) {
            for (int x = 0; x < MAXN; ++x) {
                for (int y = 0; y < MAXN; ++y) {
                    for (int k = 0; k < 3; ++k) {
                        dp[i][j][x][y][k] = INF;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        dp[0][1][pos[1].first][pos[1].second][i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int ni = 0; ni < n; ++ni) {
                for (int nj = 0; nj < n; ++nj) {
                    for (int k = 0; k < 3; ++k) {
                        if (check(i, j, ni, nj, k)) {
                            go[i][j][k].push_back({ni, nj});
                        }
                    }
                }
            }
        }   
    }   

    for (int op = 0; op < MAXANS - 1; ++op) {
        for (int num = 1; num <= n * n; ++num) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        if (num == n * n && dp[op][num][i][j][k] != INF) {
                            ans = min(ans, {op, dp[op][num][i][j][k]});
                        }
                        for (auto t : go[i][j][k]) {
                            int ni = t.first, nj = t.second;
                            if (check(i, j, ni, nj, k)) {
                                bool ch = (pos[num + 1].first == ni && pos[num + 1].second == nj);
                                dp[op + 1][num + ch][ni][nj][k] = min(dp[op + 1][num + ch][ni][nj][k], dp[op][num][i][j][k]);
                            }
                        }
                        for (int nk = 0; nk < 3; ++nk) {
                            if (nk != k) {
                                dp[op + 1][num][i][j][nk] = min(dp[op + 1][num][i][j][nk], dp[op][num][i][j][k] + 1);
                            }
                        }
                    }
                }
            }
        }
    }
}

void print() {
    cout << ans.first << ' ' << ans.second << '\n';
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}