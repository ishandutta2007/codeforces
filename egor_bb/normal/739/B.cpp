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
const int LOG = 19;

int a[N], res[N], add[N];
pair<int,ll> par[N][LOG];
vector <int> g[N];

int dfs(int v, int p) {
	for (int to : g[v]) {
		if (to != p)
			res[v] += dfs(to, v);
	}
	return res[v] + add[v];
}

void recalc(int v, int p) {
    forab(j, 1, LOG) {
		par[v][j] = mp(par[par[v][j - 1].fst][j - 1].fst, par[v][j - 1].snd + par[par[v][j - 1].fst][j - 1].snd);
	}
	int u = v;
	fornr(j, LOG) {
		if (par[u][j].snd <= a[v])
			a[v] -= par[u][j].snd, u = par[u][j].fst;
	}
	add[v]++, add[u]--;
    for (int to : g[v]) {
        if (to != p)
            recalc(to, v);
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, n)
		cin >> a[i];
	forab(i, 1, n) {
		int p, w;
		cin >> p >> w;
		p--;
		g[p].pb(i);
		par[i][0] = mp(p, w);
	}
	recalc(0, 0);
	dfs(0, 0);
	forn(i, n)
		cout << res[i] << " ";
	cout << '\n';
	return 0;
}