#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define Rep( i, s, t ) for( register int i = (s); i < (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define vi vector<int>
#define int long long
#define pb push_back
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 4000 + 5 ; 
const int K = 80 + 5 ; 
const int P = 998244353 ; 
int n1, n2, L, ans[2][N], fac[N], inv[N], F[N][K], G[N][K], H[N][K], D[N][K] ; 
vi Go[N] ; 
int fpow(int x, int k) {
	int a = 1, base = x ;
	while(k) {
		if(k & 1) a = 1ll * a * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return a ;
}
void add(int x, int y) { Go[x].pb(y), Go[y].pb(x) ; }
int Fp[N], A[N], B[N] ; 
void Inv(int *a) {
	rep( j, 0, L ) Fp[j] = 0 ; Fp[0] = fpow(a[0], P - 2) ; 
	rep( j, 1, L ) Rep( k, 0, j ) Fp[j] = ( Fp[j] - Fp[k] * A[j - k] % P + P ) % P ;  
	rep( j, 0, L ) a[j] = Fp[j] ; 
}
void Get(int *a) {
	rep( j, 0, L ) A[j] = 0 ; 
	rep( j, 2, L ) A[j] = (P - a[j - 2]) % P ; 
	A[0] = 1, Inv(A) ;
	rep( j, 0, L ) a[j] = A[j] ; 
}
void dfs(int x, int fa, int type) {
	for(int v : Go[x]) {
		if(v == fa) continue ; 
		dfs(v, x, type) ; rep( j, 0, L ) G[x][j] = (G[x][j] + F[v][j]) % P ; 
	} 
	rep( j, 0, L ) F[x][j] = G[x][j] ; Get(F[x]) ; 
}
void Dfs(int x, int fa, int type) {
	if(x != fa) {
		rep( j, 0, L ) B[j] = 0 ;
		rep( j, 0, L ) B[j] = ( H[fa][j] - F[x][j] + P ) % P ; 
		Get(B) ; 
		rep( j, 0, L ) D[x][j] = H[x][j] = (G[x][j] + B[j]) % P ; 
		Get(D[x]) ; 
		rep( j, 0, L ) ans[type][j] = (ans[type][j] + D[x][j]) % P ; 
	}
	for(int v : Go[x]) if(v ^ fa) Dfs(v, x, type) ; 
}
int C(int x, int y) { return fac[x] * inv[y] % P * inv[x - y] % P ; }
signed main()
{
	n1 = gi(), n2 = gi(), L = gi() ; int x, y ; 
	rep( i, 2, n1 ) x = gi(), y = gi(), add(x, y) ; 
	dfs(1, 1, 0) ; 
	rep( j, 0, L ) H[1][j] = G[1][j], D[1][j] = F[1][j] ; 
	rep( j, 0, L ) ans[0][j] = (ans[0][j] + F[1][j]) % P ; 
	Dfs(1, 1, 0) ; 
	memset( H, 0, sizeof(H) ), memset( G, 0, sizeof(G) ),
	memset( D, 0, sizeof(D) ), memset( F, 0, sizeof(F) ) ;
	rep( i, 1, n1 ) Go[i].clear() ; 
	rep( i, 2, n2 ) x = gi(), y = gi(), add(x, y) ; 
	dfs(1, 1, 1) ; 
	rep( j, 0, L ) H[1][j] = G[1][j], D[1][j] = F[1][j] ; 
	rep( j, 0, L ) ans[1][j] = (ans[1][j] + F[1][j]) % P ; 
	Dfs(1, 1, 1) ; fac[0] = inv[0] = 1 ; 
	rep( i, 1, L ) fac[i] = fac[i - 1] * i % P, inv[i] = fpow(fac[i], P - 2) ;
	int Ans = 0 ;
	rep( i, 0, L ) Ans = (Ans + ans[0][i] * ans[1][L - i] % P * C(L, i) ) % P ; 
	cout << Ans << endl ; 
	return 0 ;
}