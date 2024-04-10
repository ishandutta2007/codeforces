#include<bits/stdc++.h>
using namespace std ; 
#define il inline
#define int long long
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define re register
inline int gi() {
	int cn = 0, flus = 1 ; char cc = getchar() ;
	while( cc > '9' || cc < '0' ) { if( cc == '-' ) flus = -flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' ) cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ; 
}
const int P1 = 20031223 ; 
const int P2 = 19260817 ; 
const int N = 5e5 + 5 ; 
const int M = 5e6 + 5 ;
const int Hash1 = 233 ;
const int Hash2 = 37 ; 
int n, ans, D[5], vis[N] ;
char s[M] ;
int out[N], top, pf1, pf2;
struct node {
	int a1, a2 ; 
	bool operator < ( const node &x ) const {
		return ( a1 == x.a1 ) ? ( a2 < x.a2 ) : a1 < x.a1 ; 
	}
};
set<pair<int, int>> hs;
pair<int, int> rev[N];
void init() {
	ans = D[0] = top = D[1] = 0, pf1 = pf2 = 0;
	hs.clear();
}
signed main() {
	for (scanf("%*d"); ~scanf("%d", &n);) {
		init() ; 
		rep( i, 1, n ) {
			vis[i] = 0 ; scanf("%s", s) ;
			int m = strlen(s) - 1;

			int H1 = 0, H2 = 0, H3 = 0, H4 = 0;
			rep( j, 0, m )  H1 = ( H1 * Hash1 + s[j] ) % P1, H2 = ( H2 * Hash2 + s[j] ) % P2 ;
			drep( j, 0, m ) H3 = ( H3 * Hash1 + s[j] ) % P1, H4 = ( H4 * Hash2 + s[j] ) % P2 ;
			hs.insert(pair<int, int>( H1, H2 )), rev[i] = pair<int, int>( H3, H4 ) ;
			if( s[0] == '0' && s[m] == '0' ) pf1 = 1;
			if( s[0] == '1' && s[m] == '1' ) pf2 = 1;
			if( s[0] == '0' && s[m] == '1' ) ++ D[1], vis[i] = 1;
			if( s[0] == '1' && s[m] == '0' ) ++ D[0], vis[i] = -1;
		}
		if (!D[0] && !D[1] && pf1 && pf2) {
			puts("-1"); continue;
		}
		rep( i, 1, n ) {
			if (abs(D[0] - D[1]) <= 1) break;
			if (D[0] > D[1] && vis[i] == -1 && !hs.count(rev[i]))
				out[++top] = i, D[0]--, D[1]++;
			if (D[0] < D[1] && vis[i] == 1 && !hs.count(rev[i]))
				out[++top] = i, D[0]++, D[1]--;
		}
		if( abs(D[0] - D[1]) > 1 ) 
			puts("-1");
		else {
			printf("%I64d\n", top);
			rep( i, 1, top ) printf("%I64d ", out[i]);
			puts("");
		}
	}
	return 0 ; 
}