#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <int> from[10010], num[10010];
int vis[10010], sum[10010], fa[10010][20], deep[10010], fa_id[10010];
int cnt[10010], sum1[10010], cnt1[10010];
int n, m, all;
queue <pii> q;

void dfs(int x, int last){
	vis[x] = 1, fa[x][0] = last;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		if (vis[v]) continue;
		deep[v] = deep[x] + 1, fa_id[v] = num[x][i], dfs(v, x);
	}
}

void color(int x){
	vis[x] = 1;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		if (vis[v]){
			if (deep[x] > deep[v] && (deep[x] - deep[v]) % 2 == 0){
				sum[x]++, sum[v]--, cnt[num[x][i]]++, all++;
//				cout << "  " << x << " " << v << " " << LCA(x, v) << endl;
//				cout << "  deep:" << deep[x] << " " << deep[v] << " " << deep[LCA(x, v)] << endl;
			}
			else if (deep[x] > deep[v] && deep[x] - deep[v] != 1) sum[x]--, sum[v]++;
		}
		else color(v), sum[x] += sum[v];
	}
	cnt[fa_id[x]] += sum[x];
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		int u, v; scanf("%d%d", &u, &v);
		from[u].push_back(v), from[v].push_back(u);
		num[u].push_back(i), num[v].push_back(i);
	}
	for (int i = 1; i <= n; i++){
		if (!vis[i]) fa_id[i] = m + 1, dfs(i, i);
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++){
		if (!deep[i]) color(i);
	}
	vector <int> ans;
//	cout << all << endl;
	if (!all){
		printf("%d\n", m);
		for (int i = 0; i < m; i++){
			printf("%d ", i + 1);
		}
		printf("\n");
		return 0;
	}
//	cout << all << endl;
	for (int i = 0; i < m; i++){
		if (cnt[i] == all) ans.push_back(i + 1);
	}
//	cout << endl;
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}