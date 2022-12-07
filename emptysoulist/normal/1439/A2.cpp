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
const int N = 100 + 5 ; 
const int M = 1e5 + 5 ; 
int T, n, m, cnt ; 
char s[N][N], f[N][N] ; 
struct node {
	int x, y ; 
	node(int _x = 0, int _y = 0) { x = _x, y = _y ; }
};
struct Opt {
	node a[3] ; 
} opt[M] ;
void Make(Opt &u, node x, node y, node z) {
	u.a[0] = x, u.a[1] = y, u.a[2] = z ; 
	rep( i, 0, 2 ) s[u.a[i].x][u.a[i].y] ^= 1 ; 
}
void Solve() {
	cnt = 0 ;
	rep( i, 1, n - 1 ) {
		for(re int j = 1; j < m; ++ j) {
			if( s[i][j] && s[i][j + 1] ) 
				++ cnt, Make(opt[cnt], node(i, j), node(i, j + 1), node(i + 1, j + 1)) ; 
			else if( s[i][j] ) ++ cnt, Make(opt[cnt], node(i, j), node(i + 1, j), node(i + 1, j + 1)) ;
		}
		if( s[i][m] ) ++ cnt, Make(opt[cnt], node(i, m), node(i + 1, m - 1), node(i + 1, m)) ;
	}
	for(re int j = 1; j <= m; ++ j) {
//		printf("now case %d (%d %d %d)\n", j, s[n][j], s[n][j + 1], s[n][j + 2] ) ; 
		if( s[n][j] && s[n][j + 1] && s[n][j + 2] )  
			++ cnt, Make(opt[cnt], node(n, j), node(n - 1, j + 1), node(n, j + 1) ),
			++ cnt, Make(opt[cnt], node(n, j + 2), node(n, j + 1), node(n - 1, j + 2) ),
			++ cnt, Make(opt[cnt], node(n, j + 1), node(n - 1, j + 2), node(n - 1, j + 1) ) ;  
		else if( s[n][j] && (!s[n][j + 1]) && s[n][j + 2] ) 
			++ cnt, Make(opt[cnt], node(n, j), node(n - 1, j + 1), node(n, j + 1) ),
			++ cnt, Make(opt[cnt], node(n, j + 2), node(n - 1, j + 1), node(n, j + 1) ) ;  
		else if( s[n][j] && s[n][j + 1] ) 
			++ cnt, Make(opt[cnt], node(n, j), node(n - 1, j), node(n - 1, j + 1) ),
			++ cnt, Make(opt[cnt], node(n, j + 1), node(n - 1, j), node(n - 1, j + 1) ) ; 
		else if( s[n][j] ) {
			if( j != m ) {
				++ cnt, Make(opt[cnt], node(n, j), node(n - 1, j), node(n - 1, j + 1) ),
				++ cnt, Make(opt[cnt], node(n - 1, j), node(n, j), node(n, j + 1) ),
				++ cnt, Make(opt[cnt], node(n - 1, j + 1), node(n, j), node(n, j + 1) ) ; 	
			}
			else {
				++ cnt, Make(opt[cnt], node(n, j), node(n - 1, j), node(n - 1, j - 1) ),
				++ cnt, Make(opt[cnt], node(n - 1, j), node(n, j), node(n, j - 1) ),
				++ cnt, Make(opt[cnt], node(n - 1, j - 1), node(n, j), node(n, j - 1) ) ; 	 	
			}
		}
		s[n][j] = 0 ; 
	}
}
void solve() {
	n = gi(), m = gi(), cnt = 0 ; 
	rep( i, 1, n ) scanf("%s", f[i] + 1 ) ;
	rep( i, 1, n ) rep( j, 1, m ) f[i][j] -= '0' ; 
	rep( i, 1, n ) rep( j, 1, m ) s[i][j] = f[i][j] ; 
	int flag = 0 ; 
	if( n < m ) {
		swap( n, m ) ;
		rep( i, 1, n ) rep( j, 1, m ) s[i][j] = f[j][i] ; 
		flag = 1 ; 
	}
	Solve() ; 
	printf("%d\n", cnt ) ;
	rep( i, 1, cnt ) {
		if( !flag ) {
			rep( j, 0, 2 ) printf("%d %d ", opt[i].a[j].x, opt[i].a[j].y ) ; 
			puts("") ; 
		}
		else {
			rep( j, 0, 2 ) printf("%d %d ", opt[i].a[j].y, opt[i].a[j].x ) ; 
			puts("") ; 
		}
	} 
}
signed main()
{
	T = gi() ; 
	while( T-- ) solve() ; 
	return 0 ;
}