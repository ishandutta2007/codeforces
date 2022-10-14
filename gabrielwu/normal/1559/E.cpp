#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 998244353
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

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
typedef std::decay<decltype(MOD)>::type mod_t;
struct mi {
	mod_t val;
	explicit operator mod_t() const { return val; }
	mi() { val = 0; }
	mi(const long long& v) {
		val = (-MOD <= v && v < MOD) ? v : v % MOD;
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

	// -- Sieve start --
	const int MAX_PRIME = 100005;
	vector<int> sieve(MAX_PRIME);	// sieve[i] := smallest factor of i greater than 1.
	vector<int> primes;				// list of primes up to MAX_PRIME
	
	for(int i=2; i<MAX_PRIME; i++) {
			if(!sieve[i]) {
					primes.push_back(i);
					for(int x=i; x<MAX_PRIME; x+=i) {
							if(sieve[x] == 0) {
									sieve[x] = i;
							}
					}
			}
	}
	// -- Sieve end --

	int n, m;
	cin >> n >> m;
	vector<int> l(n), r(n);
	forn(i, n){
		cin >> l[i] >> r[i];
	}

	mi ans = 0;

	for(int g = 1; g<=m; g++){
		int cnt = 0;
		int bef = -1;
		int x = g;
		bool sf = true;
		while(x != 1){
			sf &= bef != sieve[x];
			bef = sieve[x];
			x /= sieve[x];
			cnt++;
		}

		if(!sf) continue;
		int len = m/g+1;
		vector<mi> dp(len);
		vector<mi> pref(len);
		dp[0] = 1;
		bool works = true;
		forn(i, n){
			int lo = (l[i]-1)/g+1, hi = r[i]/g;
			if(lo > hi){
				works = false;
				break;
			}

			pref[0] = dp[0];
			forn(j, len-1){
				pref[j+1] = dp[j+1] + pref[j];
			}

			for(int j=len-1; j>=0; j--){
				dp[j] = (j - lo >= 0 ? pref[j-lo] : 0) - (j - hi - 1 >= 0 ? pref[j-hi-1] : 0);
			}
			// cout << dp << "\n";
		}
		// cout << g << " " << cnt << " " << works << " " << dp << "\n";
		mi d = 0;
		forn(i, len){
			d += dp[i];
		}
		if(works){
			if(cnt%2 == 0){
				ans += d;
			} else {
				ans -= d;
			}
		}
	}

	cout << ans << "\n";


	
}