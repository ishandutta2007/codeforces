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
const int N = 1e5 + 5 ; 
char A[N], B[N] ; 
int n ;  
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi() ; 
		scanf("%s", A + 1 ), scanf("%s", B + 1 ) ;
		int flag = 1, ans = 0 ; 
		rep( i, 1, n ) if( A[i] > B[i] ) flag = 0 ; 
		if( !flag ) { puts("-1") ; continue ; }
		for(char c = 'a'; c <= 't'; ++ c) {
			char f = 't' + 1 ;
			rep( i, 1, n ) if(A[i] == c && B[i] != c) f = min(f, B[i]) ;
			if( f == 't' + 1 ) continue ; 
			++ ans ; 
			rep( i, 1, n ) if(A[i] == c && B[i] != c) A[i] = f ; 
		}
		cout << ans << endl ; 
	} 
	return 0 ;
}