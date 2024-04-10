#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
vector<int> G[maxn];
int son[maxn], ans;
void dfs(int u, int f){
	son[u] = 1;
	for(int v : G[u]) if(v != f){
		dfs(v, u);
		son[u] += son[v];
		if(son[v] % 2 == 0) ans += 1;
	}
}
int main(){
	int n;
	scanf("%d", &n);
	if(n & 1) return printf("-1"), 0;
	for(int i = 1; i < n; i += 1){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	printf("%d\n", ans);
}