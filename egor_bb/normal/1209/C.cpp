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

int a[N], mn[N], col[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	forn(q, t) {
		int n;
		cin >> n;
		forn(i, n) col[i] = 2;
		string s;
		cin >> s;
		forn(i, n) a[i] = s[i] - '0';
		mn[n - 1] = n - 1;
		fornr(i, n - 1) {
			mn[i] = mn[i + 1];
			if (a[i] <= a[mn[i]]) {
				mn[i] = i;
			}
		}
		int pos = 0, start2 = 10;
		while(pos < n) {
			int nxt = mn[pos];
			if (nxt > pos && start2 == 10) {
				start2 = a[pos];
			}
			if (a[nxt] > start2) break;
			col[nxt] = 1;
			pos = nxt + 1;
		}
		bool ok = true;
		int last = -1;
		forn(i, n) {
			if (col[i] == 1 && a[i] < last) {
				ok = false;
				break;
			}
			if (col[i] == 1) {
				last = a[i];
			}
		}
		forn(i, n) {
			if (col[i] == 2 && a[i] < last) {
				ok = false;
				break;
			}
			if (col[i] == 2) {
				last = a[i];
			}
		}
		if (ok) {
			forn(i, n) cout << col[i];
		} else {
			cout << '-';
		}
		cout << '\n';
	}
	return 0;
}