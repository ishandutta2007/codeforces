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
const int N = 705 ; 
const int P = 1e9 + 7 ; 
int n, f[N][2], g[N][2] ; 
char A[N] ; 
void inc(int &x, int y) { ((x += y) >= P) && (x -= P) ; }
void dec(int &x, int y) { ((x -= y) < 0) && (x += P) ; }
void DP(int d) {
	rep( j, 1, n ) g[j][0] = g[j][1] = f[j][0] = f[j][1] = 0 ; 
	f[n + 1][0] = f[n + 1][1] = 0 ; 
	g[n + 1][0] = g[n + 1][1] = 1 ; 
	for(int l = n; l >= 1; -- l) {
		rep( type, 0, 1 ) {
			int ret = (type) ? A[l] : 9 ; 
			rep( i, 0, ret ) {
				int ty = (type & (i == ret)) ; 
				if(i < d) 
					inc(f[l][type], f[l + 1][ty]), inc(g[l][type], g[l + 1][ty]) ; 
				if(i == d) 
					inc(f[l][type], 10 * f[l + 1][ty] % P), inc(f[l][type], g[l + 1][ty]),
					inc(g[l][type], g[l + 1][ty]) ; 
				if(i > d) 
					inc(f[l][type], f[l + 1][ty] * 10 % P), inc(g[l][type], g[l + 1][ty] * 10 % P) ; 
			}
		}
	}
}
int solve(int d) {
	DP(d) ; return f[1][1] ; 
}
signed main()
{
	scanf("%s", A + 1) ; n = strlen(A + 1) ; 
	rep( i, 1, n ) A[i] -= '0' ; int ans = 0 ;
	rep( i, 1, 9 ) {
		int z = solve(i) ; 
		ans += i * z, ans %= P ; 
	}
	cout << ans << endl ; 
	return 0 ;
}