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

constexpr int N=1e5+1;
int a[N], vis[N];
int n;
inline int sc(int x) {
    memset(vis, 0, sizeof(vis));
    int cur=1, cnt=0;
    rep(i, n) {
        if(vis[a[i]]==cur) continue;
        if(cnt>x) cnt=0, cur++;
        vis[a[i]]=cur, cnt++;
    }
    return cur;
}

constexpr int sz=1000;
constexpr int rsz=100;
int32_t main() {
    fastio;
    cin>>n; rep(i, n) cin>>a[i];
    vi ans(n, INT_MAX);
    rep(i, min(sz, n)) ans[i]=sc(i);
    for(int i=rsz; i>0; i--) {
        int l=0, r=n-1;
        while(l<r) {
            int m=(l+r+1)/2;
            if(sc(m)>i) l=m;
            else r=m-1;
        } ++l;
        if(l<n) ans[l]=min(ans[l], i);
    }
    rep1(i, n-1) ans[i]=min(ans[i], ans[i-1]);
    rep(i, n) cout<<ans[i]<<' '; cout<<endl;
}