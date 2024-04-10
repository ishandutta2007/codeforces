#include <bits/stdc++.h>
using namespace std;

const int N = 405;
int g[N][N], dist[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	memset(g, 0, sizeof(g));
	memset(dist, -1, sizeof(dist));
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		g[u][v] = g[v][u] = 1;
	}
	if(g[1][n]){
		queue<int> q;
		dist[1] = 0;
		q.push(1);
		while(!q.empty()){
			int v = q.front(); q.pop();
			for(int u = 1; u <= n; u++){
				if(g[v][u] == 0 && dist[u] == -1){
					dist[u] = dist[v] + 1;
					q.push(u);
				}
			}
		}
		cout << dist[n] << '\n';
	}else{
		queue<int> q;
		dist[1] = 0;
		q.push(1);
		while(!q.empty()){
			int v = q.front(); q.pop();
			for(int u = 1; u <= n; u++){
				if(g[v][u] == 1 && dist[u] == -1){
					dist[u] = dist[v] + 1;
					q.push(u);
				}
			}
		}
		cout << dist[n] << '\n';
	}

	return 0;
}