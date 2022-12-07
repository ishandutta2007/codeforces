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
int T, n, a[N] ; 
char s[N] ; 
signed main()
{
	T = gi() ; 
	while( T-- ) {
		scanf("%s", s + 1 ) ;
		n = strlen(s + 1) ;
		rep( i, 1, n ) {
			if( s[i] == 'A' ) a[i] = 0 ;
			if( s[i] == 'B' ) a[i] = 1 ; 
		}
		int cnt = 0, cnt2 = 0, ans = 0, flag = 0 ; 
		rep( i, 1, n ) {
			if( a[i] == 0 ) ++ cnt ; 
			else {
				if(cnt2) cnt2 = 0 ;
				else if(cnt > 0) -- cnt ; 
				else ++ cnt2 ; 
			}
		}
		cout << cnt + cnt2 << endl ; 
	}
	return 0 ;
}