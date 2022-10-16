#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


vector< pair<int,int> > adj[110000];
vector<int> moves[2];
vector< int > nadj[110000];
int p[110000];
int s[110000];
int comp[110000];
int compsz[310000];
int tk[310000];
int n,m;

int find(int x) {
	if (p[x]==x) return x;
	return p[x] = find(p[x]);
}

void link(int a, int b) {
	int x = find(a), y = find(b);
	if (x == y) return;
	s[y] += s[x];
	p[x]=y;
}

bool dfs(int v, int cc) {
	if (comp[v] != -1 && comp[v] != cc) return false;
	if (comp[v] == cc) return true;

	comp[v] = cc;
	compsz[cc] += s[v];
	for (int x : nadj[v]) {
		if (!dfs(x, cc^1)) return false;
	}

	return true;
}

void solve() {
	scanf("%d %d", &n, &m);
	REP(i,m) {
		int u,v; char c;
		scanf("%d %d %c", &u, &v, &c); u--; v--;
		c = (c == 'B');
		adj[u].push_back( {v, c} );
		adj[v].push_back( {u, c} );
	}

	int ans = 1000000000;

	for (int targ = 0; targ < 2; targ++) {
		REP(i,n) {p[i] = i; s[i] = 1; comp[i] = -1; nadj[i].clear();}

		REP(i,n) {
			for (pair<int,int> p : adj[i]) if (p.second == targ) link(i, p.first);
		}

		REP(i,n) {
			for (pair<int,int> p : adj[i]) if (p.second != targ) {
				nadj[find(i)].push_back(find(p.first));
			}
		}

		int cc = 0;
		bool ok = true;
		REP(i,n) if (find(i)==i && comp[i] == -1) {
			compsz[cc] = compsz[cc+1] = 0;
			tk[cc] = tk[cc+1] = 0;
			if (!dfs(i, cc)) ok = false;
			cc += 2;
		} 

		if (ok) {
			for (int i = 0; i < cc; i+=2) {
				if (compsz[i+1]) {
					if (compsz[i] < compsz[i+1]) tk[i] = 1;
					else tk[i+1] = 1;
				}
			}
			REP(i,n) if (tk[comp[find(i)]]) moves[targ].push_back(i);
			
			ans = min(ans, (int)moves[targ].size());
		}
	}

	if (ans == 1000000000) printf("-1\n");
	else {
		printf("%d\n", ans);
		if (moves[1].size() == ans) swap(moves[0],moves[1]);
		for (int x : moves[0]) printf("%d ", x+1);
		printf("\n");
	}
}

int main() {
    solve();
}