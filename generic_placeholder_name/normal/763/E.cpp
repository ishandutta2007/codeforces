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

//solution is super nice
//but nobody explained it before
//so i thought i'd give it a shot here

constexpr int N=100005;

int n, k, m;
int t[N];
vi adj[N];

//fenwick operations
inline void upd(int x) {for(; x<=n; x+=x&-x) t[x]++;}
inline int getpf(int x) {int res=0; for(; x; x-=x&-x) res+=t[x]; return res;}
inline int get(int l, int r) {return getpf(r)-getpf(l-1);}

int in[N];

void dfs(int u) {
    //in[i] = visit time of i
    //basically if i-j then if in[i]<in[j] i is the ancestor if j
    //this will be useful later
    static int t=0;
    in[u]=++t;
    for(int v: adj[u]) if(!in[v]) dfs(v);
}

bool rt[N]; //root check

int check(int u, int l, int r){
	if(rt[u]) return 0;
	for(int v: adj[u]){
		if(v<l||v>r) continue;
		if(in[v]<in[u]) return 0;
		//remember that part about visiting time? well it's used here
		//to check if u is a descendant of any valid node or not
		//if yes then you can just attach it to that component, so return 0
	}
	return 1;
}

int query(int l, int r) {
    //so here's the catch:
    //the answer is the number of distinct trees in the dfs-forest
    //the part between l+k and r-k is basically fixed b/c the edge set doesn't change for them
    //so we look for new root nodes between l and l+k-1 and r-k+1 and r
    //which is easy enough
    //just check for all nodes in valid range if there's any that's before it in the original dfs-order
    //which gives O(log n + k^2) per query
    int ans=get(l, r);
    for(int i=l; i<=min(r, l+k-1); i++) ans+=check(i, l, r);
    for(int i=max(l+k, r-k+1); i<=r; i++) ans+=check(i, l, r);
    return ans;
}

int32_t main() {
    fastio;
    cin>>n>>k>>m;
    rep(i, m) {
        int u, v; cin>>u>>v;
        adj[u].pb(v); adj[v].pb(u);
    }
    rep1(i, n) if(!in[i]) rt[i]=1, upd(i), dfs(i);
    int q; cin>>q;
    while(q--) {
        int l, r; cin>>l>>r;
        cout<<query(l, r)<<endl;
    }
}