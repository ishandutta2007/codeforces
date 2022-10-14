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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N=601;
vi adj[N];
int color[N];
int par[N];

int ask(const vi& a) {
    cout<<"? "<<a.size()<<endl;
    for(int v: a) cout<<v<<' ';
    cout<<endl;
    int ret; cin>>ret; return ret;
}

bool has_intersection(int x, const vi& a) {
    vi b=a; b.pb(x);
    return ask(b)>ask(a);
}

int bs(int u, const vi& a, int l, int r) {
    if(l==r) return a[l];
    else {
        int m=(l+r)/2;
        vi b;
        for(int i=l; i<=m; i++) b.pb(a[i]);
        vi c=b; c.pb(u);
        if(ask(c)>ask(b)) return bs(u, a, l, m);
        else return bs(u, a, m+1, r);
    }
}

void dfs(int u, int c, int p=-1) {
    color[u]=c;
    for(int v: adj[u]) if(v!=p) dfs(v, c^1, u);
}

void dfs2(int u, int p=-1) {
    par[u]=p;
    for(int v: adj[u]) if(v!=p) dfs2(v, u);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n; cin>>n;
    if(n<=2) return puts("Y 1\n1"), 0;
    vi lf{1}, rg(n-1);
    iota(all(rg), 2);
    while(!rg.empty()) {
        int u=0;
        while(!u) {
            u=lf.back();
            if(!has_intersection(u, rg)) {
                lf.pop_back();
                u=0;
            }
        }
        int v=bs(u, rg, 0, rg.size()-1);
        adj[u].pb(v);
        adj[v].pb(u);
        lf.pb(v);
        rg.erase(find(all(rg), v));
    }
    dfs(1, 0);
    vi c[2];
    rep1(i, n) c[color[i]].pb(i);
    int s[2]={ask(c[0]), ask(c[1])};
    if(!s[0]&&!s[1]) {
        cout<<"Y "<<c[0].size()<<endl;
        for(int v: c[0]) cout<<v<<' ';
        cout<<endl;
        return 0;
    }
    else {
        if(s[1]) {
            swap(s[0], s[1]);
            c[0].swap(c[1]);
        }
        int x=0, y=0;
        for(int v: c[0]) {
            vi rst; rst.reserve(c[0].size()-1);
            for(int x: c[0]) if(x!=v) rst.pb(x);
            if(ask(rst)<s[0]) {
                x=v;
                y=bs(x, rst, 0, rst.size()-1);
            }
        }
        vi ans{x};
        dfs2(x);
        int cur=y;
        while(cur!=x) ans.pb(cur), cur=par[cur];
        cout<<"N "<<ans.size()<<endl;
        for(int v: ans) cout<<v<<' ';
        cout<<endl;
        return 0;
    }
}