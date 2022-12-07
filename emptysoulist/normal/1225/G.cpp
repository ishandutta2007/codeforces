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
const int N = (1 << 17) + 5 ; 
const int S = 2047 ; 
int n, k, m, flag, top, st[25], zk[25], a[25], c[25] ; 
bitset<S> dp[N] ;  
void Dfs(int u, int w) {
	if( u == 0 && w == 0 ) return flag = 1, void(); 
	if( flag ) return ; 
	if( (w * k <= m) && dp[u][w * k] ) {
		for(int i = 0; i < n; ++ i) if( (1 << i) & u ) ++ c[i] ;
		Dfs(u, w * k) ;
	}
	else {
		for(int i = 0; i < n; ++ i)
			if( ((1 << i) & u) && a[i] <= w && dp[(1 << i) ^ u][w - a[i]] ) 
				Dfs((1 << i) ^ u, w - a[i]) ;
	}
}
signed main()
{
	n = gi(), k = gi() ; int maxn = (1 << n) - 1 ; 
	rep( i, 1, n ) a[i - 1] = gi(), m += a[i - 1] ; 
	dp[0][0] = 1 ; 
	rep( i, 0, maxn ) {
		for(re int j = m; j >= k; -- j) 
		if( (j % k == 0) && dp[i][j] ) dp[i][j / k] = 1 ;  
		for(re int j = 0; j < n; ++ j)
		if( !((1 << j) & i) ) 
			dp[i | (1 << j)] |= (dp[i] << a[j]) ;
	}
	if( !dp[maxn][1] ) { puts("NO") ; exit(0) ; }
	puts("YES"), Dfs(maxn, 1), top = n ; 
	for(re int i = 1; i < n; ++ i) {
		int op1 = -1, op2 = -1, mx = 0, lp = top ; top = 0 ;
		for(re int j = 0; j < lp; ++ j) mx = max( mx, c[j] ) ;
		for(re int j = 0; j < lp; ++ j) {
			if( (c[j] == mx) && (op1 == -1) ) op1 = j ; 
			else if((c[j] == mx) && (op2 == -1)) op2 = j ; 
			else st[++ top] = a[j], zk[top] = c[j] ; 
		}
		printf("%d %d\n", a[op1], a[op2] ) ;
		int u = a[op1] + a[op2], b = mx ;
		while( u % k == 0 ) u /= k, -- b ; 
		st[++ top] = u, zk[top] = b ;
		rep( j, 1, top ) a[j - 1] = st[j], c[j - 1] = zk[j] ; 
	}
	return 0 ;
}