#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 100;
int a[maxn][maxn][3];
vvi p, bp;
int n;

int sum(int x, int y) {
	int s = 0;
	forn(z, 3) if (a[x][y][z]) ++s;
	return s;
}

int rec(int i) {
	if (i == n * n) {
		bool ok = true;
		forn(x, n) forn(y, n) {
			ok &= sum(x, y) > 0;
		}
		return (ok ? 0 : 1e9);
	}
	int ans = rec(i + 1);
	int x = i / n, y = i % n;
	if (sum(x, y) < 2) {
		forn(xx, n) ++a[xx][y][0];
		forn(yy, n) ++a[x][yy][1];
		fore(d, -n, n) {
			int xx = x + d, yy = y + d;
			if (min(xx, yy) >= 0 && max(xx, yy) < n) ++a[xx][yy][2];
		}
		uin(ans, rec(i + 1) + 1);
		forn(xx, n) --a[xx][y][0];
		forn(yy, n) --a[x][yy][1];
		fore(d, -n, n) {
			int xx = x + d, yy = y + d;
			if (min(xx, yy) >= 0 && max(xx, yy) < n) --a[xx][yy][2];
		}
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
//    freopen("input.txt", "rt", stdin);
#endif

	int n;
	cin >> n;
	::n = n;
	int zx = 0, zy = 0;
	vector<pii> a;
	if (n % 3 == 0) --n, zx = -1, zy = -1, a.pb({-1, -1});
	else if (n % 3 == 1) ++n;
	int s = n - n / 3 - 1;
//	cerr << s << '\n';
	forn(i, s) a.pb({i, (s / 2 - i - 1 + s) % s});
	s = 0;
	for (auto [x, y]: a) if (x >= zx && y >= zy) ++s;
	cout << s << '\n';
	for (auto [x, y]: a) if (x >= zx && y >= zy) cout << x - zx + 1 << ' ' << y - zy + 1 << '\n';

//	cout << rec(0) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}