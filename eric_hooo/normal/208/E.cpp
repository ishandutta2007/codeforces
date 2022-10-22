#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <int> from[100010];
int l[100010], r[100010], size[100010], deep[100010];
int cnt = 0;
vector <pii> q;
vector <int> order, path;
vector <int> all[100010];
vector <pii> add[100010];
int tot[100010], ans[100010];

void dfs(int x){
	l[x] = cnt++, size[x] = 1;
	order.push_back(x);
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		deep[v] = deep[x] + 1, dfs(v);
		size[x] += size[v];
	}
	r[x] = l[x] + size[x] - 1;
}

void dfs2(int x){
	path.push_back(x);
	for (int i = 0; i < all[x].size(); i++){
		int id = all[x][i];
		if ((int)path.size() - q[id].se - 1 <= 0) continue;
		int fa = path[path.size() - q[id].se - 1];
		add[l[fa]].push_back(mp(id, -1));
		add[r[fa]].push_back(mp(id, 1));
	}
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		dfs2(v);
	}
	path.pop_back();
}

int main(){
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		int x; scanf("%d", &x);
		from[x].push_back(i);
	}
	dfs(0);
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++){
		int x, p; scanf("%d%d", &x, &p);
		q.push_back(mp(x, p));
		all[x].push_back(i);
	}
	dfs2(0);
	for (int i = 1; i < cnt; i++){
		int x = order[i];
		tot[deep[x]]++;
		for (int j = 0; j < add[i].size(); j++){
			int id = add[i][j].fi, p = add[i][j].se;
			ans[id] += tot[deep[q[id].fi]] * p;
		}
	}
	for (int i = 0; i < m; i++){
		printf("%d ", max(ans[i] - 1, 0));
	}
	printf("\n");
	return 0;
}