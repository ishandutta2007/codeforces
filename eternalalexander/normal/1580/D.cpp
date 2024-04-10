#include <bits/stdc++.h>

const int maxn = 4005;
using ll = long long;
const ll inf = 1e18;

int n,m,mul;
ll a[maxn],f[maxn][maxn],w[maxn];
int siz[maxn],ch[maxn][2];

int solve(int l,int r,int fat = 0) {
	if (l > r) return 0;
	int s = l;
	for (int i = l; i <= r; ++ i) if (a[i] < a[s]) s = i;
	w[s] = a[s] - a[fat];
	ch[s][0] = solve(l,s - 1,s);
	ch[s][1] = solve(s + 1,r,s);
	siz[s] = 1 + siz[ch[s][0]] + siz[ch[s][1]];
	return s;
}

void dfs(int rt) {
	if (!rt) return ;
	dfs(ch[rt][0]);
	dfs(ch[rt][1]);
	for (int i = 0; i <= siz[ch[rt][0]]; ++ i)
	for (int j = 0; j <= siz[ch[rt][1]]; ++ j) {
		f[rt][i+j] = std::max(f[rt][i+j],f[ch[rt][0]][i] + f[ch[rt][1]][j] - (i + j) * (i + j) * w[rt]);
		f[rt][i+j+1] = std::max(f[rt][i+j+1],f[ch[rt][0]][i] + f[ch[rt][1]][j] - (i + j + 1) * (i + j + 1) * w[rt] + mul * a[rt]);
	} 
//	printf("%d>\n",rt);
//	for (int i = 0; i <= siz[rt]; ++ i) printf("%lld ",f[rt][i]); puts("");
}

int main() {
	scanf("%d%d",&n,&m); mul = m;
	for (int i = 1; i <= n; ++ i) scanf("%lld",&a[i]);
	int rt = solve(1,n);
	dfs(rt);
	printf("%lld",f[rt][m]);
	return 0;
}