#include<bits/stdc++.h>
#define maxn 6000
using namespace std;
typedef long long LL;
vector<int> G[maxn];
int n, m;
inline int dis(int a, int b){
	return b >= a ? b - a : b + n - a;
}
inline int solve(int s){
	int res = 0;
	for(int i = 1; i <= n; i += 1) if(G[i].size()){
		int pres = n;
		for(const int &j : G[i]) pres = min(pres, dis(i, j));
		pres += (G[i].size() - 1) * n + dis(s, i);
		res = max(res, pres);
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < m; i += 1){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
	}
	for(int i = 1; i <= n; i += 1) cout << solve(i) << " ";
}