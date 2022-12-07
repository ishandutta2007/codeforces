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
const int N = 8005 ; 
const int P = 1e9 + 7 ; 
char s[N] ; 
int n, dp[N], sum[N], f[30][N], fac[N], inv[N] ; 
void inc(int &x, int y) { ((x += y) >= P) && (x -= P) ; }
void dec(int &x, int y) { ((x -= y) < 0) && (x += P) ; }
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
int C(int x, int y) {
	return 1ll * fac[x] * inv[y] % P * inv[x - y] % P ; 
}
signed main()
{
	n = gi() ; 
	scanf("%s", s + 1) ; 
	f[0][0] = sum[0] = 1 ; 
	rep( i, 1, n ) s[i] -= 'a', ++ s[i] ; 
	for(int i = n; i >= 1; -- i) {
		int u = s[i] ; 
		rep( j, 1, n ) dp[j] = (sum[j - 1] - f[u][j - 1] + P) % P ; 
		rep( j, 1, n ) 
			dec(sum[j], f[u][j]), f[u][j] = dp[j], inc(sum[j], f[u][j]) ; 
	}
	fac[0] = inv[0] = 1 ; 
	rep( i, 1, n ) fac[i] = 1ll * fac[i - 1] * i % P ; 
	rep( i, 0, n ) inv[i] = fpow(fac[i], P - 2) ; 
	long long ans = 0 ; 
	rep( i, 1, n ) ans += 1ll * C(n - 1, i - 1) * sum[i] % P, ans %= P ; 
	cout << ans << endl ; 
	return 0 ;
}