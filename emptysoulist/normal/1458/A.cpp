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
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
int n, m, a[N], b[N] ; 
int gcd(int x, int y) {
	return (!x) ? y : gcd(y % x, x) ; 
}
signed main()
{
	n = gi(), m = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	rep( i, 1, m ) b[i] = gi() ;
	if(n == 1) {
		rep( i, 1, m ) printf("%lld ", b[i] + a[1] ) ; exit(0) ; 
	}
	sort(a + 1, a + n + 1) ; 
	int t = a[2] - a[1] ; 
	rep( i, 2, n ) t = gcd(t, a[i] - a[i - 1]) ; 
	rep( i, 1, m ) printf("%lld ", gcd(a[n] + b[i], t)) ; 
	return 0 ;
}