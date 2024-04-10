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

const int N = 82;

vector <pii> g[N];

int dp[N][N][N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int m;
	cin >> m;
	forn(i, m) {
		int u, v, c;
		cin >> u >> v >> c;
		g[u].pb(mp(v, c));
	}
	forn(i, N)
		forn(j, N)
			forn(k, N)
				forn(q, N)
					dp[i][j][k][q] = -1;
	forab(i, 1, n + 1)
		dp[1][i][0][n + 1] = 0;
	forab(vis, 1, k) {
		forab(pos, 1, n + 1) {
			forn(mn, N) {
				forab(mx, mn + 2, N) {
					if (dp[vis][pos][mn][mx] == -1)
						continue;
					int c = dp[vis][pos][mn][mx];
					for(pii nxt : g[pos]) {
						int to = nxt.fst, cost = nxt.snd + c;
						if (to > mn && to < mx) {
							if (to > pos) {
								if (dp[vis + 1][to][pos][mx] == -1 || dp[vis + 1][to][pos][mx] > cost) {
									dp[vis + 1][to][pos][mx] = cost;
								}
							} else {
								if (dp[vis + 1][to][mn][pos] == -1 || dp[vis + 1][to][mn][pos] > cost) {
									dp[vis + 1][to][mn][pos] = cost;
								}
							}
						}
					}
				}
			}
		}
	}
	int best = 1000000000;
	forn(i, N) {
		forn(j, N) {
			forn(q, N) {
				if (dp[k][i][j][q] != -1)
					best = min(best, dp[k][i][j][q]);
			}
		}
	}
	if (best == 1000000000)
		cout << -1 << '\n';
	else
		cout << best << '\n';
	return 0;
}