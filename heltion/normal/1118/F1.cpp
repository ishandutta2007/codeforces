#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
auto read = [](){LL x; cin >> x; return x;};
auto no = [](){cout << "NO"; exit(0);};
#define maxn 360000
int b[maxn], r[maxn], uc[maxn], c[maxn], sb, sr, suc;
vector<int> G[maxn];
bool vis[maxn];
int ans;
void DFS(int u){
	vis[u] = true;
	for(int v : G[u]) if(vis[v] == false){
		DFS(v);
		uc[u] += uc[v];
		r[u] += r[v];
		b[u] += b[v];
	}
	if(u > 1)
		if(r[u] == 0 || b[u] == 0)
			if(sr - r[u] == 0 || sb - b[u] == 0)
				ans += 1;
}
int main(){
	ios::sync_with_stdio(false);
	int n = read();
	for(int i = 1; i <= n; i += 1){
		c[i] = read();
		if(c[i] == 0) suc += 1, uc[i] = 1;
		else if(c[i] == 1) sr += 1, r[i] = 1;
		else sb += 1, b[i] = 1;
	}
	for(int i = 1; i < n; i += 1){
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DFS(1);
	cout << ans;
}