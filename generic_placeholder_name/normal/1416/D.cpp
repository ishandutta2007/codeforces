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
    struct op {
        int v, p, t;
        op() {}
        op(int v, int p, int t): v(v), p(p), t(t) {}
    };

    vi d;
    stack<op> s;
    vvi g;
    vi pos;
    vb del;

    dsu() {}
    dsu(vi& v): d(v.size(), -1), g(v.size()), pos(v.size()+1), del(v.size()+1) {
        rep(i, v.size()) {
            g[i].pb(v[i]);
            pos[v[i]]=i;
		}
    }

    int find(int x) {
        int v=x;
        while(d[v]>=0) v=d[v];
        return v;
    }

    void join(int x, int y, int t) {
        x=find(x); y=find(y);
        if(x==y) return;
        if(d[x]>d[y]) swap(x, y);
        s.emplace(x, d[x], t);
        s.emplace(y, d[y], t);
        d[x]+=d[y]; d[y]=x;
        for(int v: g[y]) g[x].pb(v), pos[v]=x;
    }

    int query(int v) {
        v=find(v);
        while(!g[v].empty()) {
            int u=g[v].back();
            g[v].pop_back();
            if (!u||pos[u]!=v||del[u]) continue;
            else {
                del[u]=1;
                return u;
            }
        }
        return 0;
    }

    void rollback(int t) {
        while(!s.empty()&&s.top().t>=t) {
            op small=s.top(); s.pop();
            op large=s.top(); s.pop();
            for(int x: g[small.v]) pos[x]=small.v;
            d[small.v]=small.p;
            d[large.v]=large.p;
        }
    }
};

int32_t main() {
    fastio;
    int n, m, q; cin>>n>>m>>q;
    vi a(n); rep(i, n) cin>>a[i];
    vector<pii> e(m); vb rem(m);
    rep(i, m) {
        int u, v; cin>>u>>v;
        e[i]={u-1, v-1};
    }
    vector<pii> qs(q);
    rep(i, q) {
        cin>>qs[i].fi>>qs[i].se; --qs[i].se;
        if(qs[i].fi==2) rem[qs[i].se]=1;
    }
    dsu d(a);
    int t=0;
    rep(i, m) if(!rem[i]) d.join(e[i].fi, e[i].se, -1);
    for(int i=q-1; ~i; i--) if(qs[i].fi==2) {
        int x=qs[i].se;
        d.join(e[x].fi, e[x].se, t++);
    }
    rep(i, n) sort(all(d.g[i]));
    rep(i, q) {
        if(qs[i].fi==2) d.rollback(--t);
        else cout<<d.query(qs[i].se)<<endl;
    }
    return 0;
}