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

namespace Factor {
    namespace { //helper functions
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

    unordered_set<ll> factorize(ll n) { //get all prime factors
        if(n==1) return unordered_set<ll>{};
        if(is_prime(n)) return unordered_set<ll>({n});
        if(n<1e9) {
            unordered_set<ll> m;
            for(int p=2; p*p*p<=n; p++) if(n%p==0) {
                m.insert(p);
                while(n%p==0) n/=p;
            }
            if(n==1) {}
            else if(is_prime(n)) m.insert(n);
            else {
                ll x=pollard(n);
                m.insert(x); m.insert(n/x);
            }
            return m;
        }
        else {
            unordered_set<ll> m;
            ll x=pollard(n);
            unordered_set<ll> aux1=factorize(x), aux2=factorize(n/x);
            for(ll x: aux1) m.insert(x); for(ll x: aux2) m.insert(x);
            return m;
        }
    }

    ll get_prime_factor(ll n) { //get a random prime factor
        if(n==1) return 2;
        if(!_init) init();
        while(!is_prime(n)) n/=pollard(n);
        return n;
    }
}

struct Tester {
    vll a;
    Tester(vll a): a(a) {}
    inline ll get() {
        int idx=rng()%a.size();
        mt19937::result_type seed=chrono::steady_clock::now().time_since_epoch().count();
        auto gen=bind(uniform_int_distribution<ll>(a[idx]-1, a[idx]+1), mt19937(seed));
        ll res=0; while(res==0) res=gen();
        ll x=Factor::get_prime_factor(res);
        return x;
    }
    inline int test(const ll& pr) {
        int res=0;
        for(ll x: a) {
            if(x<=pr) {
                if(pr-x>a.size()) return INT_MAX;
                res+=pr-x;
            }
            else {
                if(min(x%pr, pr-(x%pr))>a.size()) return INT_MAX;
                res+=min(x%pr, pr-(x%pr));
            }
            if(res>a.size()) return INT_MAX;
        }
        return res;
    }
    inline int calc() {
        int ans=INT_MAX;
        unordered_set<ll> pr{2, 3, 5, 7};
        rep(i, 30) { //about 7 primes or so each
            ll elem=a[rng()%a.size()];
            ll res=0; while(res==0) res=elem+rng()%3-1;
            unordered_set<ll> f=Factor::factorize(res);
            for(ll it: f) pr.insert(it);
        }
        rep(i, 75) pr.insert(get()); //get some more for good measure
        for(const ll& it: pr) ans=min(ans, test(it));
        return ans;
    }
};

int32_t main() {
    fastio;
    int n; cin>>n; vll a(n); rep(i, n) cin>>a[i];
    cout<<Tester(a).calc()<<endl;
}