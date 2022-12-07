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
const int N = 100 + 5 ; 
const int M = 1e5 + 5 ; 
int L, R, cnt, tot, num, root ; 
int f[N] ; 
struct node {
	int x, y, z ; 
} e[M] ;
void add(int x, int y, int z) {
	e[++ tot] = (node){x, y, z} ; 
}
void solve(int x) {
	vector<int> st ; st.pb(root) ; int k = 1 ; 
	for(k = 1; k <= x; k <<= 1) {
		++ cnt ; int siz = st.size() ; 
		for(int i = 0; i < siz; ++ i)
		add(st[i], cnt, f[i]) ; 
		st.pb(cnt) ; 
	}
	++ cnt ; 
	int siz = st.size() ; 
	for(int i = siz - 1; i >= 1; -- i) {
		if(x > (1 << (i - 1))) {
			add(st[i], cnt, x - (1 << (i - 1))) ; 
			x -= (1 << (i - 1)) ; 
		}
	}
	add(st[0], cnt, 1) ; 
}
signed main()
{
	L = gi(), R = gi() ; 
	f[0] = 1 ; 
	rep( i, 1, 25 ) f[i] = (1 << (i - 1)) ; 
	puts("YES") ; 
	if(L == R) {
		printf("2 1\n") ;
		printf("1 2 %d\n", L ) ; exit(0) ; 
	}
	cnt = root = 1 ; 
	if(L != 1) {
		cnt = root = 2 ; 
		add(1, 2, L - 1) ; 
	}
	R = R - L + 1 ; 
	solve(R) ; 
	printf("%d %d\n", cnt, tot ) ; 
	rep( i, 1, tot ) printf("%d %d %d\n", e[i].x, e[i].y, e[i].z ) ; 
	return 0 ;
}