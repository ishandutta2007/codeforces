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
const int K = 11;

int k;
vector <int> g[N];
ll dp[N][K], cnt[N][K];

void dfs(int v, int p) {
	for(int to : g[v]) {
		if (to == p)
			continue;
		dfs(to, v);
		forn(i, k) {
			cnt[v][(i + 1) % k] += cnt[to][i];
			dp[v][(i + 1) % k] += dp[to][i];
		}
		dp[v][1 % k] += cnt[to][0];
	}
	cnt[v][0]++;
}

ll tmp[K], tmp_cnt[K];

void dfs2(int v, int p) {
	if (p != -1) {
		forn(i, k)
			tmp[i] = dp[p][i], tmp_cnt[i] = cnt[p][i];
		forn(i, k) {
			tmp_cnt[i] -= cnt[v][(i - 1 + k) % k];
			tmp[i] -= dp[v][(i - 1 + k) % k];
		}
		tmp[1 % k] -= cnt[v][0];
		forn(i, k) {
			cnt[v][(i + 1) % k] += tmp_cnt[i];
			dp[v][(i + 1) % k] += tmp[i];
		}
		dp[v][1 % k] += tmp_cnt[0];
	}
	for(int to : g[v]) {
		if (to == p)
			continue;
		dfs2(to, v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n >> k;
	forn(i, n - 1) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(0, 0);
/*	forn(i, n) {
		forn(j, k) {
			cout << i << " " << j << " --- " << dp[i][j] << " " << cnt[i][j] << '\n';
		}
	}*/
	dfs2(0, -1);
	ll ans = 0;
	forn(i, k) {
		forn(v, n) {
			ans += dp[v][i];
		}
	}
	cout << ans / 2 << '\n';
	return 0;
}