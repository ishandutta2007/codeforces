#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int P = 1e9 + 7 ; 
const int N = 5e4 + 5 ; 
const int M = 100 + 5 ; 
int ch[N][12], fail[N] ; 
int n, d, cnt, ed[N], lim[M], fac[M], ret[M], vis[M][N][2], dp[M][N][2] ; 
char s[N], a[M], b[M], p[M] ; 
void insert( char *t ) {
	int u = 0, l = d / 2 ; 
	rep( i, 1, l ) {
		if( !ch[u][t[i]] ) ch[u][t[i]] = ++ cnt ; 
		u = ch[u][t[i]] ; 
	} 
	ed[u] = 1 ; 
}
queue<int> q ; 
inline void GetFail() {
	rep( i, 0, 9 ) if( ch[0][i] ) q.push(ch[0][i]) ;
	while( !q.empty() ) {
		int u = q.front() ; q.pop() ;
		rep( i, 0, 9 )
			if( !ch[u][i] ) ch[u][i] = ch[fail[u]][i] ; 
			else fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]) ;
	}
}
int dfs( int x, int limit, int u ) {
	if( vis[x][u][limit] ) return dp[x][u][limit] ; 
	if( ed[u] ) return ( limit ) ? ret[x] : fac[d - x + 1] ; 
	if( x == d + 1 ) { return 0 ; }
	int res = ( limit ) ? lim[x] : 9, ans = 0 ; 
	rep( i, 0, res ) ans = ( ans + dfs( x + 1, ( limit & ( i == res ) ), ch[u][i] ) ) % P ;
	vis[x][u][limit] = 1 ; 
	return dp[x][u][limit] = ans ; 
}
int F( char *t ) {
	memset( vis, 0, sizeof(vis) ), memset( dp, 0, sizeof(dp) ), memset( ret, 0, sizeof(ret) ) ; 
	rep( i, 1, d ) lim[i] = t[i] ; 
	rep( i, 1, d ) {
		int u = 0 ; 
		rep( j, i, d ) u = ( u * 10 + lim[j] ) % P ;
		ret[i] = u + 1 ; 
	} ret[d + 1] = 1 ; 
	int ans = dfs( 1, 1, 0 ) ; 
	return ans ;  
}
signed main()
{ 
	scanf("%s", s + 1 ), scanf("%s", a + 1 ), scanf("%s", b + 1 ) ; 
	n = strlen(s + 1), d = strlen(a + 1) ; 
	rep( i, 1, n ) s[i] = s[i] - '0' ; 
	rep( i, 1, d ) a[i] = a[i] - '0' ; 
	rep( i, 1, d ) b[i] = b[i] - '0' ; 
	int l = d / 2 ; fac[0] = 1 ; 
	rep( i, 1, d ) fac[i] = fac[i - 1] * 10 % P ;  
	for( re int i = 1; i <= n - l + 1; ++ i ) {
		rep( j, 1, l ) p[j] = s[i + j - 1] ; 
		int u = 0 ; 
		rep( i, 1, l ) {
			if( !ch[u][p[i]] ) ch[u][p[i]] = ++ cnt ; 
			u = ch[u][p[i]] ; 
		} 
		ed[u] = 1 ; 
	}
	GetFail() ; int ls = F(a), rs = F(b), ans = ( rs - ls + P ) % P, u = 0 ; 
	rep( i, 1, d ) {
		u = ch[u][a[i]] ; 
		if( ed[u] ) { ++ ans ; break ; }
	}
	printf("%lld\n", ans % P ) ;
	return 0 ;
}