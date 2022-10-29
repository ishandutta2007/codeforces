#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2001;
int n;
char a[N][N];
int l[10], r[10];
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                scanf(" %c", &a[i][j]);
                a[i][j] -= '0';
            }          
        }
        int ans[10], Lx[10], Rx[10], Ly[10], Ry[10];
        memset(ans, 0, sizeof(ans));
        memset(Lx, 10000, sizeof(Lx));
        memset(Rx, 0, sizeof(Rx));
        memset(Ly, 10000, sizeof(Ly));
        memset(Ry, 0, sizeof(Ry));
        for (int i = 1; i <= n; i ++) 
            for (int j = 1; j <= n; j ++) {
                Lx[a[i][j]] = min(Lx[a[i][j]], i);
                Rx[a[i][j]] = max(Rx[a[i][j]], i);
                Ly[a[i][j]] = min(Ly[a[i][j]], j);
                Ry[a[i][j]] = max(Ry[a[i][j]], j);
            }
        for (int i = 1; i <= n;i ++) {
            memset(l, 0, sizeof(l));
            memset(r, 0, sizeof(r));
            for (int j = 1; j <= n; j ++) {
                if (!l[a[i][j]])
                    l[a[i][j]] = j;
                r[a[i][j]] = j;
            }
            for (int j = 0; j < 10; j ++) 
                if (r[j]){
                    ans[j] = max(ans[j], (r[j] - l[j]) * max(i - 1, n - i));
                    ans[j] = max(ans[j], max(i - Lx[j], Rx[j] - i) * max(r[j] - 1, n - l[j]));
                }
        }
        
        for (int i = 1; i <= n;i ++) {
            memset(l, 0, sizeof(l));
            memset(r, 0, sizeof(r));
            for (int j = 1; j <= n; j ++) {
                if (!l[a[j][i]])
                    l[a[j][i]] = j;
                r[a[j][i]] = j;
            }
            for (int j = 0; j < 10; j ++)
                if (r[j]) {
                    ans[j] = max(ans[j], (r[j] - l[j]) * max(i - 1, n - i));
                    ans[j] = max(ans[j], max(i - Ly[j], Ry[j] - i) * max(r[j] - 1, n - l[j]));
                }
        }
        for (int i = 0;i < 10; i ++)
            printf("%d%c", ans[i], " \n"[i == 9]);
    }
    return 0;
}