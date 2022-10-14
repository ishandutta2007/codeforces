#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
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

ll multmod(ll a, ll b, ll p) {
    a%=p, b%=p;
    if(a<1e18/b) return (a*b)%p;
    else {
        ll res=0;
        while(b) {
            if(b&1) res=(res+a)%p;
            (a*=2)%=p;
            b>>=1;
        }
        return res;
    }
}

ll exp(ll x, ll y, ll p) {
    if(!y) return 1;
    else {
        ll r=exp(x, y/2, p);
        if(y%2==0) return multmod(r, r, p);
        else return multmod(multmod(r, r, p), x, p);
    }
}

namespace Factor { //black box to put in problems to save time
    namespace { //helper functions
        const int MAX_SIEVE_VALUE=1000000;
        bool isprime[MAX_SIEVE_VALUE+1];
        bool _init=0;
        void init() { //sieve for small primes
            _init=1;
            int n=MAX_SIEVE_VALUE;
            memset(isprime, true, sizeof(isprime));
            isprime[0]=isprime[1]=0;
            for(ll p=2; p*p<=n; p++) if(isprime[p]) {
                for(ll i=p*p; i<=n; i+=p) isprime[i]=0;
            }
        }

        bool test(ll n, ll a, ll d, int s) { //miller-rabin test
            ll x=exp(a, d, n);
            if(x==1||x==n-1) return 0;
            rep(_, s-1) {
                x=exp(x, 2, n);
                if (x==n-1) return 0;
            }
            return 1;
        }

        bool miller_rabin(ll n) { //miller-rabin, deterministic up until long long
            if (n<2) return 0;
            int r=0;
            ll d=n-1;
            while((d&1)==0) d>>=1, r++;
            for(int a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
                if (n==a) return 1;
                if (test(n, a, d, r)) return 0;
            }
            return 1;
        }
    }

    bool is_prime(ll n) {
        if(!_init) init();
        if(n<=MAX_SIEVE_VALUE) return isprime[n];
        else return miller_rabin(n);
    }

    ll pollard(ll n) { //get random divisor
        if (n==1) return n;
        if (n%2==0) return 2;
        mt19937::result_type seed=chrono::steady_clock::now().time_since_epoch().count();
        auto rng=bind(uniform_int_distribution<ll>(2, n-1), mt19937(seed));
        ll x=rng(), y=x;
        auto rng2=bind(uniform_int_distribution<ll>(1, n-1), mt19937(seed));
        ll c=rng2(), d=1;
        while (d==1) {
            x=(exp(x, 2, n)+c+n)%n;
            y=(exp(y, 2, n)+c+n)%n;
            y=(exp(y, 2, n)+c+n)%n;
            d=gcd(abs(x-y), n);
            if (d==n) return pollard(n);
        }
        return d;
    }

    gp_hash_table<int, int> factorize(int n) { //get factorization in the form of (prime, exponent)
        if(n==1) return gp_hash_table<int, int>();
        gp_hash_table<int, int> m;
        for(int p=2; p*p*p<=n; p++) if(n%p==0) {
            while(n%p==0) {
                n/=p; m[p]++;
            }
        }
        if(n==1) {}
        else if(is_prime(n)) m[n]++;
        else {
            ll x=pollard(n);
            m[x]++; m[n/x]++;
        }
        return m;
    }
}

const ll MOD=1e9+7;
int32_t main() {
    fastio;
    auto start = chrono::steady_clock::now();
    int n; cin>>n; ll a[n]; rep(i, n) cin>>a[i];
    unordered_set<int> primes;
    gp_hash_table<int, vi> m;
    rep(i, n) {
        gp_hash_table<int, int> _m=Factor::factorize(a[i]);
        for(auto& it: _m) m[it.fi].pb(it.se);
    }
    ll ans=0;
    int fact[n+1]; fact[0]=1; rep1(i, n) fact[i]=multmod(fact[i-1], i, MOD);
    int nCr[n+1]; nCr[0]=1; rep1(i, n) nCr[i]=multmod(multmod(fact[n], exp(fact[i], MOD-2, MOD), MOD), exp(fact[n-i], MOD-2, MOD), MOD);
    int pf[n+1]; pf[0]=0; rep1(i, n) pf[i]=(0LL+pf[i-1]+nCr[i])%MOD;
    int pw=exp(2, n-1, MOD);
    int mult[n]; rep(i, n) mult[i]=(1LL+pf[i]+MOD-pw)%MOD;
    for(auto& it: m) {
        vi b=it.se;
        int cnt[20]={0};
        for(int it: b) cnt[it]++;
        int cur=0;
        rep(i, 20) rep(j, cnt[i]) b[cur++]=i;
        rep(i, b.size()) ans+=(1LL*mult[n-b.size()+i]*b[i])%MOD;
        ans=((ans%MOD)+MOD)%MOD;
    }
    cout<<ans<<endl;
}