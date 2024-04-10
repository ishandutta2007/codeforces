#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 3e5 + 5 ; 
int n, a[N], L, Ans, Ed[2] ;
char s[N] ; 
signed main()
{
	n = gi() ; scanf("%s", s + 1 ) ;
	rep( i, 1, n ) {
		a[i] = s[i] - 'A' ; 
		if( !Ed[a[i] ^ 1] ) Ans += ( i - 1 ) ;
		else {
			if( Ed[a[i] ^ 1] == i - 1 ) Ans += ( Ed[a[i]] ) ;
			if( Ed[a[i]] == i - 1 ) Ans += ( i - 2 ) ;
		}
		Ed[a[i]] = i ; 
	}
	printf("%I64d\n", Ans ) ; 
	return 0 ;
}