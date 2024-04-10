#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

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

constexpr int N=1e5+1;

vi adj[N];
int color[N];

struct state {
    ordered_set<pii>* a;
    ordered_set<pii>* r;
    state() {a=new ordered_set<pii>(); r=new ordered_set<pii>();}
    const size_t size() {return a->size();}
    void add(int idx, int val=1) {
        auto it=(*a).lower_bound({idx, -1});
        if(it==a->end()||(*it).fi!=idx) a->insert({idx, val}), r->insert({val, idx});
        else {
            pii x=*it;
            a->erase(a->find(x)); r->erase(r->find({x.se, x.fi}));
            a->insert({x.fi, x.se+val}); r->insert({x.se+val, x.fi});
        }
    }
    int get(int x) {
        return r->size()-r->order_of_key({x, -1});
    }
    void clear() {a->clear(); r->clear();}
};

void merge(state& a, state& b) {
    if(b.size()>a.size()) swap(a, b);
    for(const auto& it: *(b.a)) a.add(it.fi, it.se);
    b.clear();
}

state st[N];
vi x[N]; vi idx[N];
int ans[N];

void dfs(int u, int par=-1) {
    st[u].add(color[u]);
    for (int v: adj[u]) if(v!=par) {
        dfs(v, u);
        merge(st[u], st[v]);
    }
    rep(i, idx[u].size()) ans[idx[u][i]]=st[u].get(x[u][i]);
}

int32_t main() {
    fastio;
    int n, q; cin>>n>>q;
    rep(i, n) cin>>color[i];
    rep(i, n-1) {
        int u, v; cin>>u>>v;
        adj[--u].pb(--v); adj[v].pb(u);
    }
    rep(i, q){
        int v, k; cin>>v>>k; --v;
        idx[v].pb(i); x[v].pb(k);
    }
    dfs(0);
    rep(i, q) cout<<ans[i]<<endl;
}