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

constexpr int N=1e6+2;

int a[N];
int par[N];
vi adj[N];
int tin[N], tout[N];

void dfs(int u) {
    static int t=0;
    tin[u]=t++;
    for(int v: adj[u]) dfs(v);
    tout[u]=t-1;
}

int t[4*N+8], lz[4*N+8];

void push(int v) {
    if(!lz[v]) return;
    t[v*2]+=lz[v];
    lz[v*2]+=lz[v];
    t[v*2+1]+=lz[v];
    lz[v*2+1]+=lz[v];
    lz[v]=0;
}

void upd(int ql, int qr, int val, int v=1, int l=0, int r=N) {
    if(ql>r||qr<l) return;
    if(ql<=l&&qr>=r) {
        t[v]+=val;
        lz[v]+=val;
    }
    else {
        push(v);
        int m=(l+r)/2;
        upd(ql, qr, val, v*2, l, m);
        upd(ql, qr, val, v*2+1, m+1, r);
        t[v]=max(t[v*2], t[v*2+1]);
    }
}

int get(int ql, int qr, int v=1, int l=0, int r=N) {
    if(ql>r||qr<l) return INT_MIN;
    if(ql<=l&&qr>=r) return t[v];
    else {
        push(v);
        int m=(l+r)/2;
        return max(get(ql, qr, v*2, l, m), get(ql, qr, v*2+1, m+1, r));
    }
}

int32_t main() {
    fastio;
    int n, k; cin>>n>>k;
    rep(i, n) cin>>a[i];
    stack<int> val;
    rep(i, n) {
        while(!val.empty()&&a[val.top()]<a[i]) {
            int v=val.top(); val.pop();
            par[v]=i; adj[i].pb(v);
        }
        val.push(i);
    }
    while(!val.empty()) {
        int v=val.top(); val.pop();
        par[v]=n; adj[n].pb(v);
    }
    dfs(n);
    rep(i, k) upd(tin[i], tout[i], 1);
    cout<<get(tin[n], tout[n])<<' ';
    for(int i=k; i<n; i++) {
        upd(tin[i], tout[i], 1);
        upd(tin[i-k], tout[i-k], -1);
        cout<<get(tin[n], tout[n])<<' ';
    }
    cout<<endl;
}