#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 200500;
                                     
int n, u, v, ch;
int used[MAXN], leaves[MAXN], leaf[MAXN], lex[MAXN];
vi g[MAXN];
int ans[2];

void dfs0(int v) {
	used[v] = 1;
	
	bool f = 1;
	forn(i, g[v].size()) {
		if (used[g[v][i]]) {
			swap(g[v][i], g[v].back());
			g[v].pop_back();
			i--;
		} else {
			dfs0(g[v][i]);
			leaves[v] += leaves[g[v][i]];
			f = 0;	
		}
	}
	
	if (f) {
		leaves[v] = 1;
		leaf[v] = 1;
	}
}

vector<pii> lexs;

void dfs(int v, int h) {
	used[v] = 1;
	if (leaves[v] == 1) {
		lex[v] = 0;
		return;
	}
	
	for (auto w: g[v]) {
		assert(!used[w]);
		dfs(w, h ^ 1);	
	}
	
	if (ch == 0) {
		if (h == 0) {
			int mind = INF;
			assert(g[v].size() > 0);
			for (auto w: g[v]) {
				mind = min(mind, leaves[w] - 1 - lex[w]);	
			}
			lex[v] = leaves[v] - 1 - mind;
		} else {
			lex[v] = 0;
			for (auto w: g[v])
				lex[v] += lex[w];
			}
	} else {
		if (h == 1) {
			int mind = INF;
			assert(g[v].size() > 0);
			for (auto w: g[v]) {
				mind = min(mind, lex[w]);	
			}
			lex[v] = mind;
		} else {
			lex[v] = leaves[v] - 1;
			for (auto w: g[v])
				lex[v] -= leaves[w] - 1 - lex[w];
		}
	}
}

int main() {

    cin >> n;
    forn(i, n - 1) {
    	scanf("%d%d", &u, &v);
    	u--, v--;
    	g[u].pb(v);
    	g[v].pb(u);	
    }
    
    dfs0(0);
    for (ch = 0; ch < 2; ch++) {
    	memset(used, 0, sizeof(used));
    	dfs(0, 0);	
    	ans[ch] = lex[0] + 1;
    }    	
    
    forn(i, 2)
    	cout << ans[i] << ' ';
    						
	return 0;
}