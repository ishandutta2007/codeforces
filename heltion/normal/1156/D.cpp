//Author: Heltion
//Date: 2019-05-01
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
constexpr int maxn = 240000;
vector<pair<int, int> > G[maxn];
int c[2][maxn], d[2][maxn];
LL ans;
void DFS(int u, int pa){
	for(const auto &p : G[u]){
		int v = p.first, w = p.second;
		if(v == pa) continue;
		DFS(v, u);
		if(w == 0) c[0][u] += c[0][v] + 1;
		if(w == 1) c[1][u] += c[1][v] + 1;
	}
}
void DFS2(int u, int pa){
	for(const auto &p : G[u]){
		int v = p.first, w = p.second;
		if(v == pa) continue;
		if(w == 0) d[0][v] += d[0][u] + c[0][u] - c[0][v];
		if(w == 1) d[1][v] += d[1][u] + c[1][u] - c[1][v];
		DFS2(v, u);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1, u, v, w; i < n; i += 1){
		cin >> u >> v >> w;
		G[u].push_back(make_pair(v, w));
		G[v].push_back(make_pair(u, w));
	}
	DFS(1, 0);
	DFS2(1, 0);
	for(int i = 1; i <= n; i += 1){
		//cout << c[0][i] << " " << d[0][i] << " " << c[1][i] << " " << d[1][i] << endl;
		ans += c[0][i] + d[0][i] + c[1][i] + d[1][i];
		ans += 1LL * (c[0][i] + d[0][i]) * (c[1][i] + d[1][i]);
	}
	cout << ans;
	return 0;
}