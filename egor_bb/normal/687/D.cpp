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

const int N = 1e3 + 100;

struct e {
	int a, b, w, id;
	e() = default;
	bool operator <(const e &x) const {
		return (w < x.w || (w == x.w && id < x.id));
	}
};

e edges[N * N];
int color[N], comp[N];
vector <int> lst[N];

inline void clear() {
	memset(color, 0, sizeof(color));
	forn(i, N)
		comp[i] = i, lst[i].clear(), lst[i].pb(i);
}

inline bool merge(int v, int u) {
	if (comp[v] == comp[u])
		return (color[v] == color[u]);
	int cv = comp[v], cu = comp[u];
	if (sz(lst[cv]) > sz(lst[cu]))
		swap(cv, cu);
	if (color[v] == color[u]) 
		forn(i, sz(lst[cv]))
			color[lst[cv][i]] = 1 - color[lst[cv][i]];
	forn(i, sz(lst[cv]))
		comp[lst[cv][i]] = cu, lst[cu].pb(lst[cv][i]);
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	forn(i, m) {
		scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].w);
		edges[i].id = i;
		edges[i].a--, edges[i].b--;
	}
	sort(edges, edges + m);
	while(q--) {
		clear();
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		bool flag = true;
		fornr(i, m) {
			if (l > edges[i].id || edges[i].id >= r)
				continue;
			if (merge(edges[i].a, edges[i].b)) {
				printf("%d\n", edges[i].w), flag = false;
				break;
			}
		}
		if (flag)
			puts("-1");
	}
	return 0;
}