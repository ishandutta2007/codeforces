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
const int N = 2000 + 5 ;  
int n ; 
signed main()
{
	int T = gi() ; 
	while(T--) {
		n = gi() ; int bef = 0 ; 
		rep( i, 2, n ) {
			printf("? %d %d\n", i - 1, 1 ) ; cout.flush() ; 
			rep( j, 1, i - 1 ) printf("%d ", j ) ; puts("") ; cout.flush() ; 
			printf("%d\n", i ) ; cout.flush() ; 
			int flag = gi() ; 
			if(flag) {
				bef = i ; break ; 
			}
		}
		int l = 1, r = bef - 1, ans = 1 ; 
		while(l <= r) {
			int mid = (l + r) >> 1 ; 
			printf("? %d 1\n", bef - mid) ; cout.flush() ; 
			for(int i = mid; i < bef; ++ i) printf("%d ", i) ; puts("") ; cout.flush() ; 
			printf("%d\n", bef ) ; cout.flush() ; 
			int flag = gi() ; 
			if(flag) ans = mid, l = mid + 1 ; 
			else r = mid - 1 ; 
		}
		vector<int> ANS ; 
		for(int i = 1; i < ans; ++ i) ANS.pb(i) ;
		for(int i = ans + 1; i < bef; ++ i) ANS.pb(i) ; 
		for(int i = bef + 1; i <= n; ++ i) {
			printf("? 1 1\n%d\n%d\n", bef, i ) ; cout.flush() ; 
			int flag = gi() ; 
			if(!flag) ANS.pb(i) ; 
		}
		printf("! %d ", ANS.size() ) ; 
		for(int u : ANS) printf("%d ", u ) ; puts("") ; cout.flush() ; 
	}
	return 0 ;
}