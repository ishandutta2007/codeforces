#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const ll mod = 998244353;

template<typename T>
T inv(T a, T m) {
    T r = 1;
    for (T k = m-2; k; k >>= 1) {
        if (k&1) r = (r*a)%m;
        a = (a*a)%m;
    }
    return r%m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> a(n), p(n+1); for (auto& x : a) cin >> x;
    sort(all(a));
    for (int i = 0; i < n; i++)
        p[i+1] = a[i]+p[i];
    for (ll k = 1; k <= n; k++) {
        ll s = (n-k)/k, r = (n-k)%k, c = r;
        ll x = (p[r]*(s+1))%mod;
        for (ll i = s; i > 0; i--) {
            x = (x+(p[c+k]-p[c])*i)%mod;
            c += k;
        }
        x = (x*inv(n, mod))%mod;
        cout << x << "\n";
    }
}