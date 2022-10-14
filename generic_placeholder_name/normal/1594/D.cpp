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

struct dsu {
    vi d;
    dsu(int n): d(n, -1) {}
    int find(int x) {return d[x] < 0 ? x : d[x] = find(d[x]);}
    void join(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(d[x] > d[y]) swap(x, y);
        d[x] += d[y]; d[y] = x;
    }
    bool is_joined(int x, int y) {return find(x) == find(y);}
    int comp_size(int x) {return -d[find(x)];}
};

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n, m; cin >> n >> m;
        vector<pii> same, diff;
        dsu d(n);
        rep(i, m) {
            int u, v; string type; cin >> u >> v >> type; --u, --v;
            if(type == "crewmate") same.eb(u, v);
            else diff.eb(u, v);
        }
        for(auto& [u, v]: same) d.join(u, v);
        vi idx(n, -1);
        vi a;
        rep(i, n) if(i == d.find(i)) {
            idx[i] = a.size();
            a.pb(d.comp_size(i));
        }
        vvi adj(a.size());
        bool ok = 1;
        for(auto& [u, v]: diff) {
            if(d.is_joined(u, v)) {
                ok = 0;
                break;
            }
            else {
                int i = idx[d.find(u)], j = idx[d.find(v)];
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
        if(!ok) {
            cout << "-1\n";
            continue;
        }
        ok = 1;
        vi side(a.size(), -1);
        queue<int> q;
        int mx = 0;
        int z[2] = {0};
        rep(i, a.size()) {
            if(!~side[i]) {
                q.push(i);
                side[i] = 0;
                z[0] = a[i];
                z[1] = 0;
                while(!q.empty()) {
                    int u = q.front(); q.pop();
                    for(int v: adj[u]) {
                        if(!~side[v]) {
                            side[v] = side[u] ^ 1;
                            z[side[v]] += a[v];
                            q.push(v);
                        }
                        else {
                            ok &= side[v] != side[u];
                        }
                    }
                }
                mx += max(z[0], z[1]);
            }
        }
        if(!ok) cout << "-1\n";
        else cout << mx << endl;
    }
}