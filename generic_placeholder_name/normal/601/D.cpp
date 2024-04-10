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

constexpr int N=3e5+1;
constexpr int pr=31;
constexpr ll MOD=141862177280553647LL;

vi adj[N];
int add[N];
int ans[N];
char s[N];

struct state {
    using si=unordered_set<ll>;
    si* a;
    state() {a=new si();}
    const size_t size() {return a->size();}
    void add(ll val) {
        a->insert(val);
    }
};

state merge(state a, state b) {
    if(b.size()>a.size()) swap(a, b);
    for(const auto& it: *(b.a)) a.add(it);
    return a;
}

state st[N];

void dfs(int u, int par, ll h) {
    h=(h*pr+s[u]-'a'+1)%MOD;
    st[u].add(h);
    for(int v: adj[u]) if(v!=par) {
        dfs(v, u, h);
        st[u]=merge(st[u], st[v]);
    }
    ans[u]=st[u].size()+add[u];
}

int32_t main() {
    fastio;
    int n; cin>>n;
    rep(i, n) cin>>add[i];
    rep(i, n) cin>>s[i];
    rep(i, n-1) {
        int u, v; cin>>u>>v;
        adj[--u].pb(--v);
        adj[v].pb(u);
    }
    dfs(0, -1, 0);
    int mx=*max_element(ans, ans+n);
    int cnt=0; rep(i, n) cnt+=ans[i]==mx;
    cout<<mx<<endl<<cnt<<endl;
}