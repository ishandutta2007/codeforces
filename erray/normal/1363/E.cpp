#include<bits/stdc++.h>                     

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	vector<vector<int>> adj(n), ct(n, vector<int>(2));
	vector<int> cur_ct(2), tar_ct(2), mn(n);
	for(int i = 0; i < n; ++i){
		cin >> mn[i] >> v[i].first >> v[i].second;
		++tar_ct[v[i].first];
		++cur_ct[v[i].second];
	}
	for(int i = 0; i < n - 1; ++i){
		int a, b;
		cin >> a >> b;
		adj[--a].push_back(--b);
		adj[b].push_back(a);
	}
	if(cur_ct[0] != tar_ct[0])return cout << -1, 0;
	long long ans = 0;
	function<void(int, int)> dfs = [&](int nd, int par){
		if(v[nd].first != v[nd].second)++ct[nd][v[nd].first];
		for(int a : adj[nd]){
			if(a == par)continue;
			mn[a] = min(mn[a], mn[nd]);
			dfs(a, nd);
			ct[nd][0] += ct[a][0];
			ct[nd][1] += ct[a][1];
		}
		int add = min(ct[nd][0], ct[nd][1]);
		ans += (long long)add*mn[nd];
		//cout << nd << ' ' << mn[nd] << "  counts are " << ct[nd][0] << ' ' << ct[nd][1] << '\n';
		ct[nd][0] -= add;
		ct[nd][1] -= add;
	};
	dfs(0, -1);
	cout << ans*2;	
}