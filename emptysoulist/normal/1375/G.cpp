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
const int N = 2e5 + 5 ; 
struct E {
	int to, next ; 
} e[N << 1] ;
int n, cnt, A, B, head[N] ; 
void add(int x, int y) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y] }, head[y] = cnt ; 
}
void Dfs(int x, int fa, int dep) {
	(dep ^ 1) ? ++ A : ++ B ; 
	Next( i, x ) if( e[i].to ^ fa ) Dfs(e[i].to, x, dep ^ 1) ;
}
signed main()
{
	n = gi() ; int x, y ; 
	rep( i, 2, n ) x = gi(), y = gi(), add(x, y) ; 
	Dfs(1, 1, 0) ;
	cout << min(A, B) - 1 << endl ; 
	return 0 ;
}