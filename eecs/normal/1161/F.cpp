#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
int T, n, ver, pos[maxn], a[maxn][maxn];
int L[maxn][maxn], R[maxn][maxn], id[maxn][maxn], ans[maxn * 2];
bool mark[maxn][maxn];
char type;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        cout << "B" << endl;
        cin >> type >> ver;
        int sign = (type == 'I') == (ver <= n) ? 1 : -1;
        for (int i = 1; i <= n; i++) {
            iota(L[i] + 1, L[i] + n + 1, 1);
            sort(L[i] + 1, L[i] + n + 1, [&](int x, int y) { return sign * a[i][x] < sign * a[i][y]; });
            iota(R[i] + 1, R[i] + n + 1, 1);
            sort(R[i] + 1, R[i] + n + 1, [&](int x, int y) { return sign * a[x][i] > sign * a[y][i]; });
            for (int j = 1; j <= n; j++) id[i][R[i][j]] = j;
        }
        memset(ans, 0, sizeof(ans));
        memset(pos, 0, sizeof(pos));
        memset(mark, 0, sizeof(mark));
        while (count(ans + 1, ans + n + 1, 0)) {
            for (int i = 1; i <= n; i++) if (!ans[i]) {
                int j = L[i][++pos[i]];
                if (!ans[j + n] || id[j][i] < id[j][ans[j + n]]) {
                    ans[ans[j + n]] = 0, ans[i] = j + n, ans[j + n] = i;
                }
            }
        }
        while (~ver) {
            cout << ans[ver] << endl;
            cin >> ver;
        }
    }
    return 0;
}