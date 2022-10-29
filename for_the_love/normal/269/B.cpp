#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, i, j, mn, f[5005][5005], s[5005];
double x[5005];

int main(){
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) scanf("%d%lf", &s[i], &x[i]);
    memset(f, 0x7f, sizeof(f));
    f[0][0] = 0;
    for (i = 1; i <= n; i++){
        mn = 1e9;
        for (j = 0; j <= m; j++){
            mn = min(mn, f[i - 1][j]);
            if (s[i] == j) f[i][j] = mn;
            else f[i][j] = mn + 1;
        }
    }
    int ans = 1e9;
    for (i = 0; i <= m; i++) ans = min(ans, f[n][i]);
    cout << ans << endl;

}