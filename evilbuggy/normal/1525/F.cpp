#include <bits/stdc++.h>
using namespace std;

const int N = 55;
long long dp[N][N], x[N], y[N];
int n, m, k, g[N][N], ng[N][N], match[N], vis[N], rem[N], mem[N][N];
vector<int> opBefore[N];

bool dfs(int v){
	if(vis[v])return false;
	vis[v] = true;
	for(int i = 1; i <= n; i++){
		if(g[v][i] == 0)continue;
		if(match[i] == -1 || dfs(match[i])){
			match[i] = v;
			return true;
		}
	}
	return false;
}

int compute(){
	memset(match, -1, sizeof(match));
	for(int i = 1; i <= n; i++){
		memset(vis, 0, sizeof(vis));
		dfs(i);
	}
	int ret = 0;
	for(int i = 1; i <= n; i++){
		if(match[i] != -1)ret++;
	}
	return ret;
}

int get(int total){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			ng[i][j] = g[i][j];
		}
	}
	for(int v = 1; v <= n; v++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				g[i][j] = ng[i][j];
			}
		}
		for(int i = 1; i <= n; i++){
			g[v][i] = 0;
		}
		int tmp = compute();
		if(tmp < total)return v;
	}
	for(int v = 1; v <= n; v++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				g[i][j] = ng[i][j];
			}
		}
		for(int i = 1; i <= n; i++){
			g[i][v] = 0;
		}
		int tmp = compute();
		if(tmp < total)return -v;
	}
	assert(false);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	memset(g, 0, sizeof(g));
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u][v] = 1;
	}
	int total = compute();
	for(int i = 1; i <= k; i++){
		cin >> x[i] >> y[i];
	}
	memset(rem, 0, sizeof(rem));
	deque<int> ops;
	for(int i = 1; i <= k; i++){
		while(n - total <= i){
			ops.push_back(get(total));
			total--;
			rem[i]++;
		}
	}
	for(int i = n; i >= 1; i--){
		rem[i] += rem[i + 1];
	}
	memset(dp, 0xaf, sizeof(dp));
	dp[n + 1][0] = 0;
	for(int i = n; i >= 1; i--){
		for(int j = 0; j <= rem[i]; j++){
			for(int k = 0; j + k <= rem[i]; k++){
				long long val = dp[i + 1][j] + max(0LL, x[i] - k*y[i]);
				if(val > dp[i][j + k]){
					dp[i][j + k] = val;
					mem[i][j + k] = k;
				}
			}
		}
	} 
	int cnt = rem[1];
	for(int i = 1; i <= n; i++){
		int m = mem[i][cnt];
		for(int j = 0; j < m; j++){
			opBefore[i].push_back(ops.front());
			ops.pop_front();
		}
		reverse(opBefore[i].begin(), opBefore[i].end());
		cnt -= m;
	}
	

	vector<int> ans;
	for(int i = 1; i <= k; i++){
		for(auto x : opBefore[i]){
			ans.push_back(x);
		}
		ans.push_back(0);
	}
	cout << ans.size() << '\n';
	for(auto x : ans){
		cout << x << " ";
	}
	cout << '\n';

	return 0;
}