#include<bits/stdc++.h>
#define maxn 240000
using namespace std;
vector<int> G[maxn * 2];
bool vis[maxn * 2];
void dfs(int u){
	vis[u] = true;
	for(int v: G[u])
		if(vis[v] == false) dfs(v);
}
int main(){
	int n, m, q, ans = 0;
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 0; i < q; i += 1){
		int r, c;
		scanf("%d %d", &r, &c);
		G[r].push_back(n + c);
		G[n + c].push_back(r);
	}
	for(int i = 1; i <= n + m; i += 1) if(vis[i] == false){
		ans += 1;
		dfs(i);
	}
	printf("%d", ans - 1);
}