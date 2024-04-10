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

	// -- Combo Start --
	const int MAX_FAC = 1000005;
	
	vector<mi> fac(MAX_FAC + 1, 1), ifac(MAX_FAC + 1);
	for(int i=1; i<=MAX_FAC; i++) fac[i] = fac[i-1] * i;
	ifac[MAX_FAC] = inv(fac[MAX_FAC]);
	for(int i=MAX_FAC-1; i>=0; i--) ifac[i] = ifac[i+1] * (i+1);
	
	function<mi(int, int)> choose = [&](int a, int b) {
		assert(a >= 0 && b >= 0 && a <= MAX_FAC);
		return a >= b ? fac[a]*ifac[a-b]*ifac[b] : 0;
	};
	// -- Combo End --
	
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	forn(i, n){
		char c;
		cin >> c;
		if(c == '1') v[i] = 1;
	}

	int ones = 0;
	vector<int> loc;
	loc.pb(-1);
	forn(i, n){
		if(v[i]){
			loc.pb(i);
			ones += 1;
		}
	}
	loc.pb(n);

	if(k > ones){
		cout << 1 << "\n";
		return 0;
	}

	mi ans = 1;
	for(int x=k; x>=1; x--){
		int p1 = 0;
		int p2 = x + 1;
		while(p2 < loc.size()){
			if(x >= 2){
				ans += (choose(loc[p2]-loc[p1]-1, x)-choose(loc[p2]-loc[p1+1]-1, x-1)
					-choose(loc[p2-1]-loc[p1]-1, x-1)+choose(loc[p2-1]-loc[p1+1]-1, x-2));
			} else {
				ans += (loc[p2]-loc[p1]-1-1);
			}
			// ans += mult*(loc[p1+1choose(loc[p2]-loc[p1]-1, x);
			// cout << choose(loc[p2]-loc[p1]-1, x) << "\n";
			p1++;
			p2++;
		}
	}

	cout << ans << "\n";
}
// 6+6+10 - 3-3