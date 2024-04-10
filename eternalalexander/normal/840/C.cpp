

#include  <bits/stdc++.h>

using ll = long long;
const int mod = 1e9 + 7;

int f[605],g[605][605],h[605],C[605][605],n,a[605],fac[605];
std::map<int,int>cnt;

int det(int x) { return x & 1 ? mod - 1 : 1; }

int work(int x) {
	for (int i = 2; i * i <= x; ++ i) 
		while (x % (i * i) == 0) x /= (i * i);
	return x;
}

void multiply(int *f,int *g,int *h) {
	for (int i = 0; i <= n; ++ i) h[i] = 0;
	for (int i = 0; i <= n; ++ i)
	for (int j = 0; j + i <= n; ++ j)
		h[i + j] = ( h[i + j] + (ll) f[i] * g[j] % mod * C[i+j][j] % mod ) % mod;
}

void calc() {
	for (int i = 0; i <= n; ++ i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++ j) 
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
	fac[0] = 1;
	for (int i = 1; i <= n; ++ i)
		fac[i] = (ll) fac[i - 1] * i % mod;
	for (int i = 1; i <= n; ++ i) 
		for (int j = 1; j <= i; ++ j) 
			g[i][j] = (ll) det(i - j) * C[i - 1][i - j] % mod * fac[i] % mod;
}

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d",&a[i]);
		cnt[work(a[i])] ++;
	} 
	calc();
	f[0] = 1;
	for (auto p:cnt) {
		int w = p.second;
		std::memcpy(h,f,sizeof(f));
		multiply(g[w],h,f);
	}
	int ans = 0;
	for (int i = 0; i <= n; ++ i) {
		ans = (ans + f[i]) % mod;
		//printf("%d ",f[i]);
	}
	printf("%d",ans);
	return 0;
}