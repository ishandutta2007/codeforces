#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

#define int long long

const int MOD = 1000 * 1000 * 1000 + 7;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   

int fp(int n, int p) {
    if (p == 0) {
        return 1;
    }   
    int t = fp(n, p >> 1);
    if (p & 1) {
        return mod(mod(t * t) * n);
    }                              
    else {
        return mod(t * t);
    }   
}   

int mdiv(int a, int b) {
    return mod(a * fp(b, MOD - 2));
}   

int f[MAXN];
void prec() {
    f[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        f[i] = mod(f[i - 1] * i);
    }   
}   

int n;
int a[MAXN];

int C(int n, int k) {
    return mdiv(f[n], mod(f[n - k] * f[k]));
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    prec();

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }   

    int ans = 1;
    int curr = 0;
    for (int i = 0; i < n; ++i) {
        ans = mod(ans * C(curr + a[i], a[i]));
        curr += a[i] + 1;
    }   

    cout << ans << '\n';
    return 0;
}