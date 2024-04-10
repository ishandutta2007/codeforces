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
const int MAXN = 1000500;

int n;
bool a[MAXN], s[MAXN], any;
vi g[MAXN];
int par[MAXN], pos[MAXN];
pii h[MAXN];
vi path;
vi add[MAXN];

void dfs(int v, int p = -1, int ch = 0) {
	pos[v] = (int)path.size();
	a[v] ^= 1;
	path.pb(v);
	h[v] = {ch, v};
	for (auto w: g[v]) {
		if (w == p)
			continue;
			
		par[w] = v;
		dfs(w, v, ch + 1);
		path.pb(v);
		a[v] ^= 1;
	}
}

int main() {
	
	scanf("%d", &n);
	any = 1;
	forn(i, n) {
		int k;
		scanf("%d", &k);
		a[i] = (k == 1 ? 1 : 0);
		s[i] = a[i];
		any |= !a[i];	
	}
	
	if (!any) {
		cout << 1 << '\n';
		return 0;	
	}
	
	forn(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);	
	}
	
	dfs(0);
	
	sort(h, h + n);
	
	for (int i = n - 1; i > 0; i--) {
		int v = h[i].Y;
		//cout << v << ' ' << h[i].X << endl;
		assert(v != 0);
		if (!a[v]) {
			add[pos[v]].pb(par[v]);
			add[pos[v]].pb(v);
			a[v] ^= 1;
			a[par[v]] ^= 1;
		}
	}
	
	if (a[0]) {
		path.pop_back();
		a[0] ^= 1;	
	}
	/*
	forn(i, n)
		cout << s[i] << " \n"[i == n - 1];
	*/
	for (int i = 0; i < (int)path.size(); i++) {
		printf("%d ", path[i] + 1);
		s[path[i]] ^= 1;
		for (auto v: add[i]) {
			printf("%d ", v + 1);	
			s[v] ^= 1;
		}
	}
	/*
	cout << '\n';
	forn(i, n)
		cout << s[i] << " \n"[i == n - 1];
	*/
	return 0;
}