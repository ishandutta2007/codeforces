#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

vector<int> adj[100005];
bool init[100005], goal[100005], changed[100005];
int parent[100005];

vector<int> ans;

void dfs(int node){
	bool c=0;
	if(parent[node] == -1)
		c=0;
	else{
		int p=parent[node];
		p=parent[p];
		if(p != -1)
			c=(init[p]!=goal[p]);
	}
	if(c^init[node]^goal[node])
		ans.push_back(node);
	for(int i=0; i < adj[node].size(); ++i){
		int to=adj[node][i];
		if(to != parent[node]){
			parent[to]=node;
		dfs(to);
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n-1; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		--a;--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0; i < n; ++i){
		int a;
		scanf("%d", &a);
		init[i]=a;
		changed[i]=0;
	}
	for(int i=0; i < n; ++i){
		int a;
		scanf("%d", &a);
		goal[i]=a;
	}
	parent[0]=-1;
	dfs(0);
	printf("%d\n", ans.size());
	for(int i=0; i < ans.size(); ++i)
		printf("%d\n", ans[i]+1);
	return 0;
}