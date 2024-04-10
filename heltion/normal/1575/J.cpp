#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000 + 2;
int a[maxn][maxn];
int nxt[maxn][maxn];
int fnxt(int i, int j) {
    return nxt[i][j] == i ? i : nxt[i][j] = fnxt(nxt[i][j], j);
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i += 1) 
        for (int j = 1; j <= m; j += 1) {
            cin >> a[i][j];
            nxt[i][j] = i;
            if (a[i][j] == 2) nxt[i][j] = i + 1;
        }
    for (int i = 1; i <= m; i += 1) nxt[n + 1][i] = n + 1;
    for (int i = 1; i <= k; i += 1) {
        int x = 1, y;
        cin >> y;
        while (true) {
            x = fnxt(x, y);
            if (x == n + 1) break;
            if (a[x][y] == 1) {
                a[x][y] = 2;
                nxt[x][y] = x + 1;
                y += 1;
            }
            if (a[x][y] == 3) {
                a[x][y] = 2;
                nxt[x][y] = x + 1;
                y -= 1;
            }
        }
        cout << y << "\n";
    }
    return 0;
}