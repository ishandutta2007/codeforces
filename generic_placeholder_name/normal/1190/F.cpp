#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,tune=native")

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

namespace Factor {
    namespace { //helper functions
        const int MAX_SIEVE_VALUE=1000000;
        bool isprime[MAX_SIEVE_VALUE+1];
        bool _init=0;
        inline void init() { //sieve for small primes
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

    map<ll, int> factorize(ll n) { //get factorization in the form of (prime, exponent)
        assert(n>1);
        if(n<1e9) {
            map<ll, int> m;
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
        else {
            map<ll, int> m;
            while(!is_prime(n)) {
                ll x=pollard(n);
                map<ll, int> aux=factorize(x);
                if(m.size()<aux.size()) swap(m, aux);
                for(auto it: aux) m[it.fi]+=it.se;
                n/=x;
            }
            m[n]++; return m;
        }
    }

    vll get_factors(ll n) { //get a vector of all factors
        assert(n>1);
        map<ll, int> m=factorize(n);
        vll f; vi d; for(auto it: m) f.pb(it.fi), d.pb(it.se);
        vll ans; gen(f, d, ans, 0, f.size()-1);
        return ans;
    }

    vll get_prime_factors(ll n) { //get a vector of all prime factors
        assert(n>1);
        map<ll, int> m=factorize(n);
        vll f; for(auto it: m) f.pb(it.fi);
        return f;
    }

    ll get_prime_factor(ll n) { //get a random prime factor
        assert(n>1);
        if(!_init) init();
        while(!is_prime(n)) n=pollard(n);
        return n;
    }
}

///resub to test if the revised template is any better
///commented code if I need to understand this later
int32_t main() {
    fastio;
    ll n, m, p; cin>>n>>m>>p;
    ll pr=Factor::get_prime_factor(m), phi=m/pr*(pr-1);
    if(p==1||p%pr==0) {
        ///trivial cases, we randomize to get answers
        gp_hash_table<ll, bool> excl;
        excl[0]=1;
        if(phi<=n) cout<<-1<<endl;
        else {
            rep(_, n) {
                ll x=rng()%m; while(x==1||x%pr==0||excl.find(x)!=excl.end()) x=rng()%m;
                excl[x]=1, cout<<x<<' ';
            }
            cout<<endl;
        }
    }
    else {
        vll f=Factor::get_factors(phi);
        ll mn; for(ll it: f) if(exp(p, it, m)==1) {mn=it; break;}
        if(phi-mn<n) cout<<-1<<endl;
        else {
            ll g;
            if(m%8==0) g=5;
            else if(m==2) g=1;
            else {
                vll _f=Factor::get_prime_factors(phi);
                bool ok=0;
                while(ok==0) {
                    g=rng()%(m-2)+2;
                    ok=g!=p&&gcd(g, m)==1;
                    for(ll it: _f) ok&=(exp(g, phi/it, m)!=1);
                }
            }
            ///get a primitive root for later use
            if(m%8==0) {
                ///p%4==0 is already subsumed by above cases
                if(p%4==1) {
                    /**
                    we observe some math things to solve this case
                    relatively simple
                    **/
                    int cnt=0, root=1, add=2;
                    while(cnt<n) {
                        root=add+1; add*=2;
                        assert(p%add!=root);
                        for(int i=root; i<=m&&cnt<n; i+=add, cnt++) cout<<i<<' ';
                    }
                    cout<<endl;
                }
                else {
                    if(m<=4.5*n) {
                        /**
                        this algorithm sequentially searches from 1 to m for n satisfactory integers.
                        this should be O(n) visits, but that's assuming values are about 1/2
                        which is not true for every testcase.
                        however, we can limit the upper bound of using this algorithm
                        **/
                        for(int curr=3, cnt=0; curr<m&&cnt<n; curr+=2) {
                            if(exp(curr, mn, m)!=1) goto print;
                            if(mn%2==0&&exp(curr, mn/2, m)==1) {if(curr%8!=1) goto print;}
                            else if(curr%8!=p%8) goto print;
                            continue;
                            print: cout<<curr<<" "; cnt++;
                        }
                    }
                    else {
                        /**
                        this algorithm returns all satisfactory integers of form 8n+5 and 8n+7.
                        This is >1/4 of all satisfactory integers.
                        However, with m high enough, we can use this algorithm.
                        **/
                        ll psq=multmod(p, p, m), gsq=multmod(g, g, m);
                        ll x=g, y=gsq;
                        gp_hash_table<ll, bool> excl;
                        int cnt=0;
                        while(cnt<n) {
                            while(excl.find(x)!=excl.end()) x=multmod(x, gsq, m);
                            while(excl.find(m-y)!=excl.end()) y=multmod(y, gsq, m);
                            excl[x]=1; cout<<x<<' '; cnt++;
                            if(cnt<n) {excl[m-y]=1; cout<<m-y<<' '; cnt++;}
                            x=multmod(x, psq, m);
                            y=multmod(y, psq, m);
                        }
                    }
                    cout<<endl;
                }
            }
            else {
                /***
                this is where i explain what the primitive root thing is about
                so we have a primitive root g, and p=g^k.
                We see that g^(kx)=g^y has a solution if kx=y(mod phi).
                this leads to the fact that there is a solution for every gcd(k, phi) numbers.
                This means that k>=2, so g^1!=k.
                Therefore, we can search for gk, gk^2, ..., g^2k, g^2k^2, ... until done.
                In the above case, there are no guarantees that g^1!=k, so I had to do some cheaty stuff.
                ***/
                ll x=g;
                gp_hash_table<ll, bool> excl;
                rep(_, n) {
                    while(excl.find(x)!=excl.end()) x=multmod(x, g, m);
                    excl[x]=1;
                    cout<<x<<' '; x=multmod(x, p, m);
                }
                cout<<endl;
            }
        }
    }
}