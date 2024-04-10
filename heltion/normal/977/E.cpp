#include<bits/stdc++.h>
using namespace std;
vector<int> G[200010];
int d[200010];
bool vis[200010];
int ans;
bool flag;
void DFS(int u){
	vis[u] = true;
	if(d[u] != 2) flag = false;
	for(int v: G[u]) if(vis[v] == false) DFS(v);
}
int main(){
 	int n, m;
 	scanf("%d %d", &n, &m);
 	for(int i = 0; i < m; i += 1){
 		int u, v;
 		scanf("%d %d", &u, &v);
 		d[u] += 1;
 		d[v] += 1;
 		G[u].push_back(v);
 		G[v].push_back(u);
	}
	for(int i = 1; i <= n; i += 1) if(vis[i] == false){
		flag = true;
		DFS(i);
		if(flag) ans += 1;
	}
	printf("%d\n", ans);
}