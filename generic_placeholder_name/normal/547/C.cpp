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

constexpr int N=5e5+1;
int u[N], cnt[N], a[N];
vi d[N];
bool cur[N];

int32_t main() {
    fastio;
    rep1(i, N-1) {
        for(int j=i; j<N; j+=i) d[j].pb(i);
        if(i==1) u[i]=1;
        else if((i/d[i][1])%d[i][1]==0) u[i]=0;
        else u[i]=-u[i/d[i][1]];
    }
    ll ans=0;
    auto query = [&](int idx) -> void {
        if(cur[idx]) for(int x: d[a[idx]]) cnt[x]--, ans-=u[x]*cnt[x];
        else for(int x: d[a[idx]]) ans+=u[x]*cnt[x], cnt[x]++;
        cur[idx]^=1;
    };
    int n, q; cin>>n>>q;
    rep(i, n) cin>>a[i];
    rep(i, q) {int x; cin>>x; query(--x); cout<<ans<<endl;}
}