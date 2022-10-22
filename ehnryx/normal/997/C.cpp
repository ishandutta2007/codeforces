#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

////////////////////////////////////////////////////////////////////////
// Extended Euclidean Algorithm (UBC)
// egcd(a,b,x,y) calculates x,y such that ax+by=gcd(a,b)
// To find a^{-1} mod m, use egcd(a,m,x,y), then x = a^{-1}
// Returns gcd(a,b)
ll egcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    } else {
        ll d = egcd(b, a%b, y, x);
        y -= x * (a/b);
        return d;
    }
}
//*/

////////////////////////////////////////////////////////////////////////
// Int struct for operations on a prime field (TESTED)
// WARNING: slow
struct Int {
    ll x;
    Int (ll n=0) { x = n % MOD; if (x < 0) x += MOD; }
    operator ll() { return x; }
    Int operator + (const Int& n) const { return Int(x + n.x); }
    Int operator - (const Int& n) const { return Int(x - n.x); }
    Int operator * (const Int& n) const { return Int(x * n.x); }
    Int operator / (const Int& n) const { return Int(x * n.inv()); }
    void operator += (const Int& n) { x = (x + n.x) % MOD; }
    void operator -= (const Int& n) { x = (x + MOD - n.x) % MOD; }
    void operator *= (const Int& n) { x = (x * n.x) % MOD; }
    void operator /= (const Int& n) { x = (x * n.inv()) % MOD; }
    ll inv() const {
        if (x == 0) throw runtime_error("divide by zero");
        ll c, d;
        egcd(x, MOD, c, d);
        return (c < 0) ? c+MOD : c;
    }
};
//*/

const int N = 1e6+1;
Int fact[N];
Int invf[N];
void init() {
	fact[0] = 1;
	invf[0] = 1;
	for (int i=1; i<=N; i++) {
		fact[i] = fact[i-1] * Int(i);
		invf[i] = fact[i].inv();
	}
}

Int ncr(int n, int r) {
	return fact[n] * invf[n-r] * invf[r];
}

Int power(Int b, ll e) {
	Int res = 1;
	while (e > 0) {
		if (e & 1) res *= b;
		b *= b;
		e >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
	init();

	int n;
	cin >> n;

	Int row = 0;
	for (int i=1; i<=n; i++) {
		Int cur = ncr(n,i) * power(Int(3), (ll)n*(n-i) + i);
		if (i%2 == 1) row += cur;
		else row -= cur;
	}

	Int mid = 0;
	for (int i=1; i<=n; i++) {
		Int base = power(Int(3), n-i);
		Int cur = ncr(n,i) * (power(base-Int(1), n) - power(base, n));
		if (i%2 == 1) mid += cur;
		else mid -= cur;
	}

	cout << Int(2)*row + Int(3)*mid << nl;

	return 0;
}