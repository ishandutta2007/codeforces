#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998244353;
const int MAXN = 1e6 + 7;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   

int fp(int a, int b) {
    if (b == 0) {
        return 1;
    }   
    int t = fp(a, b >> 1);
    if (b & 1) {
        return mod(mod(t * t) * a);
    }   
    else {
        return mod(t * t);
    }   
}   

int mdiv(int a, int b) {
    return mod(a * fp(b, MOD - 2));
}   

int f[MAXN];

int C(int n, int k) {
    return mdiv(f[n], mod(f[k] * f[n - k]));
}   

signed main() {
    #ifdef HOME
        //freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    f[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        f[i] = mod(f[i - 1] * i);
    }   

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = mod(ans + mod(C(n, i) * mod(f[i] - 1)) * f[n - i]);
    }   

    cout << mod(ans + 1) << '\n';
    return 0;
}