#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const ll mod = 998244353, maxn = 500005;
ll f[maxn];

// returns a unique number b s.t. ab = 1 mod m in O(logm) time.
template<typename T>
T inv(T a, T m) {
    T r = 1, k = m-2;
    while (k) {
        if (k&1) r = (r*a)%m;
        a = (a*a)%m;
        k >>= 1;
    }
    return r%m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    f[0] = 1;
    for (ll i = 1; i < maxn; i++)
        f[i] = (f[i-1]*i)%mod;
    ll n, k; cin >> n >> k;
    ll out = 0;
    for (ll i = 1; i <= n; i++) {
        if (n/i < k) continue;
        ll c = f[n/i-1];
        c = c*inv(f[k-1], mod)%mod;
        c = c*inv(f[n/i-k], mod)%mod;
        out = (out+c)%mod;
    }
    cout << out << "\n";
}