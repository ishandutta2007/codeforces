#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int M = 5e5 + 5 ; 
const int N = 1e5 + 5 ; 
struct E {
	int to, next ; 
} e[M] ;
int n, m, cnt, head[N], Dec[N], L[N], R[N], vis[N], Ans ;
void add( int x, int y ) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y] }, head[y] = cnt ; 
}
queue<int> q ;
void Del( int x ) {
	R[L[x]] = R[x], L[R[x]] = L[x] ;
}
int solve( int x ) {
	q.push(x), Del(x) ; 
	while( !q.empty() ) {
		int u = q.front() ; q.pop() ; 
		Next( i, u ) Dec[e[i].to] = 1 ; 
		for( re int i = R[0]; i != n + 1; i = R[i] ) {
			if( Dec[i] ) continue ;
			vis[i] = 1, Del(i), q.push(i) ;
		}
		Next( i, u ) Dec[e[i].to] = 0 ; 
	}
}
signed main()
{
	n = gi(), m = gi() ; int x, y ; R[0] = 1 ; 
	rep( i, 1, m ) x = gi(), y = gi(), add( x, y ) ; 
	rep( i, 1, n ) L[i] = i - 1, R[i] = i + 1 ;
	rep( i, 1, n ) if( !vis[i] ) solve(i), ++ Ans ;
	printf("%d\n", Ans - 1 ) ;
	return 0 ;
}