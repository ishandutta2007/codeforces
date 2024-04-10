#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 4000 + 5 ; 
int T, n, m, a[N], st[N], top, vis[N] ; 
bool dp[N] ; 
signed main()
{
	T = gi() ;
	while( T-- ) {
		n = gi(), m = n * 2 ; int Mx = 0 ; 
		rep( i, 1, m ) a[i] = gi() ; 
		rep( i, 1, m ) {
			if( a[i] > Mx ) Mx = a[i], st[++ top] = 1 ; 
			else ++ st[top] ;
		}
		dp[0] = 1 ; 
		rep( i, 1, top ) {
			drep( j, st[i], m ) dp[j] |= dp[j - st[i]] ; 
		}
		if( dp[n] ) puts("YES") ; 
		else puts("NO") ; 
		rep( i, 0, m ) dp[i] = 0 ; 
		rep( i, 1, n ) vis[i] = 0 ;
		rep( i, 1, top ) st[i] = 0 ; 
		top = 0 ; 
	}
	return 0 ;
}