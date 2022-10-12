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
#define debug(...) 0
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

    // returns true if a and b are in the same set, and then unites them.
    bool unite(int a, int b) {
        a = rep(a), b = rep(b);
        if (sz[a] < sz[b]) swap(a, b);
        if (a != b) p[b] = a, sz[a] += sz[b];
        return a == b;
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

template<ll M>
struct modint {

    static ll _pow(ll n, ll k) {
        ll r = 1;
        for (; k > 0; k >>= 1, n = (n*n)%M)
            if (k&1) r = (r*n)%M;
        return r;
    }

    ll v; modint(ll n = 0) : v(n%M) { v += (M&(0-(v<0))); }
    
    friend string to_string(const modint n) { return to_string(n.v); }
    friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
    friend ostream& operator<<(ostream& o, const modint n) { return o << n.v; }
    template<typename T> explicit operator T() { return T(v); }

    friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
    friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
    friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
    friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
    friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
    friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }

    modint& operator+=(const modint n) { v += n.v; v -= (M&(0-(v>=M))); return *this; }
    modint& operator-=(const modint n) { v -= n.v; v += (M&(0-(v<0))); return *this; }
    modint& operator*=(const modint n) { v = (v*n.v)%M; return *this; }
    modint& operator/=(const modint n) { v = (v*_pow(n.v, M-2))%M; return *this; }
    friend modint operator+(const modint n, const modint m) { return modint(n) += m; }
    friend modint operator-(const modint n, const modint m) { return modint(n) -= m; }
    friend modint operator*(const modint n, const modint m) { return modint(n) *= m; }
    friend modint operator/(const modint n, const modint m) { return modint(n) /= m; }
    modint& operator++() { return *this += 1; }
    modint& operator--() { return *this -= 1; }
    modint operator++(int) { modint t = *this; return *this += 1, t; }
    modint operator--(int) { modint t = *this; return *this -= 1, t; }
    modint operator+() { return *this; }
    modint operator-() { return modint(0) -= *this; }

    // O(logk) modular exponentiation
    modint pow(const ll k) const {
        return k < 0 ? _pow(v, M-1-(-k%(M-1))) : _pow(v, k);
    }
    modint inv() const { return _pow(v, M-2); }
};

using mod = modint<int(1e9+7)>;

vector<ll> get_possible_masks() {
    vector<ll> x = {0};
    for (int i = 0; i < 32; i++) {
        vector<ll> y;
        for (ll j : x) {
            bool has_one = 0, has_both = 0;
            for (int k = 1; k < i; k++) {
                if ((k^i) >= i) continue;
                if ((j&(1ll<<k)) && (j&(1ll<<(k^i))))
                    has_both = 1;
                if ((j&(1ll<<k)) && !(j&(1ll<<(k^i))))
                    has_one = 1;
                if (!(j&(1ll<<k)) && (j&(1ll<<(k^i))))
                    has_one = 1;
            }
            if (!has_both) y.pb(j);
            if (!has_one) y.pb(j|(1ll<<i));
        }
        x = y;
    }
    sort(all(x));
    return x;
}
const auto masks = get_possible_masks();
map<ll, int> mask_to_i;
vector<vector<int>> combine;

ll fill_mask(ll x) {
    for (int i = 0; i < 32; i++)
        for (int j = 0; j < 32; j++)
            if ((x&(1ll<<i)) && (x&(1ll<<j)))
                x |= 1ll<<(i^j);
    return x;
}

vector<int> red, vis, val;
vector<vector<pair<ll, int>>> adj;
map<ll, vector<ll>> cyc;
map<ll, ll> cyc_mask;
int vis_t = 1;

void dfs(int i, int j, int c) {
    vis[i] = vis_t++;
    for (auto& [w, k] : adj[i])
        if ((red[k] == -1 || k == c) && k != j) {
            if (vis[k]) {
                if (vis[k] < vis[i]) {
                    cyc[c].pb(val[i]^val[k]^w);
                }
            } else {
                val[k] = val[i]^w;
                dfs(k, i, c);
            }
        }
}

int collapse_to_mask(vector<ll> c) {
    int y = 0;
    for (ll x : c) {
        if (x == 0) return -1;
        if (combine[y][mask_to_i[1ll<<x]] == -1)
            return -1;
        y = combine[y][mask_to_i[1ll<<x]];
    }
    return y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int s = masks.size();
    for (int i = 0; i < s; i++)
        mask_to_i[masks[i]] = i;
    combine.assign(s, vector<int>(s));
    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
            combine[i][j] = ((masks[i]&masks[j]) > 1) ? -1 : mask_to_i[fill_mask(masks[i]|masks[j])];

    ll n, m; cin >> n >> m;
    red.assign(n, -1);
    adj.assign(n, {});
    while (m--) {
        ll x, y, w; cin >> x >> y >> w;
        x--, y--;
        if (x > y) swap(x, y);
        if (x == 0)
            red[y] = w;
        else {
            adj[x].pb({w, y}), adj[y].pb({w, x});
        }
    }

    vis.assign(n, 0);
    val.assign(n, 0);
    for (int i = 0; i < n; i++)
        if (red[i] != -1) {
            dfs(i, i, i);
            cyc_mask[i] = collapse_to_mask(cyc[i]);
        }
    debug(red);
    vector<vector<ll>> opts;
    vis.assign(n, 0);
    for (int i = 0; i < n; i++)
        if (red[i] != -1) {
            for (auto& [w, j] : adj[i])
                if (red[j] != -1 && !vis[i] && !vis[j]) {
                    vis[i] = 1, vis[j] = 1;
                    vector<ll> opt;
                    for (ll x : cyc[j])
                        cyc[i].pb(x);
                    cyc_mask[i] = collapse_to_mask(cyc[i]);

                    if (cyc_mask[i] != -1) {
                        opt.pb(cyc_mask[i]);
                        opt.pb(cyc_mask[i]);
                    }

                    cyc[i].pb(red[i]^red[j]^w);
                    cyc_mask[i] = collapse_to_mask(cyc[i]);

                    if (cyc_mask[i] != -1) {
                        opt.pb(cyc_mask[i]);
                    }

                    if (!opt.empty())
                        opts.pb(opt);
                }
        }

    for (int i = 0; i < n; i++)
        if (red[i] != -1 && !vis[i]) {
            if (cyc_mask[i] != -1)
                opts.pb({cyc_mask[i]});
        }

    debug(opts);

    vector<mod> dp0(s), dp1(s);
    dp0[0] = dp1[0] = 1;

    for (auto& opt : opts) {

        debug(dp0);

        debug(opt);

        for (int x : opt)
            for (int i = 0; i < s; i++) {
                if (combine[i][x] != -1)
                    dp1[combine[i][x]] += dp0[i];
            }

        dp0 = dp1;
    }

    mod ans = 0;
    for (int i = 0; i < s; i++)
        ans += dp0[i];
    cout << ans << "\n";
}