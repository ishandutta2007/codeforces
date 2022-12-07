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
const int N = 3e5 + 5 ; 
int n, b[5], c[5], id[5] ; 
char A[4][N], ans[N] ; 
bool cmp(int x, int y) {
	return c[x] < c[y] ; 
}
void solve() {
	n = gi() ;
	scanf("%s", A[1] + 1),
	scanf("%s", A[2] + 1),
	scanf("%s", A[3] + 1) ;
	int L = 2 * n ; 
	rep( j, 1, 3 ) c[j] = b[j] = 0 ; 
	rep( j, 1, 3 ) rep( i, 1, L ) 
		if(A[j][i] == '0') ++ c[j] ;
		else ++ b[j] ; 
	rep( j, 1, 3 ) id[j] = j ; 
	sort(id + 1, id + 4, cmp) ; 
	int tot = 0, R = 1 ; 
	if(c[id[2]] <= n) {
		rep( i, 1, L ) {
			if(A[id[1]][i] == '1') {
				while((R <= L) && (A[id[2]][R] == '0')) ans[++ tot] = '0', ++ R ;  
				ans[++ tot] = '1' ; 
				if((R <= L) && (A[id[2]][R] == '1')) ++ R ; 
			}
			else {
				ans[++ tot] = '0' ; 
				if((R <= L) && (A[id[2]][R] == '0')) ++ R ; 
			}
		}
		while((R <= L)) ans[++ tot] = A[id[2]][R], ++ R ;  
	}
	else { 
		rep( i, 1, L ) {
			if(A[id[3]][i] == '0') {
				while((R <= L) && (A[id[2]][R] == '1')) ans[++ tot] = '1', ++ R ;  
				ans[++ tot] = '0' ; 
				if((R <= L) && (A[id[2]][R] == '0')) ++ R ; 
			}
			else {
				ans[++ tot] = '1' ; 
				if((R <= L) && (A[id[2]][R] == '1')) ++ R ; 
			}
		}
		while((R <= L)) ans[++ tot] = A[id[2]][R], ++ R ;  
	}
	printf("%s", ans + 1) ; puts("") ; 
	rep( j, 1, tot ) ans[j] = 0 ; 
}
signed main()
{
	int T = gi() ; 
	while(T--) solve() ; 
	return 0 ;
}