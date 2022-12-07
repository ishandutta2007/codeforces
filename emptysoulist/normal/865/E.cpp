#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i < (t); ++ i )
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
const int N = 14 ; 
const int inf = (1ll << 61) ; 
int n, ans, c[N], a[N], d[N], f[1 << 14] ; 
char s[N] ; 
void write(int x, int l) {
	if(!l) return ; 
	write(x / 16, l - 1) ;
	int z = x % 16 ; 
	if(z <= 9) cout << z ;
	else cout << (char)(z - 10 + 'a') ;
}
signed main()
{
	cin >> s, n = strlen(s) ; int sum = 0 ; 
	rep( i, 0, n )
		c[i] = (s[i] >= 'a') ? (s[i] - 'a' + 10) : (s[i] - '0'),
		sum += c[i], a[n - i - 1] = c[i] ; 
	if(sum % 15) { puts("NO") ; exit(0) ; } 
	sum /= 15, ans = inf ; 
	int limit = (1 << (n - 1)) - 1, m = 0 ; 
	for(int T = 0; T <= limit; ++ T) {
		m = 0 ; rep( i, 0, n ) m += ((T >> i) & 1) ; 
		if(m != sum) continue ; 
		int o = 0 ; rep( i, 0, n ) d[i] = a[i] ; 
		rep( i, 0, n ) if((T >> i) & 1) d[i] -= 16, ++ d[i + 1] ; 
		rep( i, 0, n ) o += d[i] ;
		if(o != 0) continue ; int lim = (1 << n) ; 
		rep( S, 0, lim ) f[S] = inf ; 
		rep( i, 0, n ) f[1 << i] = 0 ; 
		rep( S, 1, lim ) {
			int su = 0 ; 
			rep( j, 0, n ) if((S >> j) & 1) su += d[j] ; 
			if(su > 15 || su < 0) continue ; 
			rep( j, 0, n ) if((S >> j) & 1) {
				su -= d[j] ;
				if(su >= 0 && su <= 15) 
					f[S] = min(f[S ^ (1ll << j)] + su * (1ll << (4 * j)), f[S]) ; 
				su += d[j] ; 
			}
		} ans = min(ans, f[lim - 1]) ;  
	}
	if(ans >= inf) puts("NO") ; 
	else write(ans, n) ;
	return 0 ;
}