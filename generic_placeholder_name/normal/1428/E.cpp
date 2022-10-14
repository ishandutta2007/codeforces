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
template<typename _def> using ordered_set=tree<_def, null_type, greater<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr ll INF=1e15;
ll f(int n, int k) {
    if(n<k) return INF;
    int x=n/k, y=n/k+1;
    int sy=n%k, sx=k-sy;
    return sx*1LL*x*x+sy*1LL*y*y;
}

int32_t main() {
    fastio;
    int n, k; cin>>n>>k;
    int a[n]; rep(i, n) cin>>a[i];
    int sz[n]; rep(i, n) sz[i]=1;
    typedef pair<ll, int> pli;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    ll ans=0;
    rep(i, n) {
        ans+=a[i]*1LL*a[i];
        pq.emplace(f(a[i], sz[i]+1)-f(a[i], sz[i]), i);
    }
    rep(_i, k-n) {
        ll df=pq.top().fi; int i=pq.top().se;
        pq.pop();
        ans+=df;
        sz[i]++;
        pq.emplace(f(a[i], sz[i]+1)-f(a[i], sz[i]), i);
    }
    cout<<ans<<endl;
}