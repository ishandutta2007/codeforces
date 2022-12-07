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
const int W = 1e8 ;
vi A, B, C ; int D ; 
int query(int x, int y) { 
	printf("0 %d %d\n", x, y), fflush(stdout) ;
	int p = gi() ; 
	return p ; 
}
void solve(int l, int r)
{
	if (l > r) return ;
	int mid = (l + r) >> 1, d = query(mid, mid) ;
	if(d == 0) C.push_back(mid), d = 1 ;
	solve(l, mid - d), solve(mid + d, r) ;
}
int sw(int x) {
	return (1ll * rand() << 16ll ^ rand()) % x + 1 ; 
}
signed main() {
	srand(time(NULL)) ; 
	while(1) {
		D = sw(W) ; 
		int p = query(D, D) ; 
		if(p) break ; 
	}
	solve(-W, W) ;
	for(int x : C) if(query(x, D) == 0) A.pb(x) ;
	for(int x : C) if(query(D, x) == 0) B.pb(x) ;  
	printf("1 %d %d\n", (int)A.size(), (int)B.size()) ; 
	for(int x : A) printf("%d ", x) ; puts("") ; 
	for(int x : B) printf("%d ", x) ; puts("") ; 
	return 0;
}