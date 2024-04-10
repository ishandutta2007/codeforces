#include <bits/stdc++.h>

using namespace std;

int n, m, k, maxi, a[4020][4020];

void add(int r1, int r2, int c1, int c2, int val) {
    a[r1][c1] += val;
    a[r1][c2+1] -= val;
    a[r2+1][c1] -= val;
    a[r2+1][c2+1] += val;
}

void solve(int l, int r) {
    for(int v = 1; v < (r-l+1); v++) {
        if(v >= k) break;

        int pl = l + v - k;
        int er = r - v + k, pr = r - v + 1;

        if(pl >= 0) {
            add(0, pl, pl, pl, v);
            if(er < n) add(pl, pl, pr, n, v);
        }
        if(er < n) {
            if(pl >= 1) {
                add(0, pl-1, pr, pr, v);
                //add(pl, pl, pr, pr, -v);
            }
            add(pr, pr, pr, n, v);
        }
    }
    if(r-l+1 <= k) {
        int len = r-l+1;
        int dif = k - len;
        int pl = max(l - dif, 0);
        int pr = min(l, n-k);

        if(pl <= pr) {
            for(int i = 0; i < pl; i++) {
                add(i, i, pl, pr, len);
            }
            //add(0, pl-1, pl, pr, len);
            for(int i = pl; i <= pr; i++) {
                add(i, i, i, n, len);
            }
        }
    } else {
        for(int i = l; i + k - 1 <= r; i++) {
            if(l) add(0, l-1, i, i, k);
            add(i, i, i, n, k);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        solve(--l, --r);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            maxi = max(maxi, a[i][j]);
            a[i][j+1]   += a[i][j];
            a[i+1][j]   += a[i][j];
            a[i+1][j+1] -= a[i][j];
        }
    }

    printf("%d\n", maxi);
    return 0;
}