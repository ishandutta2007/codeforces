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

struct dsu {
    int n; vi par;
    dsu() {};
    dsu(int n): n(n) {par.assign(n, -1);}
    const int find(int x) {return par[x]<0?x:par[x]=find(par[x]);}
    const int size(int x) {return -par[find(x)];}
    void join(int x, int y) {
        x=find(x); y=find(y);
        if(x==y) return;
        if(par[x]>par[y]) swap(x, y);
        par[x]+=par[y]; par[y]=x;
    }
};

int32_t main() {
    fastio;
    int n; cin>>n;
    dsu d[2]; d[0]=dsu(n); d[1]=dsu(n);
    rep(i, n-1) {
        int u, v, w; cin>>u>>v>>w;
        d[w].join(--u, --v);
    }
    ll ans=0;
    rep(i, n) ans+=1LL*d[0].size(i)*d[1].size(i)-1;
    cout<<ans<<endl;
}