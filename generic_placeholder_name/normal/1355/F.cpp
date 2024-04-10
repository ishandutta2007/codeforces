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

namespace Factor {
    namespace {
        const int MAX_SIEVE_VALUE=1000000;
        bool isprime[MAX_SIEVE_VALUE+1];
        bool _init=0;
        void init() {
            _init=1;
            int n=MAX_SIEVE_VALUE;
            memset(isprime, true, sizeof(isprime));
            isprime[0]=isprime[1]=0;
            for(ll p=2; p*p<=n; p++) if(isprime[p]) {
                for(ll i=p*p; i<=n; i+=p) isprime[i]=0;
            }
        }

        bool test(ll n, ll a, ll d, int s) {
            ll x=exp(a, d, n);
            if(x==1||x==n-1) return 0;
            rep(_, s-1) {
                x=exp(x, 2, n);
                if (x==n-1) return 0;
            }
            return 1;
        }

        bool miller_rabin(ll n) {
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

    ll pollard(ll n) {
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

    map<ll, int> factorize(ll n) {
        if(n==1) return map<ll, int>();
        map<ll, int> m;
        while(!is_prime(n)) {
            ll x=pollard(n);
            map<ll, int> aux=factorize(x);
            for(auto it: aux) m[it.fi]+=it.se;
            n/=x;
        }
        m[n]++; return m;
    }

    void gen(vll factors, vi exponents, vll& ans, int l, int r){
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

    vll get_factors(ll n) {
        assert(n>1);
        map<ll, int> m=factorize(n);
        vll f; vi d; for(auto it: m) f.pb(it.fi), d.pb(it.se);
        vll ans; gen(f, d, ans, 0, f.size()-1);
        return ans;
    }

    vll get_prime_factors(ll n) {
        assert(n>1);
        map<ll, int> m=factorize(n);
        vll f; for(auto it: m) f.pb(it.fi);
        return f;
    }

    ll get_prime_factor(ll n) {
        assert(n>1);
        while(!is_prime(n)) n=pollard(n);
        return n;
    }
}

namespace Queries {
    vll a, l;
    namespace {
        bool _init=0;
        void init() {
            _init=1;
            vll primes; rep1(i, 1001) if(Factor::is_prime(i)) primes.pb(i); primes.pb(LLONG_MAX);
            vector<pll> queries; ll curr=1;
            for(ll prime: primes) {
                if(curr>1e18/prime) {
                    if(prime==LLONG_MAX) prime=1009;
                    queries.pb({curr, prime});
                    curr=1;
                }
                curr*=prime;
            }
            for(auto query: queries) a.pb(query.fi), l.pb(query.se);
        }
    }
    struct QueryHandler {
        QueryHandler() {if(!_init) init();}
        map<ll, int> f;
        set<int> rem;
        ll c=1, r=1;
        void ask(ll x, bool ins=0) {
            cout<<"? "<<x<<endl;
            ll res; cin>>res;
            if(ins) c*=res;
            map<ll, int> aux=Factor::factorize(res);
            for(auto it: aux) {
                f[it.fi]=it.se;
                if(ins) r*=it.se+1;
                if(!ins) rem.insert(it.fi);
            }
        }
        void answer(ll x) {
            cout<<"! "<<x<<endl;
            return;
        }
        void query(ll x, ll y=-1) {
            ll ax=x, ay=y;
            while(ax*x<1e9) ax*=x;
            if(y!=-1) while(ay*y<1e9) ay*=y;
            ask(y==-1?ax:ax*ay, 1);
        }
        void discharge() {
        }
        void process() {
            rep(i, a.size()) {
                ask(a[i]);
                while(rem.size()>=2) {
                    ll x=*rem.begin(); rem.erase(rem.find(x));
                    ll y=*rem.begin(); rem.erase(rem.find(y));
                    //cout<<"querying 2 primes "<<x<<' '<<y<<endl;
                    query(x, y);
                    //cout<<"remaining primes size "<<rem.size()<<", primes=";
                    //for(auto it: rem) cout<<it<<' '; cout<<endl;
                }
                if(l[i]>177&&f.size()<=1) {
                    if(f.size()==0) {
                        //cout<<"answer case 1"<<endl;
                        answer(8); return;
                    }
                    else if(!rem.empty()) {
                        ll x=*rem.begin(); rem.erase(rem.find(x));
                        //cout<<"querying 1 prime "<<x<<endl;
                        query(x);
                    }
                }
                if(Factor::is_prime(c)&&c*l[i]*l[i]*l[i]*l[i]>1e9) {
                    if(!rem.empty()) {
                        ll x=*rem.begin(); rem.erase(rem.find(x));
                        //cout<<"querying 1 prime "<<x<<endl;
                        query(x);
                    }
                    //cout<<"answer case 2"<<endl;
                    answer(8); return;
                }
                if(c*l[i]*l[i]*l[i]>1e9) {
                    if(!rem.empty()) {
                        ll x=*rem.begin(); rem.erase(rem.find(x));
                        //cout<<"querying 1 prime "<<x<<endl;
                        query(x);
                    }
                    //cout<<"answer case 3"<<endl;
                    answer(r*2); return;
                }
            }
        }
    };
}

int32_t main() {
    int q; cin>>q; while(q--) {
        Queries::QueryHandler a;
        a.process();
    }
    return 0;
}