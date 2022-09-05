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
const int MX = 100001; //check the limits, dummy

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


void solve() {

    int N; cin >> N;
    ll X; cin >> X;
    ll D[N]; F0R(i, N) cin >> D[i];
    vl nums({X});
    ll cur = X;
    F0R(i, N) {
        cur += D[i]; nums.pb(cur);
    }
    sort(all(nums));
    auto it = unique(all(nums));
    int M = it - nums.begin();
    mi dp[N+1][M]; 
    map<ll, int> pos;
    F0R(i, M) {
        pos[nums[i]] = i;
    }
    F0R(i, N+1) F0R(j, M) dp[i][j] = 0;

    cur = X; ll lo = X, hi = 0;
    mi ans = 1;
    dp[0][pos[X]] = 1;
    ll sta[N], fin[N];
    mi invs[101]; FOR(i, 1, 101) invs[i] = inv(mi(i));
    F0R(i, N) {
        ll nxt = cur+D[i];
        sta[i] = cur; fin[i] = nxt;
        if (nxt == cur) continue;
        int A = min(pos[cur], pos[nxt]);
        int B = max(pos[cur], pos[nxt]);
        int nd = 0, ni = 0;
        if (nxt > cur) {
            ni++;
        } else {
            nd++;
        }
        FOR(p, A, B+1) {

            int nd = 0, ni = 0;
            if (p == 0 || p == pos[cur]) continue;
            if (p > A) {
                if (nxt > cur) {
                    ni++;
                } 
            }
            F0Rd(lst, i+1) {
                if (lst > 0 && sta[lst-1] <= nums[p-1] && fin[lst-1] >= nums[p]) {
                    ni++;
                } 
                F0R(k, nd+1) {
                    ll dist = nums[p] - nums[p-1] - 1 - k;
                    if (dist < 0) continue;
                    if (ni == 0 && dist == 0) {
                        dp[i+1][p] += dp[lst][p-1];
                    } else if (ni > 0) {
                        mi val = 1;
                        FOR(i, 1, ni) {
                            val *= invs[i];
                            val *= dist+ni-i;
                        }
                        FOR(i, 1, k+1) {
                            val *= nd-i+1;
                            val *= invs[i];
                        }
                        dp[i+1][p] += dp[lst][p-1] * val;
                    }
                    
                }
                if (lst > 0 && sta[lst-1] >= nums[p] && fin[lst-1] <= nums[p-1]) {
                    nd++;
                }
            }
        }
        if (ckmin(lo, nxt)) {

            F0R(k, i+2) F0R(j, M) dp[k][j] = 0;
        }
        if (nxt == lo) {
            dp[i+1][pos[nxt]]++;
        }
        FOR(j, pos[cur]+1, pos[nxt]+1) {
            
            dp[i+1][j] += dp[i+1][j-1];
        }

        if (ckmax(hi, nxt-lo)) {
            ans = 0;
        }
        if (pos.count(lo+hi)) ans += dp[i+1][pos[lo+hi]];

        cur += D[i];
    }
    if (hi == 0) {

        cout << 1 << " " << (X-cur+1)%MOD << nl; return;
    }
    cout << hi+1 << " " << ans << nl;
    /*F0R(i, M) {
        cout << nums[i] << " ";
    }
    cout << nl;
    cout << nl;
    F0R(i, N+1) {
        F0R(j, M) {
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