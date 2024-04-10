#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next ) 
#define drep( i, s, t ) for( register int i = t; i >= s; -- i )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long 
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int P = 1e9 + 7 ; 
const int N = 3000 + 5 ;  
int n, cnt, D, head[N], dp[N][N], sum[N][N], fac[N], Inv[N], Y[N] ; 
struct E {
	int to, next ; 
} e[N] ;
int fpow( int x, int k ) {
	int ans = 1, base = x ; 
	while( k ) {
		if( k & 1 ) ans = ( ans * base ) % P ; 
		base = ( base * base ) % P, k >>= 1 ;  
	} return ans ; 
}
void add( int x, int y ) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt ; 
}
void dfs( int x ) {
	rep( j, 1, n ) dp[x][j] = 1 ; 
	Next( i, x ) {
		int v = e[i].to ; dfs(v) ; 
		rep( j, 1, n ) dp[x][j] = ( dp[x][j] * sum[v][j] ) % P ;
	}
	rep( j, 1, n ) sum[x][j] = ( sum[x][j - 1] + dp[x][j] ) % P ; 
}
void Large() {
	fac[0] = Inv[0] = 1 ;
	rep( i, 1, n ) fac[i] = ( fac[i - 1] * i ) % P ;
	Inv[n] = fpow( fac[n], P - 2 ) ;
	drep( i, 1, n ) Inv[i - 1] = ( Inv[i] * i ) % P ; 
} 
int Get( int x ) {
	if( x <= n ) return sum[1][x] ; 
	int Ans = 0, Sum = 1 ; rep( i, 1, n ) Y[i] = x - i, Sum = ( Sum * Y[i] ) % P ;
	rep( i, 1, n ) Y[i] = fpow( Y[i], P - 2 ) ;
	rep( i, 1, n ) {
		int dy = Sum * Y[i] % P, dx = Inv[i - 1] * Inv[n - i] % P ;
		if( ( n - i ) & 1 ) dx = ( P - dx ) % P ;
		int X = dy * dx % P ;
		Ans = ( Ans + sum[1][i] * X % P ) % P ;
	} return Ans ; 
}
signed main()
{
	n = gi(), D = gi() ; int x ; 
	rep( i, 2, n ) x = gi(), add( x, i ) ;
	n += 2, dfs(1), Large() ; 
	printf("%lld\n", Get(D) % P ) ;
	return 0 ;
}