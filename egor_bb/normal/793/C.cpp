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
typedef pair <ld, ld> pii;

pii intersect(pii a, pii b) {
	return mp(max(a.fst, b.fst), min(a.snd, b.snd));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int x1,y1,x2,y2;
	if (x1 > x2)
		swap(x1, x2);
	if (y1 > y2)
		swap(y1, y2);
	cin >> x1 >> y1 >> x2 >> y2;
	pii ans = mp(0, 1e100);
	forn(i, n) {
		int x, y, vx, vy;
		cin >> x >> y >> vx >> vy;
		pii ax;
		if (vx > 0) {
			ax.fst = (x1 - x) * 1. / vx;
			ax.snd = (x2 - x) * 1. / vx;
		} else if (vx == 0) {
			if (x <= x1 || x2 <= x) {
				cout << -1 << '\n';
				return 0;
			}
			ax = mp(0, 1e100);
		} else {
			ax.fst = (x2 - x) * 1. / vx;
			ax.snd = (x1 - x) * 1. / vx;
		}
		pii ay;
		if (vy > 0) {
			ay.fst = (y1 - y) * 1. / vy;
			ay.snd = (y2 - y) * 1. / vy;
		} else if (vy == 0) {
			if (y <= y1 || y2 <= y) {
				cout << -1 << '\n';
				return 0;
			}
			ay = mp(0, 1e100);
		} else {
			ay.fst = (y2 - y) * 1. / vy;
			ay.snd = (y1 - y) * 1. / vy;
		}
		ans = intersect(ans, ax);
		ans = intersect(ans, ay);
	}
	cout.precision(20);
	if (ans.fst < ans.snd) {
		cout << fixed << dbl(ans.fst) << '\n';
	} else {
		cout << -1 << '\n';
	}
	return 0;
}