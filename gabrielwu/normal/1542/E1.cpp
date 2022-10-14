#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vii;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
int MOD = 13;

typedef std::decay<decltype(MOD)>::type mod_t;
struct mi {
    mod_t val;
    explicit operator mod_t() const { return val; }
    mi() { val = 0; }
    mi(const long long& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD; }
    friend std::istream& operator >> (std::istream& in, mi& a) {
        long long x; std::cin >> x; a = mi(x); return in; }
    friend std::ostream& operator << (std::ostream& os, const mi& a) { return os << a.val; }
    friend bool operator == (const mi& a, const mi& b) { return a.val == b.val; }
    friend bool operator != (const mi& a, const mi& b) { return !(a == b); }
    friend bool operator < (const mi& a, const mi& b) { return a.val < b.val; }
    friend bool operator > (const mi& a, const mi& b) { return a.val > b.val; }
    friend bool operator <= (const mi& a, const mi& b) { return a.val <= b.val; }
    friend bool operator >= (const mi& a, const mi& b) { return a.val >= b.val; }
    mi operator - () const { return mi(-val); }
    mi& operator += (const mi& m) {
        if ((val += m.val) >= MOD) val -= MOD;
        return *this; }
    mi& operator -= (const mi& m) {
        if ((val -= m.val) < 0) val += MOD;
        return *this; }
    mi& operator *= (const mi& m) { val = (long long) val * m.val % MOD;
        return *this; }
    friend mi pow(mi a, long long p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans; }
    friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
    mi& operator /= (const mi& m) { return (*this) *= inv(m); }
    friend mi operator + (mi a, const mi& b) { return a += b; }
    friend mi operator - (mi a, const mi& b) { return a -= b; }
    friend mi operator * (mi a, const mi& b) { return a *= b; }
    friend mi operator / (mi a, const mi& b) { return a /= b; }
};

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n >> MOD;

	int imax = (n*(n-1)/2 + 3*n + 5)*2;
	int zero = n*(n-1)/2 + 3*n + 5;

	vector<mi> fac(n+5);
	fac[0] = 1;
	forn(i, n+4){
		fac[i+1] = fac[i] * (i+1);
	}

	vector<vector<mi>> dp(n+1, vector<mi>(imax));
	dp[0][zero] = 1;
	forn(i, n){
		vector<mi> pref(imax);
		pref[0] = dp[i][0];
		forn(j, imax-1){
			pref[j+1] = pref[j] + dp[i][j+1];
		}
		function<mi(int a, int b)> rs = [&](int a, int b){
			return pref[b] - (a > 0 ? pref[a-1] : 0);
		};

		int ci = i+1;
		mi curr = 0;
		forn(j, ci+1){
			curr += j*dp[i][j];
		}
		forn(j, ci){
			curr += (i-j)*dp[i][ci+1+j];
		}
		dp[i+1][ci] = curr;
		while(ci+i+1 < imax){
			curr += rs(ci+1, ci+i+1) - rs(ci-i, ci);
			ci++;
			dp[i+1][ci] = curr;
		}
	}

	mi ans = 0;
	mi mult = 1;
	forn(i, n-1){
		mi add = 0;
		vector<mi> v(zero-1);
		forn(j, zero-1){
			v[j] = dp[n-1-i][j+zero];
		}
		// cout << v << "\n";

		mi curr = 0;
		for(int j=2; j<v.size(); j++){
			curr += v[j];
		}
		for(int diff = 1; diff <= n-i; diff++){
			// cout << fac[i] << " " << curr << " " << n-i-diff << "\n";
			add += mult * curr * (n-i-diff);
			curr -= v[diff+1];
		}
		// cout << add << "\n";
		ans += add;
		mult *= (n-i);
	}
	cout << ans << "\n";

}