#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> g[N];
vector<string> ans;
int a[N], b[N], dist[N];

void dfs(int i, int n, int k, string &str){
	if(i == n + 1){
		ans.emplace_back(str);
		return;
	}
	for(auto ind : g[i]){
		str[ind] = '1';
		dfs(i + 1, n, k, str);
		str[ind] = '0';
		if(ans.size() == k)break;
	}	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		cin >> a[i] >> b[i];
		g[a[i]].emplace_back(i);
		g[b[i]].emplace_back(i);
	}
	memset(dist, 0x3f, sizeof(dist));
	queue<int> qu;
	dist[1] = 0;
	qu.push(1);
	while(!qu.empty()){
		int v = qu.front(); qu.pop();
		for(int i : g[v]){
			int u = a[i]^b[i]^v;
			if(dist[u] > dist[v] + 1){
				dist[u] = dist[v] + 1;
				qu.push(u);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		vector<int> vec;
		for(int j : g[i]){
			int x = a[j]^b[j]^i;
			if(dist[x] + 1 == dist[i]){
				vec.emplace_back(j);
			}
		}
		g[i] = vec;
	}
	string str(m, '0');
	dfs(2, n, k, str);
	cout << ans.size() << '\n';
	for(auto x : ans){
		cout << x << '\n';
	}


	return 0;
}