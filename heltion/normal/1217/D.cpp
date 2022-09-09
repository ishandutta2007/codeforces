//Author: Heltion
//Date: 09-05-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 6000;
vector<int> G[maxn];
int vis[maxn], cyc;
void DFS(int u){
	vis[u] = -1;
	for(int v : G[u])
		if(vis[v] == -1){
			cyc = 1;
			continue;
		}
		else if(vis[v] == 0) DFS(v);
	vis[u] = 1;
}
int u[maxn], v[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i += 1){;
		cin >> u[i] >> v[i];
		G[u[i]].push_back(v[i]);
	}
	for(int i = 1; i <= n; i += 1) if(not vis[i]) DFS(i);
	if(cyc){
		cout << "2\n";
		for(int i = 1; i <= m; i += 1) cout << (u[i] < v[i] ? "1 " : "2 ");
	}
	else{
		cout << "1\n";
		for(int i = 1; i <= m; i += 1) cout << "1 ";
	}
	return 0;
}