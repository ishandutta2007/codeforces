#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2222;
const int INF = 1e9 + 7;
int f[N][N], a[N], r[N], l[N];

int n;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        a[i] = abs(a[i]);
    }
    int ans = 0;
    while (n){
        int m = 0, mx = 0;
        for (int i = 1; i <= n; i++) mx = max(mx, a[i]);
        for (int i = 1; i <= n; i++)
        if (a[i] == mx) l[i] = m; else m++;
        m = 0;
        for (int i = n; i >= 1; i--)
        if (a[i] == mx) r[i] = m; else m++;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        if (a[i] == mx) l[++cnt] = l[i], r[cnt] = r[i];
        for (int i = 0; i <= cnt; i++)
        for (int j = 0; j <= cnt; j++)
            f[i][j] = INF;
        f[0][0] = 0;
        for (int i = 1; i <= cnt; i++)
        for (int j = 0; j <= i; j++){
            if (j) f[i][j] = min(f[i][j], f[i - 1][j - 1] + i - j + l[i]);
            if (j < i) f[i][j] = min(f[i][j], f[i - 1][j] + r[i]);
        }
        int mn = INF;
        for (int i = 0; i <= cnt; i++) mn = min(mn, f[cnt][i]);
        ans += mn;
        m = n;
        n = 0;
        for (int i = 1; i <= m; i++)
        if (a[i] != mx) a[++n] = a[i];
    }
    printf("%d\n", ans);
}