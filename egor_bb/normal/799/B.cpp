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

const int N = 2e5 + 100;
const int INF = 1e9 + 7;

vector <int> b[10];
int a[N], p[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, n) {
		cin >> p[i];
	}
	forn(i, n) {
		int t; cin >> t;
		a[i] += t - 1;
	}
	forn(i, n) {
		int t; cin >> t;
		a[i] += 3 * (t - 1);
	}
	forn(i, n) {
		b[a[i]].pb(p[i]);
	}
	forn(i, 9) {
		sort(all(b[i]));
		reverse(all(b[i]));
	}
	int m;
	cin >> m;
	forn(i, m) {
		int t;
		cin >> t;
		t--;
		int best = INF;
		forn(j, 9) {
			if (j / 3 == t || (j % 3) == t) {
				if (!b[j].empty()) {
					best = min(best, b[j].back());
				}
			}
		}
		forn(j, 9) {
			if (j / 3 == t || (j % 3) == t) {
				if (!b[j].empty()) {
					if (best == b[j].back())
						b[j].pop_back();
				}
			}
		}
		if (best == INF)
			cout << -1 << ' ';
		else
			cout << best << ' ';
	}
	cout << '\n';
	return 0;
}