#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int N = 2e3 + 228;

int A[N][N];
int used[N][N];
int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};

int n, m;

bool check(int x, int y) {
    int cnt = 0;
    if (x < 0 || y < 0 || x > n || y > m)
        return false;
    if (A[x][y])
        return false;
    for (int k = 0; k < 4; ++k) {
        if (!A[x + mx[k]][y + my[k]]) {
            ++cnt;
        }
    }
    if (!cnt) {
        cout << "Not unique\n";
        exit(0);
    }
    return cnt == 1;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i <= n + 3; ++i)
        fill(A[i], A[i] + m + 4, 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            A[i][j] = (c == '*');
        }
    }

    vector<pair<int, int>> now;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (check(i, j)) {
                now.emplace_back(i, j);
                used[i][j] = 1;
            }
        }
    }
    while (now.size()) {
        auto [x, y] = now.back();
        now.pop_back();
        if (A[x][y])
            continue;
        check(x, y);
        if (!A[x][y + 1]) {
            A[x][y] = 2, A[x][y + 1] = 3;
        }
        if (!A[x + 1][y]) {
            A[x][y] = 4, A[x + 1][y] = 5;
        }
        if (!A[x][y - 1]) {
            A[x][y] = 3, A[x][y - 1] = 2;
        }
        if (!A[x - 1][y]) {
            A[x][y] = 5, A[x - 1][y] = 4;
        }

        for (int i = 0; i < 4; ++i) {
            int a = x + mx[i], b = y + my[i];
            if (!used[a][b] && check(a, b)) {
                used[a][b] = 1;
                now.emplace_back(a, b);
            }
            if (a != 0 && a != n + 1 && b != 0 && b != m + 1) {
                for (int j = 0; j < 4; ++j) {
                    if (!used[a + mx[j]][b + my[j]] && check(a + mx[j], b + my[j])) {
                        used[a + mx[j]][b + my[j]] = 1;
                        now.emplace_back(a + mx[j], b + my[j]);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!A[i][j]) {
                cout << "Not unique\n";
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i][j] == 1) {
                cout << "*";
            } else if (A[i][j] == 4) {
                cout << "^";
            } else if (A[i][j] == 5) {
                cout << "v";
            } else if (A[i][j] == 2) {
                cout << "<";
            } else if (A[i][j] == 3) {
                cout << ">";
            }
        }
        cout << '\n';
    }
}