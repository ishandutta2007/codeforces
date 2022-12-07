#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 20 + 5 ; 
int n, a[N], m, b[N], dp[(1 << 20) + 5] ; 
int flag, c[N], num, K, cnt, st[(1 << 12)], top ; 
struct hashmap {
	static const int maxn = 2192 , P = 999983 ;
	struct node {
		int next, key, val ;
	} e[maxn] ;
	int head[P + 100], cnt ;
	inline void ins(int x, int k) {
		int hsh = (x % P + P) % P ;
		for (int i = head[hsh]; i; i = e[i].next)
			if (e[i].key == x) return void(e[i].val += k) ;
		e[++ cnt] = (node){head[hsh], x, 1}, head[hsh] = cnt ;
	}
	inline bool qry(int x) {
		int hsh = (x % P + P) % P ; 
		for ( int i = head[hsh]; i; i = e[i].next)
			if( e[i].key == x && e[i].val > 0 ) return 1 ;
		return 0 ; 
	}
	inline void del(int x) {
		head[(x % P + P) % P] = 0 ; 
	}
	inline void clear() { 
		rep( i, 1, cnt ) e[i].next = e[i].key = e[i].val = 0 ;
		cnt = 0 ; 
	}
} Hsh ; 
void Dfs1(int x, int ed, int S) {
	if( x == ed + 1 ) {
		return Hsh.ins(2 * S, 1), st[++ top] = S, void() ; 
	}
	Dfs1(x + 1, ed, S), Dfs1(x + 1, ed, S + c[x]) ; 
}  
void Dfs2(int x, int ed, int fl, int S) {
	if( x == ed + 1 ) { 
		if( !fl ) Hsh.ins(0, -1) ;  
		for( re int j = K + cnt - 1; j >= K; j -= 2 ) 
			if( Hsh.qry(j - 2 * S) ) flag = 1 ; 
		if( !fl ) Hsh.ins(0, 1) ; 
		return ; 
	}
	Dfs2(x + 1, ed, fl, S), Dfs2(x + 1, ed, 1, S + c[x]) ; 
} 
bool check(int x) {
	int S = 0 ; num = 0, flag = 0, cnt = 0, top = 0 ; 
	rep( i, 1, n ) if( (x >> (i - 1)) & 1 ) c[++ num] = a[i], S += a[i], ++ cnt ; 
	if( num == 1 || ((S & 1) != ((cnt ^ 1) & 1))) return 0 ; 
	Dfs1(1, num / 2, 0) ; 
	K = S, Dfs2(num / 2 + 1, num, 0, 0) ; 
	rep( i, 1, top ) Hsh.del(2 * st[i]) ; Hsh.clear() ;
	return flag ; 
}
signed main()
{
	m = gi() ; 
	rep( i, 1, m ) {
		b[i] = gi() ; 
		if( b[i] != 0 ) a[++ n] = b[i] ; 
	}
	if( n == 0 ) { puts("0") ; exit(0) ; }
	int lim = (1 << n) - 1 ; 
	rep( i, 1, lim ) if( (dp[i] == 0) && check(i) ) {
		dp[i] = 1 ; 
		for(re int k = i; k <= lim; k = (k + 1) | i ) dp[k] = max( dp[k], 1 + dp[i ^ k] ) ;
	}
	dp[lim] = max( dp[lim], 0ll ) ;
	printf("%lld\n", n - dp[lim] ) ;
	return 0 ;
}