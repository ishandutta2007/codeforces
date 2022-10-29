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

int n, m;
vi g[MAXN];
int used[MAXN];
vi ans[3];

bool dfs(int v, int id) {
	used[v] = id;
	for (auto w: g[v])
		if (used[w] == 0) {
			if (!dfs(w, 3 - id))
				return 0;
		} else if (used[w] == id)
			return 0;
			
	return 1;
}

int main() {
	
	scanf("%d%d", &n, &m);
	forn(i, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	forn(i, n)
		if (used[i] == 0)
			if (!dfs(i, 1)) {
				cout << -1 << '\n';
				return 0;
			}
			
	forn(i, n) {
		assert(used[i] != 0);
		ans[used[i]].pb(i);
	}
	
	forab(i, 1, 3) {
		printf("%d\n", ans[i].size());
		forn(j, ans[i].size())
			printf("%d%c", ans[i][j] + 1, " \n"[j == (int)ans[i].size() - 1]);	
	}
	
	
	return 0;
}