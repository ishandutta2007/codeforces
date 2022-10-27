#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> pli;

const int N = 605;
const int M = N*N;

vector<int> g[N];
long long dist[N], ans[N][N], uwu[N];
int rem[N + N], a[M], b[M], c[M], d[M], vis[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < N + N; i++){
		rem[i] = i%n;
	}
	for(int i = 1; i <= m; i++){
		cin >> a[i] >> b[i] >> c[i];
		g[a[i]].push_back(i);
	}
	for(int i = 0; i < n; i++){
		priority_queue<pli, vector<pli>, greater<pli> > pq;
		memset(vis, 0, sizeof(vis));
		memset(dist, 0x7f, sizeof(dist));
		pq.push({0, i});
		dist[i] = 0;
		while(!pq.empty()){
			int u = pq.top().second; pq.pop();
			if(vis[u])continue;
			vis[u] = 1;
			for(int j = 0; j < n; j++){
				uwu[j] = 1e18;
			}
			int t = dist[u]%n;
			for(int ind : g[u]){
				int nu = rem[t + b[ind]];
				uwu[nu] = min(uwu[nu], dist[u] + c[ind]);
			}
			for(int j = 0; j < 3; j++){
				for(int k = 0; k + 1 < n; k++){
					uwu[k + 1] = min(uwu[k + 1], uwu[k] + 1);
				}
				uwu[0] = min(uwu[0], uwu[n - 1] + 1);
			}
			for(int j = 0; j < n; j++){
				if(uwu[j] < dist[j]){
					dist[j] = uwu[j];
					pq.push({dist[j], j});
				}
			}
		}
		for(int j = 0; j < n; j++){
			ans[i][j] = dist[j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}