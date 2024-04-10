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

const int N = 2e6;

int deg[N], used[N], ins[N], total, real_deg[N];
vector <int> g[N];
int cnt = 0;

void dfs(int v) {
	used[v] = 1;
	for(int to : g[v]) {
		if (to == v) {
			cnt++;
			continue;
		}
		if (used[to] == 1) {
			cnt++;
		} else if (used[to] == 0) {
			dfs(to);
		}
	}
	used[v] = 2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	forn(i, m) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		deg[v]++;
		if (u != v) deg[u]++, real_deg[v]++, real_deg[u]++;
		g[v].pb(u);
		if (u != v) g[u].pb(v);
		if (u == v)
			ins[v]++, total++;
	}
	forn(i, n) {
		if (deg[i] != 0 && !used[i]) {
			dfs(i);
			if (cnt != m) {
				cout << 0 << '\n';
				return 0;
			}
		}
	}
	ll ans = 0;
	forn(v, n) {
		ans += real_deg[v] * 1ll * (real_deg[v] - 1) / 2;
	}
	ans += total * 1ll * (m - total);
	ans += total * 1ll * (total - 1) / 2;
	cout << ans << '\n';
	return 0;
}