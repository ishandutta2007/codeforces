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

int coordinate_compress(vector<pii>& a, vi& rev) { //returns max value
    const int n=a.size();
    set<int> s; map<int, int> m;
    rep(i, n) s.insert(a[i].fi), s.insert(a[i].se);
    int cur=0, sz=s.size(); while(!s.empty()) m[*s.begin()]=cur++, rev.pb(*s.begin()), s.erase(s.begin());
    rep(i, n) a[i].fi=m[a[i].fi], a[i].se=m[a[i].se];
    return sz;
}

struct dsu {
    vi d;
    dsu() {}
    dsu(int n): d(n, -1) {}
    int find(int x) {return d[x]<0?x:d[x]=find(d[x]);}
    void join(int x, int y) {
        x=find(x); y=find(y);
        if(x==y) return;
        if(d[x]>d[y]) swap(d[x], d[y]);
        d[x]+=d[y]; d[y]=x;
    }
};

int32_t main() {
    fastio;
    int n; cin>>n;
    vector<pii> a(n); rep(i, n) cin>>a[i].fi>>a[i].se;
    vi rev;
    int m=coordinate_compress(a, rev);
    dsu d(m);
    rep(i, n) d.join(a[i].fi, a[i].se);
    vvi V(m); vi E(m, 0);
    rep(i, m) V[d.find(i)].pb(i);
    rep(i, n) E[d.find(a[i].fi)]++;
    rep(i, m) if(V[i].size()<E[i]) return cout<<"-1\n", 0;
    int ans=0;
    rep(i, m) if(E[i]) {
        if(V[i].size()==E[i]) ans=max(ans, V[i].back()); //max
        else ans=max(ans, V[i][V[i].size()-2]); //second max
    }
    cout<<rev[ans]<<endl;
}