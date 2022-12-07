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
while( cc < '0' || cc > '9' ) { if( cc == '-' ) flus = - flus ; cc = getchar() ; }
while( cc >= '0' && cc <= '9' ) cn = cn * 10 + cc - '0', cc = getchar() ;
return cn * flus ;
}
const int inf = 1e9 + 7 ;
const int N = 5000 + 5 ;
int n, t[N], c[N], g[N][N] ; // g[i][j], i has robot, get j, min time
bool f[N][N] ;
int L[N], R[N], ll[N], rr[N] ;
int Get(int x, int l, int r) {
if( l > r ) return inf ;
if( l <= x && x <= r ) return 0 ;
return min( abs(l - x), abs(r - x) ) ;
}
signed main()
{
//	freopen("test.in", "r", stdin ) ;
//	freopen("test.out", "w", stdout ) ;
n = gi() ;
rep( i, 1, n ) t[i] = gi(), c[i] = gi() ;
memset(ll, 31, sizeof(ll)), memset( L, 31, sizeof(L) ),
memset(rr, -31, sizeof(rr)), memset( R, -31, sizeof(R) ) ;
memset( g, 31, sizeof(g) ) ;
f[0][0] = 1, ll[0] = 0, rr[0] = 0, L[0] = 0, R[0] = 0, t[0] = 0, c[0] = 0 ;
rep( i, 1, n ) g[0][i] = abs(c[i]) ;
rep( i, 1, n ) {
rep( j, i, n ) {
if(abs(c[i - 1] - c[i]) <= t[i] - t[i - 1])
f[i][j] |= f[i - 1][j] ;
if(abs(c[j] - c[i]) <= t[i] - g[i - 1][j])
f[i][j] = 1 ;
}
if(f[i - 1][i - 1]) {
int lp = t[i - 1] +
min(Get(c[i], L[i - 1], R[i - 1]), Get(c[i], ll[i - 1], rr[i - 1])) ;
if( lp <= t[i] ) {
f[i][i] = 1 ; int l = t[i] - lp ;
L[i] = c[i] - l, R[i] = c[i] + l ;
rep( j, i, n ) g[i][j] = max( t[i], abs(c[j] - c[i]) + lp ) ;
}
}
if(f[i - 1][i]) {
f[i][i] = 1 ; int l = t[i] - t[i - 1] ;
ll[i] = c[i - 1] - l, rr[i] = c[i - 1] + l ;
rep( j, i, n ) g[i][j] = min( g[i][j], max( t[i], abs(c[j] - c[i - 1]) + t[i - 1] ) ) ;
}}
if(f[n][n]) {
puts("YES") ;
}
else {
puts("NO") ;
}
//for test, thanks
return 0 ;
}