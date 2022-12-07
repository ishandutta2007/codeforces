#include<bits/stdc++.h>
using namespace std;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define ls(x) tr[x].l
#define rs(x) tr[x].r
#define maxn 1e9
#define inf 1e17
#define int long long
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int N = 2e5 + 5 ; 
int Ans, n, m, e, K, w[N], Id[N], totA, totB, totC ; 
int vis[N], A[N], B[N], C[N], idnex, rt, sz ;
struct Tr {
	int l, r, gk, val ; 
} tr[N * 35] ;
bool cmp( int x, int y ) {
	return w[x] < w[y] ; 
}
void Ins( int &x, int l, int r, int w ) {
	if( !x ) x = ++ idnex ; ++ tr[x].gk, tr[x].val += w ; 
	if( l == r ) return ; 
	int mid = ( l + r ) >> 1 ; 
	if( mid >= w ) Ins( ls(x), l, mid, w ) ;
	else Ins( rs(x), mid + 1, r, w ) ;
}
int Query( int x, int l, int r, int k ) {
	if( !x ) return inf ; 
	if( k < 0 ) return inf ; 
	if( !k ) return 0 ; 
	if( l == r ) return k * l ; 
	int mid = ( l + r ) >> 1 ; 
	if( tr[ls(x)].gk >= k ) return Query( ls(x), l, mid, k ) ;
	else return tr[ls(x)].val + Query( rs(x), mid + 1, r, k - tr[ls(x)].gk ) ;
}
signed main()
{
	n = read(), K = read(), m = read() ; 
	rep( i, 1, n ) w[i] = read(), Id[i] = i ; 
	e = read() ; rep( i, 1, e ) vis[read()] += 1 ;
	e = read() ; rep( i, 1, e ) vis[read()] += 2 ; 
	sort( Id + 1, Id + n + 1, cmp ) ; int flag = 0 ;
	rep( i, 1, n ) {
		if( !vis[Id[i]] ) Ins( rt, 1, maxn, w[Id[i]] ), ++ sz ;
		if( vis[Id[i]] == 1 ) A[++ totA] = Id[i] ; 
		if( vis[Id[i]] == 2 ) B[++ totB] = Id[i] ; 
		if( vis[Id[i]] == 3 ) C[++ totC] = Id[i] ; 
	}
	while( totA > m ) Ins( rt, 1, maxn, w[A[totA]] ), -- totA, ++ sz ;
	while( totB > m ) Ins( rt, 1, maxn, w[B[totB]] ), -- totB, ++ sz ; 
	int sum = inf, sum1 = 0, sum2 = 0, sum3 = 0 ; 
	rep( i, 1, totA ) sum1 += w[A[i]] ;
	rep( i, 1, totB ) sum2 += w[B[i]] ; 
	rep( i, 0, totC ) {
		while( totA > m - i && totA > 0 ) Ins( rt, 1, maxn, w[A[totA]] ), sum1 -= w[A[totA]], -- totA, ++ sz ; 
		while( totB > m - i && totB > 0 ) Ins( rt, 1, maxn, w[B[totB]] ), sum2 -= w[B[totB]], -- totB, ++ sz ;
	//	if( i > K ) break ; 
		sum3 += w[C[i]] ;
		if( totA >= m - i && totB >= m - i ) {
			flag = 1, sum = min( sum, sum3 + sum1 + sum2 + Query( 1, 1, maxn, K - i - totA - totB ) ) ;
		}
	}
	if( sum < inf ) printf("%lld\n", sum ) ;
	else puts("-1") ; 
	return 0 ;
}