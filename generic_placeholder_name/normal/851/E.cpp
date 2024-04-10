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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

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


namespace Factor {
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

        void gen(vll factors, vi exponents, vll& ans, int l, int r){ //helper function for generating factors set from factorization
            if(l==r) {
                ll tmp=1;
                rep(i, exponents[l]+1) {
                    ans.pb(tmp);
                    tmp*=factors[l];
                }
                return;
            }
            gen(factors, exponents, ans, l+1, r);
            ll tmp=factors[l];
            int sz=ans.size();
            rep1(i, exponents[l]) {
                rep(j, sz) {
                    ans.pb(ans[j]*tmp);
                }
                tmp*=factors[l];
            }
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

    vi _factorize(int n) {
        if(n==1) return vi();
        if(n<1e9) {
            vi m;
            for(int p=2; p*p*p<=n; p++) if(n%p==0) {
                while(n%p==0) {
                    n/=p; m.pb(p);
                }
            }
            if(n==1) {}
            else if(is_prime(n)) m.pb(n);
            else {
                int x=pollard(n);
                m.pb(x); m.pb(n/x);
            }
            return m;
        }
        else {
            vi m;
            if(!is_prime(n)) {
                int x=pollard(n);
                vi aux1=_factorize(x), aux2=_factorize(n/x);
                for(int it: aux1) m.pb(it);
                for(int it: aux2) m.pb(it);
            }
            else m.pb(n);
            return m;
        }
    }

    gp_hash_table<int, int, custom_hash> factorize(int n) {
        gp_hash_table<int, int, custom_hash> f;
        vi aux=_factorize(n);
        for(int it: aux) f[it]++;
        return f;
    }
}

gp_hash_table<int, int> m;
int grundy(int msk) {
	if (!msk) return 0;
	if (m.find(msk)!=m.end()) return m[msk];
	unordered_set<int> s;
	for (int i=0; msk>>i; i++) s.insert(grundy(msk>>i+1|(msk&(1<<i)-1)));
	int mex=0;
	while (s.count(mex)) mex++;
	return m[msk]=mex;
}

int32_t main() {
    fastio;
    int n; cin>>n;
    gp_hash_table<int, int, custom_hash> fac;
    rep(i, n) {
        int x; cin>>x; gp_hash_table<int, int, custom_hash> f=Factor::factorize(x);
        for(auto& it: f) fac[it.fi]|=(1<<it.se-1);
    }
    int ans=0; for(auto& it: fac) ans^=grundy(it.se);
    cout<<(ans?"Mojtaba\n":"Arpa\n");
}