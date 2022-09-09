#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
void no(){cout << -1; exit(0);}
struct edge{
	int u, v;
}e[maxn];
vector<int> G[maxn];
int d[maxn], dd[maxn], ans[maxn], n, k, r;
int DFS(int u, int c, int f){
	int t = 0;
	for(int i : G[u]){
		int v = e[i].u ^ e[i].v ^ u;
		if(v == f) continue;
		if(d[u] > r){
			ans[i] = c + 1;
			DFS(v, c, u);	
		}
		else{
			if(t == c and f) t += 1;
			ans[i] = t + 1;
			DFS(v, t, u);
			t += 1;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i < n; i += 1){
		cin >> e[i].u >> e[i].v;
		G[e[i].u].push_back(i);
		G[e[i].v].push_back(i);
		d[e[i].u] += 1;
		d[e[i].v] += 1;
	}
	for(int i = 1; i <= n; i += 1) dd[i] = d[i];
	sort(dd + 1, dd + n + 1);
	r = dd[n - k];
	DFS(1, 0, 0); 
	cout << r << endl;
	for(int i = 1; i < n; i += 1)
		cout << ans[i] << " ";
}