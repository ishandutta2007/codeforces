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

constexpr int N=5e5+5;
int p[N], q[N];
bool is_rt[N];
vi cmp[N];
set<int> rem;
gp_hash_table<int, null_type> adj[N];

bool dfs(int u, bool rt=0) {
    rem.erase(u);
    int v=0, z=0;
    for(auto itr=rem.lower_bound(v); itr!=rem.end(); v++, itr=rem.lower_bound(v)) {
        v=*itr;
        if(adj[u].find(v)!=adj[u].end()) adj[u].erase(v);
        else {
            z=v;
            if(!dfs(v)) is_rt[u]=1, cmp[u].pb(v);
        }
    }
    if(!is_rt[u]&&rt) {
        if(!z) is_rt[u]=1;
        else cmp[z].pb(u);
    }
    return is_rt[u];
}

void solve_case() {
    int n, m; cin>>n>>m;
    rep1(i, n) {
        adj[i].clear();
        rem.insert(i);
        cmp[i].clear();
    }
    memset(is_rt, 0, (n+1)*sizeof(bool));
    rep(i, m) {
        int u, v; cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    rep1(i, n) if(rem.find(i)!=rem.end()) dfs(i, 1);
    for(int i=1, j=1; i<=n; i++) {
        if(is_rt[i]) {
            p[i]=j;
            for(int v: cmp[i]) {
                q[v]=j;
                p[v]=++j;
            }
            q[i]=j++;
        }
    }
    rep1(i, n) cout<<p[i]<<' '; cout<<endl;
    rep1(i, n) cout<<q[i]<<' '; cout<<endl;
}

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) solve_case();
}