#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct chash {
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

template<typename T> using pb_set = gp_hash_table<T, null_type, chash>;
template<typename T, typename U> using pb_map = gp_hash_table<T, U, chash>;
 
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
const int MX = 100001; 


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

const int K = 500;
ll cntDiv[2][K], cntRem[2][K];
mi costDiv[2][K], costRem[2][K];

void solve() {
    int N; cin >> N;
    vi A(N); F0R(i, N) cin >> A[i];
    reverse(all(A));
    F0R(i, 2) {
        F0R(j, K) {
            cntDiv[i][j] = 0;
            cntRem[i][j] = 0;
            costDiv[i][j] = 0;
            costRem[i][j] = 0;
        }
    }
    costDiv[0][1] = 0;
    cntDiv[0][1] = 1;
    mi ans = 0;
    FOR(i, 1, N) {
        int v = i%2;
        F0R(i, K) {
            costDiv[v][i] = 0; costRem[v][i] = 0;
            cntRem[v][i] = 0; cntDiv[v][i] = 0;
        }
        cntDiv[v][1] = 1;
        costDiv[v][1] = 0;
        FOR(j, 1, K) {
            if (cntDiv[1-v][j] > 0) {
                int val = A[i-1] / j;
                if (val >= A[i]) {
                    cntDiv[v][1] += cntDiv[1-v][j];
                    costDiv[v][1] += costDiv[1-v][j];
                } else {
                    //ceil(A[i] / K) <= p
                    //K = ceil(A[i] / P)
                    ll cc = (A[i] + val - 1) / val;
                    ll nv = (A[i]) / cc;
                    if (cc < K) {
                        costDiv[v][cc] += costDiv[1-v][j] + cntDiv[1-v][j] * (cc - 1);
                        cntDiv[v][cc] += cntDiv[1-v][j];
                    } else {
                        costRem[v][nv] += costDiv[1-v][j] + cntDiv[1-v][j] * (cc - 1);
                        cntRem[v][nv] += cntDiv[1-v][j];

                    }
                }
                //dbg("DONE");
            }

            if (cntRem[1-v][j] > 0) {
                //dbg(i, j, "REM");
                if (j >= A[i]) {
                    cntDiv[v][1] += cntRem[1-v][j];
                    costDiv[v][1] += costRem[1-v][j];
                } else {
                    //ceil(A[i] / K) <= p
                    //K = ceil(A[i] / P)
                    ll cc = (A[i] + j - 1) / j;
                    ll nv = (A[i]) / cc;
                    if (cc < K) {
                        costDiv[v][cc] += costRem[1-v][j] + cntRem[1-v][j] * (cc - 1);
                        cntDiv[v][cc] += cntRem[1-v][j];
                    } else {
                        costRem[v][nv] += costRem[1-v][j] + cntRem[1-v][j] * (cc - 1);
                        cntRem[v][nv] += cntRem[1-v][j];

                    }
                }
                //dbg("DONE");
            }


        }
        F0R(j, K) {
            ans += costDiv[v][j]; ans += costRem[v][j];
        }
    }
    cout << ans << nl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}