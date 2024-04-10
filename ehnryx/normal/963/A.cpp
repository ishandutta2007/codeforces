#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+9;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

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
////////////////////////////////////////////////////////////////////////

Int power(Int b, int e) {
	Int p = b;
	Int res = 1;
	while (e > 0) {
		if (e & 1) res *= p;
		p *= p;
		e /= 2;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, a, b, k;
	cin >> n >> a >> b >> k;

	string s;
	cin >> s;

	Int inva = Int(1) / Int(a);
	Int cura = power(a, k-1);
	Int curb = Int(1);

	Int factor = Int(0);
	for (int i = 0; i < k; i++) {
		factor += Int(s[i] == '+' ? 1 : -1) * cura * curb;
		cura *= inva;
		curb *= Int(b);
	}

	Int geo;
	Int ratio = power(b, k) / power(a, k);
	if (ratio == 1) {
		geo = power(a, n-k+1) * Int((n+1)/k);
	} else {
		geo = power(a, n-k+1) * (power(ratio, (n+1)/k) - Int(1)) / (ratio - Int(1));
	}

	cerr << "factor: " << factor << nl;
	cerr << "geo: " << geo << nl;

	cout << factor * geo << nl;

	return 0;
}