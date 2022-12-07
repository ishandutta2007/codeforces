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
const int N = 5e5 + 5 ; 
int n, a[N] ; 
map<int, int> S ; 
void solve() {
	n = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	rep( i, 1, n ) {
		int x = a[i], u = 1 ; 
		for(int j = 2; j <= sqrt(x); ++ j) {
			if(x % j) continue ; 
			int t = 0 ; 
			while(x % j == 0) x /= j, t ^= 1 ; 
			if(t) u = u * j ; 
		}
		u = u * x, ++ S[u] ;
	}
	int ans0 = S[1], ans1 = 1 ; 
	for(auto z : S) {
		ans1 = max(ans1, z.second) ;
		if((z.first != 1) && (z.second % 2 == 0)) 
			ans0 += z.second ; 
	}
	int q = gi() ; 
	while(q--) {
		long long w ; scanf("%lld", &w ) ; 
		if(!w) printf("%d\n", ans1 ) ; 
		else printf("%d\n", max(ans0, ans1) ) ; 
	}
	S.clear() ; 
}
signed main()
{
	int T = gi() ; 
	while(T--) solve() ; 
	return 0 ;
}