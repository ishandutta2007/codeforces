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
typedef pair <LL, LL> pll;

const int N = 3e5 + 100;
const LL INF = 1e18;

vector <int> g[N];
set <pll> s[N];
LL add[N], real_value[N];
vector<pll> start[N];
vector<int> finish[N];

void Unite(int v, int to, LL x) {
	add[to] += x;
	if (sz(s[v]) < sz(s[to]))
		s[v].swap(s[to]), swap(add[v], add[to]);
	for(pll p : s[to]) {
		p.fst += add[to];
		p.fst -= add[v];
		real_value[p.snd] = p.fst;
		s[v].insert(p);
	}
}

LL ans = INF;

void dfs(int v, int p) {
	LL sum = 0;
	for(int to : g[v]) {
		if (to == p)
			continue;	
		dfs(to, v);
//		cerr << v << " " << sz(s[to]) << '\n';
		if (s[to].empty()) {
			puts("-1");
			exit(0);
		}
		sum += s[to].begin()->fst + add[to];
	}
	forn(i, sz(start[v])) {
		real_value[start[v][i].snd] = sum + start[v][i].fst;
		s[v].insert(mp(start[v][i].fst + sum, start[v][i].snd));
	}
	for(int to : g[v]) {
		if (to == p)
			continue;
		Unite(v, to, sum - s[to].begin()->fst - add[to]);
	}
	forn(i, sz(finish[v])) {
		LL real = real_value[finish[v][i]];
		s[v].erase(mp(real, finish[v][i]));
		if (!v) {
			ans = min(ans, real + add[v]);
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
if(n==1){
puts("0");
return 0;
}
	forn(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	forn(i, m) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		u--, v--;
		start[u].pb(mp(c, i));
		finish[v].pb(i);
	}
	dfs(0, -1);
	if (!s[0].empty()) {
		ans = min(ans, (s[0].begin()->fst + add[0]));
	}
	if (ans != INF)
		cout << ans << '\n';
	else 
		cout << -1  << '\n';
	return 0;
}