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

constexpr int N=1e6+1;

int n, k;
vi adj[N];
int color[N];
int par[N];
int c[N];

map<int, int>* dfs(int u, int d, int& sum) {
    map<int, int>* ans=new map<int, int>();
    sum=0;
    for(int v: adj[u]) {
        int cur=0;
        map<int, int>* m=dfs(v, d+1, cur);
        if(m->size()>ans->size()) swap(m, ans);
        for(const auto& it: *m) (*ans)[it.fi]+=it.se;
        sum+=cur;
    }
    if(adj[u].empty()) (*ans)[d]=1, sum=1;
    while(!ans->empty()&&ans->begin()->fi>=d+k) sum-=ans->begin()->se, ans->erase(ans->begin());
    c[u]=sum;
    return ans;
}

int f(int u) {
    if(adj[u].empty()) return 1;
    int r=0, mx=-1e9;
    for(int v: adj[u]) {
        r+=c[v];
        mx=max(mx, f(v)-c[v]);
    }
    return r+mx;
}

int32_t main() {
    fastio;
    cin>>n>>k;
    rep1(i, n-1) {
        cin>>par[i];
        adj[--par[i]].pb(i);
    }
    if(n==1) return cout<<"1\n", 0;
    int _; dfs(0, 0, _);
    cout<<f(0)<<endl;
}