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

constexpr int N=200001;
int a[N+1]; ll pf[N+1];
int n;

inline ld solve(int idx, int len) {
    return ld(pf[n]-pf[n-len]+pf[idx]-pf[idx-len-1])/(2*len+1)-a[idx];
}

int32_t main() {
    fastio;
    cin>>n; rep1(i, n) cin>>a[i];
    sort(a+1, a+n+1);
    rep1(i, n) pf[i]=pf[i-1]+a[i];
    ld ans=-1, idx=0, len=0;
    rep1(i, n) {
        int l=0, r=min(i-1, n-i);
        while(l<=r-3) {
            int m1=(l+l+r)/3;
            int m2=(l+r+r)/3;
            if(solve(i, m1)>solve(i, m2)) r=m2;
            else l=m1;
        }
        for(int k=l; k<=r; k++) if(ans<solve(i, k)) ans=solve(i, k), idx=i, len=k;
    }
    cout<<len*2+1<<endl;
    for(int i=idx-len; i<=idx; i++) cout<<a[i]<<' ';
    for(int i=n-len+1; i<=n; i++) cout<<a[i]<<' ';
    cout<<endl; return 0;
}