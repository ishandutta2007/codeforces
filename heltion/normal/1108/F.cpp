#include<bits/stdc++.h>
using namespace std;
#define maxn 240000
struct edge{
	int u, v, w;
	bool operator <(const edge &b){
		return w < b.w;
	}
}e[maxn];
int f[maxn];
int get(int u){
	return u == f[u] ? u : f[u] = get(f[u]);
}
int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i += 1) f[i] = i;
	for(int i = 0; i < m; i += 1) cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e, e + m);
	int ans = 0, x = 0;
	int L = 0;
	for(int i = 0; i < m; i += 1){
		int u = get(e[i].u), v = get(e[i].v);
		if(u != v) ans += 1;
		
		if(e[i + 1].w != e[i].w){
			for(int j = L; j <= i; j += 1){
				int u = get(e[j].u), v = get(e[j].v);
				if(u != v) f[u] = v;
			}
			L = i + 1;
		}
	}
	cout << ans - (n - 1);
}