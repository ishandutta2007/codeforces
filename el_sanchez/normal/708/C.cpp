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
const int MAXN = 400500;

int n, a, b;
vi g[MAXN];
int par[MAXN];
int used[MAXN];
int dsz[MAXN], usz[MAXN], maxsub[MAXN], maxsup[MAXN];
int ans[MAXN];

void dfs(int v) {
	used[v] = 1;
	dsz[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int w = g[v][i];
		if (used[w]) {
			swap(g[v][i], g[v].back());
			g[v].pop_back();
			par[v] = w;
			i--;
			continue;	
		} else {
			dfs(w);	
			dsz[v] += dsz[w];
		}
	}
	
	usz[v] = n + 1 - dsz[v];
}

void dfs2(int v) {
	maxsub[v] = 1;
	for (auto w: g[v]) {
		dfs2(w);
		maxsub[v] = max(maxsub[v], maxsub[w]);
	}
	
	if (dsz[v] <= n / 2)
		maxsub[v] = max(maxsub[v], dsz[v]);
}

int mx[2][MAXN];

void dfs3(int v) {
	if (g[v].empty())
		return;
		
	mx[0][0] = maxsub[g[v][0]];
	for (int i = 1; i < (int)g[v].size(); i++)
		mx[0][i] = max(mx[0][i - 1], maxsub[g[v][i]]);
	
	mx[1][(int)g[v].size() - 1] = maxsub[g[v].back()];
	for (int i = (int)g[v].size() - 2; i >= 0; i--)
		mx[1][i] = max(mx[1][i + 1], maxsub[g[v][i]]);
	
	for (int i = 0; i < (int)g[v].size(); i++) {
		int w = g[v][i];
		
		maxsup[w] = maxsup[v];
		if (i > 0)
			maxsup[w] = max(maxsup[w], mx[0][i - 1]);
		if (i < (int)g[v].size() - 1)
			maxsup[w] = max(maxsup[w], mx[1][i + 1]);
		
		if (usz[w] - 1 <= n / 2)
			maxsup[w] = max(maxsup[w], usz[w] - 1);
	}
	
	for (auto w: g[v])
		dfs3(w);
}

void getAns(int v) {
	for (auto w: g[v])
		getAns(w);
		
	int status = 0;
	int i;
	for (i = 0; i < (int)g[v].size(); i++) {
		if (dsz[g[v][i]] > n / 2) {
			status = 1;
			break;
		}
	}
	
	if (status == 0) {
		if (par[v] != -1 && usz[v] - 1 > n / 2) {
			status = 2;
		}
	}
	
	if (status == 0) {
		ans[v] = 1;	
	} else if (status == 1) {
		int w = g[v][i];
		int S = dsz[w];
		ans[v] = (maxsub[w] <= n / 2 && S - maxsub[w] <= n / 2);
	} else {
		int S = usz[v] - 1;
		//cout << v << " -> " << S << endl;
		ans[v] = (maxsup[v] <= n / 2 && S - maxsup[v] <= n / 2);
	}
}

int main() {

	scanf("%d", &n);
	forn(i, n - 1) {
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	memset(par, -1, sizeof(par));
	dfs(0);
	assert(par[0] == -1);
	forab(i, 1, n)
		assert(par[i] != -1);
	
	dfs2(0);
	
	dfs3(0);
	
	getAns(0);
	/*
	forn(i, n)
		cout << dsz[i] << ' ' << usz[i] << '\n';
		
	forn(i, n)
		cout << maxsub[i] << " \n"[i == n - 1];
	
	forn(i, n)
		cout << maxsup[i] << " \n"[i == n - 1];
	*/
	forn(i, n)
		printf("%d ", ans[i]);
	cout << '\n';
	
	return 0;
}