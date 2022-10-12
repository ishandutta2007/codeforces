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

template<typename T>
T inv(T a, T m) {
    T r = 1;
    for (T k = m-2; k; k >>= 1) {
        if (k&1) r = (r*a)%m;
        a = (a*a)%m;
    }
    return r%m;
}

template<typename T>
T choose(T n, T k, T m) {
    T a = 1, b = 1, r = n;
    k = min(k, n-k);
    for (T d = 1; d <= k; d++, r--) {
        a = (a*r)%m;
        b = (b*d)%m;
    }
    return (a*inv(b, m))%m;
}

const ll N = 1e6, mod = 998244353;
array<ll, 2> a[N];
ll f[N], fi[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    f[0] = fi[0] = 1;
    for (ll i = 1; i <= n; i++)
        f[i] = f[i-1]*i%mod, fi[i] = inv(f[i], mod);
    for (int i = 0; i < n; i++) {
        ll l, r; cin >> l >> r;
        a[2*i] = {l, 0}, a[2*i+1] = {r, 1};
    }
    sort(a, a+2*n);
    ll r = 0, ans = 0;
    for (ll i = 0; i < 2*n; i++) {
        if (!a[i][1] && r >= k-1) {
            ans += f[r]*fi[k-1]%mod*fi[r-k+1]%mod;
            ans %= mod;
        }
        r += a[i][1] ? -1 : 1;
    }
    cout << ans << "\n";
}