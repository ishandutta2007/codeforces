#include<bits/stdc++.h>
#define maxn 240000
using namespace std;
typedef long long LL;
vector<int> G[maxn];
int f[maxn], d[maxn], t[maxn], p[maxn];
bool flag = true;
void dfs(int u){
	for(int v: G[u]) if(d[v] == 0){
		f[v] = u;
		d[v] = d[u] + 1;
		dfs(v);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i += 1){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= n; i += 1){
		scanf("%d", p + i);
		t[p[i]] = i;
	}
	dfs(d[1] = 1);
	for(int i = 1; i <= n; i += 1){
		//printf("f[%d] = %d, d[%d] = %d\n", i, f[i], i, d[i]);
	}
	for(int i = 1; i < n; i += 1){
		if(d[p[i + 1]] < d[p[i]]) flag = false;
		if(t[f[p[i + 1]]] < t[f[p[i]]]) flag = false;
	}
	printf(flag ? "Yes" : "No");
}