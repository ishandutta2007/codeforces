#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, m, K, a[maxn][maxn];

int main() {
    scanf("%d %d %d", &n, &m, &K);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    while (K--) {
        int r = 1, c;
        scanf("%d", &c);
        while (r <= n) {
            int _r, _c;
            if (a[r][c] == 1) _r = r, _c = c + 1;
            if (a[r][c] == 2) _r = r + 1, _c = c;
            if (a[r][c] == 3) _r = r, _c = c - 1;
            a[r][c] = 2, r = _r, c = _c;
        }
        printf("%d ", c);
    }
    return 0;
}