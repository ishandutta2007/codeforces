#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100005];
int x[100005];
vector<int> ans;
bool vis[100005];

void bfs(int node, int parent){
	if(vis[node])
		return;
	ans.push_back(node);
	x[node]^=1;
	vis[node]=1;
	for(int i=0; i < adj[node].size(); ++i){
		bfs(adj[node][i], node);
	}
	if(parent == -1){
		if(x[node]){
			ans.pop_back();
			x[node]^=1;
		}
		return;
	}
	if(x[node]){
		ans.push_back(parent);
		ans.push_back(node);
		x[node]=0;
	}
	else{
		x[parent]^=1;
	}
	ans.push_back(parent);
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i < m; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		--a;--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int non1=-1;
	for(int i=0; i < n; ++i){
		scanf("%d", x+i);
		if(x[i])
			non1=i;
	}
	if(non1 == -1){
		printf("0\n");
		return 0;
	}
	bfs(non1, -1);
	bool anyBad=0;
	for(int i=0; i < n; ++i)
		if(x[i])
			anyBad=1;
	if(anyBad){
		printf("-1\n");
		return 0;
	}
	printf("%d\n", ans.size());
	for(int i=0; i < ans.size(); ++i)
		printf("%d ", ans[i]+1);
	printf("\n");
}