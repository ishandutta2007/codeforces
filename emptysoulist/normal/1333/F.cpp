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
const int N = 5e5 + 5 ; 
int n, f[N], d[N], ans[N] ; 
struct node {
	int id, w ; 
	bool operator < ( const node& x ) const {
		return w > x.w ; 
	}
} ;
priority_queue<node> q ; 
signed main()
{
	n = gi() ;
	rep( i, 1, n ) for( re int j = i; j <= n; j += i ) ++ d[j] ;
	rep( i, 1, n ) {
		-- d[i] ; 
		if( d[i] == 1 ) q.push((node){ i, 1 }) ; 
		f[i] = 1 ; 
	}
	
	for( re int i = 1; i < n; ++ i ) {
		int u = q.top().id ; 
		for( re int j = 2 * u; j <= n; j += u ) {
			-- d[j], f[j] = max( f[j], u ) ;
			if( d[j] == 1 ) q.push((node){ j, f[j] }) ;
		}
		ans[i + 1] = max( ans[i], q.top().w ), q.pop() ; 
	}
	rep( i, 2, n ) printf("%I64d ", ans[i] ) ;
	return 0 ;
}