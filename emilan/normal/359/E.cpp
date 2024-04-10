#include <bits/stdc++.h>

using namespace std;

const int N = 502;
int n;
int a[N][N], p[N][N];
bool vis[N][N];
string ans1, ans2;

// [l, r)
bool query(int x1, int y1, int x2, int y2) {
    x1--, y1--, x2--, y2--;
    return p[x2][y2] - p[x1][y2] - p[x2][y1] + p[x1][y1];
}

void dfs(int x, int y) {
    vis[x][y] = true;

    if (a[x][y] == 0) ans1 += '1';

    if (query(1, y, x, y + 1) && !vis[x - 1][y]) {
        ans1 += 'U';
        ans2 += 'U';

        dfs(x - 1, y);

        ans1 += 'D';
        ans2 += 'D';
    }
    if (query(x + 1, y, n + 1, y + 1) && !vis[x + 1][y]) {
        ans1 += 'D';
        ans2 += 'D';

        dfs(x + 1, y);

        ans1 += 'U';
        ans2 += 'U';
    }
    if (query(x, 1, x + 1, y) && !vis[x][y - 1]) {
        ans1 += 'L';
        ans2 += 'L';

        dfs(x, y - 1);

        ans1 += 'R';
        ans2 += 'R';
    }
    if (query(x, y + 1, x + 1, n + 1) && !vis[x][y + 1]) {
        ans1 += 'R';
        ans2 += 'R';

        dfs(x, y + 1);

        ans1 += 'L';
        ans2 += 'L';
    }

    ans2 += '2';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int x0, y0;
    cin >> n >> x0 >> y0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            p[i][j] += a[i][j];
            p[i + 1][j] += p[i][j];
            p[i][j + 1] += p[i][j];
            p[i + 1][j + 1] -= p[i][j];
        }
    }

    dfs(x0, y0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] && !vis[i][j]) return cout << "NO", 0;
        }
    }

    cout << "YES\n";
    cout << ans1 << ans2;
}