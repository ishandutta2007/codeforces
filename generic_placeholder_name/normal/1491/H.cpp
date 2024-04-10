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

constexpr int N=1e5+5, T=250;
int a[N];
int blk[N];
int lst[N];
int lz[N/T+1];

__attribute__((always_inline)) int get_nxt(int v) {
    return max(a[v]-lz[blk[v]], (v>1?1:0));
}

int get_lst(int v) {
    if(lz[blk[v]]>=T) return get_nxt(v);
    else return lst[v];
}

void calc(int l, int r, int x) {
    for(int v=l; v<=r; v++) {
        int par=get_nxt(v);
        if(blk[par]<blk[v]) lst[v]=par;
        else lst[v]=lst[par];
    }
}

int32_t main() {
    fastio;
    int n, q; cin>>n>>q;
    blk[0]=-1; a[1]=0;
    rep1(i, n-1) cin>>a[i+1];
    rep1(i, n) blk[i]=(i-1)/T;
    rep(i, (n+T-1)/T) calc(i*T+1, min(i*T+T, n), 0);
    while(q--) {
        int type; cin>>type;
        if(type==1) {
            int l, r, x; cin>>l>>r>>x;
            int lf=blk[l], rg=blk[r];
            if(lf!=rg) {
                for(; blk[l]==lf; l++) a[l]-=x;
                for(; blk[r]==rg; r--) a[r]-=x;
                for(int b=lf+1; b<rg; b++) lz[b]+=x;
            }
            else {
                for(int i=l; i<=r; i++) a[i]-=x;
            }
            for(int b=lf; b<=rg; b++) {
                if(lz[b]<T) calc(b*T+1, min(b*T+T, n), lz[b]);
            }
        }
        else {
            assert(type==2);
            int u, v; cin>>u>>v;
            for(; lst[u]!=lst[v]; v=get_lst(v)) {
                if(blk[u]>blk[v]) swap(u, v);
            }
            for(; u!=v; v=get_nxt(v)) {
                if(u>v) swap(u, v);
            }
            cout<<u<<endl;
        }
    }
}