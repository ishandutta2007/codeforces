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
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = (1 << 15) + 2 ;
const int M = 63 ; 
int n, K, q, cnt, mn, a[18][100005], Id[20], b[20] ; 
struct Bitset {
	unsigned long long b[520] ;
	void init() { rep( i, 0, mn ) b[i] = 0 ; }
	int find(int x) {
		int k = x / 64, u = x & M ;
		return ((b[k] >> u) & 1ll) ; 
	}
} f[100020] ;
Bitset operator & ( Bitset &x, Bitset &y ) {
	Bitset ans ; 
	rep( i, 0, mn ) ans.b[i] = x.b[i] & y.b[i] ; 
	return ans ; 
} 
Bitset operator | ( Bitset &x, Bitset &y ) {
	Bitset ans ; 
	rep( i, 0, mn ) ans.b[i] = x.b[i] | y.b[i] ; 
	return ans ; 
} 
bool cmp(int x, int y) {
	return b[x] > b[y] ; 
}
signed main()
{
	K = gi(), n = gi(), q = gi() ; 
	rep( i, 1, n ) rep( j, 1, K ) a[i][j] = gi() ; 
	int limit = (1 << n) - 1 ; 
	rep( i, 1, n ) {
		int num = 0, z = 0 ; 
		for(re int j = 0; j <= limit; ++ j) {
			if(j & (1 << (i - 1))) f[i].b[num] |= (1ull << z) ; 
			++ z ; if(z == 64) ++ num, z = 0 ; 
		}
	}
	mn = (limit / 64) + 1 ; 
	cnt = n ; 
	while(q--) {
		int opt = gi(), x = gi(), y = gi() ; 
		if(opt == 1) ++ cnt, f[cnt] = (f[x] | f[y]) ;
		if(opt == 2) {
			++ cnt, f[cnt] = (f[x] & f[y]) ; 
		}
		if(opt == 3) {
			rep( i, 1, n ) b[i] = a[i][y], Id[i] = i ; 
			sort(Id + 1, Id + n + 1, cmp) ; 
			int u = 0, ans = 0 ; 
			rep( i, 1, n ) {
				u |= (1 << (Id[i] - 1)) ; 
				if(f[x].find(u)) { ans = b[Id[i]] ; break ; } 
			}
			printf("%d\n", ans ) ; 
		}
	}
	return 0 ;
}