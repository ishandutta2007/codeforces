#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const long long MOD = 1e9 + 7;
long long f[2222][2222], fac[2222], u[2222], v[2222], n;

long long Dfs(long long x, long long y){
    if (x == y) f[x][y] = fac[x];
    if (f[x][y] != -1) return f[x][y];
    f[x][y] = Dfs(x, y + 1) - Dfs(x - 1, y) + MOD;
    f[x][y] %= MOD;
    return f[x][y];
}

int main(){
    //scanf("%d", &n);
    cin >> n;
    fac[0] = 1;
    for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    long long m = n;
    for (int i = 1; i <= n; i++){
        long long x;
        cin >> x;
        if (x == -1) v[i] = 1; else{
            u[x] = 1;
            m--;
        }
    }
    long long cnt = 0;
    for (long long i = 1; i <= n; i++)
    if (!u[i] && v[i]) ++cnt;
    memset(f, -1, sizeof(f));
    cout << Dfs(m, m - cnt) << endl;
}