#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;
const int MAXN = 100500;
const int MAXK = 18;

int n, m, a, b;
vi g[MAXN];
int parent[MAXN];
int level[MAXN];
int distToRoot[MAXK][MAXN];
int ans[MAXN];

int dfs(int v, int &center, int sz = 0, int p = -1) {
	int sum = 1;
	for (auto w: g[v])
		if (w != p && level[w] == -1)
			sum += dfs(w, center, sz, v);	

	if (center == -1 && 2 * sum >= sz)
		center = v;	
	return sum;
}

void build(int v, int L = 0, int p = -1) {
	int center;
	dfs(v, center = -1, dfs(v, center));

	parent[center] = p;
	level[center] = L;

	for (auto w: g[center])
		if (level[w] == -1)
			build(w, L + 1, center);		
}

void dfs2(int v, int L, int h = 0, int p = -1) {
	distToRoot[L][v] = h;
	for (auto w: g[v])
		if (w != p && level[w] >= L) {
			dfs2(w, L, h + 1, v);	
		}
}

void upd(int c, int v) {
	while (c != -1) {
		ans[c] = min(ans[c], distToRoot[level[c]][v]);
		c = parent[c];
	}
}

int get(int c, int v) {
	if (c == -1)
		return INF;
	return min(get(parent[c], v), distToRoot[level[c]][v] + ans[c]);
}

int main() {
	
	scanf("%d%d", &n, &m);
	forn(i, n - 1) {
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	memset(level, -1, sizeof(level));
	build(0);
	forn(i, n)
		ans[i] = INF;
	forn(i, n)
		dfs2(i, level[i]);	
	/*	
	forn(i, n)
		cout << i << ' ' << level[i] << '\n';
	forn(v, n) {
		cout << "dists from " << v << ":\n";
		forn(w, n)
			cout << distToRoot[level[v]][w] << " \n"[w == n - 1];	
	}
	*/
	upd(0, 0);
	forn(i, m) {
		scanf("%d%d", &a, &b);
		b--;
		if (a == 1) {
			upd(b, b);					
		} else {
			printf("%d\n", get(b, b));	
		}
	}
	
	return 0;
}