#include <stdio.h>

int n, a, q, op;
int d[1000];
int cntr[1000];
int cntc[1000];

int mat[1000][1000];

int main() {
    scanf("%d", &n);
    int ans;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &mat[i][j]);
        ans += mat[i][i];
        d[i] = mat[i][i];
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &op);
    
        if (op < 3) {
            scanf("%d", &a);
            ans -= d[a];
            ans += 1-d[a];
            d[a] = 1-d[a];
        }
        else printf("%d", ans%2);
    }
}