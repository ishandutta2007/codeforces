#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
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
const int P = 1e9 + 7 ; 
const int N = 505 ; 
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
int n, m, lim, D, L, A[N], B[N], H[N], F[N], Q[N] ; 
void inc(int &x, int y) { ((x += y) >= P) && (x -= P) ; }
void dec(int &x, int y) { ((x -= y) < 0) && (x += P) ; }
int fp[N], ans[N], base[N] ; 
void Mul(int *a, int *b) {
	rep( i, 0, lim ) fp[i] = 0 ; 
	rep( i, 0, D ) rep( j, 0, D ) 
	inc(fp[i + j], a[i] * b[j] % P) ; 
	rep( i, 0, lim ) a[i] = fp[i] ; 
}
void Mod(int *a) {
	for(int i = lim; i >= D; -- i) 
		drep( j, 0, D ) dec(a[i - j], a[i] * Q[D - j] % P) ; 
}
void fpow(int *a, int k) {
	rep( j, 0, lim ) ans[j] = base[j] = 0 ;
	rep( j, 0, lim ) base[j] = a[j] ; ans[0] = 1 ; 
	while(k) {
		if(k & 1) Mul(ans, base), Mod(ans) ;
		Mul(base, base), Mod(base), k >>= 1 ;  
	} rep( i, 0, D ) a[i] = ans[i] ; 
}
signed main()
{
	n = gi(), m = gi(), L = gi() ; 
	rep( i, 1, n ) A[i] = gi() ; 
	rep( i, 1, m ) B[i] = gi(), D = max(D, B[i]) ; 
	Q[D] = 1 ; rep( i, 1, m ) dec(Q[D - B[i]], 1) ; 
	lim = 2 * D ; 
	rep( i, 1, n ) {
		rep( j, 0, lim ) F[j] = 0 ; 
		F[1] = 1, fpow(F, A[i]) ; 
		rep( j, 0, D ) inc(H[j], F[j]) ; 
	} fpow(H, L) ; 
	drep( i, 0, D ) rep( j, 1, m ) 
	if(i >= B[j]) inc(H[i - B[j]], H[i]) ; 
	cout << H[0] << endl ; 
	return 0 ;
}