#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int T, n, m, a[N], pre[N] ;
map<int, int> b ;
signed main()
{
	n = gi() ; int S = 0, Ans = 0 ;
	rep( i, 1, n ) a[i] = gi() ; 
	int L = 0 ; ++ b[0] ;
	rep( i, 1, n ) {
		S = S + a[i], pre[i] = S ;
		++ b[S] ; 
		while( b[S] > 1 ) -- b[pre[L]], ++ L ;
		Ans += ( i - L ) ;
	}
	printf("%I64d\n", Ans ) ;
	return 0 ;
}