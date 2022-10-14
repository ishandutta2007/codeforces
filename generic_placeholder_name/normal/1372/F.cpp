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

//was quite surprised to see that the segtree construction idea works
//probably is obvious in retrospect as segtrees doesn't have more than 4*n vertices

constexpr int N=2.5e5+100;
vi a(N, -1);

pii ask(int l, int r) {
    cout<<"? "<<l<<' '<<r<<endl;
    pii resp; cin>>resp.fi>>resp.se;
    return resp;
}

void solve(int l, int r) {
    if(l>r) return;
    int x, f;
    tie(x, f)=ask(l, r);
    int l1=r+1-f, r1=l-1+f;
    if(l1<=r1) {
        for(int i=l1; i<=r1; i++) a[i]=x;
        solve(l, l1-1);
        solve(r1+1, r);
    }
    else {
        int m=(l+r)/2;
        solve(l, m);
        solve(m+1, r);
    }
}

int32_t main() {
    int n; cin>>n;
    solve(1, n);
    cout<<"! "; rep1(i, n) cout<<a[i]<<' '; cout<<endl;
}