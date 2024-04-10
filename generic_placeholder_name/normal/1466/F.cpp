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
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

struct dsu {
    vi d;
    vb t;

    dsu(int n): d(n, -1), t(n, 0) {}

    int find(int x) {return d[x]<0?x:d[x]=find(d[x]);}
    bool join(int x, int y) {
        x=find(x), y=find(y);
        if(x==y) return 0;
        if(d[x]>d[y]) swap(x, y);
        d[x]+=d[y]; d[y]=x;
        if(t[x]&&t[y]) return 0;
        else return t[x]=t[x]|t[y], 1;
    }
    bool is_activated(int x) {return t[find(x)];}
    void activate(int x) {t[find(x)]=1;}
};

int32_t main() {
    fastio;
    int n, m; cin>>n>>m;
    vector<pii> a(n);
    rep(i, n) {
        int s; cin>>s;
        if(s==1) cin>>a[i].fi, --a[i].fi, a[i].se=-1;
        else {
            cin>>a[i].fi>>a[i].se;
            --a[i].fi, --a[i].se;
            if(a[i].fi>a[i].se) swap(a[i].fi, a[i].se);
        }
    }
    //hmm
    //it's literally a vector basis
    vi ans;
    dsu d(m);
    rep(i, n) {
        if(~a[i].se) {
            if(d.join(a[i].fi, a[i].se)) ans.pb(i);
        }
        else {
            if(!d.is_activated(a[i].fi)) d.activate(a[i].fi), ans.pb(i);
        }
    }
    int cnt=1; rep(_, ans.size()) {cnt*=2; if(cnt>=1000000007) cnt-=1000000007;}
    cout<<cnt<<' '<<ans.size()<<endl;
    for(auto& v: ans) cout<<v+1<<' '; cout<<endl;
}