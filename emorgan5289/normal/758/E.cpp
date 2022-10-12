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

template<int N>
struct fenwick_multiset {

    ll s = 0, tree[N+1] = {};
    ll size() const { return s; }
    
    // insert x llo the set with multiplicity k
    void insert(ll x, const ll k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] += k;
        s += k;
    }

    // remove x from the set with multiplicity k
    void remove(ll x, const ll k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] -= k;
        s -= k;
    }

    // returns the number of elements in
    // the set which are strictly lower than x
    ll index(ll x) const {
        ll i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    // returns the number of elements in the set
    // which are exactly equal to x, O(1) amortized
    ll count(ll x) const {
        ll y = x+1, i = tree[x+1];
        for (y -= y & -y; x != y; x -= x & -x)
            i -= tree[x];
        return i;
    }

    // returns the x'th element of the set,
    // 0-based indexing
    ll get(ll x) const {
        ll i = 0;
        for (ll m = 1<<(31-__builtin_clz(N)); m > 0; m >>= 1)
            if (i+m <= N && tree[i+m] <= x)
                x -= tree[i += m];
        return i;
    }
};

const int N = 2e5+5;
int ord[N], par[N], vin[N], vout[N], h[N], t = 0;
ll w[N], p[N];
vector<int> adj[N];
fenwick_multiset<N> f;
multiset<pair<ll, int>, greater<>> dp[N];

ll qry(int i) {
    return f.index(vout[i]+1)-f.index(vin[i]);
}

void dfs1(int i) {
    vin[i] = t++;
    if (i != 0) f.insert(vin[par[i]], w[i]);
    for (auto& j : adj[i]) {
        h[j] = h[i]+1, dfs1(j);
        dp[i].insert({h[j], j});
    }
    vout[i] = t-1;
}

void dfs2(int i) {
    for (auto& j : adj[i]) {
        dfs2(j);
        if (dp[i].size() < dp[j].size())
            swap(dp[i], dp[j]);
        for (auto& x : dp[j])
            dp[i].insert(x);
        dp[j].clear();
    }
    while (qry(i) > p[i]) {
        if (dp[i].empty()) cout << "-1\n", exit(0);
        auto [_, j] = *dp[i].begin();
        dp[i].erase(dp[i].begin());
        ll d = min(w[j]-1, p[j]-qry(j));
        if (d < 0) cout << "-1\n", exit(0);
        ll c = min(d, qry(i)-p[i]);
        p[j] -= c, w[j] -= c;
        f.remove(vin[par[j]], c);
        if (c != d) dp[i].insert({h[j], j});
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        ll x, y; cin >> x >> y; x--, y--;
        cin >> w[y] >> p[y];
        adj[x].pb(y);
        ord[i] = y, par[y] = x;
    }
    p[0] = inf_ll;
    dfs1(0); dfs2(0);
    cout << n << "\n";
    for (int i = 0; i < n-1; i++) {
        int j = ord[i];
        cout << par[j]+1 << " " << j+1 << " " << w[j] << " " << p[j] << "\n";
    }
}