#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int P = 1e9 + 7 ; 
const int N = 42 ; 
int n, a[N], st[N], vis[N], sum[N], c[N], fac[N], cnt, top ; 
int inv[N], dp[1451][N][N][N], C[N][N], g[N], G[N][N] ; 
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
void dfs(int x, int d) {
	if(vis[x]) { st[++ top] = d ; return ; }
	vis[x] = 1, dfs(a[x], d + 1) ; 
}
map<vector<int>, int> Id ; 
vector<int> f[10001] ; 
void Dfs(int x) {
	if(x == n + 1) {
		vector<int> ans ; ans.resize(n + 1) ; 
		rep( i, 1, n ) ans[i] = c[i] ; 
		f[++ cnt] = ans, Id[ans] = cnt ; return ; 
	}
	for(re int i = 0; i <= sum[x]; ++ i)
	c[x] = i, Dfs(x + 1) ; 
}
void inc(int &x, int y) {
	((x += y) >= P) && (x -= P) ; 
}
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	rep( i, 1, n ) if(!vis[i]) dfs(i, 0) ; 
	sort(st + 1, st + top + 1) ; 
	rep( i, 1, top ) ++ sum[st[i]] ;
	Dfs(1), inv[0] = fac[0] = C[0][0] = 1 ; 
	rep( i, 1, n ) fac[i] = 1ll * fac[i - 1] * i % P, inv[i] = fpow(i, P - 2) ; 
	rep( i, 1, n ) rep( j, 0, i ) 
	C[i][j] = (!j) ? 1 : (C[i - 1][j] + C[i - 1][j - 1]) % P ; 
	rep( i, 0, n - 1 ) {
		rep( j, 0, i ) 
		inc(g[i], 1ll * C[i][j] * fac[j] % P * fac[n - j - 1] % P) ; 
		G[i][0] = 1 ; rep( j, 1, n ) G[i][j] = 1ll * G[i][j - 1] * g[i] % P ; 
	}
	dp[1][0][0][0] = 1 ; 
	rep( u, 1, cnt ) {
		vector<int> v = f[u] ; 
		int sz = 0 ; rep( i, 1, n ) sz += i * v[i] ; 
		rep( i, 1, n ) {
			if(v[i] == sum[i]) continue ; 
			vector<int> p = v ; ++ p[i] ;
			int o = Id[p] ; 
			rep(j, 0, n) rep(k, 0, top) rep(t, 0, n) {
					if(!dp[u][j][k][t]) continue ; 
					if(!k) {
						inc(dp[o][i][1][0], 1ll * dp[u][j][k][t] * G[0][i] % P) ; 
						continue ; 
					}
					if(k) {
					inc(dp[o][i][1][j], 
						1ll * dp[u][j][k][t] % P * (G[sz][i] - G[sz - j][i] + P) % P) ;
					inc(dp[o][i + j][k + 1][t], 
						1ll * dp[u][j][k][t] * (G[sz - j][i] - G[sz - j - t][i] + P) % P * inv[k + 1] % P) ; 
					}
					if(!t) 	
					inc(dp[o][i + j][k + 1][t], 
						1ll * dp[u][j][k][t] * G[0][i] % P * inv[k + 1] % P) ; 
			}
		}
	} int ans = 0 ; 
	rep(j, 1, n) rep(k, 1, top) rep(t, 0, n) {
		inc(ans, dp[cnt][j][k][t]) ; 
	}
	rep( i, 1, n ) ans = 1ll * ans * fac[sum[i]] % P ; 
	cout << ans << endl ; 
	return 0 ;
}