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

typedef long long LL;
typedef unsigned long long ULL;
typedef double dbl;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 1e5 + 100;
const LL INF = 2e18;

LL ax, ay, bx, by, tx, ty, x[N], y[N];

LL dist(LL a, LL b) {
	return (a - tx) * (a - tx) + (b - ty) * (b - ty);
}

int main() {
	cin >> ax >> ay >> bx >> by >> tx >> ty;
	int n;
	cin >> n;
	forn(i, n)
		cin >> x[i] >> y[i];
	LL pos1 = -1, pos2 = -1;
	LD mx1 = -INF, mx2 = -INF;
	forn(i, n) {
		LD d = sqrt(1. * dist(x[i], y[i])) - sqrt(1. * (x[i] - ax) * (x[i] - ax) + (y[i] - ay) * (y[i] - ay));
		if (mx1 < d) {
			mx2 = mx1, pos2 = pos1;
			mx1 = d, pos1 = i;
		} else if (mx2 < d) {
			mx2 = d, pos2 = i;
		}
	}	
	LL pos3 = -1, pos4 = -1;
	LD mx3 = -INF, mx4 = -INF;
	forn(i, n) {
		LD d = sqrt(1. * dist(x[i], y[i])) - sqrt(1. * (x[i] - bx) * (x[i] - bx) + (y[i] - by) * (y[i] - by));
		if (mx3 < d) {
			mx4 = mx3, pos4 = pos3;
			mx3 = d, pos3 = i;
		} else if (mx4 < d) {
			mx4 = d, pos4 = i;
		}
	}	
	LD m1, m2, m3, m4;
	m1 = mx1;
	m3 = mx3;
	m2 = mx2;
	m4 = mx4;
	LD ans = min(-m1, -m3);
	if (pos1 != pos3) {
		ans = min(ans, -m1 - m3);
	} else {
		if (pos4 != -1)
			ans = min(ans, -m1 - m4);
		if (pos2 != -1)
			ans = min(ans, -m2 - m3);
	}
	forn(i, n) {
		ans += 2 * sqrt(1. * dist(x[i], y[i]));
	}
	cout.precision(15);
	cout << fixed << double(ans) << '\n';

	return 0;
}