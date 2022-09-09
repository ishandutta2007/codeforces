#include<bits/stdc++.h>
using namespace std;
#define maxn 240000
typedef long long LL;
int n, m;
LL a[maxn];
struct edge{
	int u, v;
	LL w;
	bool operator < (const edge &b){
		return w < b.w;
	}
}e[maxn << 1];
int f[maxn];
int get(int u){
	return u == f[u] ? u : f[u] = get(f[u]);
}
int main(){
	cin >> n >> m;
	LL mini = 0;
	a[0] = 1E13;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		if(a[i] < a[mini]) mini = i;
	}
	for(int i = 1; i <= n; i += 1)
		e[i] = (edge) {i, mini, a[i] + a[mini]}, f[i] = i;
	for(int i = n + 1; i <= n + m; i += 1) cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1, e + n + m + 1);
	LL ans = 0;
	for(int i = 1; i <= n + m; i += 1){
		int u = get(e[i].u), v = get(e[i].v);
		if(u != v){
			f[u] = v;
			ans += e[i].w;
		}
	}
	cout << ans;
}