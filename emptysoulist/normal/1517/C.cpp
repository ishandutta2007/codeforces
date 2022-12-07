#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
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
const int N = 505 ; 
int n, m, p[N], a[N][N] ;  
void dfs(int x, int y, int d, int s) {
	if(!s) return ; 
	a[x][y] = d ; 
	if(y != 1) {
		if(!a[x][y - 1]) dfs(x, y - 1, d, s - 1) ; 
		else dfs(x + 1, y, d, s - 1) ; 
	}
	else dfs(x + 1, y, d, s - 1) ; 
}
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) p[i] = gi() ; 
	rep( i, 1, n ) dfs(i, i, p[i], p[i]) ; 
	rep( i, 1, n ) {
		rep( j, 1, i ) printf("%d ", a[i][j]) ; puts("") ; 
	}
	return 0 ;
}