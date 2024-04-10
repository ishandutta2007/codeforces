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
const int N = 3e5 + 5 ; 
int t, n, B[N], a[N], pre[N], nxt[N] ; 
int gcd(int x, int y) {
	if(!x || !y) return x + y ; 
	return gcd(y % x, x) ; 
}
signed main()
{
	t = gi() ; 
	while(t--) {
		n = gi() ; int k = gi() ;  
		rep( i, 1, n ) a[i] = gi() ; 
		rep( i, 2, n ) B[i] = a[i] - a[i - 1] ; 
		rep( i, 2, n ) pre[i] = (i == 2) ? B[i] : gcd(pre[i - 1], B[i]) ; 
		int flag = 0 ; 
		rep( i, 1, n ) {
			int g = pre[n] ;
			g = gcd(g, a[i] - a[1]) ;
			if((k - a[i]) % g == 0) flag = 1 ; 
		}
		rep( i, 1, n ) B[i] = pre[i] = nxt[i] = 0 ;
		if(flag) puts("YES") ; 
		else puts("NO") ; 
	}
	return 0 ;
}