#include <bits/stdc++.h>
using namespace std;
int main() {
    int Case, n, m;
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d%d", &n, &m);
        int mxR = 0, mxW = 0;
        for (int i = 1, r, w; i <= m; ++i) {
            scanf("%d%d", &r, &w);
            mxR = max(mxR, r);
            mxW = max(mxW, w);
        }
        if (mxR + mxW > n) {
            puts("IMPOSSIBLE");
        } else {
            for (int i = 1; i <= mxR; ++i) putchar('R');
            for (int i = mxR + 1; i <= n; ++i) putchar('W');
            puts("");
        }
    }
    return 0;
}