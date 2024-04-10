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

const int N = 1e6 + 100;

int a[N], sum[N], m, ans[N];
vector <pii> q[N];
vector <int> tree;
map <int, int> last;

void add(int v, int l, int r, int pos, int x) {
	if (pos < l || r <= pos)
		return;
	if (l == r - 1) {
		tree[v] ^= x;
		return;
	}
	add(2 * v, l, (l + r) / 2, pos, x);
	add(2 * v + 1, (l + r) / 2, r, pos, x);
	tree[v] = tree[2 * v] ^ tree[2 * v + 1];
}

int get(int v, int l, int r, int a, int b) {
	if (a <= l && r <= b)
		return tree[v];
	if (r <= a || b <= l)
		return 0;
	return get(2 * v, l, (l + r) / 2, a, b) ^ get(2 * v + 1, (l + r) / 2, r, a, b);
}

int main() {
	int n; scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &a[i]);
		sum[i + 1] = sum[i] ^ a[i];
	}
	int w; cin >> w;
	forn(i, w) {
		int l, r;
		scanf("%d%d", &l, &r);
		q[r - 1].pb(mp(l - 1, i));
	}
	m = 1;
	while(m < n)
		m *= 2;
	tree.resize(2 * m, 0);
	forn(i, n) {
		if (last[a[i]]) {
			add(1, 0, m, last[a[i]] - 1, a[i]);
		} 
		last[a[i]] = i + 1;
		add(1, 0, m, i, a[i]);
		forn(j, sz(q[i])) {
			int l = q[i][j].fst,  id = q[i][j].snd;
			ans[id] = sum[l] ^ sum[i + 1];
			ans[id] ^= get(1, 0, m, l, i + 1);
		}
	}
	forn(i, w)
		printf("%d\n", ans[i]);
	return 0;
}