#include<bits/stdc++.h>
#define maxn 360000
using namespace std;
typedef long long LL;
LL d[maxn];
struct edge{
	int x, y, w;
	int id, key;
	bool operator<(const edge &rhs){
		return key > rhs.key;
	}
}e[maxn];
vector<int> G[maxn];
vector<int> C[maxn];
int f[maxn], h[maxn];
void dfs(int u){
	h[u] = 1;
	for(int v : C[u]){
		dfs(v);
		h[u] = max(h[v] + 1, h[u]);
	}
	if(u != 1) e[f[u]].key = h[u];
}
priority_queue<pair<LL, int>, vector<pair<LL, int> >, greater<pair<LL, int> > > q;
int main(){
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i += 1){
		e[i].id = i;
		cin >> e[i].x >> e[i].y >> e[i].w;
		G[e[i].x].push_back(i);
		G[e[i].y].push_back(i);
	}
	fill(d + 2, d + n + 1, 1LL << 60);
	q.push({d[1], 1});
	while(q.empty() == false){
		auto p = q.top();
		q.pop();
		int u = p.second;
		if(d[u] < p.first) continue;
		for(int i: G[u]){
			int v = e[i].x ^ e[i].y ^ u, w = e[i].w;
			if(d[v] > d[u] + w){
				f[v] = i;
				q.push({d[v] = d[u] + w, v});
			}
		}
	}
	//for(int i = 1; i <= n; i += 1) cout << d[i] << endl;
	//for(int i = 1; i <= n; i += 1) cout << f[i] << endl;
	for(int i = 2; i <= n; i += 1)
		C[e[f[i]].x ^ e[f[i]].y ^ i].push_back(i);
	dfs(1);
	sort(e + 1, e + m + 1);
	cout << k << endl;
	for(int i = 1; i <= k; i += 1)
		cout << e[i].id << " ";
}