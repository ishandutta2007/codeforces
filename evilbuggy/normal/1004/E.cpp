#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, k, up[N], dw[N];
vector<pair<int, int> > g[N];

void dfsdw(int v, int p){
	dw[v] = 0;
	for(auto x : g[v]){
		if(x.first != p){
			dfsdw(x.first, v);
			dw[v] = max(dw[v], dw[x.first] + x.second);
		}
	}
}

void dfsup(int v, int p, int dist){
	up[v] = dist;
	int mx1 = dist, mx2 = 0;
	for(auto x : g[v]){
		if(x.first != p){
			int ndist = dw[x.first] + x.second;
			if(mx1 <= ndist){
				mx2 = mx1; mx1 = ndist;
			}else if(mx2 <= ndist){
				mx2 = ndist;
			}
		}
	}
	for(auto x : g[v]){
		if(x.first != p){
			int ndist = dw[x.first] + x.second;
			if(ndist != mx1){
				dfsup(x.first, v, mx1 + x.second);
			}else{
				dfsup(x.first, v, mx2 + x.second);
			}
		}
	}
}

int dfs1(int v, int p, int lim){
	vector<int> vec;
	for(auto x : g[v]){
		if(x.first != p){
			if(dw[x.first] + x.second > lim){
				vec.emplace_back(x.first);
			}
		}
	}
	if(vec.empty())return 1;
	if(vec.size() > 1)return (int)1e6;
	return 1 + dfs1(vec[0], v, lim);
}

int dfs2(int v, int p, int lim){
	vector<int> vec;
	for(auto x : g[v]){
		if(x.first != p){
			if(dw[x.first] + x.second > lim){
				vec.emplace_back(x.first);
			}
		}
	}
	if(vec.empty()){
		if(up[v] <= lim)return 1;
		return 2;
	}
	if(vec.size() > 2){
		return (int)1e6;
	}
	if(vec.size() == 1){
		if(up[v] <= lim)return dfs2(vec[0], v, lim);
		return 2 + dfs1(vec[0], v, lim);
	}else{
		if(up[v] > lim)return (int)1e6;
		return 1 + dfs1(vec[0], v, lim) + dfs1(vec[1], v, lim);
	}
}

bool check(int lim){
	if(dw[1] <= lim)return true;
	return dfs2(1, 0, lim) <= k;
}

int compute(){
	int ret = (int)1e9;
	for(int i = 1; i <= n; i++){
		ret = min(ret, max(up[i], dw[i]));
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for(int i = 0; i < n - 1; i++){
		int u, v, c;
		cin >> u >> v >> c;
		g[u].emplace_back(v, c);
		g[v].emplace_back(u, c);
	}
	dfsdw(1, 0); dfsup(1, 0, 0);
	// if(k == 1){
	// 	cout << compute() << '\n';
	// 	exit(0);
	// }
	int lo = 0, hi = (int)1e9 + 5;
	while(lo < hi){
		int mi = (lo + hi)/2;
		if(check(mi))hi = mi;
		else lo = mi + 1;
	}
	cout << lo << '\n';

	return 0;
}