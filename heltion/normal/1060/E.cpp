#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {LL x; scanf("%lld", &x); return x;}
void read(char *s) {scanf("%s", s);}
void no() {printf("no"); exit(0);}

#define maxn 240000
vector<int> G[maxn];
LL F[2][maxn], S[maxn], fa[maxn], tot, odd, n;
bool vis[maxn];
void DFS(int u){
	vis[u] = true;
	S[u] = 1;
	F[0][u] = 1;
	LL EVEN = 0, ODD = 0;
	for(int v: G[u]){
		if(vis[v] == false)
		{
			fa[v] = u;
			DFS(v);
			F[0][u] += F[1][v];
			F[1][u] += F[0][v];
			EVEN += F[0][v];
			ODD = F[1][v];
			S[u] += S[v];
		}
	}
	odd += F[1][u];
	for(int v: G[u]) if(fa[u] != v){
		odd += F[1][v] * (EVEN - F[0][v]);
	}
	tot += S[u] * (n - S[u]);
	
}
int main() {
	n = read();
	for(int i = 1; i < n; i += 1){
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DFS(1);
	/*for(int i = 1; i <= n; i += 1)
		printf("S[%d] = %lld\n", i, S[i]);
	for(int i = 1; i <= n; i += 1)
		printf("f[0][%d] = %lld\n", i, F[0][i]);
	for(int i = 1; i <= n; i += 1)
		printf("f[1][%d] = %lld\n", i, F[1][i]);
	printf("%lld %lld\n", tot, odd);*/
	printf("%lld", (tot + odd) / 2);
}