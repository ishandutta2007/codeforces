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
 
constexpr int N=3e5+1;
int n;
 
ll sum[4*N+1]; int mx[4*N+1];
 
int div(int x) {
    int cnt=0;
    for(int i=1; i*i<=x; i++) if(x%i==0) cnt+=1+(i*i!=x);
    return cnt;
}
 
void build(int a[], int v=1, int tl=0, int tr=n-1) {
    if(tl==tr) sum[v]=mx[v]=a[tl];
    else {
        int tm=(tl+tr)/2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        sum[v]=sum[v*2]+sum[v*2+1];
        mx[v]=max(mx[v*2], mx[v*2+1]);
    }
}
 
int getmx(int l, int r, int v=1, int tl=0, int tr=n-1) {
    if(l>r) return INT_MIN;
    if(l==tl&&r==tr) return mx[v];
    else {
        int tm=(tl+tr)/2;
        return max(getmx(l, min(r, tm), v*2, tl, tm), getmx(max(tm+1, l), r, v*2+1, tm+1, tr));
    }
}
 
void upd(int l, int r, int v=1, int tl=0, int tr=n-1) {
    if(l>r) return;
    if(getmx(l, r)<=2) return;
    if(tl==tr) {
        sum[v]=mx[v]=div(sum[v]);
    }
    else {
        int tm=(tl+tr)/2;
        upd(l, min(r, tm), v*2, tl, tm);
        upd(max(tm+1, l), r, v*2+1, tm+1, tr);
        sum[v]=sum[v*2]+sum[v*2+1];
        mx[v]=max(mx[v*2], mx[v*2+1]);
    }
}
 
ll get(int l, int r, int v=1, int tl=0, int tr=n-1) {
    if(l>r) return 0;
    if(l==tl&&r==tr) return sum[v];
    else {
        int tm=(tl+tr)/2;
        return get(l, min(r, tm), v*2, tl, tm)+get(max(tm+1, l), r, v*2+1, tm+1, tr);
    }
}
 
int32_t main() {
    fastio;
    int q; cin>>n>>q;
    int a[n]; rep(i, n) cin>>a[i];
    build(a);
    while(q--) {
        int t; cin>>t;
        if(t==1) {
            int l, r; cin>>l>>r; upd(--l, --r);
        }
        else {
            int l, r; cin>>l>>r; cout<<get(--l, --r)<<endl;
        }
    }
}