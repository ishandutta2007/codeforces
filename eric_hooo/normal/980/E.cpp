#include <bits/stdc++.h>
using namespace std;

vector <int> from[1000010];
int n, k;
int deep[1000010];
int fa[1000010][30];
int vis[1000010];

void dfs(int x, int last){
	fa[x][0] = last;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		if (v == last) continue;
		deep[v] = deep[x] + 1;
		dfs(v, x);
	}
}

void get_f(){
	for (int j = 1; j < 30; j++){
		for (int i = 1; i <= n; i++){
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	}
}

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++){
		int u, v; scanf("%d%d", &u, &v);
		from[u].push_back(v);
		from[v].push_back(u);
	}
	dfs(n, n), get_f();
	int now = 1;
	vis[n] = 1;
	k = n - k;
	for (int i = n - 1; i >= 1; i--){
		if (vis[i]) continue;
		int x = i, cnt = 1;
		for (int j = 29; j >= 0; j--){
			if (!vis[fa[x][j]]) x = fa[x][j], cnt += (1 << j); 
		}
		if (now + cnt > k) continue;
//		cout << "i:" << i << " " << cnt << endl;
		now += cnt;
		x = i;
		while (!vis[x]){
			vis[x] = 1, x = fa[x][0];
		}
	}
	for (int i = 1; i <= n; i++){
		if (!vis[i]) printf("%d ", i);
	}
	printf("\n");
	return 0;
}