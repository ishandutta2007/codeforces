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
const int P = 998244353 ; 
const int N = 1e5 + 5 ; 
const int M = 322 ;
int n, K, a[N], f[N], sum[N], pre[N], w[N], Id[N], kS ; 
int idx, cnt, nw[M], ans[M], tag[M], col[M][(N * 2) + 5], L[M], R[M] ; 
void inc(int &x, int y) { ((x += y) >= P) && (x -= P) ; }
void dec(int &x, int y) { ((x -= y) < 0) && (x += P) ; }
void Rmove(int x) { ++ nw[x] ; if( nw[x] > 0 ) dec(ans[x], col[x][nw[x] - 1]) ; }
void Lmove(int x) { -- nw[x] ; if( nw[x] >= 0 ) inc(ans[x], col[x][nw[x]]) ; }
void Ins(int x) { ++ tag[x], Lmove(x) ; }
void Del(int x) { -- tag[x], Rmove(x) ; }
void Push(int x, int l, int r, int type) {
	nw[x] = kS, ans[x] = 0 ;
	rep( i, L[x], R[x] ) col[x][sum[i]] = 0, sum[i] += tag[x] ; 
	rep( i, l, r ) sum[i] += type ; tag[x] = 0 ; 
	rep( i, L[x], R[x] ) {
		inc(col[x][sum[i]], f[i]) ; 
		if( sum[i] >= kS ) inc(ans[x], f[i]) ;
	}
}
void SIns(int l) { Push(Id[l], l, R[Id[l]], 1) ; rep( i, Id[l] + 1, idx ) Ins(i) ; }
void SDel(int l) { Push(Id[l], l, R[Id[l]], -1) ; rep( i, Id[l] + 1, idx ) Del(i) ; }
void RKS() { for(re int i = 1; i <= idx; ++ i) Rmove(i) ; ++ kS ; }
void LKS() { for(re int i = 1; i <= idx; ++ i) Lmove(i) ; -- kS ; }
signed main()
{
	n = gi(), K = gi() ; cnt = sqrt(n) ;
	if( (n / cnt) > 300 ) cnt = n / 300 ; 
	rep( i, 1, n ) 
		a[i] = gi(), pre[i] = w[a[i]], w[a[i]] = i ; 
	idx = 1, L[idx] = 0 ; 
	rep( i, 0, n ) {
		Id[i] = idx ; 
		if( i % cnt == 0 ) 
			R[idx] = i, L[++ idx] = i + 1 ; 
	}
	R[idx] = n, kS = n - K ;
	if( R[idx - 1] == n ) -- idx ; 
	rep( i, 0, n ) sum[i] = n ;  
	rep( i, 1, idx ) nw[i] = n - K ; 
	col[1][n] = 1, f[0] = 1, ans[1] = 1 ; 
	rep( i, 1, n ) {
		int de = 0 ;
		if( pre[pre[i]] ) ++ de, SIns(pre[pre[i]]) ; 
		if( pre[i] ) de -= 2, SDel(pre[i]), SDel(pre[i]) ;
		SIns(i), ++ de ; 
		while( de > 0 ) RKS(), -- de ;
		while( de < 0 ) LKS(), ++ de ; 
		rep( j, 1, idx ) inc(f[i], ans[j]) ;
		Push(Id[i], L[Id[i]], R[Id[i]], 0) ;
	}
	cout << f[n] << endl ; 
	return 0 ;
}