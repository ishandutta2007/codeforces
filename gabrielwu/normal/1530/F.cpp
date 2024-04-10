#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 31607
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

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
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
	mi inv = (mi)1 / 10000;

	// cout << inv << "\n";

	int n;
	cin >> n;
	

	vector<vector<mi>> ov(n, vector<mi>(n)), oiv(n, vector<mi>(n));
	vector<vector<mi>> v(n, vector<mi>(n)), iv(n, vector<mi>(n));
	forn(i, n){
		forn(j, n){
			cin >> ov[i][j];
			ov[i][j] *= inv;
			oiv[i][j] = 1/ov[i][j];
		}
	}
	// cout << ov << " " << oiv << "\n";

	int base = 0;
	mi ans = 1;

	function<mi(void)> solve = [&](){
		mi ret = 0;
		// mi m = 1;
		vector<mi> row(n), col(n);
		forn(i, n){
			row[i] = 1;
			col[i] = 1;
			forn(j, n){
				row[i] *= v[i][j];
				col[i] *= v[j][i];
			}
			// m *= row[i];
		}
		// ret -= m;

		forn(mask, (1<<n)){
			int bits = 0;
			mi c = 1;
			//update row
			if(mask){
				forn(i, n){
					if((1<<i) & mask){
						bits++;
						c *= col[i];
					}
					//turn off
					if(((1<<i)&mask) && !((1<<i)&(mask-1))){
						forn(j, n){
							row[j] *= iv[j][i];
						}
					} else if(!((1<<i)&mask) && ((1<<i)&(mask-1))){	//turn on
						forn(j, n){
							row[j] *= v[j][i];
						}
					}
				}
			}
			// cout << row << "\n";
			mi even, odd;
			if(bits%2) odd = 1;
			else even = 1;
			forn(i, n){
				mi newodd = odd + row[i]*even;
				mi neweven = even + row[i]*odd;
				odd = newodd;
				even = neweven;
			}
			// cout << "mask: " << mask << " odd: " << odd << " even: " << even << " c: " << c << "\n";
			ret += (odd - even)*c;
		}

		return ret;
	};

	v = ov;
	iv = oiv;
	// cout << "s " << solve() << "\n";
	ans += solve();
	mi c = 1;
	forn(i, n){
		c *= ov[i][i];
		v[i][i] = 1;
		iv[i][i] = 1;
	}
	ans -= c*solve();
	// cout << "t " << solve() << "\n";
	v = ov;
	iv = oiv;
	c = 1;
	forn(i, n){
		c *= ov[n-1-i][i];
		v[n-1-i][i] = 1;
		iv[n-1-i][i] = 1;
	}
	ans -= c * solve();
	// cout << "u " << solve() << "\n";
	v = ov;
	iv = oiv;
	c = 1;
	forn(i, n){
		c *= ov[n-1-i][i];
		v[n-1-i][i] = 1;
		iv[n-1-i][i] = 1;
	}
	forn(i, n){
		c *= v[i][i];
		v[i][i] = 1;
		iv[i][i] = 1;
	}
	// cout << "v " << solve() << "\n";
	ans += c*solve();

	cout << ans << "\n";	
}