#include <bits/stdc++.h>

#define MN 1001000

using namespace std;

int t, n, m, a[26][2020], ans[50][1<<12], b[26][2020];
vector<pair<int, int>> cols;

void merge(int* a, int* b, int* c) {
    for(int m = 0; m < (1 << n); m++) {
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
        memset(ans, 0, sizeof ans);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &b[i][j]);

        for(int j = 0; j < m; j++) {
            int maxi = 0;
            for(int i = 0; i < n; i++) {
                maxi = max(maxi, b[i][j]);
            }
            cols.emplace_back(maxi, j);
        }
        sort(cols.begin(), cols.end(), greater<pair<int, int>>());

        for(int i = 0; i < n; i++)
            for(int j = 0; j < min(n, m); j++)
                a[i][j] = a[i+n][j] = b[i][cols[j].second];

        build(0, 0, min(n, m)-1);
        printf("%d\n", ans[0][(1<<n)-1]);
    }
    return 0;
}