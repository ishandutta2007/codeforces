#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct dsu {

    vector<int> p, sz;

    dsu(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int rep(int x) {
        while (x != p[x]) x = p[x] = p[p[x]];
        return x;
    }

    void unite(int a, int b) {
        a = rep(a), b = rep(b);
        if (a != b) p[b] = a, sz[a] += sz[b];
    }

    // returns true if a and b are in the same set.
    bool query(int a, int b) {
        return rep(a) == rep(b);
    }

    // returns the size of the set containing x
    int size(int x) {
        return sz[rep(x)];
    }
};

const int N = 1e6+5;
int cyc[N];
bitset<N> dp;

void apply(ll i) {
    debug(i);
    dp = (dp<<i)|dp;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    dsu u(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a; a--;
        if (u.query(i, a)) cyc[u.size(i)]++;
        u.unite(i, a);
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) ans += (cyc[i])*(i/2);
    ans = min(n, 2*min(k, ans) + max(0ll, k-ans));
    dp[0] = 1;
    for (int i = 0; i <= n; i++)
        if (cyc[i]) {
            ll x = 1ll<<(31-__builtin_clz(cyc[i]));
            for (ll y = 1; y < x; y *= 2) apply(y*i);
            apply((cyc[i]-x+1)*i);
        }
    for (int i = 0; i <= n; i++)
        debug((int)dp[i]);
    cout << (k+(dp[k] ? 0 : 1)) << " " << ans << "\n";
}