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
//*!
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
//*!
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

const int N = 1e3+1;
Int dp[N][4][2*N];

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	dp[1][0][1] = 1;
	dp[1][1][2] = 1;
	dp[1][2][2] = 1;
	dp[1][3][1] = 1;
	for (int i=2; i<=n; i++) {
		for (int cur=0; cur<4; cur++) {
			for (int v=0; v<=2*n; v++) {
				dp[i][cur][v] += dp[i-1][cur][v];
				if (cur == 0 || cur == 3) {
					dp[i][cur][v] += dp[i-1][1][v] + dp[i-1][2][v];
					if (v>0) dp[i][cur][v] += dp[i-1][3-cur][v-1];
				} else {
					if (v>2) dp[i][cur][v] += dp[i-1][3-cur][v-2];
					if (v>1) dp[i][cur][v] += dp[i-1][0][v-1] + dp[i-1][3][v-1];
				}
			}
		}
	}

	Int ans = 0;
	for (int i=0; i<4; i++) {
		ans += dp[n][i][k];
	}
	cout << ans << nl;

	return 0;
}