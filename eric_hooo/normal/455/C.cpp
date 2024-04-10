#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int fa[300010], maxd[300010], path[300010];
int down[300010], up[300010], vis[300010];
int maxj = 0;
vector <int> from[300010];
vector <int> all;

void dfs_down(int x, int last){
	vis[x] = 1, down[x] = 0;
	all.push_back(x);
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		if (v == last) continue;
		dfs_down(v, x);
		down[x] = max(down[x], down[v] + 1);
	}
}

void dfs_up(int x, int last){
	int max1 = -1, max2 = -1, pos = -1;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		if (v == last) continue;
		if (max1 == -1 || down[v] > max1) max2 = max1, max1 = down[v], pos = v;
		else if (max2 == 0 || down[v] > max2) max2 = down[v];
	}
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		if (v == last) continue;
		up[v] = max(up[x] + 1, (v == pos ? (max2 == -1 ? 0 : max2 + 2) : max1 + 2));
		dfs_up(v, x);
	}
	if (max1 == -1 || up[x] > max1) max2 = max1, max1 = up[x];
	else if (max2 == 0 || up[x] > max2) max2 = up[x];
	maxj = max(maxj, max1 + (max2 == -1 ? 0 : max2));
}

void init(){
	for (int i = 1; i <= n; i++){
		if (vis[i]) continue;
		all.clear(), dfs_down(i, i);
		up[i] = 0, maxj = 0, dfs_up(i, i);
		int minj = 0x3f3f3f3f, pos = -1;
		for (int j = 0; j < all.size(); j++){
			int x = all[j], val = max(up[x], down[x]);
			if (minj > val) minj = val, pos = x;
		}
		for (int j = 0; j < all.size(); j++){
			int x = all[j];
			fa[x] = pos;
		}
		maxd[pos] = max(up[pos], down[pos]);
		path[pos] = maxj;
	}
}

int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y){
	x = find(x), y = find(y);
	if (x == y) return ;
	if (maxd[x] < maxd[y]) swap(x, y);
	fa[y] = x;
	path[x] = max(path[x], maxd[x] + maxd[y] + 1);
	maxd[x] = max(maxd[x], maxd[y] + 1);
}

int main(){
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; i++){
		int u, v; scanf("%d%d", &u, &v);
		from[u].push_back(v);
		from[v].push_back(u);
	}
	init();
	while (q--){
		int op, x, y;
		scanf("%d", &op);
		if (op == 1){
			scanf("%d", &x);
			printf("%d\n", path[find(x)]);
		} else {
			scanf("%d%d", &x, &y);
			merge(x, y);
		}
	}
	return 0;
}