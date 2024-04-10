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
 
//Lucy Hedgehog Sieve template
//Written by me and thenymphsofdelphi
 
constexpr int UB=2e6+1;
struct accesser {
    ll a[UB+1];
    gp_hash_table<ll, ll> large; //roughly uniform anyway
    accesser() {memset(a, 0, sizeof(a)); large.clear();}
    inline ll get(const ll& n) {if(n<=UB) return a[n]; else return large[n];}
    inline void set(const ll& n, const ll x) {if(n<=UB) a[n]=x; else large[n]=x;}
    inline void add(const ll& n, const ll& x) {
        if(n<=UB) a[n]=a[n]+x;
        else large[n]=large[n]+x;
    }
};
 
constexpr int MAXR=1.5e8+1;
bitset<MAXR+1> isprime;
int Sum[MAXR+1];
void init() {
    for(int i=2; i<=MAXR; i++) isprime[i]=1;
    isprime[0]=isprime[1]=0;
    for(int p=2; p*p<=MAXR; p++) if(isprime[p]) {
        for(int i=p*p; i<=MAXR; i+=p) isprime[i]=0;
    }
    for(int i=1; i<=MAXR; i++) Sum[i]=Sum[i-1]+isprime[i];
}
 
accesser S;
ll cnt(ll n) {
    if(n<=MAXR) return Sum[n];
    int r=sqrt(n);
    vector<ll> V; V.reserve(2*r);
    rep1(i, r) V.pb(n/i);
    for(int i=V.back()-1; i>0; i--) V.push_back(i);
    rep(i, V.size())  {
        S.set(V[i], V[i]-1);
    }
    for(int p=2; p<=r; p++) {
        if (isprime[p]) {
            rep(i, V.size()) {
                const ll v=V[i];
                if(v<1ll*p*p) break;
                S.add(v, S.get(p-1)-S.get(v/p));
            }
        }
    }
    return S.get(n);
}
 
int32_t main() {
    //resub to note a couple things
    //1. complexity is O(n^(7/8) log log n ^ (1/2))
    //  achieved with k = n^(7/8) / log log n ^ (1/2).
    //2. i am dumb and good sol is way simpler
    //3. also doing this kind of bullshit is really fun
    //kek
    fastio;
    init();
    ll n; cin>>n;
    ll ans=0;
    rep(i, 5e3) if(isprime[i]&&1LL*i*i*i<=n) ans++;
    for(int i=2; 1LL*i*i<n; i++) {
        if(isprime[i]) {
            ans+=cnt(n/i)-cnt(i);
            //cout<<i<<' '<<n/i<<' '<<cnt(i)<<' '<<cnt(n/i)<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}