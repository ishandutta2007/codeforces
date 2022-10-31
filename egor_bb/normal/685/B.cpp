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

const int N = 3e5 + 100;

int size[N], ans[N], par[N], mx[N];
vector <int> g[N];

bool good(int v, int sum) {
	int m = max(sum - size[v], size[mx[v]]);
	if (m * 2 <= sum)
		return 1;
	else
		return 0;
}

void dfs(int v) {
	size[v] = 1;
	mx[v] = -1;
	for(int to : g[v]) {
		dfs(to);
		size[v] += size[to];
		if (mx[v] == -1 || size[mx[v]] < size[to])
			mx[v] = to;
	}
	if (mx[v] == -1 || size[mx[v]] * 2 <= size[v])
		ans[v] = v;
	else {
		ans[v] = ans[mx[v]];
		while(!good(ans[v], size[v]))
			ans[v] = par[ans[v]];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	forn(i, n - 1) {
		int p; cin >> p;
		g[p - 1].pb(i + 1);
		par[i + 1] = p - 1;
	}
	dfs(0);
	while(q--) {
		int v; cin >> v;
		cout << ans[v - 1] + 1 << '\n';
	}
	return 0;
}