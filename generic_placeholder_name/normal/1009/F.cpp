#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("unroll-loops")
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

//this is why i hate handling pointers
constexpr int N=1e6+1;

struct state {
    vi* a;
    int mx;
    state() {a=new vi(); mx=0;}
    state(vi* a, int mx): a(a), mx(mx) {}
    const size_t size() {return a->size();}
    void add(int i, int val) {
        (*a)[i]+=val;
        if((*a)[i]+(i>mx)>(*a)[mx]) mx=i; //depth is reversed
    }
};

state pull(state z) { //add end vertex
    if(z.size()==0) return state(new vi(1, 1), 0);
    else {
        state c(z.a, z.mx);
        c.a->pb(0);
        c.add(c.size()-1, 1);
        return c;
    }
}

state merge(state a, state b) {
    if(b.size()>a.size()) swap(a, b);
    state c(a.a, a.mx);
    rep(i, b.size()) c.add(a.size()-i-1, (*(b.a))[b.size()-i-1]);
    return c;
}

state s[N];
vi adj[N];
int ans[N];

void dfs(int u, int par=-1) {
    for(int v: adj[u]) if(v!=par) {
        dfs(v, u);
        s[u]=merge(s[u], s[v]);
    }
    s[u]=pull(s[u]);
    ans[u]=s[u].size()-s[u].mx-1;
}

int32_t main() {
    fastio;
    int n; cin>>n;
    rep(i, n-1) {
        int u, v; cin>>u>>v;
        adj[--u].pb(--v);
        adj[v].pb(u);
    }
    dfs(0);
    rep(i, n) cout<<ans[i]<<' '; cout<<endl;
}