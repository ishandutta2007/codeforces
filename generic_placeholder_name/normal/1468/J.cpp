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
    int cmp;

    dsu() {}
    dsu(int n): d(n, -1), cmp(n) {}

    int find(int x) {return d[x]<0?x:d[x]=find(d[x]);}
    bool join(int x, int y) {
        x=find(x), y=find(y);
        if(x==y) return 0;
        if(d[x]>d[y]) swap(x, y);
        d[x]+=d[y]; d[y]=x;
        return cmp--, 1;
    }
    bool is_connected() {return cmp==1;}
};

struct Edge {
    int u, v, w;

    Edge() {}
    Edge(int u, int v, int w): u(u), v(v), w(w) {}

    bool operator < (const Edge& oth) const {return w<oth.w;}
};

void solve_case() {
    int n, m, k; cin>>n>>m>>k;
    dsu d(n);
    vector<Edge> small, large;
    rep(i, m) {
        int u, v, w; cin>>u>>v>>w;
        if(w<=k) small.eb(--u, --v, w);
        else large.eb(--u, --v, w);
    }
    sort(all(small));
    sort(all(large));
    for(auto& edge: small) d.join(edge.u, edge.v);
    if(d.is_connected()) {
        int ans=k-small.back().w;
        if(!large.empty()) ans=min(ans, large[0].w-k);
        return void(cout<<ans<<endl);
    }
    else {
        ll ans=0;
        for(auto& edge: large) {
            if(d.join(edge.u, edge.v)) ans+=edge.w-k;
            if(d.is_connected()) return void(cout<<ans<<endl);
        }
        assert(0);
    }
}

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) solve_case();
}