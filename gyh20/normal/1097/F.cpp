#include<bits/stdc++.h>
using namespace std;
#define il inline
#define re register
il int read() {
    re int x = 0, f = 1; re char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
    return x * f;
}
#define rep(i, s, t) for(re int i = s; i <= t; ++ i)
#define maxn 7001
#define maxm 100005
int n, m, prim[maxn], vis[maxn], mu[maxn], cnt;
bitset<maxn>G[maxn], a[maxm], u[maxn];
int main() {
	n = read(), m = read(), mu[1] = 1;
	rep(i, 2, 7000) {
		if(!vis[i]) prim[++ cnt] = i, mu[i] = -1;
		for(re int j = 1; j <= cnt && prim[j] * i <= 7000; ++ j) {
			vis[i * prim[j]] = 1;
			if(i % prim[j] == 0) break;
			mu[i * prim[j]] = -mu[i];
		}
	}
	rep(i, 1, 7000) {
		for(re int j = i; j <= 7000; j += i) G[j][i] = 1, u[i][j] = mu[j / i] != 0;
	}
	while(m --) {
		int opt = read(), x = read();
		if(opt == 1) a[x] = G[read()];
		if(opt == 2) a[x] = a[read()] ^ a[read()];
		if(opt == 3) a[x] = a[read()] & a[read()];
		if(opt == 4) printf("%d", (u[read()] & a[x]).count() & 1);
	}
	return 0;
}