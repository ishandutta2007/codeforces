#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const long long MOD = 1e9 + 7;
long long i, n, m, x, j, ans, cnt, l, c[1005][1005], pw2[1005], v[1005];
int main(){
    cin >> n >> m;
    for (i = 1; i <= m; i++){
        cin >> x;
        v[x] = 1;
    }
    pw2[0] = 1;
    for (i = 1; i <= n; i++) pw2[i] = (pw2[i - 1] * 2) % MOD;
    for (i = 0; i <= n; i++) c[i][0] = 1;
    for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
        c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    ans = 1;
    for (i = 1; i <= n; i++)
    if (!v[i]){
        j = i;
        while (j <= n && !v[j]) j++;
        l = j - i; cnt += l;
        if (i > 1 && j <= n) ans =  ans * pw2[l - 1] % MOD;
        ans = ans * c[cnt][l] % MOD;
        i = j - 1;
    }
    cout << ans << endl;

}