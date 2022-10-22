#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998244353;
const int MAXN = 1e6 + 7;

int f[MAXN];

inline int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}

void precalc() {
    f[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        f[i] = mod(f[i - 1] * i);
    }
}

int fp(int a, int b) {
    if (b == 0) return 1;
    int t = fp(a, b / 2);
    if (b % 2 == 0) return mod(t * t);
    else return mod(mod(t * t) * a);
}

int mdiv(int a, int b) {
    return mod(a * fp(b, MOD - 2));
}

int c(int n, int k) {
    return mdiv(f[n], mod(f[k] * f[n - k]));
}

int get(int n, int t) {
    return mod(fp(t + 1, n) - fp(t, n));
}

double gett() {
    return (double)clock() / CLOCKS_PER_SEC;
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precalc();
    
    int n;
    cin >> n;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int a_ = c(n, i);
        int b_;
        if (i & 1) b_ = 1;
        else b_ = -1;
        int c_ = get(n, -fp(3, i));
        ans = mod(ans + mod(mod(a_ * b_) * c_));
    }
    ans = mod(ans * 3);
    
    int add = 0;
    for (int i = 1; i <= n; ++i) {
        int a_ = c(n, i);
        int b_;
        if (i & 1) b_ = 1;
        else b_ = -1;
        int c_ = fp(3, i);
        int d_ = fp(3, n * (n - i));
        add = mod(add + mod(mod(mod(a_ * b_) * c_) * d_));
    }
    add = mod(add * 2);

    cout << mod(ans + add) << '\n';
    //cout << gett() << '\n';
    return 0;
}