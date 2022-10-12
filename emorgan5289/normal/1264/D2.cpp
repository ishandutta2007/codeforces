#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

// returns (b^r)%m, runs in O(logr) time.
template<typename T>
T powmod(T b, T r, T m) {
    T out = 1;
    for (T t = 1; t <= r; t <<= 1) {
        if (r&t) out = (out*b)%m;
        b = (b*b)%m;
    }
    return out;
}

// returns a unique number b s.t. ab = 1 mod m in O(logm) time.
template<typename T>
T inv(T a, T m) {
    T r = 1;
    for (T k = m-2; k; k >>= 1) {
        if (k&1) r = (r*a)%m;
        a = (a*a)%m;
    }
    return r%m;
}

const ll N = 1e6+5, mod = 998244353;
ll p2[N], f[N], finv[N], p[N], a[N];

ll choose(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return f[n]*finv[n-k]%mod*finv[k]%mod;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    p2[0] = f[0] = finv[0] = 1;
    for (int i = 1; i <= n; i++) {
        p2[i] = 2*p2[i-1]%mod;
        f[i] = i*f[i-1]%mod;
        finv[i] = inv(f[i], mod);
        a[i] = a[i-1]+(s[i-1] == '?');
        p[i] = p[i-1]+(s[i-1] == '(');
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = (ans+p[i]*choose(a[n], n-p[n]-i))%mod;
        ans = (ans+a[i]*choose(a[n]-1, n-p[n]-i-1))%mod;
    }
    cout << ans << "\n";
}