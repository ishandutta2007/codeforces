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

constexpr int MAXN=1e6+2;
bitset<MAXN+1> isprime;
inline void init() {
    constexpr int n=MAXN;
    rep(i, n+1) isprime[i]=true;
    isprime[0]=isprime[1]=0;
    for(ll p=2; p*p<=n; p++) if(isprime[p]) {
        for(ll i=p*p; i<=n; i+=p) isprime[i]=0;
    }
}

ll pf[MAXN*2];
int _cnt[MAXN*2];
int occ[MAXN*2];
inline void upd(int x) {occ[x]++;}
inline void calc() {
    pf[0]=0, _cnt[0]=occ[0];
    for(int i=1; i<MAXN*2; i++) {
        pf[i]=pf[i-1]+ll(i)*occ[i];
        _cnt[i]=_cnt[i-1]+occ[i];
    }
}
inline int cnt(int x, int y) {return _cnt[y]-_cnt[x-1];}
inline ll get(int x, int y) {return pf[y]-pf[x-1];}

int32_t main() {
    fastio;
    int n, x, y; cin>>n>>x>>y;
    while(n--) {int x; cin>>x; upd(x);}
    init(); calc();
    ll ans=1e18;
    for(int i=2; i<=MAXN; i++) if(isprime[i]) {
        ll tmp=0;
        for(int j=0; j<=MAXN; j+=i) {
            int k=j+i, l=max(1LL*j, (1LL*k*y-x)/y);
            tmp+=ll(cnt(j+1, l))*x+(1LL*k*cnt(l+1, k)-get(l+1, k))*y;
        }
        ans=min(ans, tmp);
    }
    cout<<ans<<endl;
}