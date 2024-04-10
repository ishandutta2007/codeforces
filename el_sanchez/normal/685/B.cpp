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
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;
const int MAXN = 300500;

int n, q;
int S[MAXN], mx[MAXN];
int listId[MAXN], ans[MAXN];
vi g[MAXN];
vector<pii> L[MAXN];

void dfs(int v) {
	S[v] = 1;
	mx[v] = 0;
	
	for (auto w: g[v]) {
		dfs(w);	
		S[v] += S[w];
		mx[v] = max(mx[v], S[w]);
	}
	
	int need = S[v] / 2;
	
	if (mx[v] <= need) {
		ans[v] = v;
		listId[v] = v;		
		L[listId[v]].pb({mx[v], v});
	} else {
		int w = -1;
		for (auto z: g[v])
			if (S[z] == mx[v]) {
				w = z;
				break;
			}
			
		assert(w != -1);
		listId[v] = listId[w];
		L[listId[v]].pb({mx[v], v});
		
		pii pp = {need + 1, -INF};
		int it = lower_bound(all(L[listId[v]]), pp) - L[listId[v]].begin();
		it--;
		
		assert(it >= 0);
		ans[v] = L[listId[v]][it].Y;
	}
}

int main() {

	scanf("%d%d", &n, &q);
	forn(i, n - 1) {
		int p;
		scanf("%d", &p);
		p--;
		g[p].pb(i + 1);	
	}
	
	dfs(0);
	
	forn(i, q) {
		int v;
		scanf("%d", &v);
		v--;

		printf("%d\n", ans[v] + 1);	
	}
	
	return 0;
}