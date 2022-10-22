#include <bits/stdc++.h>

using namespace std;

int n, m;
int v[1005];
vector<int> adj[1005];
bool vis[1005];
int dis[1005];

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i < n; ++i){
		scanf("%d", v+i);
	}
	for(int i=0; i < m; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		--x;--y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int ans=0;
	for(int i=0; i < n; ++i){
		int best=-1, bestI=-1;
		for(int j=0; j < n; ++j){
			if(vis[j])
				continue;
			if(v[j] > best){
				best=v[j];
				bestI=j;
			}
		}
		vis[bestI]=1;
		for(int j=0; j < adj[bestI].size(); ++j){
			if(vis[adj[bestI][j]])
				continue;
			ans += v[adj[bestI][j]];
		}
	}
	printf("%d\n", ans);
}