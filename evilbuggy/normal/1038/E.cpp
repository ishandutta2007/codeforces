#include <bits/stdc++.h>
using namespace std;

int parent[4], degree[4], value[4];

void init(){
	iota(parent, parent + 4, 0);
	memset(value, 0, sizeof(value));
	memset(degree, 0, sizeof(degree));
}

int find(int v){
	return (parent[v] == v)?v:(parent[v] = find(parent[v]));
}

void combine(int u, int v, int w){
	degree[u]++;
	degree[v]++;
	u = find(u);
	v = find(v);
	if(u == v){
		value[u] += w;
		return;
	}
	parent[v] = u;
	value[u] += value[v] + w;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> edges[4][4];
	for(int i = 0; i < n; i++){
		int c1, v, c2;
		cin >> c1 >> v >> c2;
		if(c1 > c2)swap(c1, c2);
		edges[c1 - 1][c2 - 1].emplace_back(v);
	}
	int ans = 0;
	vector<array<int, 3> > remvec;
	for(int i = 0; i < 4; i++){
		for(int j = i; j < 4; j++){
			if(edges[i][j].empty())continue;
			
			sort(edges[i][j].rbegin(), edges[i][j].rend());
			remvec.push_back({i, j, edges[i][j].back()});
			edges[i][j].pop_back();
		}
	}
	int m = (int)remvec.size();
	for(int mask = 0; mask < (1 << m); mask++){
		init();
		for(int i = 0; i < 4; i++){
			for(int j = i; j < 4; j++){
				for(auto x : edges[i][j]){
					combine(i, j, x);
				}
			}
		}
		for(int i = 0; i < m; i++){
			if((mask >> i) & 1){
				combine(remvec[i][0], remvec[i][1], remvec[i][2]);
			}
		}
		for(int i = 0; i < 4; i++){
			if(find(i) == i){
				int cnt = 0;
				for(int j = 0; j < 4; j++){
					if(find(j) == i && degree[j]%2 == 1)cnt++;
				}
				if(cnt <= 2)ans = max(ans, value[i]);
			}
		}
	}
	cout << ans << '\n';

	return 0;
}