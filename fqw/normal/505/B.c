#include <stdio.h>

int g[100][100][100];
int main() {
    int n, m; scanf("%d%d", &n,&m);
    int i, j, k, p;
    for(i=0; i<m; ++i) {
        int a, b, c; scanf("%d%d%d", &a,&b,&c);
        --a, --b, --c;
        g[c][a][b]=g[c][b][a]=1;
    }
    for(i=0; i<m; ++i) for(j=0; j<n; ++j) g[i][j][j]=1;
    for(p=0; p<m; ++p) {
        for(k=0; k<n; ++k) for(i=0; i<n; ++i) for(j=0; j<n; ++j)
            if(g[p][i][k] && g[p][k][j])
                    g[p][i][j]=1;
    }
    int q; scanf("%d", &q);
    while(q--) {
        int u, v; scanf("%d%d", &u,&v);
        int ans=0;
        --u, --v;
        for(p=0; p<m; ++p) if(g[p][u][v]) ++ans;
        printf("%d\n", ans);
    }
    return 0;
}