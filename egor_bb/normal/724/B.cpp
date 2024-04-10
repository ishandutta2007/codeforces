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

const int N = 50;

int a[N][N];

bool check(int n, int m) {
	forn(i, n) {
		int cnt = 0;
		forn(j, m) {
			if (a[i][j] != j + 1)
				cnt++;
		}
		if (cnt > 2)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	forn(i, n) {
		forn(j, m) {
			cin >> a[i][j];
		}
	}
	forn(x, m) {
		forn(y, m) {
			forn(i, n) {
				swap(a[i][x], a[i][y]);
			}
			if (check(n, m)) {
				cout << "YES\n";
				return 0;
			}
			forn(i, n) {
				swap(a[i][x], a[i][y]);
			}
		}
	}
	cout << "NO\n";
	return 0;
}