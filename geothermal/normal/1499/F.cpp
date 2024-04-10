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
 
const int MOD = 998244353;
const char nl = '\n';
const int MX = 5001; //check the limits, dummy

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
int K;

mi dp[MX][MX];
vector<vi> graph(MX);

void dfs(int v, int p) {
    vi chil;
    trav(a, graph[v]) if (a != p) dfs(a, v);
    trav(a, graph[v]) if (a != p) chil.pb(a);

    /*mi pre[sz(chil)][K+1];
    F0R(i, sz(chil)) F0R(j, K+1) pre[i][0] += dp[chil[i]][j];

    FOR(i, 1, K+1) {
        F0R(j, sz(chil)) {
            pre[j][i] = dp[chil[j]][i-1];
            if (i > 0) pre[j][i] += pre[j][i-1];
        }
    }*/
    /*F0R(i, sz(chil)) {
        F0R(j, K+1) {
            cout << "TEST " << i << " " << j << " " << pre[i][j] << endl;
        }
    }
    cout << "DONE " << v << endl;*/
    /*mi sum[K+1]; F0R(i, K+1) sum[i] = 1;

    F0R(i, K+1) F0R(j, sz(chil)) {
        if (i > 0) {
            sum[i] *= dp[chil[j]][i-1] + dp[chil[j]][K];
        } else {
            sum[i] *= dp[chil[j]][K];
        }
    }
    F0R(i, K+1) {
        if (i * 2 <= K) {
            dp[v][i] += sum[i];
            if (i > 0) dp[v][i] -= sum[i-1];
        } else {
            int oth = K-i;
            F0R(j, sz(chil)) {
                mi X = dp[chil[j]][K];
                if (oth > 0) X += dp[chil[j]][oth-1];
                mi val = sum[oth] * inv(X); 
                //if (oth > 0) val -= sum[oth-1] * inv(pre[j][oth-1]);
                dp[v][i] += dp[chil[j]][i-1] * val;
                if (i > 1) dp[v][i] -= dp[chil[j]][i-2] * val;
            }
        }
    }
    F0R(i, K) {
        dp[v][i+1] += dp[v][i];
    }*/

    dp[v][0] = 1;
    trav(a, chil) {
        mi val = dp[a][K];
        FORd(i, 1, K+1) {
            dp[a][i] = dp[a][i-1] + val;
        }
        dp[a][0] = val;
        mi pref[K+1]; F0R(i, K+1) pref[i] = dp[v][i];
        FOR(i, 1, K+1) pref[i] += pref[i-1];
        F0R(i, K+1) dp[v][i] = 0;
        F0R(i, K+1) {
            if (i * 2 <= K) {
                dp[v][i] += pref[i] * dp[a][i];
                if (i > 0) dp[v][i] -= pref[i-1] * dp[a][i-1];
            } else {
                int oth = K - i;
                dp[v][i] += pref[oth] * dp[a][i];
                dp[v][i] -= pref[oth] * dp[a][i-1];
                dp[v][i] += (pref[i] - pref[i-1]) * dp[a][oth];
            }
        }
        /*F0R(i, K+1) {
            cout << dp[v][i] << " ";
        }
        cout << nl;*/
    }
    F0R(i, K) dp[v][i+1] += dp[v][i];
    
}

void solve() {

    int N; cin >> N >> K;
    F0R(i, N-1) {
        int X, Y; cin >> X >> Y; X--; Y--; graph[X].pb(Y); graph[Y].pb(X);
    }

    dfs(0, -1);
    cout << dp[0][K] << nl;

    /*F0R(i, N) {
        F0R(j, K+1) {
            cout << dp[i][j] << " ";
        }
        cout << nl;
    }*/
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343