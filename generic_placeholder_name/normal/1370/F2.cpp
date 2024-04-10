#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

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
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N=1001;
vi adj[N], dist[N]; int child[N];

map<vi, pii> queries;
pii ask(vi& x) {
    if(queries.find(x)!=queries.end()) return queries[x];
    cout<<"? "<<x.size()<<' ';
    for(int it: x) cout<<it+1<<' '; cout<<endl;
    pii res; cin>>res.fi>>res.se;
    assert(res.fi!=-1);
    --res.fi;
    return queries[x]=res;
}

void answer(int x, int y) {
    cout<<"! "<<x+1<<' '<<y+1<<endl;
    string resp; cin>>resp;
    assert(resp=="Correct");
}

int dfs(int u, int d, int p) {
    dist[d].pb(u);
    int ans=1;
    for(int v: adj[u]) if(v!=p) ans+=dfs(v, d+1, u);
    return child[u]=ans;
}

void cut(int u, int d, int p) {
    dist[d].erase(find(all(dist[d]), u));
    for(int v: adj[u]) if(v!=p) cut(v, d+1, u);
}

int32_t main() {
    int t; cin>>t; while(t--) {
        rep(i, N) adj[i].clear(), dist[i].clear(), child[i]=0;
        queries.clear();
        int n; cin>>n; rep(i, n-1) {
            int u, v; cin>>u>>v;
            adj[--u].pb(--v); adj[v].pb(u);
        }
        vi e(n); iota(all(e), 0);
        pii ret=ask(e); int rt=ret.fi, d=ret.se;
        dfs(rt, 0, -1);
        int mxs, mxsz=0;
        for(int v: adj[rt]) if(child[v]>mxsz) mxsz=child[v], mxs=v;
        cut(mxs, 1, rt);
        int l=0, r=n-1;
        while(l<r) {
            int m=(l+r+1)/2;
            if(dist[m].empty()) r=m-1;
            else if(ask(dist[m]).se!=d) r=m-1;
            else l=m;
        }
        int p1=ask(dist[l]).fi;
        rep(i, n) dist[i].clear(), child[i]=0;
        dfs(p1, 0, -1);
        int p2=ask(dist[d]).fi; answer(p1, p2);
    }
}