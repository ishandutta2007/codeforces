#include <bits/stdc++.h>
using namespace std;

int a[410];
int g[410][410];
int vis[410], path[410];
queue <int> q;

int prime(int x){
	for (int i = 2; i * i <= x; i++){
		if (x % i == 0) return 0;
	}
	return 1;
}

int bfs(int s, int t){
	for (int i = 0; i <= t; i++){
		vis[i] = 0;
	}
	while (!q.empty()) q.pop();
	q.push(s), vis[s] = 1;
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (int i = 0; i <= t; i++){
			if (vis[i] || g[u][i] <= 0) continue;
			vis[i] = 1, path[i] = u;
			if (i == t) break;
			q.push(i);
		}
	}
	if (!vis[t]) return 0;
	int now = t, minj = 0x3f3f3f3f;
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
	int n;
	scanf("%d", &n);
	int s = 0, t = n + n + 1;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	int tot = 0;
	for (int i = 1; i <= n; i++){
		tot += 1 - a[i] % 2;
		for (int j = 1; j <= n; j++){
			if (a[i] % 2 == 1 && a[j] % 2 != 1 && prime(a[i] + a[j])) g[i][j + n] = 1;
		}
	}
	for (int i = 1; i <= n; i++){
		if (a[i] % 2) g[s][i] = 2;
		else g[i + n][t] = 2;
	}
	int flow = 0;
	while (1){
		int tmp = bfs(s, t);
		if (!tmp) break;
		flow += tmp;
	}
	if (flow != tot * 2){
		printf("Impossible\n");
		return 0;
	}
//	for (int i = 0; i <= n + n + 1; i++){
//		for (int j = 0; j <= n + n + 1; j++){
//			printf("%d ", g[i][j]);
//		}
//		printf("\n");
//	}
//											return 0;
	vector <vector <int> > ans;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++){
		if (vis[i]) continue;
		ans.push_back({});
		int now = i, last = now, pd = 1;
		while (pd || now != i){
//			cout << "  now:" << now << endl;
//			cout << "  last:" << last << endl; 
			pd = 0;
			ans.back().push_back(now);
			vis[now] = 1;
//			cout << "  now:" << now << endl;
			for (int j = 1; j <= n; j++){
				if (a[now] % 2 == a[j] % 2 || j == last) continue;
//					cout << "    j:" << j << endl;
//					cout << "    g:" << g[now + n][j] << endl;
				if (a[now] % 2 == 1 && g[j + n][now] || a[j] % 2 == 1 && g[now + n][j]){
					last = now, now = j;
					break;
				}
			}
		}
	}
	if (ans.size() > n / 3){
		printf("Impossible\n");
		return 0;
	}
	for (int i = 0; i < ans.size(); i++){
		if (ans[i].size() < 3){
			printf("Impossible\n");
			return 0;
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i].size());
		for (int j = 0; j < ans[i].size(); j++){
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}