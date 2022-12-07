#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = (1 << 12) + 5 ; 
int w, n, m, pot[N], sta[N], low[N], fac[N], c[N], f[N][N], L[N], R[N] ; 
char s[N] ; 
signed main()
{
	w = gi(), n = gi(), m = gi() ; int limit = (1 << w) - 1 ;
	rep( i, 1, n ) {
		int x = gi() ; 
		rep( j, 0, limit ) ++ f[j][x & j] ; 
	}
	fac[0] = 1 ; 
	rep( i, 1, limit ) fac[i] = -fac[i ^ (i & (-i))] ; 
	rep( i, 0, w ) low[1 << i] = i ; 
	while(m --) {
		scanf("%s", s + 1) ; 
		int lim = 0, ret = 0, tot = 0 ; 
		tot = 1, L[1] = R[1] = 0 ; 
		rep( i, 1, w ) {
			int d = (1 << (w - i)) ; 
			if(s[i] == 'A') lim |= d, ret |= d ;
			if(s[i] == 'o') lim |= d ;
			if(s[i] == 'X') {
				rep( j, 1, tot ) 
				L[j + tot] = L[j] | d, R[j + tot] = R[j] | d ; 
				tot = tot * 2 ; 
			}
			if(s[i] == 'a') {
				rep( j, 1, tot ) L[j] = L[j] | d, R[j] = R[j] | d ;
			}
			if(s[i] == 'x') {
				rep( j, 1, tot ) L[j] = L[j] | d ; 
				rep( j, 1, tot ) 
				L[j + tot] = L[j] ^ d, R[j + tot] = R[j] ^ d ; 
				tot = tot * 2 ; 
			}
		}int o = limit ^ lim, num = 0 ; long long Ans = 0 ; 
		for(int S = lim; S; S = (S - 1) & lim) pot[++ num] = S ; 
		pot[++ num] = 0 ; 
		rep( i, 1, num ) sta[i] = pot[num - i + 1] ; c[0] = 0 ; 
//		rep( j, 1, tot ) printf("%d %d\n", L[j], R[j] ) ; 
		rep( tt, 1, num ) {
			int S = sta[tt], d = (S & (-S)), t = S ^ d, z = 0 ; 
			c[S] = c[t] | (ret & d) ; int r = c[S] ; 
			rep( j, 1, tot ) z += f[o | S][L[j] | r] * f[o | S][R[j] | r] ; 
			Ans += z * fac[S] ; 
//			cout << S << " " << " " << c[S] << " " << fac[S] << " " << z << endl ; 
		}
		printf("%lld\n", Ans ) ; 
	}
	return 0 ;
}