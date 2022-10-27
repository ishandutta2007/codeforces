#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int M = 500005;
const int mod = 1000000007;

vector<int> g[N];
vector<pair<int, int> > ng[M];
int iter, x[N], y[N], dig[N], len[N], vis[M], ans[M];

inline void addEdges(int u, int v, int x){
	while(dig[x] > 1){
		ng[iter].emplace_back(x%10, v);
		v = iter; iter++;
		x /= 10;
	}
	ng[u].emplace_back(x, v);
}

void dfs(vector<int> vec, int cur){
	vector<vector<int> > go(10);
	for(int v : vec){
		if(vis[v])continue;
		ans[v] = cur; vis[v] = 1;
		for(auto x : ng[v]){
			if(!vis[x.second]){
				go[x.first].emplace_back(x.second);
			}
		}
	}
	cur = 10LL*cur%mod;
	for(int i = 0; i < 10; i++){
		if(!go[i].empty())dfs(go[i], cur);
		cur++; if(cur == mod)cur = 0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	dig[0] = 0;
	for(int i = 1; i < N; i++){
		dig[i] = dig[i/10] + 1;
	}
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> x[i] >> y[i];
		g[x[i]].emplace_back(i);
		g[y[i]].emplace_back(i);
	}
	memset(vis, 0, sizeof(vis));
	memset(len, 0x3f, sizeof(len));
	priority_queue<pair<int, int> > pq;
	pq.push({0, 1}); len[1] = 0;
	while(!pq.empty()){
		int v = pq.top().second; pq.pop();
		if(vis[v])continue; vis[v] = 1;
		for(int i : g[v]){
			int u = x[i]^y[i]^v;
			if(len[u] > len[v] + dig[i]){
				len[u] = len[v] + dig[i];
				pq.push({-len[u], u});
			}
		}
	}
	iter = n + 1;
	for(int i = 1; i <= m; i++){
		if(len[x[i]] + dig[i] == len[y[i]]){
			addEdges(x[i], y[i], i);
		}
		if(len[y[i]] + dig[i] == len[x[i]]){
			addEdges(y[i], x[i], i);
		}
	}
	memset(vis, 0, sizeof(vis));
	ans[1] = 0; dfs(vector<int>({1}), 0);
	for(int i = 2; i <= n; i++){
		cout << ans[i] << '\n';
	}

	return 0;
}