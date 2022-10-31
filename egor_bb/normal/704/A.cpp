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

const int N = 5e5 + 100;

vector <int> app[N];
int done[N], cnt = 0, total, mx = 0, st[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q; cin >> n >> q;
	forn(i, q) {
		int t; cin >> t;
		if (t == 1) {
			int x; cin >> x;
			app[x].pb(total);
			total++; cnt++;
		} else if (t == 2) {
			int x; cin >> x;
			while(st[x] < sz(app[x])) {
				if (!done[app[x][st[x]]]) {
					done[app[x][st[x]]] = 1;
					cnt--;
				}
				st[x]++;
			}
		} else {
			int x; cin >> x;
			while(mx < x) {
				if (!done[mx])
					done[mx] = 1, cnt--;
				mx++;
			}
		}
		cout << cnt << '\n';
	}	
	return 0;
}