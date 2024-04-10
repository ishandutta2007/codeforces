#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
struct{int u, v;}e[maxn];
int d[maxn], f[maxn];
int gf(int u){
	return f[u] == u ? u : f[u] = gf(f[u]);
}
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i += 1){ 
		scanf("%d %d", &e[i].u, &e[i].v);
		d[e[i].u] += 1;
		d[e[i].v] += 1;
	}
	int r = 0;
	for(int i = 1; i <= n; i += 1){
		f[i] = i;
		if(d[r] < d[i]) r = i;
	}
	for(int i = 0; i < m; i += 1)
		if(e[i].u == r or e[i].v == r){
			printf("%d %d\n", e[i].u, e[i].v);
			f[e[i].u] = f[e[i].v] = r;
		}
	
	for(int i = 0; i < m; i += 1){
		int u = gf(e[i].u), v = gf(e[i].v);
		if(u != v){
			printf("%d %d\n", e[i].u, e[i].v);
			f[u] = v;
		}
	}
}