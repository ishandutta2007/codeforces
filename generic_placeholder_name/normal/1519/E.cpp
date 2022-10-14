#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

struct chash {
    inline static const uint64_t splitmix64(const uint64_t& x) {
        uint64_t z = (x + 0x9e3779b97f4a7c15);
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
        z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
        return z ^ (z >> 31);
    }

    template<typename T, typename U>
    const size_t operator() (const pair<T, U>& x) const {
        static const uint64_t RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.fi + RANDOM) ^ splitmix64(x.se + RANDOM);
    }
};

int32_t main() {
    fastio;
    int n; cin >> n;
    vi a(n), b(n), c(n), d(n);
    rep(i, n) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        int gx = gcd(a[i], b[i]);
        int gy = gcd(c[i], d[i]);
        a[i] /= gx, b[i] /= gx;
        c[i] /= gy, d[i] /= gy;
    }
    vector<vector<pii>> adj; adj.reserve(n << 1);
    int sz = 0;
    auto get = [&](int a, int b, int c, int d) -> int {
        static gp_hash_table<pair<ll, ll>, int, chash> conv;
        ll x = a * 1LL * d, y = b * 1LL * c;
        ll g = gcd(x, y);
        x /= g, y /= g;
        auto r = mp(x, y);
        if(conv.find(r) != conv.end()) return conv[r];
        else return adj.eb(), conv[r] = sz++;
    };
    auto add_edge = [&](int u, int v, int i) {
        adj[u].eb(v, i);
        adj[v].eb(u, i);
    };
    rep(i, n) add_edge(get(a[i], b[i], c[i] + d[i], d[i]), get(a[i] + b[i], b[i], c[i], d[i]), i);
    vi vis(sz);
    vector<pii> ans;
    auto dfs = [&](int u) -> void {
        auto dfs = [&](int u, const auto& self) -> int {
            vis[u] = -1;
            int cur = -1;
            for(auto [v, i]: adj[u]) {
                if(!~vis[v]) continue;
                if(!vis[v]) {
                    int x = self(v, self);
                    if(~x) ans.eb(i, x), i = -1;
                }
                if(~i) {
                    if(~cur) {
                        ans.eb(cur, i);
                        cur = -1;
                    }
                    else cur = i;
                }
            }
            vis[u] = 1;
            return cur;
        };
        dfs(u, dfs);
    };
    rep(i, sz) if(!vis[i]) dfs(i);
    cout << ans.size() << endl;
    for(auto& [u, v]: ans) cout << u + 1 << ' ' << v + 1 << endl;
}