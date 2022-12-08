#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1010;
const int maxm = 1010;
const int INF = 1010000000;

vector<int> adj[maxn];
bool pathexists[maxn][maxn];

int n, m, s, t;

vector<int> bfs(int st) {
	bool vis[maxn];
	vector<int> dist(maxn, INF);
	for(int i = 1;i <= n;i++) {
		vis[i] = false;
	}
	
	queue<int> tovis;
	tovis.push(st);
	vis[st] = true;
	dist[st] = 0;
	
	while(!tovis.empty()) {
		int cnode = tovis.front();
		vis[cnode] = true;
		tovis.pop();
		
		for(int j = 0;j < adj[cnode].size();j++) {
			int onode = adj[cnode][j];
			
			if(!vis[onode]) {
				vis[onode] = true;
				tovis.push(onode);
				dist[onode] = dist[cnode]+1;
			}
		}
		
	}
	
	return dist;
	
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			pathexists[i][j] = false;
		}
	}
	
	for(int i = 0;i < m;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		
		adj[a].push_back(b);
		adj[b].push_back(a);
		pathexists[a][b] = pathexists[b][a] = true;
	}
	
	vector<int> froms = bfs(s);
	vector<int> frome = bfs(t);
	
	int original = froms[t];
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = i+1;j <= n;j++) {
			if (pathexists[i][j])
				continue;
			if ( ( froms[i]+frome[j]+1 >= original) && ( frome[i]+froms[j]+1 >= original) )
				ans++;
		}
	}
	printf("%d\n", ans);
	
	return 0;
}