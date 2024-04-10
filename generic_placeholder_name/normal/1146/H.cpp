#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma,popcnt")

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

pii sub(const pii& a, const pii& b) {return mp(a.fi-b.fi, a.se-b.se);}
ll mul(const pii& a, const pii& b) {return a.fi*1LL*b.se-a.se*1LL*b.fi;}
ll ccw(const pii& o, const pii& u, const pii& v) {return mul(sub(u, o), sub(v, o));}

constexpr int N=303;
bitset<N> f[N][N];
pii a[N];

int32_t main() {
    fastio;
    int n; cin>>n; rep(i, n) cin>>a[i].fi>>a[i].se;
    rep(i, n) rep(j, n) rep(k, n) f[i][j][k]=(ccw(a[i], a[j], a[k])>0);
    ll ans=(n*1LL*(n-1)*(n-2)*(n-3)*(n-4))/120;
    ll sub=0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=i+1; k<n; k++) if(f[i][j][k]) {
                int cnt=(f[i][j]&f[j][k]&f[k][i]).count();
                sub+=cnt*(n-4);
                ans+=cnt*(cnt-1)/2;
            }
        }
    }
    ans-=sub/2;
    cout<<ans<<endl;
}