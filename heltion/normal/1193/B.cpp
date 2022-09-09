#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000;
LL p[maxn], v[maxn], d[maxn], w[maxn], dp[20][maxn];
vector<int> G[maxn], X[maxn];
map<LL, LL> mp[maxn];
void insert(LL d, LL w, map<LL, LL> &mp){
	mp[d] += w;
	auto it = mp.upper_bound(d);
	LL sd = 0, sw = 0;
	for(; sw <= w and it != mp.end(); it = mp.erase(it)){
		sw += it->second;
		sd = it->first;
	}
	if(sw > w) mp[sd] = sw - w;
}
int main(){
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 2; i <= n; i += 1){
		cin >> p[i];
		G[p[i]].push_back(i);
	}
	for(int i = 1; i <= m; i += 1){
		cin >> v[i] >> d[i] >> w[i];
		X[v[i]].push_back(i);
	}
	for(int i = n; i >= 1; i -= 1){
		int hs = 0;
		for(int j : G[i]) if(mp[j].size() > mp[hs].size()) hs = j;
		swap(mp[i], mp[hs]);
		for(int j : G[i]) for(auto p : mp[j]) mp[i][p.first] += p.second;
		for(int j : X[i]) insert(d[j], w[j], mp[i]);
	}
	LL ans = 0;
	for(auto p : mp[1]) ans += p.second;
	cout << ans;
	return 0;
}