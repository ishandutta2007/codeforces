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

constexpr int MOD=998244353;

struct custom_hashes {
    inline static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    template<typename T> //should take care of all types that can turn into integers
    size_t operator()(T x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64((uint64_t)x + FIXED_RANDOM);
    }
};

template<typename _F, typename _T> using safe_map=gp_hash_table<_F, _T, custom_hashes>;

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

int fact[64];
int inv[64];
void precalc_fact() {
    fact[0]=1; rep1(i, 63) fact[i]=(1LL*fact[i-1]*i)%MOD;
    inv[0]=1; rep1(i, 63) inv[i]=exp(fact[i], MOD-2, MOD);
}

namespace Factor {
    namespace { //helper functions
        const int MAX_SIEVE_VALUE=1000000;
        bool isprime[MAX_SIEVE_VALUE+1];
        int f[MAX_SIEVE_VALUE+1];
        bool _init=0;
        inline void init() { //sieve for small primes
            _init=1;
            int n=MAX_SIEVE_VALUE;
            memset(f, 0, sizeof(f));
            memset(isprime, true, sizeof(isprime));
            isprime[0]=isprime[1]=0;
            for(ll p=2; p*p<=n; p++) if(isprime[p]) {
                for(ll i=p*p; i<=n; i+=p) {
                    isprime[i]=0;
                    if(!f[i]) f[i]=p;
                }
            }
            rep1(i, n) if(!f[i]) f[i]=i;
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

        long long brent(long long n, long long x0=2, long long c=1) {
            long long x = x0;
            long long g = 1;
            long long q = 1;
            long long xs, y;

            int m = 128;
            int l = 1;
            while (g == 1) {
                y = x;
                for (int i = 1; i < l; i++)
                    x = (exp(x, 2, n) + c) % n;
                int k = 0;
                while (k < l && g == 1) {
                    xs = x;
                    for (int i = 0; i < m && i < l - k; i++) {
                        x = (exp(x, 2, n) + c) % n;
                        q = multmod(q, abs(y - x), n);
                    }
                    g = gcd(q, n);
                    k += m;
                }
                l *= 2;
            }
            if (g == n) {
                do {
                    xs = (exp(xs, 2, n) + c) % n;
                    g = gcd(abs(xs - y), n);
                } while (g == 1);
            }
            return g;
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
        ll ans=brent(n);
        while(ans==n||ans==1) {
            mt19937::result_type seed=chrono::steady_clock::now().time_since_epoch().count();
            auto rng=bind(uniform_int_distribution<ll>(2, n-1), mt19937(seed));
            ll x=rng();
            auto rng2=bind(uniform_int_distribution<ll>(1, n-1), mt19937(seed));
            ll c=rng2();
            ans=brent(n, x, c);
        }
        return ans;
    }

    safe_map<ll, int> factorize(ll n) { //get factorization in the form of (prime, exponent)
        if(n==1) return safe_map<ll, int>();
        else if(is_prime(n)) {safe_map<ll, int> m; m[n]=1; return m;}
        if(n<=MAX_SIEVE_VALUE) {
            safe_map<ll, int> m;
            while(n!=1) m[f[n]]++, n/=f[n];
            return m;
        }
        else {
            ll x=pollard(n);
            safe_map<ll, int> aux=factorize(x);
            safe_map<ll, int> m=factorize(n/x);
            if(m.size()<aux.size()) swap(m, aux);
            for(auto it: aux) m[it.fi]+=it.se;
            return m;
        }
    }
}

safe_map<ll, int> ans;
ll get(ll x) {
    if(ans.find(x)!=ans.end()) return ans[x];
    safe_map<ll, int> f=Factor::factorize(x);
    int sum=0; ll res=1;
    for(const auto& it: f) sum+=it.se, res=(res*inv[it.se])%MOD;
    res=(res*fact[sum])%MOD;
    return ans[x]=res;
}

int32_t main() {
    fastio;
    precalc_fact();
    ll d; cin>>d;
    int q; cin>>q; while(q--) {
        ll x, y; cin>>x>>y; cout<<(get(x/gcd(x, y))*get(y/gcd(x, y)))%MOD<<endl;
    }
}