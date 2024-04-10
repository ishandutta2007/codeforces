#include <bits/stdc++.h>
using namespace std;
int f[2][101][10001];
int a[101], sum, xx;
bool bz, bz1;
int n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++) {
        int x = 0;
        scanf("%d", &x);
        a[x] ++;
        xx = x;
    }
    bz = 0;
    bz1 = 1;
    f[0][0][0] = 1;
    for (int i = 0; i < 100; i ++, swap(bz, bz1)) {
        for (int j = 0; j <= 10000; j ++)
            for (int l = 0; l <= 100; l ++)
            if (f[bz][l][j]){
                    for (int k = 0; k <= a[i + 1]; k ++)
                        f[bz1][l + k][j + k * (i + 1)] +=f[bz][l][j];
                    f[bz][l][j] = 0;
                }
        if (a[i + 1])
            sum ++;
    }
    int ans = 0;
    if (f[bz][a[xx]][a[xx] * xx] == 1 && sum == 2)  ans = n;
    for (int i = 1; i <= 100; i ++)
        for (int j = 1; j <= a[i]; j ++)
            if (f[bz][j][j * i] == 1) {
                ans = max(ans, j);
            }
    printf("%d", ans);
}