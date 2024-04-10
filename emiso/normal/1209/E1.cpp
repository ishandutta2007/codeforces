#include <bits/stdc++.h>

#define MN 1001000

using namespace std;

int t, n, m, a[26][2020], ans[8000][1<<12];
vector<pair<int, int>> cols;

void merge(int* a, int* b, int* c) {
    for(int m = 0; m < (1 << n); m++) {
        a[m] = 0;
        for(int subset = m; subset > 0; subset = (subset-1) & m)
            a[m] = max(a[m], b[subset] + c[m ^ subset]);
        a[m] = max(a[m], b[0] + c[m]);
    }
}

void build(int id, int l, int r) {
    if(l == r) {
        for(int m = 0; m < (1 << n); m++) {
            int maxi = 0;
            for(int i = 0; i < n; i++) {
                int cur = 0;
                for(int b = 0; b < n; b++) {
                    if(m & (1 << b))
                        cur += a[i + b][l];
                }
                if(maxi < cur) maxi = cur;
            }

            ans[id][m] = maxi;
        }
    } else {
        int m = (l + r) / 2;
        build(id * 2 + 1, l,   m);
        build(id * 2 + 2, m+1, r);
        merge(ans[id], ans[id*2+1], ans[id*2+2]);
    }
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        cols.clear();
        //memset(ans, 0, sizeof ans);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
                a[i+n][j] = a[i][j];
            }

        build(0, 0, m-1);
        printf("%d\n", ans[0][(1<<n)-1]);
    }
    return 0;
}