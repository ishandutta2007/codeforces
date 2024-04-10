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

int32_t main() {
    fastio;
    int n; cin>>n;
    vi a(n+1);
    rep1(i, n) cin>>a[i];
    vi inc(n+1); iota(all(inc), 0);
    vector<pii> ans;
    const auto op = [&](int i, int j) {
        ans.eb(i, j);
        swap(a[i], a[j]);
        a[i]=-a[i]; a[j]=-a[j];
    };
    auto solve_pair_cyc = [&](const vi& f, const vi& s) { //miscounted this as n+1 in contest
        int x=f.back(), y=s.back();
        op(x, y);
        while(-a[x]!=y||-a[y]!=x) {
            if(-a[x]!=y) op(x, -a[x]);
            else op(y, -a[y]);
        }
        op(x, y);
    };
    auto solve_cyc = [&](const vi& cyc) {
        if(cyc.size()==2) {
            int t=1; while(cyc[0]==t||cyc[1]==t) t++;
            op(t, cyc[0]);
            op(t, cyc[1]);
            op(t, cyc[0]);
        }
        else {
            int m=cyc.size();
            op(cyc[m-1], cyc[m-3]);
            rep(i, m-3) op(cyc[m-3], cyc[i]);
            op(cyc[m-3], cyc[m-2]);
            op(cyc[m-2], cyc[m-1]);
            op(cyc[m-1], cyc[m-3]);
        }
    };
    vvi cycs;
    vb vis(n+1);
    rep1(i, n) if(!vis[i]&&a[i]!=i) {
        cycs.pb(vi{i}); vis[i]=1;
        for(int p=a[i]; p!=i; p=a[p]) cycs.back().pb(p), vis[p]=1;
    }
    for(int i=0; i+1<cycs.size(); i+=2) solve_pair_cyc(cycs[i], cycs[i+1]);
    if(cycs.size()&1) solve_cyc(cycs.back());
    assert(a==inc);
    assert(ans.size()<=n+1);
    cout<<ans.size()<<endl;
    for(auto& p: ans) cout<<p.fi<<' '<<p.se<<endl;
}