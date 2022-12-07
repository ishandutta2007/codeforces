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
int f[N << 1] ; 
int n, a[N], D[N], sum, Mx, num, Id, cnt[N] ; 
vector<int> col ; 
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) a[i] = gi(), ++ cnt[a[i]] ; 
	rep( i, 1, n ) 
	if( cnt[i] > Mx ) Mx = cnt[i], Id = i, num = 1 ; 
	else if( cnt[i] == Mx ) ++ num ; 
	if( num > 1 ) { cout << n << endl ; exit(0) ; }
	for(re int i = 1; i <= n; ++ i) if(a[i] == Id) D[i] = 1 ; 
	int Ans = 0 ; 
	for(re int i = 1; i <= min(n, 100); ++ i) {
		rep( j, 0, 2 * n ) f[j] = 0 ; f[n] = 1 ; 
		if( i == Id ) continue ; 
		rep( j, 1, n ) if( a[j] == i ) D[j] = -1 ; sum = 0 ; 
		rep( j, 1, n ) {
			sum += D[j] ; 
			if( !f[sum + n] ) f[sum + n] = j + 1 ; 
			Ans = max( Ans, j + 1 - f[sum + n] ) ;
		}
		rep( j, 1, n ) if( a[j] == i ) D[j] = 0 ; 
	}
	cout << Ans << endl ; 
	return 0 ;
}