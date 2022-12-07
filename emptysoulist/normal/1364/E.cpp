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
const int N = 2048 + 5 ; 
int n, P[N], tp[N] ; 
signed main()
{
	srand(time(NULL)) ; 
	n = gi() ; 
	rep( i, 1, n ) tp[i] = i ; 
	random_shuffle(tp + 1, tp + n + 1) ;
	int x = tp[1], y = tp[2] ; 
	printf("? %d %d\n", tp[1], tp[2] ), cout.flush() ; 
	int val = gi() ; 
	rep( i, 3, n ) {
		printf("? %d %d\n", y, tp[i] ), cout.flush() ; 
		int fs = gi() ; 
		if( fs > val ) continue ;
		else if( fs < val ) val = fs, x = tp[i] ;
		else if( fs == val ) {
			y = tp[i] ;
			printf("? %d %d\n", x, y ), cout.flush() ;
			val = gi() ; 
		}
	}
	int f0 = x, f1 = y ; 
	rep( i, 1, 100 ) {
		int u = rand() % n + 1 ; 
		if( u == x || u == y ) continue ; 
		printf("? %d %d\n", u, y ), cout.flush() ;
		int fs1 = gi() ; 
		printf("? %d %d\n", x, u ), cout.flush() ; 
		int fs2 = gi() ;
		if( fs1 == fs2 ) continue ; 
		else {
			f0 = ( fs1 > fs2 ) ? x : y ; 
			break ; 
		}
	} 
	rep( i, 1, n ) {
		if( f0 == i ) continue ; 
		printf("? %d %d\n", i, f0 ), cout.flush() ;
		P[i] = gi() ; 
	}
	printf("! ") ;
	rep( i, 1, n ) printf("%d ", P[i] ) ;
	return 0 ;
}