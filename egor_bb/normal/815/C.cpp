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

const int N = 5e3 + 100;
const ll INF = 1e13;

int c[N], d[N];
ll dp[N][N][2];
vector<int> g[N];

int dfs(int v) {
	forn(i, N)
		dp[v][i][0] = dp[v][i][1] = INF;
	dp[v][0][0] = 0;
	dp[v][1][0] = c[v];
	dp[v][1][1] = c[v] - d[v];
	int mxsz = 1;
	for (int to : g[v]) {
		int size = dfs(to);
		forba(i, 0, mxsz + 1)
			fornr(j, size + 1) {
				ll xi = dp[v][i][0], xj = dp[v][i][1], yi = dp[to][j][1], yj = dp[to][j][0];
				dp[v][i + j][0] = min(dp[v][i + j][0], xi + yj);
				dp[v][i + j][1] = min(dp[v][i + j][1], xj + min(yj, yi));	
			}
		mxsz += size;
	}
	return mxsz;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, b;
	cin >> n >> b;
	forn(i, n) {
		cin >> c[i] >> d[i];
		if (i) {
			int p; cin >> p;
			p--;
			g[p].pb(i);
		}
	}
	dfs(0);
/*	forn(i, n) {
		cout << i << ":\n";
		forn(j, n + 1) {
			cout << "j = " << j << ", " << dp[i][j][0] << " " << dp[i][j][1] << '\n';
		}
	}*/
	fornr(i, n + 1) {
		if (dp[0][i][0] <= b || dp[0][i][1] <= b) {
			cout << i << '\n';
			return 0;
		}
	}
	assert(0);
	return 0;
}