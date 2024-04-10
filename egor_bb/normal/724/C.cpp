#define FNAME ""

#undef __STRICT_ANSI__

#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (int)(n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (int)(b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
	#define U64 "%I64u"
#else
	#define I64 "%lld"
	#define U64 "%llu"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const ll INF = 1e18;

ll gcd (ll a, ll b, ll &x, ll &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

ll calc(int m, int n, int d, int yy) {
	if (!d)
		return yy;
	int g = __gcd(m, n);
	m /= g;
	n /= g;
	if (d % g != 0)
		return INF;
	d /= g;
	ll x, y;
	gcd(m, n, x, y);
	x *= d, y *= d;
//	cerr << m << " " << n << " " << x << " " << y << " " << d << '\n';
	ll sub = min(x / n, (-y / m));
	x -= sub * n;
	y += sub * m;
	while(x >= 0 && y <= 0) {
		x -= n;
		y += m;
	}
	while(x < 0 || y > 0) {
		x += n;
		y -= m;
	}
//	cerr << m << " " << n << " " << x << " " << y << " " << d << " " << yy << '\n';
//	cerr << yy + g * m * 1ll * x << '\n';
	return yy + m * 1ll * g * x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	forn(i, k) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == y) {
			printf("%d\n", x);
			continue;
		}
		ll ans = INF;
		ans = min(ans, calc(2 * m, 2 * n, x - y, y));
		ans = min(ans, calc(2 * m, 2 * n, (2 * n - x) - y, y));
		ans = min(ans, calc(2 * m, 2 * n, x - (2 * m - y), (2 * m - y)));
		ans = min(ans, calc(2 * m, 2 * n, (2 * n - x) - (2 * m - y), (2 * m - y))); 
		if (ans == INF) {
			puts("-1");
		} else {
			printf("%lld\n", ans);
		}
	}
	return 0;
}