#include <bits/stdc++.h>

using ll = long long;
const int mod = 998244353;
const int maxn = 500005;
int d,n,m,l[maxn],p[maxn],vis[maxn],L[19][maxn],R[19][maxn],f[maxn],g[20][20];
int inv(int x) { return x == 1 ? 1 : (ll) ( mod - mod / x ) * inv(mod % x) % mod; }
int queryL(int l,int r,int x) {
	if (l > r) return 0;
//	printf("<%d> %d %d %d / %d\n",x,l,r,L[x][r],L[x][l-1]);
	return (ll) L[x][r] * inv(L[x][l-1]) % mod;
}
int queryR(int l,int r,int x) {
	if (l > r) return 0;
	return (ll) R[x][r] * inv(R[x][l-1]) % mod;
}

int main() {
	scanf("%d%d%d",&d,&n,&m);
	for (int i = 1; i <= n; ++ i) scanf("%d",&l[i]);
	for (int i = 1; i <= m; ++ i) scanf("%d",&p[i]);
	std::sort(l + 1,l + n + 1);
	std::sort(p + 1,p + m + 1);
	for (int i = 1; i <= n; ++ i) vis[l[i]] = 1;
	for (int i = 1; i <= m; ++ i) {
		L[i][0] = R[i][0] = 1;
		for (int j = 1; j <= d; ++ j) {
			L[i][j] = L[i][j-1];
			R[i][j] = R[i][j-1];
			if (vis[j]) {
				L[i][j] = (ll) L[i][j] * (j - p[i] + mod) % mod;
				R[i][j] = (ll) R[i][j] * (p[i] - j + mod) % mod;
			}
			assert(L[i][j]);
			assert(R[i][j]);
		}
	} //puts("!");
	f[0] = 1;
	for (int i = 1; i <= n; ++ i)
		f[0] = (ll) f[0] * (d + 1) % mod;
	for (int S = 1; S < (1 << m); ++ S) {
		int last = 0;
		f[S] = 1;
		for (int j = 1; j <= m; ++ j) {
			if (!(S & (1 << (j - 1)))) continue;
			int mid;
			if (!last) {
				f[S] = (ll) f[S] * queryR(1,p[j],j) % mod;
			}
			else {
				mid = (p[last] + p[j]) / 2;
				f[S] = (ll) f[S] * queryL(p[last] + 1,mid,last) % mod * queryR(mid + 1,p[j],j) % mod;
			}
			last = j;
		} f[S] = (ll) f[S] * queryL(p[last] + 1,d,last) % mod;
	}
	//puts("!");
//	for (int S = 0; S < (1 << m); ++ S) printf("%d : %d\n",S,f[S]);
	for (int i = 1; i < (1 << m); i <<= 1)
	for (int len = (i << 1),j = 0; j < (1 << m); j += len)
	for (int k = 0; k < i; k ++) 
		f[j + k] = (f[j + k] - f[j + k + i] + mod) % mod;
	for (int S = 1; S < (1 << m); ++ S) {
		int l = 0, r = 0;
		for (int i = 1; i <= m; ++ i) {
			if (!(S & (1 << (i - 1)))) continue;
			if (!l) l = i;
			r = i;
		} g[l][r] = (g[l][r] + f[S]) % mod;
	}
//	for (int S = 0; S < (1 << m); ++ S) printf("%d : %d\n",S,f[S]);
	int q,x;
	scanf("%d",&q);
	while (q--) {
		scanf("%d",&x);
		int ans = (ll) (d + 1) * f[0] % mod;
		for (int l = 1; l <= m; ++ l)
		for (int r = l; r <= m; ++ r) {
			int w = std::min(d,std::max(std::abs(p[l] - x),std::abs(p[r] - x)));
		//	printf("<%d %d> %d %d += %d*%d\n",l,r,w,ans,g[l][r],d - w + 1);
			ans = (ans + (ll) g[l][r] * (d - w + 1) % mod) % mod;
		} printf("%d\n",ans);
	}
	return 0;
}