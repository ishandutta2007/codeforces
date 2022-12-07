#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
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
const int N = 1e5 + 5 ; 
const int M = 150 ; 
bitset<M> g ; 
int n, limit, cnt, a[15][15], trans[N][M], vis[M], dp[10][N] ; 
unordered_map<bitset<M>, int> S ; 
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
void dfs(bitset<M> f) {
	if(S[f]) return ; S[f] = ++ cnt ; 
	rep( i, 0, limit ) vis[i] = f[i] ; 
	rep( i, 0, limit ) {
		bitset<M> F ; F = f ; 
		rep( j, 1, n ) {
			if(!(i & (1 << (j - 1)))) continue ; 
			rep( k, 0, limit ) if(k & (1 << (j - 1))) 
			F[k] = F[k] | f[k ^ (1 << (j - 1))] ; 
		}
		dfs(F), trans[S[f]][i] = S[F] ; 
	} return ; 
}
signed main()
{
	n = gi(), limit = (1 << n) - 1 ; int I = fpow(100, P - 2) ; 
	rep( i, 1, n ) rep( j, 1, n ) a[i][j] = gi() * I % P ; 
	g[0] = 1, dfs(g), dp[0][1] = 1 ; 
	rep( i, 1, n ) rep( j, 1, limit ) {
		int p = 1 ; 
		rep( o, 1, n ) {
			if((1 << (o - 1)) & j) p = p * a[i][o] % P ;
			else p = p * (1 - a[i][o] + P) % P ; 
		}
		rep( k, 1, cnt ) 
		dp[i][trans[k][j]] = (dp[i][trans[k][j]] + dp[i - 1][k] * p) % P ; 
	}
	rep( i, 0, limit ) g[i] = 1 ; 
	cout << dp[n][S[g]] << endl ; 
	return 0 ;
}