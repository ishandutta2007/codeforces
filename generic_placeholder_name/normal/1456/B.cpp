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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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

int32_t main() {
    fastio;
    int n; cin>>n;
    int a[n];
    rep(i, n) {
        cin>>a[i];
        if(i>=2&&a[i-2]>0&&__lg(a[i])==__lg(a[i-2])) return puts("1"), 0;
    }
    int ans=INT_MAX;
    for(int r=1; r<n; r++) for(int l=0; l<r; l++) {
        int x=0;
        for(int i=l; i<=r; i++) x^=a[i];
        if(l>0&&a[l-1]>x) ans=min(ans, r-l);
        if(r<n-1&&x>a[r+1]) ans=min(ans, r-l);
    }
    for(int m=1; m<n-1; m++) for(int l=0; l<m; l++) for(int r=m+1; r<n; r++) {
        int x=0, y=0;
        for(int i=l; i<=m; i++) x^=a[i];
        for(int i=m+1; i<=r; i++) y^=a[i];
        if(x>y) ans=min(ans, r-l-1);
    }
    if(ans==INT_MAX) ans=-1;
    cout<<ans<<endl;
}