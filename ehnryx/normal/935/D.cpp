#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

inline void srand() { srand(chrono::high_resolution_clock::now().time_since_epoch().count()); }

template <class T, class U>
ostream& operator << (ostream& os, const pair<T,U>& v) {
	os << "(" << v.first << "," << v.second << ")"; return os;
}

template <class T>
ostream& operator << (ostream& os, const vector<T>& v) {
	for (const T& it : v) os << it << " "; return os;
}

template <class T>
ostream& operator << (ostream& os, const set<T>& v) {
	os << "{ "; for (const T& it : v) os << it << " "; os << "}"; return os;
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
	operator ll() { return x; }
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

typedef pair<Int,Int> pII;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	srand();

	ll n, m;
	cin >> n >> m;

	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	pII same(m*(m-1)/2,m*m);

	pII ans(0,1);
	pII psame(1,1);
	for (int i = 0; i < n; i++) {
		if (a[i] == 0 && b[i] == 0) {
			// upd better
			Int f = same.first;
			Int d = same.second * psame.second;
			ans = pII(ans.first * d + ans.second * f, ans.second * d);
			// upd same
			psame.second *= m;
		}

		else if (a[i] == 0) {
			Int f = (m - b[i]);
			Int d = m * psame.second;
			//cerr << i << ": " << pII(f,d) << nl;
			ans = pII(ans.first * d + ans.second * f, ans.second * d);
			// upd same
			psame.second *= m;
		}

		else if (b[i] == 0) {
			Int f = (a[i] - 1);
			Int d = m * psame.second;
			//cerr << i << ": " << pII(f,d) << nl;
			ans = pII(ans.first * d + ans.second * f, ans.second * d);
			// upd same
			psame.second *= m;
		}

		else {
			if (a[i] != b[i]) {
				//cerr << "not equal at " << i << " break;" << endl;
				if (a[i] > b[i]) {
					//cerr << "psame: " << psame << nl;
					ans = pII(ans.first * psame.second + ans.second, ans.second * psame.second);
				}
				break;
			}
		}
	}

	cerr << ans << nl;
	cout << ans.first / ans.second << nl;

	return 0;
}