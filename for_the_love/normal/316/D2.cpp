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
const long long MOD = 1e9 + 7;
long long n, i, j, fac[1007], f[1007][1007], cnt, a[1007];
int main(){
    cin >> n;
    for (i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i]) a[++cnt] = min(a[i], (long long)2);
    }
    n = cnt;
    cnt = 0;
    for (i = 1; i <= n; i++) if (a[i] == 2) cnt++;
    fac[0] = 1;
    for (i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % MOD;

    for (i = 1; i <= n; i++) f[1][i] = 1;
    for (i = 2; i <= n; i++)
    for (j = 1; j <= n; j++)
    if (i - j < 2) f[i][j] = fac[i];
    else  f[i][j] = (f[i - 1][j - 1] * (max((long long)0, j - 1))+ f[i - 1][j] + f[i - 1][j + 1]) % MOD;
    //if (cnt >= n - 2) cout << fac[n]; else
    cout << f[n][min(n, cnt + 1)];
}