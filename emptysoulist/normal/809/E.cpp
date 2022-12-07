#include<bits/stdc++.h>
using namespace std;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int N = 2e5 + 5 ; 
const int P = 1e9 + 7 ;
int n, cnt, head[N], w[N], rev[N], vis[N], dp[N], Ans ; 
int phi[N], mu[N], p[N], F[N], f[N], top, s[N] ; 
int dfn[N], Fa[N], dep[N], sz[N], Son[N], Top[N], idnex ; 
bool isp[N] ; 
struct E {
	int to, next ; 
} e[N * 2] ;
void add( int x, int y ) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt , 
	e[++ cnt] = (E){ x, head[y] }, head[y] = cnt ; 
}
void init() {
	mu[1] = 1, phi[1] = 1 ; rep( i, 2, n ) {
		if( !isp[i] ) phi[i] = i - 1, mu[i] = -1, p[++ top] = i ;
		for( re int j = 1; j <= top && p[j] * i <= n; ++ j ) {
			isp[i * p[j]] = 1 ; 
			if( i % p[j] == 0 ) { phi[i * p[j]] = phi[i] * p[j] ; break ; } 
			phi[i * p[j]] = phi[i] * phi[p[j]], mu[i * p[j]] = - mu[i] ; 
		}
	}
}
inline void dfs( int x, int fa ) {
	dfn[x] = ++ idnex, Fa[x] = fa, dep[x] = dep[fa] + 1, sz[x] = 1 ; 
	Next( i, x ) {
		int v = e[i].to ; if( v == fa ) continue ; 
		dfs( v, x ), sz[x] += sz[v] ;
		if( sz[v] > sz[Son[x]] ) Son[x] = v ; 
	}
}
inline void dfs2( int x, int high ) {
	Top[x] = high ; 
	if( Son[x] ) dfs2( Son[x], high ) ;
	Next( i, x ) {
		int v = e[i].to ; if( v == Fa[x] || v == Son[x] ) continue ; 
		dfs2( v, v ) ; 
	}
}
inline int LCA( int x, int y ) {
	while( Top[x] != Top[y] ) {
		if( dep[Top[x]] < dep[Top[y]] ) swap( x, y ) ;
		x = Fa[Top[x]] ; 
	}
	return ( dep[x] < dep[y] ) ? x : y ; 
}
inline void Dp( int x, int fa ) {
	if( vis[x] ) Ans = ( Ans + 2 * phi[w[x]] * phi[w[x]] * dep[x] % P ) % P, dp[x] = phi[w[x]] ; 
	Next( i, x ) {
		int v = e[i].to ; if( v == fa ) continue ; 
		Dp( v, x ), Ans = ( Ans + 4 * dp[x] * dp[v] % P * dep[x] % P ) % P, 
		dp[x] = ( dp[x] + dp[v] ) % P, dp[v] = 0 ;
	}
	head[x] = 0 ; 
}
int fpow( int x, int k ) {
	int ans = 1, base = x ; 
	while( k ) {
		if( k & 1 ) ans = ( ans * base ) % P ;
		base = ( base * base ) % P, k >>= 1 ;
	}
	return ans ;  
}
int K[N], tot ; 
bool cmp( int x, int y ) {
	return dfn[x] < dfn[y] ; 
} 
void insert( int x ) {
	int lca = LCA( s[top], x ) ; if( lca == x ) return ; 
	while( top > 1 && dfn[s[top - 1]] > dfn[lca] ) add( s[top - 1], s[top] ), -- top ; 
	if( dfn[lca] < dfn[s[top]] ) add( lca, s[top] ), -- top ; 
	if( dfn[lca] > dfn[s[top]] ) s[++ top] = lca ; 
	s[++ top] = x ; 
}
void input() {
	n = gi(), init(), top = 0 ;
	rep( i, 1, n ) w[i] = gi(), rev[w[i]] = i ; 
	rep( i, 2, n ) add( gi(), gi() ) ; 
	dfs( 1, 1 ), dfs2( 1, 1 ), memset( head, 0, sizeof(head) ) ;
}
void solve() {
	rep( i, 1, n ) {
		if( i > n / 2 ) break ; 
		int Re = 0, Sum = 0 ; cnt = 0 ;
		for( re int j = i; j <= n; j += i ) {
			vis[rev[j]] = 1, Sum = ( Sum + phi[j] * dep[rev[j]] % P ) % P,  
			Re = ( Re + phi[j] ) % P, K[++ tot] = rev[j] ; 
		}
		sort( K + 1, K + tot + 1, cmp ), s[top = 1] = 1 ;
		rep( i, 1, tot ) insert( K[i] ) ;
		while( top > 1 ) add( s[top - 1], s[top] ), -- top ; 
		Sum *= Re, Sum %= P, Dp( 1, 1 ), dp[1] = head[1] = 0, F[i] = ( Sum * 2 - Ans + P ) % P ;
		for( re int j = i; j <= n; j += i ) vis[rev[j]] = 0 ; Ans = 0, tot = 0 ; 
	}
}
void Get_F() {
	rep( i, 1, n ) for( re int j = i; j <= n; j += i ) 
	f[i] += F[j] * mu[j / i], f[i] = ( f[i] + P ) % P ;
	rep( i, 1, n ) Ans = ( Ans + i * fpow( phi[i], P - 2 ) % P * f[i] ) % P ; 
	int Ks = Ans * fpow( n, P - 2 ) % P ; Ks = Ks * fpow( n - 1, P - 2 ) % P ;
	printf("%I64d\n", ( Ks + P ) % P ) ;
}
signed main()
{
	input(), solve(), Get_F() ; 
	return 0 ;
}