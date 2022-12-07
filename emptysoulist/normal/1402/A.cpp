#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define Rep( i, s, t ) for( register int i = (s); i < (t); ++ i ) 
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 40 + 5 ; 
int n, m, Ans, nxt[N][2], f[N], dp[N][N][N] ;
char s[N] ; 
void inc(int &x, int y) { (x += y) ; }
signed main()
{
	n = gi(), scanf("%s", s + 1 ), m = strlen(s + 1) ; 
	rep( i, 1, m ) s[i] -= '0' ; 
	rep( i, 1, m ) nxt[i - 1][s[i]] = i ;
	rep( i, 1, m ) {
		if(i != 1) f[i] = nxt[f[i - 1]][s[i]] ;
		nxt[i][s[i + 1] ^ 1] = nxt[f[i]][s[i + 1] ^ 1] ;
	} Ans = (1ll << n) ; 
	Rep( i, 0, m ) {
		memset(dp, 0, sizeof(dp)), dp[0][0][i] = 1 ; 
		rep(j, 1, n) Rep(k, 0, m) Rep(l, 0, m) rep(c, 0, 1)
			inc( dp[j][nxt[k][c]][nxt[l][c]], dp[j - 1][k][l] ) ; 
		Ans -= dp[n][i][i] ; 
	}
	cout << Ans << endl ; 
	return 0 ;
}