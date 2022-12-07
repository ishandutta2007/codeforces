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
const int N = 50 + 5 ; 
int n, a[N], dis[N] ;  
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi() ; 
		rep( i, 1, n ) a[i] = gi() ; 
		rep( i, 1, n ) {
			rep( j, 1, i ) dis[a[i] - a[j]] = 1 ; 
		}
		int ans = 0 ; 
		for(re int i = 1; i <= 50; ++ i)
		if(dis[i]) ++ ans ; 
		cout << ans << endl ; 
		rep( i, 0, 50 ) dis[i] = 0 ; 
	}
	return 0 ;
}