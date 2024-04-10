#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 5e5 + 5 ; 
int T, n, ans[N] ; 
char s[N] ; 
signed main()
{
	T = gi() ; 
	while( T-- ) {
		n = gi() ; 
		scanf("%s", s + 1 ) ;
		int flag = 0, flag2 = 0 ;
		rep( i, 1, n ) {
			if( s[i] == '<' ) flag = 1 ; 
			if( s[i] == '>' ) flag2 = 1 ; 
		}
		if( (!flag) || (!flag2) ) {
			printf("%lld\n", n ) ; continue ; 
		}
		rep( i, 1, n ) {
			if( s[i] == '-' ) ++ ans[i - 1], ++ ans[i % n] ; 
		}
		int Asn = 0 ;
		rep( i, 0, n - 1 ) if(ans[i] > 0) ++ Asn ;
		cout << Asn << endl ; 
		rep( i, 0, n ) ans[i] = 0 ; 
	}
	return 0 ;
}