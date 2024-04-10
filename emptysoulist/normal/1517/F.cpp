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
const int P = 998244353 ; 
const int I = (P + 1) / 2 ; 
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
const int N = 305 ; 
int n, ANS, f[N][N][3], sum1[N], sum2[N] ; 
//0 1 
// 2  
vi G[N] ; 
void inc(int &x, int y) { ((x += y) >= P) && (x -= P) ; }
void dec(int &x, int y) { ((x -= y) < 0) && (x += P) ; }
void dfs(int x, int fa, int r) {
	rep( d, 0, r + 1 ) f[x][d][0] = f[x][d][1] = f[x][d][2] = 0 ; 
	f[x][0][1] = P - 1 ; 
	for(int d = 1; d <= r; ++ d) f[x][d][0] = 1 ; 
	f[x][r + 1][1] = 2 ; 
	for(int d = 1; d <= r; ++ d) f[x][d][2] = 1 ; 
	for(int v : G[x]) {
		if(v == fa) continue ; 
		dfs(v, x, r) ; 
		for(int d = r + 1; d >= 0; -- d) {
			if(d) f[x][d][1] = (f[x][d][0] * f[v][d - 1][1] 
				+ f[x][d][1] * (f[v][d - 1][1] + f[v][d][1] + f[v][d + 1][1] + f[v][d + 1][2]) % P) % P ; 
			else 
				f[x][d][1] = (f[x][d][1] * (f[v][d][1] + f[v][d + 1][1] + f[v][d + 1][2])) % P ; 
			f[x][d][0] = f[x][d][0] * (f[v][d][1] + f[v][d + 1][1] + f[v][d + 1][2]) % P ;
			f[x][d][2] = f[x][d][2] * (f[v][d + 1][2] + f[v][d][1] + f[v][d + 1][1]) % P ; 
		}
	}
}
signed main()
{
	n = gi() ; int x, y ; 
	rep( i, 2, n ) {
		x = gi(), y = gi(),
		G[x].pb(y), G[y].pb(x) ; 
	}
	int ans = 1 ; 
	rep( i, 1, n ) ans = ans * 2 % P ; 
	rep( r, 1, n ) {
		dfs(1, 1, r) ; 
		int S = 0 ; 
		rep( d, 0, r + 1 )
		inc(S, f[1][d][1]) ; 
		S = (ans - S + P) % P ; 
		inc(ANS, S) ; 
	}
	ANS = (ANS + P - 1) % P ; 
	rep( i, 1, n ) ANS = ANS * I % P ; 
	cout << ANS << endl ; 
	return 0 ;
}