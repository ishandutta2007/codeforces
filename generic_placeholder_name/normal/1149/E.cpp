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

vi toposort(const vvi& adj) {
    int n=adj.size();
    vb vis(n);
    vi ans;
    const auto dfs = [&](int u) -> void {
        static const auto dfs = [&](int u, const auto& self) -> void {
            vis[u]=1;
            for(int v: adj[u]) if(!vis[v]) self(v, self);
            ans.pb(u);
        };
        dfs(u, dfs);
    };
    rep(i, n) if(!vis[i]) dfs(i);
    reverse(all(ans));
    return ans;
}

int32_t main() {
    fastio;
    int n, m; cin>>n>>m;
    vi a(n);
    rep(i, n) cin>>a[i];
    vvi adj(n);
    rep(i, m) {
        int u, v; cin>>u>>v; --u, --v;
        adj[u].pb(v);
    }
    vi xr(n), val(n);
    auto idx=toposort(adj);
    reverse(all(idx));
    for(int u: idx) {
        set<int> s{-1};
        for(int v: adj[u]) s.insert(val[v]);
        for(int x: s) if(s.find(x+1)==s.end()) {
            val[u]=x+1;
            break;
        }
        xr[val[u]]^=a[u];
    }
    if(none_of(all(xr), [](int x) {return x!=0;})) puts("LOSE");
    else {
        cout<<"WIN\n";
        int mx=0;
        rep(i, n) if(xr[i]) mx=i;
        int p=-1;
        rep(i, n) if(val[i]==mx&&(xr[mx]^a[i])<a[i]) {
            a[i]=xr[mx]^a[i];
            xr[mx]=0;
            p=i;
            break;
        }
        for(int v: adj[p]) if(xr[val[v]]) {
            a[v]=xr[val[v]]^a[v];
            xr[val[v]]=0;
        }
        rep(i, n) cout<<a[i]<<' '; cout<<endl;
    }
}