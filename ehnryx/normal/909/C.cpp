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

const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

const ll MOD = 1e9+7;
const ld EPS = 1e-9;


// 41 lines
/**
 * Automatically mods everything by MOD
 *
 * egcd(a,b,x,y) calculates x,y that satisfy ax+by=gcd(a,b)
 * to find a^-1 mod m use egcd(a,b,x,y) and x = a^-1
 * egcd also returns the gcd of a and b
 */
ll egcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll d = egcd(b, a%b, y, x);
    y -= x * (a/b);
    return d;
}
struct Int {
    ll x;
    Int(ll n=0) { x = n % MOD; if (x < 0) x += MOD; }
    operator ll() const { return x; }
    #define op Int operator
    #define opr Int& operator
    op + (const Int& n) { return Int(x + n.x); }
    op - (const Int& n) { return Int(x - n.x); }
    op * (const Int& n) { return Int(x * n.x); }
    op / (const Int& n) { return Int(x * n.inverse()); }
    opr += (const Int& n) { x = (x + n.x) % MOD; return *this; }
    opr -= (const Int& n) { x = (x + MOD - n.x) % MOD; return *this; }
    opr *= (const Int& n) { x = (x * n.x) % MOD; return *this; }
    opr /= (const Int& n) { x = (x * n.inverse()) % MOD; return *this; }
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


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	Int dp[n+1][n+1]; // id, layer
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;

	int maxlayer = 0;
	char c;
	bool indent = false;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (indent) {
			maxlayer++;
			for (int j = 1; j <= n; j++) {
				dp[i+1][j] = dp[i][j-1];
			}
		} else {
			Int sum = 0;
			for (int j = maxlayer; j >= 0; j--) {
				sum += dp[i][j];
				dp[i+1][j] = sum;
			}
		}
		indent = (c == 'f');
	}

	if (indent) {
		cout << 0 << nl;
		return 0;
	}

	Int ans = 0;
	for (int j = 0; j <= n; j++) {
		ans += dp[n][j];
	}
	cout << ans << nl;

	return 0;
}