#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

constexpr int N = 3e5 + 5;
gp_hash_table<int, int, custom_hash> occ;
gp_hash_table<int, int, custom_hash> conv;
vi adj[N];

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n, m; cin >> n >> m;
        occ.clear();
        rep(i, n) adj[i].clear();
        conv.clear();
        vi a(n);
        rep(i, n) {
            cin >> a[i];
            occ[a[i]]++;
        }
        sort(all(a));
        a.erase(unique(all(a)), a.end());
        int sz = a.size();
        rep(i, sz) conv[a[i]] = i;
        vvi idx(n + 1);
        for(auto& [x, v]: occ) {
            adj[conv[x]].pb(conv[x]);
            idx[v].pb(conv[x]);
        }
        vector<pair<int, vi>> p;
        rep1(i, n) if(!idx[i].empty()) p.eb(i, idx[i]);
        for(auto& [_, v]: p) sort(rall(v));
        rep(_, m) {
            int u, v; cin >> u >> v;
            u = conv[u], v = conv[v];
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vb ban(sz);
        ll ans = 0;
        for(auto& [x, c]: occ) {
            int ix = conv[x];
            for(int iy: adj[ix]) ban[iy] = 1;
            for(auto& [d, v]: p) {
                if(d > c) break;
                for(int iy: v) if(!ban[iy]) {
                    ans = max(ans, (c + d) * 1LL * (x + a[iy]));
                    break;
                }
            }
            for(int iy: adj[ix]) ban[iy] = 0;
        }
        cout << ans << endl;
    }
}