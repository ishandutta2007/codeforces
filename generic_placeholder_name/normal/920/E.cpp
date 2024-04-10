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
    vi d;
    dsu() {}
    dsu(int n): d(n, -1) {}
    int find(int x) {return d[x]<0?x:d[x]=find(d[x]);}
    int get_size(int x) {return -d[find(x)];}
    void join(int x, int y) {
        x=find(x), y=find(y);
        if(x==y) return;
        if(d[x]>d[y]) swap(x, y);
        d[x]+=d[y]; d[y]=x;
    }
};

int32_t main() {
    fastio;
    int n, m; cin>>n>>m;
    dsu d(n);
    vector<unordered_set<int>> s(n);
    rep(i, m) {
        int u, v; cin>>u>>v;
        s[--u].insert(--v);
        s[v].insert(u);
    }
    vi large, small;
    rep(i, n) {
        if(n-s[i].size()>n/2) large.pb(i);
        else small.pb(i);
    }
    rep1(i, (int)large.size()-1) d.join(large[i], large[0]);
    for(int u: small) {
        rep(v, n) {
            if(v!=u&&s[u].find(v)==s[u].end()) d.join(u, v);
        }
    }
    vi ans;
    rep(i, n) if(d.find(i)==i) ans.pb(d.get_size(i));
    sort(all(ans));
    cout<<ans.size()<<endl;
    for(int it: ans) cout<<it<<' '; cout<<endl;
}