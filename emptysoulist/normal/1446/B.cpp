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
const int N = 5000 + 5 ; 
int n, m, f[N][N] ; 
char A[N], B[N] ; 
signed main()
{
	n = gi(), m = gi() ; 
	scanf("%s", A + 1 ) ;
	scanf("%s", B + 1 ) ; 
	int Ans = 0 ; 
	rep( i, 1, n ) rep( j, 1, m ) {
		f[i][j] = max( 0, f[i - 1][j - 1] ) + ((A[i] == B[j]) ? 2 : -2) ; 
		f[i][j] = max( f[i][j], max( f[i - 1][j], f[i][j - 1] ) - 1 ) ; 
		Ans = max( Ans, f[i][j] ) ; 
	}
	cout << Ans << endl ; 
	return 0 ;
}