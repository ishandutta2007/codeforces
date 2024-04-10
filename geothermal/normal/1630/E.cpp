#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


const int MOD = 998244353;
const char nl = '\n';
const int MX = 2000001; 


struct mi {
	ll v; explicit operator ll() const { return v; }
	mi() { v = 0; }
	mi(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.v < b.v; }
   
	mi& operator+=(const mi& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mi& operator*=(const mi& m) { 
		v = v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
    mi operator++(int) { v++; if (v == MOD) v = 0; return mi(v); }
    mi operator--(int) { v--; if (v < 0) v = MOD - 1; return mi(v); }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
    friend ostream& operator<<(ostream& os, const mi& m) {
        os << m.v; return os;
    }
    friend istream& operator>>(istream& is, mi& m) {
        ll x; is >> x;
        m.v = x;
        return is;
    }
};


typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

void __print(mi X) {
    cout << X.v;
}

mi invs[MX];

vi primes, leastFac;
void compPrimes(int N) {
	F0R(i, N) {
		leastFac.pb(0);
	}
	leastFac[0] = 1; leastFac[1] = 1;
	FOR(i, 2, N) {
		if (leastFac[i] == 0) {
			primes.pb(i);
			leastFac[i] = i;
		}
		for (int j = 0; j < sz(primes) && i*primes[j] < N && primes[j] <= leastFac[i]; j++) {
			leastFac[i*primes[j]] = primes[j];
		}
	}
}

int mob[MX];

void compMob() {
    FOR(i, 1, MX) {
        int cnt = 0;
        int cur = i;
        while (cur > 1) {
            if (leastFac[cur] == leastFac[cur/leastFac[cur]]) goto notSqf;
            cnt++; cur /= leastFac[cur];
        }
        if (cnt % 2) {
            mob[i] = -1;
        } else {
            mob[i] = 1;
        }
        notSqf:
        ;
    }
}


mi facs[MX];
mi facInvs[MX];

//REMEMBER TO CHECK A >= B >= 0
mi choose(mi _a, mi _b) {
    ll a = (ll) _a, b = (ll) _b;
    mi cur = facs[a];
    cur = cur * facInvs[b];
    cur = cur * facInvs[a-b];
    return cur;
}

void initFacs() {
	facs[0] = 1;
	FOR(i, 1, MX) {
		facs[i] = (facs[i-1] * i);
	}
    facInvs[MX - 1] = inv(facs[MX-1]);
    F0Rd(i, MX-1) {
        facInvs[i] = facInvs[i+1] * (i+1);
    }
}

void solve() {
    int N; cin >> N;
    ll cnts[N]; F0R(i, N) cnts[i] = 0;
    F0R(i, N) {
        int X; cin >> X; cnts[X-1]++;
    }

    vl cnt;
    F0R(i, N) {
        if (cnts[i] != 0) {
            cnt.pb(cnts[i]);
        }
    }
    if (sz(cnt) == 1) {
        cout << 1 << nl; return;
    }
    ll G = cnt[0];
    F0R(i, sz(cnt)) G = __gcd(G, cnt[i]);

    int K = sz(cnt);
    vi factors;
    FOR(i, 1, G+1) {
        if (G%i == 0) {
            factors.pb(i);
        }
    }


    int M = sz(factors);
    mi ans[M];
    mi numPerms[M];
    F0R(i, M) {
        numPerms[i] = facs[N/factors[i]];
        F0R(j, K) {
            numPerms[i] *= facInvs[cnt[j]/factors[i]];
        }
    }
    F0R(i, K) {
       F0R(j, M) {
           ll c = cnt[i] / factors[j];
           if (c >= 2) { 
               /*mi cur = c; cur *= c-1; cur *= invs[2];
               cur *= N; cur *= numPerms[j]; cur *= facInvs[N]; cur *= facs[N-2];
               cur *= facInvs[c-2]; cur *= facs[c]; */
               mi cur = c; cur *= c-1; cur *= invs[N/factors[j]]; cur *= invs[N/factors[j] - 1]; cur *= N; cur *= numPerms[j];
               ans[j] += cur;
           }
       }
    }

    mi res = 0;
    mi den = 0;

    //dbg(numPerms[0], ans[0], M);

    F0R(i, M) {
        FOR(j, i+1, M) {
            if (factors[j] % factors[i] == 0) {
                ans[i] += ans[j] * mob[factors[j]/factors[i]];
                numPerms[i] += numPerms[j] * mob[factors[j] / factors[i]];
            }
        }
        res += ans[i] * factors[i] * invs[N];
        den += numPerms[i] * factors[i] * invs[N];
    }
    //dbg(res);

    res *= inv(den);
    cout << N - res << nl;


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    FOR(i, 1, MX) invs[i] = inv(mi(i));
    initFacs();
    compPrimes(MX);
    compMob();
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}