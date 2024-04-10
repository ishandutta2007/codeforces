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
int T, n, a[N], b[N], st[N], top ;  
char s[N], t[N] ; 
signed main()
{
	T = gi() ; 
	while( T-- ) {
		n = gi() ; 
		scanf("%s", s + 1 ) ;
		scanf("%s", t + 1 ) ;
		rep( i, 1, n ) a[i] = s[i] - '0', b[i] = t[i] - '0' ; 
		for( re int i = n; i >= 1; -- i ) {
			if( a[i] == b[i] ) continue ; 
			if( a[1] == b[i] ) {
				st[++ top] = 1, st[++ top] = i ; 
				for( re int j = 1; j <= i / 2; ++ j ) 
					swap( a[j], a[i - j + 1] ) ; 
				for( re int j = 1; j <= i; ++ j ) a[j] ^= 1 ; 
			}
			else if( a[1] != b[i] ) {
				st[++ top] = i ; 
				for( re int j = 1; j <= i / 2; ++ j ) 
					swap( a[j], a[i - j + 1] ) ; 
				for( re int j = 1; j <= i; ++ j ) a[j] ^= 1 ; 
			}
		}
		printf("%d ", top ) ;
		rep( i, 1, top ) printf("%d ", st[i] ) ; 
		puts("") ; 
		top = 0 ; 
	}
	return 0 ;
}