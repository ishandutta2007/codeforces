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
const int N = 100 + 5 ;
int n, a[N] ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		rep( i, 1, 3 ) a[i] = gi() ; 
		sort( a + 1, a + 3 + 1 ) ; //4 1 2
		//1 2 1 3 1 3 1 
		if( a[1] + a[2] + 1 >= a[3] ) printf("Yes\n") ;
		else puts("No") ;
	}
	return 0 ;
}