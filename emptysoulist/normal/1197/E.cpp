// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define ls(x) x * 2
#define rs(x) x * 2 + 1
#define inf 12345678900
#define int long long
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int mod = 1e9 + 7 ;
const int N = 2e5 + 5 ; 
int n, dp[N], g[N], Mi, Mx, cnt ; 
struct node {
	int in, out, in2, out2 ; 
} a[N];
struct Node {
	int val, sum ; 
};
struct S {
	int val, id, ip ;
} s[N * 2] ;
struct Tree {
	int mi, sum ; 
} tr[N * 5];
bool cmp( node x, node y ) {
	return x.out < y.out ;
}
bool cmp2( S x, S y ) {
	return x.val < y.val ; 
}
void build( int x, int l, int r ) {
	tr[x].mi = inf ; 
	if( l == r ) return ;
	int mid = ( l + r ) >> 1 ;
	build( ls(x), l, mid ), build( rs(x), mid + 1, r ) ;
}
Node up( Node lx, Node rx ) {
	if( lx.val < rx.val ) return lx ;
	if( rx.val < lx.val ) return rx ;
	return (Node){ lx.val, ( lx.sum + rx.sum ) % mod } ;
}
Node query( int x, int l, int r, int ql, int qr ) {
	if( ql <= l && r <= qr ) return (Node){ tr[x].mi, tr[x].sum } ;
	int mid = ( l + r ) >> 1 ;
	if( mid >= qr ) return query( ls(x), l, mid, ql, qr ) ;
	if( mid < ql ) return query( rs(x), mid + 1, r, ql, qr ) ;
	return up( query( ls(x), l, mid, ql, qr ), query( rs(x), mid + 1, r, ql, qr ) ) ;
}
void update( int x, int l, int r, int wh, int val, int sum ) {
	if( l == r ) {
		if( tr[x].mi == val ) tr[x].sum += sum, tr[x].sum %= mod ; 
		if( tr[x].mi > val ) tr[x].mi = val, tr[x].sum = sum ;
		return ;
	}
	int mid = ( l + r ) >> 1 ; 
	if( mid >= wh ) update( ls(x), l, mid, wh, val, sum ) ;
	else update( rs(x), mid + 1, r, wh, val, sum ) ;
	tr[x] = tr[ls(x)] ;
	if( tr[x].mi == tr[rs(x)].mi ) tr[x].sum += tr[rs(x)].sum ; 
	if( tr[rs(x)].mi < tr[x].mi ) tr[x] = tr[rs(x)] ;
	tr[x].sum %= mod ;
}
signed main()
{
	n = read() ; 
	rep( i, 1, n ) a[i].out = read(), a[i].in = read(), Mx = max( Mx, a[i].in ), 
	s[++ cnt].id = i, s[cnt].ip = -1, s[cnt].val = a[i].in, 
	s[++ cnt].id = i, s[cnt].ip = 1,  s[cnt].val = a[i].out ; 
	sort( s + 1, s + cnt + 1, cmp2 ) ; int num = 0 ;
	rep( i, 1, cnt ) {
		if( s[i].val != s[i - 1].val ) ++ num ;
		if( s[i].ip == 1 ) a[s[i].id].out2 = num ;
		else a[s[i].id].in2 = num ; 
	}
	sort( a + 1, a + n + 1, cmp ) ; 
	Mi = inf ; build( 1, 1, num ) ;
	rep( i, 1, n ) {
		dp[i] = a[i].in, g[i] = 1 ; 
		Node x = query( 1, 1, num, 1, a[i].in2 ) ;
		if( dp[i] == x.val + a[i].in ) g[i] += x.sum, g[i] %= mod ;
		if( dp[i] > x.val + a[i].in ) dp[i] = x.val + a[i].in, g[i] = x.sum ;
		if( a[i].out > Mx ) Mi = min( Mi, dp[i] ) ; 
		update( 1, 1, num, a[i].out2, dp[i] - a[i].out, g[i] ) ;
	}
	int Ans = 0 ;
	rep( i, 1, n ) {
		if( a[i].out > Mx && Mi == dp[i] ) Ans += g[i], Ans %= mod ; 
	}
	printf("%lld\n", Ans % mod ) ;
	return 0;
}