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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;
    
int n;
int a[MAXN];
ll path[MAXN], arc[MAXN], maxArc[MAXN], keep[MAXN], ans[MAXN];
ll res;
vi g[MAXN];

void dfs(int v, int p) {
	for (auto w: g[v])
		if (w != p) {
			dfs(w, v);
			
			ans[v] = max(ans[v], arc[v] + arc[w]);
			ans[v] = max(ans[v], keep[v] + path[w]);
			ans[v] = max(ans[v], path[v] + keep[w]);
				
			keep[v] = max(keep[v], maxArc[v] + path[w] + a[v]);
			keep[v] = max(keep[v], path[v] + arc[w]);
			keep[v] = max(keep[v], keep[w] + a[v]);
			
			ans[v] = max(ans[v], keep[v]);
			
			maxArc[v] = max(maxArc[v], arc[w]);
			
			ans[v] = max(ans[v], maxArc[v]);
			
			arc[v] = max(arc[v], path[v] + path[w]);
			arc[v] = max(arc[v], arc[w]);
			
			ans[v] = max(ans[v], arc[v]);
			
			path[v] = max(path[v], path[w] + a[v]);
			
			ans[v] = max(ans[v], path[v]);
		}
		
	path[v] = max(path[v], (ll)a[v]);
	arc[v] = max(arc[v], (ll)a[v]);
	keep[v] = max(keep[v], (ll)a[v]);
	ans[v] = max(ans[v], (ll)a[v]);
		
	res = max(res, ans[v]);
	/*
	cout << v << ":\n";
	db(path[v]);
	db(arc[v]);
	db(keep[v]);
	db(ans[v]);
	*/
}

int main() {

	scanf("%d", &n);
	forn(i, n)
		scanf("%d", &a[i]);
		
	forn(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	res = 0;
	dfs(0, -1);
	cout << res << '\n';
	
	return 0;	
}