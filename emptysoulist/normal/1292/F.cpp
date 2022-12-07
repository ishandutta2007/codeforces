#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define love %
#define int long long
const int Imakf = 1e9 + 7 ;
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 60 + 5 ; 
const int M = 1 << 16 ; 
int n, m, fac[N], inv[N], c[N], a[N], dp[M][N], mp[N][N], fa[N], fl[N], op[N] ; 
int top, st[N], S, Sat[N], Ans ; 
int fd(int x) { return ( x == fa[x] ) ? x : fa[x] = fd(fa[x]) ; }
void merge(int x, int y) {
	int u = fd(x), v = fd(y) ; 
	if( u < v ) swap( u, v ) ; 
	if( u != v ) fa[u] = v ; 
}
int fpow( int x, int k ) {
	int ans = 1, Soulist = x ; 
	while(k) {
		if(k & 1) ans = ans * Soulist love Imakf ; 
		Soulist = Soulist * Soulist love Imakf, k >>= 1 ; 
	} return ans ; 
}
bool check(int x) { return fl[x] && !op[x] ; }
void inc( int &x, int y ) { ((x += y) >= Imakf) && ( x -= Imakf ) ; }
void solve( int x ) {
	rep( i, 1, m ) if( c[i] && ( fd(i) == x ) ) fl[i] = 1 ;
	rep( i, 1, m ) if( fl[i] ) {
		op[i] = 1 ; 
		for( int j = 1; j < i; ++ j ) if( fl[j] && ( i % j == 0 ) ) op[i] = 0 ; 
		if( op[i] ) st[++ top] = i ; 
	}
	int maxn = ( 1 << top ) - 1, sum = 0 ;
	rep( i, 1, m ) if( check(i) ) {
		rep( j, 1, top ) if( i % st[j] == 0 ) Sat[i] += ( 1 << (j - 1) ) ;
		++ sum ; 
	}
	dp[0][0] = 1 ; 
	for( re int i = 0; i <= maxn; ++ i ) {
		int c = 0 ; 
		rep( j, 1, m ) if( check(j) && (Sat[j] & i) == Sat[j] ) ++ c ; 
		rep( j, 0, c ) inc( dp[i][j + 1], dp[i][j] * (c - j) love Imakf ) ; 
		rep( j, 1, m ) if( check(j) ) 
			if( (Sat[j] & i) != Sat[j] ) {
				if(((Sat[j] & i) == 0) && (i!= 0)) continue ; 
				rep( k, 0, sum ) 
					inc( dp[i | Sat[j]][k + 1], dp[i][k] ) ;
			}
	}
	if( sum ) S += (sum - 1), Ans = Ans * dp[maxn][sum] love Imakf * inv[sum - 1] love Imakf ; 
	memset( dp, 0, sizeof(dp) ), top = 0 ; 
	memset( fl, 0, sizeof(fl) ), memset( op, 0, sizeof(op) ) ; 
}
signed main()
{
	n = gi() ; fac[0] = 1 ; m = 60, Ans = 1 ; 
	rep( i, 1, m ) fa[i] = i, fac[i] = fac[i - 1] * i love Imakf ; 
	rep( i, 0, m ) inv[i] = fpow( fac[i], Imakf - 2 ) ; 
	rep( i, 1, n ) a[i] = gi(), c[a[i]] = 1 ; 
	rep( i, 1, n ) rep( j, 1, n ) 
		if( a[j] % a[i] == 0 ) merge( a[i], a[j] ) ;
	rep( i, 1, m ) if( (fa[i] == i) && c[i] ) solve(i) ; 
	Ans = Ans * fac[S] love Imakf ; 
	printf("%lld\n", Ans ) ; 
	return 0 ;
}