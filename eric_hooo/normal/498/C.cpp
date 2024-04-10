#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;

int a[110];
int tot, n, m;
vector <int> from[110];
vector <pii> f[110];
vector <int> num[110];
int g[2010][2010];
queue <int> q;
int path[2010];

int bfs(int s, int t){
	memset(path, -1, sizeof(path));
	while (!q.empty()) q.pop();
	q.push(s), path[s] = 0;
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (int i = 0; i <= t; i++){
			if (~path[i] || g[u][i] <= 0) continue;
			path[i] = u;
			if (i == t) break;
			q.push(i);
		}
	}
	if (path[t] == -1) return -1;
	int now = t, minj = INF;
	while (now != s){
		int last = path[now];
		minj = min(minj, g[last][now]);
		now = last;
	}
	now = t;
	while (now != s){
		int last = path[now];
		g[last][now] -= minj;
		g[now][last] += minj;
		now = last;
	}
	return minj;
}

int main(){
	scanf("%d%d", &n, &m);
	tot = n + 1;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for (int j = 0; j < m; j++){
		int u, v;
		scanf("%d%d", &u, &v);
		if (u % 2 == 0) swap(u, v);
		from[u].push_back(v);
	}
	int s = 0, t = 2000;
	for (int i = 1; i <= n; i++){
//		if ((i & 1) == 0) continue;
		vector <pii> &factor = f[i];
		int x = a[i];
		for (int j = 2; j * j <= x; j++){
			if (x % j != 0) continue;
			factor.push_back(mp(j, 0));
			while (x % j == 0) x /= j, factor.back().se++;
		}
		if (x > 1) factor.push_back(mp(x, 1));
		if (i & 1) g[s][i] = INF;
		else g[i][t] = INF;
		for (int j = 0; j < factor.size(); j++){
			num[i].push_back(tot), tot++;
			if (i & 1) g[i][tot - 1] = factor[j].se;
			else g[tot - 1][i] = factor[j].se;
		}
	}
	for (int i = 1; i <= n; i++){
		vector <pii> &factor = f[i];
		vector <int> &id = num[i];
		if (i & 1){
			for (int j = 0; j < factor.size(); j++){
				int p = factor[j].fi;
				for (int k = 0; k < from[i].size(); k++){
					int to = from[i][k];
					int pos = -1;
					for (int l = 0; l < f[to].size(); l++){
						if (f[to][l].fi == p){
							pos = l;
							break;
						}
					}
					if (pos == -1) continue;
					g[id[j]][num[to][pos]] = INF;
				}
			}
		}
	}
	int ans = 0;
	while (1){
		int tmp = bfs(s, t);
		if (tmp == -1) break;
		ans += tmp;
	}
	printf("%d\n", ans);
	return 0;
}