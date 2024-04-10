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
const int N = 1e6 + 5 ; 
const int P = 998244353 ;
char s[N] ; 
int cnt, n, c1[N], c2[N], pre[N], nxt[N], A[N], B[N], Ans ; 
int fpow( int x, int k ) {
	int ans = 1, base = x ; 
	while( k ) {
		if( k & 1 ) ans = ans * base % P ;
		base = base * base % P, k >>= 1 ;
	} return ans % P ; 
}
signed main()
{
	scanf("%s", s + 1 ) ; n = strlen( s + 1 ) ;
	rep( i, 1, n ) if( s[i] == '?' ) ++ cnt ; c1[0] = c2[0] = 1 ; 
	rep( i, 1, n ) {
		pre[i] = pre[i - 1] ; if( s[i] == '?' ) ++ pre[i] ;
		A[i] = A[i - 1] ; if( s[i] == '(' ) ++ A[i] ;
	}
	for( re int i = n; i >= 1; -- i ) {
		nxt[i] = nxt[i + 1] ; if( s[i] == '?' ) ++ nxt[i] ;
		B[i] = B[i + 1] ; if( s[i] == ')' ) ++ B[i] ;
	}
	rep( i, 1, cnt ) c1[i] = c1[i - 1] * ( cnt - i + 1 ) % P * fpow( i, P - 2 ) % P ; 
	rep( i, 1, cnt ) c2[i] = c2[i - 1] * ( cnt - i ) % P * fpow( i, P - 2 ) % P ;
	rep( i, 1, cnt ) c1[i] = ( c1[i] + c1[i - 1] ) % P, c2[i] = ( c2[i] + c2[i - 1] ) % P ; 
	rep( i, 1, n ) {
		int m = A[i - 1] - B[i + 1] + pre[i - 1] - 1 ;
		if( m < 0 ) continue ; 
		if( s[i] == ')' ) Ans = ( Ans + c1[min( m, cnt )] ) % P ; 
		if( s[i] == '?' ) Ans = ( Ans + c2[min( m, cnt - 1 )] ) % P ; 
	}
	printf("%lld\n", Ans ) ;
	return 0 ;
}