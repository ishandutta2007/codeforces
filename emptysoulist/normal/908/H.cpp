#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( int i = (s); i < (t); ++ i )
const int N = (1 << 23) + 5 ;
const int M = 50 ; 
const int P = 998244353 ; 
char s[M][M] ; vector<int> bel[M] ; 
int n, limit, cnt, f[N], g[N], st[M], a[M][M], b[M][M], fa[M] ; 
int fd(int x) { return (x == fa[x]) ? x : fa[x] = fd(fa[x]) ; }
void inc(int &x, int y) { ((x += y) >= P) && (x -= P) ; }
void dec(int &x, int y) { ((x -= y) < 0) && (x += P) ; }
void merge(int x, int y) { int u = fd(x), v = fd(y) ; fa[u] = v ; } 
signed main()
{
	cin >> n ; 
	rep( i, 0, n ) fa[i] = i ; 
	rep( i, 0, n ) scanf("%s", s[i]) ; 
	rep( i, 0, n ) rep( j, 0, n ) {
		if(s[i][j] == 'X') a[i][j] = 1 ;
		if(s[i][j] == 'A') merge(i, j) ; 
	}
	rep( i, 0, n ) rep( j, 0, n ) {
		if(s[i][j] != 'X') continue ;
		if(fd(i) == fd(j)) { puts("-1") ; exit(0) ; }
	}
	rep( i, 0, n ) bel[fd(i)].push_back(i) ; 
	rep( i, 0, n ) if(bel[i].size() > 1) st[cnt ++] = i ; 
	rep( i, 0, cnt ) rep( j, 0, cnt ) {
		for(int u : bel[st[i]]) for(int v : bel[st[j]])
		if(a[u][v]) b[i][j] = b[j][i] = 1 ; 
	}
	limit = (1 << cnt), f[0] = 1 ; 
	rep( i, 1, limit ) rep( j, 0, cnt ) if((i >> j) & 1) {
		int S = (i ^ (1 << j)) ; f[i] = f[S] ; 
		rep( k, 0, cnt ) if(((S >> k) & 1) && b[j][k]) f[i] = 0 ; 
		break ; 
	}
	for(int k = 1; k < limit; k <<= 1) 
	for(int i = 0; i < limit; i += (k << 1))
	for(int j = i; j < i + k; ++ j) {
		int nx = f[j], ny = f[j + k] ;
		f[j] = nx + ny, f[j + k] = nx - ny ; 
	}
	rep( i, 0, limit ) g[i] = 1, f[i] = (f[i] + P) % P ; 
	rep( k, 0, n ) {
		int sum = 0 ; 
		rep( i, 0, limit ) ((__builtin_popcount(i)) & 1) ? inc(sum, g[i]) : dec(sum, g[i]) ;  
		rep( i, 0, limit ) g[i] = 1ll * g[i] * f[i] % P ; 
		if(sum) { cout << (n - 1) + k << endl ; exit(0) ; }
	}
	return 0 ; 
}