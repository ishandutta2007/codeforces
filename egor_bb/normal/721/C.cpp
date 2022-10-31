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
const int INF = 1e9 + 1;

vector <pii> g[N];

bool was[N];
int dp[N][N], n;

void calc(int v) {
	if (was[v])
		return;
	was[v] = true;
	if (v == n - 1) {
		dp[v][1] = 0;
		return;
	}
	for (pii p : g[v]) {
		int to = p.fst, w = p.snd;
		calc(to);
		forn(i, n) {
			dp[v][i + 1] = min(dp[v][i + 1], dp[to][i] + w);
		}
	}
}

void get(int v, int len) {
	cout << v + 1 << " ";
	if (v == n - 1)
		return;
	for (pii p : g[v]) {
		int to = p.fst, w = p.snd;
		if (dp[to][len - 1] == dp[v][len] - w) {
			get(to, len - 1);
			return;
		}
	}	
	assert(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m, t;
	cin >> n >> m >> t;
	forn(i, m) {
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		g[a].pb(mp(b, w));
	}
	forn(i, n + 1) {
		forn(j, n + 1) {
			dp[i][j] = INF;
		}
	}
	calc(0);
	fornr(i, n + 1) {
		if (dp[0][i] <= t) {
			cout << i << '\n';
//			cerr << i << '\n';
			get(0, i);
			cout << '\n';
			return 0;
		}
	}
	return 0;
}