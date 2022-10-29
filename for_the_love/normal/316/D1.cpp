#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int n, i, j, fac[15], f[15][15], cnt, a[15];
int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if (a[i]) a[++cnt] = min(a[i], 2);
    }
    n = cnt;
    cnt = 0;
    for (i = 1; i <= n; i++) if (a[i] == 2) cnt++;
    fac[0] = 1;
    for (i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;

    for (i = 1; i <= n; i++) f[1][i] = 1;
    for (i = 2; i <= n; i++)
    for (j = 1; j <= n; j++)
        f[i][j] = min(f[i - 1][j - 1] * (max(0, j - 1))+ f[i - 1][j] + f[i - 1][j + 1], fac[i]);
    printf("%d\n", f[n][min(n, cnt + 1)]);
}