#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 240000;
int u[maxn], v[maxn];
bool color[maxn];
bool vis[maxn];
vector<int> G[maxn];
void no(){
	cout << "NO";
	exit(0);
}
void DFS(int u){
	vis[u] = true;
	for(int v : G[u])
	if(not vis[v]){
		color[v] = color[u] ^ 1;
		DFS(v);
	}
	else if(color[v] == color[u]) no();
}
int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i += 1){
		cin >> u[i] >> v[i];
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]);
	}
	for(int i = 1; i <= n; i += 1) if(not vis[i])
		DFS(i);
	cout << "YES" << endl;
	for(int i = 1; i <= m; i += 1) cout << color[u[i]];
}