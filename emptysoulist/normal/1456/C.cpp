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
const int N = 5e5 + 5 ; 
int n, k, a[N], b[N], lst[N], Ans ; 
signed main()
{
	n = gi(), k = gi() + 1 ; 
	rep( i, 1, n ) a[i] = gi() ; 
	sort(a + 1, a + n + 1) ; 
	int S = 0, ip = 0 ; 
	for(re int i = n; i >= 1; -- i) {
		Ans += S, S += a[i], ip = i ; 
		if(S < 0) break ; 
	}
	if(ip == 1) {
		cout << Ans << endl ; exit(0) ; 
	}
	for(re int i = 1; i < ip; ++ i) b[i] = a[i] ; 
	b[ip] = S ; 
	rep( i, 1, k ) lst[i] = 0 ; 
	int bef = 1 ; 
	for(re int i = 1; i <= ip; ++ i) {
		Ans += (b[i] * (lst[bef])), ++ lst[bef] ;
		++ bef ; 
		if(bef == k + 1) bef = 1 ; 
	}
	cout << Ans << endl ; 
	return 0 ;
}
/*
5 4 3 1 1 -2 -3 -5 -5 -9 -6 -8 -9
0 5 9 12 13 14 12 9 4 -1 0 -6 0 
*/