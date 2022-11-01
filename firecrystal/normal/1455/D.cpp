#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 505, INF = 1e9;

int n, x, a[N], f[N][N];

int main() {
    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j <= 500; j++) {
            f[i][j] = INF;
        }
    }
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &x);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        bool ok = true;
        for (int i = 1; i < n; i++)
            if (a[i] > a[i + 1]) ok = false;
        if (ok) puts("0");
        else {
            int cnt = 0;a[0] = x; a[n + 1] = 0;
            f[0][0] = 0; int ans = INF; 
            for (int i = 1; i <= n; i++) {
                for (int k = i - 1; ~k; k--) {
                    if (k + 2 < i && a[k + 1] > a[k + 2]) break;
                    for (int u = 0; u <= n + 1; u++) {
                        int j = a[u];
                        if (f[k][j] != INF && (k == 0 || (k == i - 1) || j <= a[k + 1]) && a[i] > a[k]) {
                            if (k == i - 1 || a[k] >= a[i - 1])f[i][a[k]] = min(f[i][a[k]], f[k][j] + 1);
                            
                        }
                    }
                    bool ok = true;
                    if (a[k] > a[i + 1]) ok = false;
                    for (int u = i + 1; u < n; u++)
                        if (a[u] > a[u + 1]) {
                            ok = false; break;
                        }
                    if (ok) ans = min(ans, f[i][a[k]]);  
                }
            }
        
            if (ans == INF) puts("-1");
            else printf("%d\n", ans);
            f[0][x] = INF;
            for (int i = 1; i <= n; i++) 
                for (int j = 0; j <= n; j++) f[i][a[j]] = INF;
            
        }
    }   
    return 0;
}