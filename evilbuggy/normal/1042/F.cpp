#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000005;

vector<int> g[maxN];

pair<int, int> dfs(int v, int p, int k){
	int ret = 0;
	vector<int> vec;
	for(int u : g[v]){
		if(u != p){
			pair<int, int> tmp = dfs(u, v, k);
			vec.push_back(tmp.first + 1);
			ret += tmp.second;
		}
	}
	if(vec.empty()){
		return {0, 1};
	}
	sort(vec.rbegin(), vec.rend());
	while(vec.size() >= 2){
		int m = (int)vec.size();
		if(vec[m - 1] + vec[m - 2] > k){
			break;
		}else{
			vec.pop_back();
			ret--;
		}
	}
	return {vec.back(), ret};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	for(int i = 0; i + 1 < n; i++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	for(int i = 1; i <= n; i++){
		if(g[i].size() > 1){
			cout << dfs(i, i, k).second << '\n';
			exit(0);
		}
	}

	return 0;
}