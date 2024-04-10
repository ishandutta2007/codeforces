#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
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
constexpr int INF=5e8;
int n;
int a[N], b[N];
vi idx[N];
int t[4*N+4];

int get(int ql, int qr, int v=1, int l=0, int r=n-1) {
    if(ql>r||qr<l) return INF;
    if(ql<=l&&qr>=r) return t[v];
    else {
        int m=(l+r)/2;
        return min(get(ql, qr, v*2, l, m), get(ql, qr, v*2+1, m+1, r));
    }
}

void upd(int pos, int val, int v=1, int l=0, int r=n-1) {
    if(l==r) t[v]=val;
    else {
        int m=(l+r)/2;
        if(pos<=m) upd(pos, val, v*2, l, m);
        else upd(pos, val, v*2+1, m+1, r);
        t[v]=min(t[v*2], t[v*2+1]);
    }
}

void solve() {
    cin>>n;
    rep(i, n) idx[i].clear();
    rep(i, n) cin>>a[i], idx[--a[i]].pb(i);
    rep(i, n) cin>>b[i], --b[i];
    rep(i, n) idx[i].pb(INF), reverse(all(idx[i])), upd(i, idx[i].back());
    rep(i, n) {
        if(idx[b[i]].back()==INF) {cout<<"NO\n"; return;}
        else if(get(0, b[i]-1)<idx[b[i]].back()) {cout<<"NO\n"; return;}
        else {
            idx[b[i]].pop_back();
            upd(b[i], idx[b[i]].back());
        }
    }
    cout<<"YES\n";
}

int32_t main() {
    fastio;
    int q; cin>>q; while(q--) {
        solve();
    }
}