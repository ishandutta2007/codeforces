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
const int N = 2005 ; 
int n, m, p[N], a[N] ; 
signed main()
{
	n = gi(), m = n * 2 ; int Flag = 0 ; 
	rep( i, 1, m ) a[i] = p[i] = gi() ; 
	rep( i, 1, m ) if(a[i] != i) Flag = 1 ; 
	if(!Flag) { puts("0") ; exit(0) ; }
	int lim = n * 4, ans1 = lim + 10, ans2 = lim + 10 ; 
	rep( i, 1, lim ) {
		if((i & 1)) {
			rep( j, 1, n ) swap(a[2 * j - 1], a[2 * j]) ; 
		}
		else {
			rep( j, 1, n ) swap(a[j], a[j + n]) ; 
		}
		int flag = 0 ; 
		rep( j, 1, m ) if(a[j] != j) flag = 1 ; 
		if(!flag) {	ans1 = i ; break ; }
	}
	rep( i, 1, m ) a[i] = p[i] ; 
	rep( i, 1, lim ) {
		if(!(i & 1)) {
			rep( j, 1, n ) swap(a[2 * j - 1], a[2 * j]) ; 
		}
		else {
			rep( j, 1, n ) swap(a[j], a[j + n]) ; 
		}
		int flag = 0 ; 
		rep( j, 1, m ) if(a[j] != j) flag = 1 ; 
		if(!flag) {	ans2 = i ; break ; }
	}
	if(min(ans1, ans2) > lim) puts("-1") ; 
	else cout << min(ans1, ans2) << endl ; 
	return 0 ;
}