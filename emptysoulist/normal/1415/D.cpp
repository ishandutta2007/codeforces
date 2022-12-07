#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ; 
int n, a[N], sum[N] ; 
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) a[i] = gi(), sum[i] = sum[i - 1] ^ a[i] ; 
	if(n >= 100) {
		puts("1") ; exit(0) ; 
	}
	int Ans = n + 100 ; 
	rep( i, 1, n ) rep( j, i, n ) {
		rep( k, j + 1, n ) rep( l, k, n ) {
			int v = sum[j] ^ sum[i - 1] ;
			int u = sum[l] ^ sum[k - 1] ;
			if( v > u ) Ans = min( Ans, (j - i) + (l - k) ) ; 
		}
	}
	if( Ans > n ) puts("-1") ; 
	else cout << Ans << endl ; 
	return 0 ;
}