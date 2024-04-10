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
const int P = 998244353 ; 
const int N = 5e5 + 5 ;  
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
int n, m, fac[N], inv[N] ; 
char s[N] ; 
void init(int x) {
	fac[0] = inv[0] = 1 ; 
	rep(i, 1, x) fac[i] = fac[i - 1] * i % P ; 
	rep(i, 1, x) inv[i] = fpow(fac[i], P - 2) ; 
}
int C(int x, int y) {
	if(y < 0 || x < y) return 0 ;
	return fac[x] * inv[y] % P * inv[x - y] % P ;  
}
signed main()
{
	n = gi(), m = gi(), init(n * 2) ; 
	scanf("%s", s + 1) ; 
	int de = 0, a = 0, b = 0 ;
	rep( i, 1, n ) {
		if(i & 1) {
			if(s[i] == '?') ++ a ;
			if(s[i] == 'w') ++ de ;
		}
		else {
			if(s[i] == '?') ++ b ;
			if(s[i] == 'w') -- de ; 
		}
	}
	int d = a + b, ans = 0, z = 0 ; de -= b ; 
	for(re int k = 0; k <= d; ++ k) {
		int t = abs(k + de) ;
		if(t & 1) continue ; 
		ans = (ans + C(d, k) * t) % P ; 
	}
	cout << ans * fpow(fpow(2, P - 2), d) % P << endl ; 
	return 0 ;
}