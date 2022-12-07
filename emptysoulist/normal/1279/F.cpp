#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
const int N = 1e6 + 5 ;
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
int n, k, l, pre[N], cnt[N], f[N], a[N], Ans ;
char s[N] ; 
void DP( int x ) {
	rep( i, 1, n ) {
		f[i] = f[i - 1] + a[i], cnt[i] = cnt[i - 1] ; int y = max( i - l, 0ll ) ;
		if( ( ( f[y] + x < f[i] ) || ( ( f[y] + x == f[i] ) && ( cnt[y] + 1 < cnt[i] ) ) ) ) {
			f[i] = f[y] + x, cnt[i] = cnt[y] + 1 ;
		}
	}
}
int calc(){
	int L = 0, R = n + 1, tp = 0 ;
	while( L <= R ) {
		int mid = ( L + R ) >> 1LL, c = 0 ; DP(mid) ;
		c = cnt[n] ; 
		if( c > k ) L = mid + 1 ;
		else tp = mid, R = mid - 1 ;
	} DP(tp) ;
	return f[n] - tp * k ; 
}
signed main() {
	n = gi(), k = gi(), l = gi(), scanf("%s", s + 1 ) ;
	if( k * l >= n ) { puts("0") ; exit(0) ; }
	rep( i, 1, n ) a[i] = ( s[i] >= 'A' && s[i] <= 'Z' ) ;
	Ans = calc() ; 
	rep( i, 1, n ) a[i] = ( s[i] >= 'a' && s[i] <= 'z' ) ;
	Ans = min( Ans, calc() ) ; 
	printf("%I64d\n", Ans ) ;
	return 0 ; 
}