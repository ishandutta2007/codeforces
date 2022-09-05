#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
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
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
 
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
 
const int MOD = 998244353;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
 
int D;

ll basis[35]; // basis[i] keeps the mask of the vector whose f value is i

int bs = 0; //basis size

void insertVector(ll mask) {
	for (int i = 0; i < D; i++) {
		if ((mask & 1ll << i) == 0) continue; 

		if (!basis[i]) { 
			basis[i] = mask;
			++bs;
			
			return;
		}

		mask ^= basis[i]; 
	}
}


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
    mi operator++(int) { mi temp; temp.v = v++; return temp; }
    mi operator--(int) { mi temp; temp.v = v--; return temp; }
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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N >> D;

    ll A[N]; F0R(i, N) cin >> A[i];

    F0R(i, N) {
        insertVector(A[i]);
    }

    map<ll, mi> dp[D+1][D+1];

    dp[0][0].ins({0, 1});

    F0R(b, D) {
        F0R(i, D+1) {
            trav(a, dp[b][i]) {
//                cout << b << " " << i << " " << a.f << " " << a.s << nl;
                if (a.f & (1ll << b)) {
                    dp[b+1][i+1][a.f - (1ll << b)] += a.s;
                } else {
                    dp[b+1][i][a.f] += a.s;
                }

                if (basis[b]) {
                    ll cur = a.f ^ basis[b];
                    if (cur & (1ll << b)) {
                        dp[b+1][i+1][cur - (1ll << b)] += a.s;
                    } else {
                        dp[b+1][i][cur] += a.s;
                    }
                }
            }
        }
    }
    mi mul = pow((mi) 2, N-bs);
/*    cout << basis[0] << " " << basis[1] << nl;
    cout << mul << nl;*/
    F0R(i, D+1) {
        if (sz(dp[D][i]) == 0) {
            cout << 0 << " "; continue;
        }
        cout << dp[D][i].begin()->s * mul << " ";
    }
    cout << nl;

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343