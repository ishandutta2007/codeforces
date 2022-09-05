#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define y1 _y1
using namespace std;

int read() {
    int x = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    return x;
}

const int maxn = 1010;
int n, m, q, a[maxn][maxn], s[maxn][maxn], lg[maxn], st[10][10][maxn][maxn];

inline void chk(int &x, int y) {
    if (x < y) x = y;
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = read();
            s[i][j] = !a[i][j] + s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
        }
    }
    auto test = [&](int x, int y, int k) {
        return s[x + k - 1][y + k - 1] - s[x - 1][y + k - 1] - s[x + k - 1][y -
            1] + s[x - 1][y - 1];
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1, k = 1; j <= m; j++) {
            k = max(0, k - 1);
            while (i + k <= n && j + k <= m && !test(i, j, k + 1)) k++;
            st[0][0][i][j] = k;
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) if (i || j) {
            int t1 = 1 << (i - 1), t2 = 1 << (j - 1);
            for (int x = 1; x + (1 << i) - 1 <= n; x++) {
                for (int y = 1; y + (1 << j) - 1 <= m; y++) {
                    if (i) chk(st[i][j][x][y], st[i - 1][j][x][y]), chk(st[i][j][x][y], st[i - 1][j][x + t1][y]);
                    else chk(st[i][j][x][y], st[i][j - 1][x][y]), chk(st[i][j][x][y], st[i][j - 1][x][y + t2]);
                }
            }
        }
    }
    for (int i = 2; i <= max(n, m); i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    auto qmax = [&](int x1, int y1, int x2, int y2) {
        int k1 = lg[x2 - x1 + 1], k2 = lg[y2 - y1 + 1];
        int t1 = (1 << k1) - 1, t2 = (1 << k2) - 1;
        return max({st[k1][k2][x1][y1], st[k1][k2][x2 - t1][y1], st[k1][k2][x1]
            [y2 - t2], st[k1][k2][x2 - t1][y2 - t2]});
    };
    q = read();
    while (q--) {
        int x1 = read(), y1 = read(), x2 = read(), y2 = read();
        int l = 1, r = min(x2 - x1 + 1, y2 - y1 + 1), ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (qmax(x1, y1, x2 - mid + 1, y2 - mid + 1) >= mid) l = (ans = mid) + 1;
            else r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}