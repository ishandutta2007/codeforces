#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

inline void srand() { srand(clock() + time(nullptr)); }

template <class T, class U>
ostream& operator << (ostream& os, const pair<T,U>& v) {
	os << "(" << v.first << "," << v.second << ")"; return os;
}

template <class T>
ostream& operator << (ostream& os, const vector<T>& v) {
	for (const T& it : v) os << it << " "; return os;
}

template <class T>
ostream& operator << (ostream& os, const unordered_set<T>& v) {
	os << "{ ";
	for (const T& it : v) os << it << " ";
	os << "}"; return os;
}

template <class T>
ostream& operator << (ostream& os, const set<T>& v) {
	os << "{ ";
	for (const T& it : v) os << it << " ";
	os << "}"; return os;
}

template <class T, class U>
ostream& operator << (ostream& os, const map<T,U>& v) {
	os << "{ ";
	for (const pair<T,U>& it : v) os << "{" << it.first << "," << it.second << "} "; 
	os << "}"; return os;
}

template <class T>
inline T sqr(T x) { return x*x; }

const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
//const ld PI = M_PIl;
////////////////////////////////////////////////////////////////////////

const ll MOD = 1e9+7;
const ld EPS = 1e-9;

/**
 * Automatically mods everything by MOD
 *
 * egcd(a,b,x,y) calculates x,y that satisfy ax+by=gcd(a,b)
 * to find a^-1 mod m use egcd(a,b,x,y) and x = a^-1
 * egcd also returns the gcd of a and b
 */
ll egcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) { x = 1, y = 0; return a; }
	ll d = egcd(b, a%b, y, x);
	y -= x * (a/b);
	return d;
}
struct Int {
	ll x;
	Int(ll n=0) { x = n % MOD; if (x < 0) x += MOD; }
	operator ll&() { return x; }
	Int operator + (const Int& n) { return Int(x + n.x); }
	Int operator - (const Int& n) { return Int(x - n.x); }
	Int operator * (const Int& n) { return Int(x * n.x); }
	Int operator / (const Int& n) { return Int(x * n.inverse()); }
	Int& operator += (const Int& n) { x = (x + n.x) % MOD; return *this; }
	Int& operator -= (const Int& n) { x = (x + MOD - n.x) % MOD; return *this; }
	Int& operator *= (const Int& n) { x = (x * n.x) % MOD; return *this; }
	Int& operator /= (const Int& n) { x = (x * n.inverse()) % MOD; return *this; }
	ll inverse() const {
		if (x == 0) throw runtime_error("divide by zero");
		ll c, d;
		egcd(x, MOD, c, d);
		return (c+MOD) % MOD;
	}
};
ostream& operator << (ostream& os, const Int& n) {
	os << n.x; return os;
}

unordered_set<int> solve(int len, int k, unordered_set<int>& bad) {
	unordered_set<int> res;

	if (k == 0) {
		res.insert(1);
		bad.insert(1);
	}

	else {
		int newlen = 32 - __builtin_clz(len);
		unordered_set<int> valid = solve(newlen, k-1, bad);
		for (int i = 0; i <= len; i++) {
			if (valid.count(__builtin_popcount(i)) && !bad.count(i)) {
				res.insert(i);
				bad.count(i);
			}
		}
	}

	return res;
}

Int memo[1001][1001][2]; // index, bits, follow
void dp(const string& s) {
	memset(memo, 0, sizeof memo);
	memo[0][0][1] = 1;
	for (int i = 1; i <= s.size(); i++) {
		memo[i][0][0] = memo[i-1][0][0] + memo[i-1][0][1];
		for (int j = 1; j <= 1000; j++) {
			memo[i][j][0] = memo[i-1][j][0] + memo[i-1][j-1][0];
			if (s[i-1] == '1') {
				memo[i][j][1] = memo[i-1][j-1][1];
				memo[i][j][0] += memo[i-1][j][1];
			} else {
				memo[i][j][1] = memo[i-1][j][1];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	int k;
	cin >> k;

	int n = s.size();

	if (k == 0) {
		cout << 1 << nl;
	}
	else if (k == 1) {
		cout << n-1 << nl;
	}
	else {
		unordered_set<int> bad;
		unordered_set<int> res = solve(n, k-1, bad);
		dp(s);

		Int ans = 0;
		for (int x : res) {
			ans += memo[n][x][0] + memo[n][x][1];
			//cerr << x << ": " << memo[n][x][0] << " + " << memo[n][x][1] << endl;
		}
		cout << ans << nl;
	}

	return 0;
}