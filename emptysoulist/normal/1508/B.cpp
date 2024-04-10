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
const int N = 1e5 + 5 ; 
int n, m, p[N] ; 
int check(int r) {
	if(r == n) return 1 ; 
	return (1ll << (n - r - 1)) ; 
}
signed main()
{
	int T = gi() ; 
	while(T--) {
		n = gi(), m = gi() ; 
		int tot = 0, flag = 0 ; 
		for(int l = 1, r; l <= n; l = r + 1) {
			r = l ; 
			while(r <= n) {
				if(n - r >= 62) break ; 
				if(m > (check(r))) m -= check(r) ; 
				else break ; 
				++ r ; 
			}
			if(r == n + 1) flag = 1 ; 
			for(int j = r; j >= l; -- j) p[++ tot] = j ; 
		}
		if(flag == 1) {
			puts("-1") ; 
		}
		else {
			rep( i, 1, tot ) printf("%lld ", p[i]) ; puts("") ; 
		}
	}
	return 0 ;
}