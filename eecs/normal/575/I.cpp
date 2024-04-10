#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010, maxq = 100010;
int n, q, an[maxq], s[2][maxn][maxn * 2];
struct info { int opt, x, y, dir, len; } a[maxq];

void add(int x, int y, int p, int q) {
    for (int i = x; i <= n; i += i & -i) {
        for (int j = y; j <= n * 2; j += j & -j) {
            s[p][i][j] += q;
        }
    }
}
int que(int p, int x, int y) {
    int su = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) {
            su += s[p][i][j];
        }
    }
    return su;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        cin >> a[i].opt;
        if (a[i].opt == 1) {
            cin >> a[i].dir >> a[i].x >> a[i].y >> a[i].len;
            a[i].dir = 5 - a[i].dir;
            if (a[i].dir >= 3) a[i].dir = 7 - a[i].dir;
        } else {
            cin >> a[i].x >> a[i].y;
        }
    }
    for (int di = 1; di <= 4; di++) {
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= q; i++) {
            if (a[i].opt == 1) {
                if (a[i].dir == di) {
                    add(a[i].x - a[i].len, a[i].x + a[i].y - a[i].len, 0, 1);
                    add(a[i].x + 1, a[i].x + a[i].y - a[i].len, 0, -1);
                    add(a[i].x - a[i].len, a[i].y + 1, 1, -1);
                    add(a[i].x + 1, a[i].y + 1, 1, 1);
                }
            } else {
                an[i] += que(0, a[i].x, a[i].x + a[i].y) + que(1, a[i].x, a[i].y);
            }
        }
        for (int i = 1; i <= q; i++) {
            swap(a[i].x, a[i].y);
            a[i].x = n + 1 - a[i].x;
        }
    }
    for (int i = 1; i <= q; i++) {
        if (a[i].opt == 2) cout << an[i] << "\n";
    }
    return 0;
}