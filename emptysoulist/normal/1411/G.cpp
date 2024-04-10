#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define int long long
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int P = 998244353 ; 
const int N = 1e5 + 5 ; 
const int M = 550 ; 
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
int n, m, sg[N], ex[M], f[M], cnt[M], A[M][M] ;  
vector<int> G[N] ; 
void add(int x, int y) { G[x].pb(y) ; } 
int DFS(int x) {
	if(sg[x]) return sg[x] ; 
	vector<int> st ; 
	for(int v : G[x]) st.pb(DFS(v)) ; 
	for(int v : st) ex[v] = 1 ; int ip = 0 ; 
	while(ex[ip]) ++ ip ; sg[x] = ip ; 
	for(int v : st) ex[v] = 0 ; 
	return ip ; 
}
void inc(int &x, int y) {
	x += y, x %= P ; 
}
signed main()
{
	n = gi(), m = gi() ; int x, y ; 
	rep( i, 1, m ) x = gi(), y = gi(), add(x, y) ; 
	rep( i, 1, n ) sg[i] = DFS(i) ; 
	rep( i, 1, n ) ++ cnt[sg[i]] ;  
	int iv = fpow(n + 1, P - 2) ;
	rep( i, 0, 511 ) cnt[i] = cnt[i] * iv % P ; 
	rep( i, 0, 511 ) {
		rep( j, 0, 511 ) A[i][j] = cnt[i ^ j] ; 
		A[i][512] = (P - (i != 0) * iv) % P ; 
		A[i][i] = (A[i][i] - 1) % P ; 
	}
	rep( i, 0, 511 ) rep( j, 0, 511 ) {
		if(i == j) continue ; 
		if(!A[j][i]) continue ; 
		int p = fpow(A[i][i], P - 2) * A[j][i] % P ; 
		for(int k = 0; k <= 512; ++ k) {
			A[j][k] = (A[j][k] - A[i][k] * p % P + P) % P ;  
		}
	}
	rep( i, 0, 511 ) f[i] = fpow(A[i][i], P - 2) * A[i][512] % P ; 
	cout << f[0] % P << endl ; 
	return 0 ; 
}