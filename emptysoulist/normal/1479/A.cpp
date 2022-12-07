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
const int N = 2e5 + 5 ; 
int n, a[N] ; 
int qry(int x) {
	if(x <= n) {
		printf("? %d\n", x) ; 
		fflush(stdout) ; 
		int t = gi() ; 
		return t ; 
	}
	else return n + 1 ; 
}
signed main()
{
	n = gi() ; 
	if(n == 1) {
		printf("! 1") ; exit(0) ; 
	}
	int l = 1, r = n, ans = n ; 
	int L = qry(1), R = qry(n) ; 
	while(l < r) {
		int mid = (l + r) >> 1 ; 
//		printf("%d\n", mid ) ; 
		int a1 = qry(mid), a2 = qry(mid + 1) ; 
		if(a1 < a2) {
			R = a1, ans = mid, r = mid ;  
		}
		else {
			L = a2, ans = mid + 1, l = mid + 1 ; 
		}
	}
	printf("! %d\n", ans ) ; 
	return 0 ;
}