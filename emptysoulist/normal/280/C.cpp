#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define pb push_back
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ; 
int n, dep[N] ;
double ans ; 
vector<int> G[N] ; 
void dfs( int x, int fa ) {
	dep[x] = dep[fa] + 1, ans += 1.0 / ( 1.0 * dep[x] ) ; 
	for( auto v : G[x] ) if( v ^ fa ) dfs(v, x) ;
}
signed main()
{
	n = gi() ; int x, y ; 
	rep( i, 2, n ) x = gi(), y = gi(), G[x].pb(y), G[y].pb(x) ; 
	dfs(1, 1) ; 
	printf("%.8lf\n", ans ) ;
	return 0 ;
}