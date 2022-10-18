#include <bits/stdc++.h>

const int maxn = 2e6 + 222;

using ll = long long;

const int mod = 998244353;

int f[maxn],g[maxn],c[maxn],cl[maxn],rev[maxn];

int qpow(int a,int b) {
	if (b == 0) return 1;
	ll d = qpow(a,b>>1); d = d * d % mod;
	if (b & 1) d = d * a % mod;
	return d;
}

void DFT( int *a, int flag, int lim ) {
	for (int i = 1; i < lim; ++ i) rev[i] = (rev[i>>1]>>1) | (i&1) * (lim>>1);
	for (int i = 0; i < lim; ++ i) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
	for (int i = 1; i < lim; i <<= 1) {
		int wn = qpow(3,(mod-1)/(i<<1));
		if (flag == -1) wn = qpow(wn, mod - 2);
		for (int j = 0; j < lim; j += (i<<1)) {
			for (int k = 0, w = 1; k < i; w = (ll) w * wn % mod, ++ k) {
				int a1 = a[j+k], a2 = (ll) w * a[j+k+i] % mod;
				a[j+k] = (a1 + a2) % mod; a[j+k+i] = (a1 - a2 + mod) % mod;
			}
		}
	} if (flag == -1) 
		for (int i = 0,inv=qpow(lim,mod-2); i < lim; ++i) a[i] = (ll) a[i] * inv % mod;
}

void polyInv(int len,int *a,int *c){
	if (len == 1) { c[0] = 1; return; }
	polyInv( (len+1) >> 1, a, c);
	int lim = 1; while (lim < (len << 1)) lim <<= 1;
	for (int i = len; i < lim; ++ i) c[i] = 0;
	for (int i = 0; i < len; ++ i) cl[i] = a[i];
	for (int i = len; i < lim; ++ i) cl[i] = 0;
	DFT(cl,1,lim); DFT(c,1,lim);
	for (int i = 0; i < lim; ++ i) c[i] = (ll) ( 2ll - (ll) cl[i] * c[i] % mod + mod) % mod * c[i] % mod;
	DFT(c,-1,lim); for (int i = len; i < lim; ++ i) c[i] = 0;
}


std::set<int>ch[maxn],in[maxn],out[maxn];
int n,m,k,d[maxn],vis[maxn];

void dfs1(int u) {
	vis[u] = 1;
	for (int v:ch[u]) if (!vis[v]) dfs1(v);
} 

int dfs2(int u) {
	vis[u] = 2;
	int ans = 1;
	for (int v:ch[u]) if (!vis[v]) ans += dfs2(v);
	return ans;
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1; i <= n; ++ i) {
		int c;
		scanf("%d",&c);
	//	printf("c = %d\n",c);
		int pre = 0;
		for (int j = 1; j <= c; ++ j) {
			int x;
			scanf("%d",&x);
			if (pre) {
				ch[pre].insert(x);
				ch[x].insert(pre);
				out[pre].insert(x);
				in[x].insert(pre);
			} pre = x;
		}
	} 
	for (int i = 1; i <= k; ++ i) 
		if (ch[i].size() > 2 || out[i].size() > 1 || in[i].size() > 1) dfs1(i);
	for (int i = 1; i <= k; ++ i) {
		if ((!vis[i]) && (out[i].size() == 0)) {
			int cnt = dfs2(i);
			//printf("%d>%d\n",i,cnt);
			g[cnt] ++;
		}
	} for (int i = 0; i <= std::max(m,k) + 10; ++ i) 
		g[i] = (mod - g[i]) % mod;
	g[0] = (g[0] + 1) % mod;
	polyInv(std::max(m + 1, k + 1),g,f);
	printf("%d",f[m]);
	return 0;
}