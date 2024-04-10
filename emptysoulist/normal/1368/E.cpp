#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define vi vector<int>
#define pb push_back
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int n, m, cnt, del[N], f[N] ; 
vi G[N] ; 
void solve() {
	n = gi(), m = gi() ; int x, y ; cnt = 0 ;
	rep( i, 1, n ) G[i].clear(), f[i] = del[i] = 0 ;
	rep( i, 1, m ) x = gi(), y = gi(), G[x].pb(y) ; 
	rep( i, 1, n ) {
		if( f[i] == 2 ) { ++ cnt, del[i] = 1 ; continue ; }
		for(int v : G[i]) f[v] = max( f[v], f[i] + 1 ) ;
	}
	printf("%d\n", cnt ) ;
	rep( i, 1, n ) if( del[i] ) printf("%d ", i ) ;
	puts("") ; 
}
signed main()
{
	int T = gi() ; 
	while( T-- ) solve() ; 
	return 0 ;
}