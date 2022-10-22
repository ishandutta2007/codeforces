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
inline T sqr(T x) { return x*x; }

const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
//const ld PI = M_PIl;
////////////////////////////////////////////////////////////////////////

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

// i, r
Int val[21][1000001];
vector<int> primes;

void init() {
	memset(val, 0, sizeof val);
	for (int r = 0; r <= 1000000; r++) {
		val[1][r] = 1;
	}
	for (int i = 2; i <= 20; i++) {
		val[i][1] = 2*i - 1;
		for (int r = 2; r <= 1000000; r++) {
			val[i][r] = val[i-1][r] + val[i][r-1];
		}
	}

	for (int i = 1; i <= 20; i++) {
		val[i][0] = 2;
		for (int r = 1; r <= 1000000; r++) {
			val[i][r] += val[i][r-1];
		}
	}

	bitset<1000001> notp;
	notp[0] = notp[1] = true;
	for (int i = 2; i <= 1000; i++) {
		if (!notp[i]) {
			for (int j = i*i; j <= 1000000; j += i) {
				notp[j] = true;
			}
		}
	}
	for (int i = 2; i <= 1000000; i++) {
		if (!notp[i]) {
			primes.push_back(i);
		}
	}
}

ll solve(int r, int n) {
	if (n == 1) {
		return 1;
	}
	else {
		vector<int> res;
		int lim = sqrt(n);
		for (const int& p : primes) {
			if (p > lim) 
				break;
			if (n % p == 0) {
				res.push_back(0);
				while (n % p == 0) {
					n /= p;
					res.back()++;
				}
				lim = sqrt(n);
			}
		}
		if (n > 1) {
			res.push_back(1);
		}

		Int ans = 1;
		for (const int& v : res) {
			ans *= val[v][r];
		}
		return ans;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	init();

	int q;
	cin >> q;
	while (q--) {
		int r, n;
		cin >> r >> n;
		cout << solve(r, n) << nl;
	}

	return 0;
}