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
#define ST1 f[ret][hi][hj][hk][hl]
#define ST2 f[o][i][j][k][l]
const int P = 998244353 ; 
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 6 ; 
const int M = 21 ; 
int n, m, a[N], b[N], f[32][M][M][M][M][2][2] ; 
void inc(int &x, int y) { ((x += y) >= P) && (x -= P) ; }
signed main() 
{ 
	n = gi(), m = gi() ; 
	rep( i, 1, n ) a[i] = gi(), b[i] = gi() ; 
	f[0][0][0][0][0][0][0] = 1 ; //0  <= m1  > m 
	int lim = n * 4, ret = 0 ; 
	for(int o = 0; (1 << o) <= m; ++ o) {
		int limit = (1 << n) ; ret = o + 1 ; 
//		printf("now case o %lld\n", o ) ; 
		for(int S = 0; S < limit; ++ S) {
			int fx = 0, nx = 0, fy = 0, ny = 0 ; 
			rep( i, 1, n ) if((S >> (i - 1)) & 1) {
				(a[i] > 0) ? fx += a[i] : nx -= a[i] ; 
				(b[i] > 0) ? fy += b[i] : ny -= b[i] ; 
			}
//			printf("S %lld %lld %lld %lld %lld\n", S, fx, nx, fy, ny ) ; 
			rep( i, 0, lim ) rep( j, 0, lim ) rep( k, 0, lim ) rep( l, 0, lim ) {
				int gi = i + fx, gj = j + nx, gk = k + fy, gl = l + ny ; 
				if((gi + gj) & 1) continue ; 
				if((gk + gl) & 1) continue ; 
				int hi = (gi >> 1), hj = (gj >> 1), hk = (gk >> 1), hl = (gl >> 1) ; 
				int t = ((m >> o) & 1) ; 
				if(t) {
					int tx = (gi & 1) >= t, ty = (gk & 1) >= t ; 
					inc( ST1[0 & tx][0 & ty], ST2[0][0]) ;
					inc( ST1[0 & tx][1 & ty], ST2[0][1]) ;
					inc( ST1[1 & tx][0 & ty], ST2[1][0]) ;
					inc( ST1[1 & tx][1 & ty], ST2[1][1]) ; 
				}
				else { 
					int tx = (gi & 1) > t, ty = (gk & 1) > t ; 
					inc( ST1[0 | tx][0 | ty], ST2[0][0]) ;
					inc( ST1[0 | tx][1 | ty], ST2[0][1]) ;
					inc( ST1[1 | tx][0 | ty], ST2[1][0]) ;
					inc( ST1[1 | tx][1 | ty], ST2[1][1]) ; 
				}
			}
		}
	}
	cout << (f[ret][0][0][0][0][0][0] + P - 1) % P << endl ; 
	return 0 ;
}