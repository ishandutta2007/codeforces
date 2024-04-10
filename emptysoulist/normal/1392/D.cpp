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
const int inf = 1e8 + 7 ; 
const int N = 4e5 + 5 ; 
int n ; 
char s[N] ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi() ; int ans = 0 ;
		scanf("%s", s + 1 ) ;
		rep( i, 1, n ) s[i + n] = s[i] ;
		int tmp = s[1], fl = 0 ;
		rep( i, 1, n ) if( tmp != s[i] ) fl = 1 ; 
		if( !fl ) printf("%d\n", (n + 2) / 3) ; 
		else {
			int pos = 0 ; 
			rep( i, 1, n ) if( s[i] != s[n] ) { pos = i; break ; }
			rep( i, 1, n ) s[i] = s[i + pos - 1] ;
			pos = 0 ; 
			rep( i, 1, n ) {
				if( s[i] != s[i - 1] ) ans += (pos / 3), pos = 0 ;
				++ pos ;  
			}
			ans += (pos / 3) ; 
			cout << ans << endl ; 
		} 
	}
	return 0 ;
}