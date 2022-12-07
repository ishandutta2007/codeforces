#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
const int P1 = 19491001 ; 
const int P2 = 20031223 ; 
int n, a[N], Id[N], Sum[N], Nxt[N], sum[N], has[N], has2[N], F1[N], F2[N] ; 
char s[N] ; 
signed main()
{
	n = gi(), scanf("%s", s + 1 ) ;
	rep( i, 1, n ) a[i] = s[i] - '0' ; 
	rep( i, 1, n ) {
		if( a[i] == 0 ) Id[i] = i, Sum[i] = Sum[i - 1] + 1 ;
		else Id[i] = Id[i - 1], Sum[i] = Sum[i - 1] ;
		sum[i] = sum[i - 1] ^ a[i] ; 
	}
	Nxt[n + 1] = n + 1 ;
	for( re int i = n; i >= 1; -- i ) {
		if( a[i] == 0 ) Nxt[i] = i ;
		else Nxt[i] = Nxt[i + 1] ;
	}
	has[0] = 0, has2[0] = 0 ;
	int bef = 0 ; F1[0] = 1, F2[0] = 1 ; 
	for( re int i = 1; i <= n; ++ i ) {
		if( a[i] == 0 ) {
			has[i] = ( has[bef] * 233 + ( sum[i] ^ sum[bef] ) * 13 ) % P1,
			has2[i] = ( has2[bef] * 2333 + ( sum[i] ^ sum[bef] ) * 97 ) % P2 ; 
			bef = i ;
		}
		F1[i] = F1[i - 1] * 233 % P1, 
		F2[i] = F2[i - 1] * 2333 % P2 ; 
	}
	int Q = gi() ;
	rep( i, 1, Q ) {
		int l1 = gi(), l2 = gi(), Len = gi() ;
		int ed1 = l1 + Len - 1, ed2 = l2 + Len - 1 ;
		int sum1 = Sum[ed1] - Sum[l1 - 1] ;
		int sum2 = Sum[ed2] - Sum[l2 - 1] ;
		if( sum1 != sum2 ) {
			puts("No") ; continue ;
		}
		if( sum1 == 0 ) {
			puts("Yes") ; continue ;
		}
		int G1 = Id[ed1], ll1 = Nxt[l1] ;
		int G2 = Id[ed2], ll2 = Nxt[l2] ;
		int ans1 = ( has[G1] - has[ll1] * F1[sum1 - 1] % P1 + P1 ) % P1 ;
		int ans2 = ( has[G2] - has[ll2] * F1[sum2 - 1] % P1 + P1 ) % P1 ;
		if( ans1 != ans2 ) {
			puts("No") ; continue ;
		}
		ans1 = ( has2[G1] - has2[ll1] * F2[sum1 - 1] % P2 + P2 ) % P2 ;
		ans2 = ( has2[G2] - has2[ll2] * F2[sum2 - 1] % P2 + P2 ) % P2 ;
		if( ans1 != ans2 ) {
			puts("No") ; continue ;
		}
		int PreSum1 = sum[ll1] ^ sum[l1 - 1] ;
		int PreSum2 = sum[ll2] ^ sum[l2 - 1] ;
		if( PreSum1 != PreSum2 ) {
			puts("No") ; continue ;
		}
		puts("Yes") ;
	}
	return 0 ;
}