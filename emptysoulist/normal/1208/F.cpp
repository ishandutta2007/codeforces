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
const int N = (1 << 21) + 5 ; 
int n, a[N], b[N], mi[N], mx[N], mxx[N] ; 
void upd(int x, int z) {
	if(mx[x] < z) mxx[x] = mx[x], mx[x] = z ; 
	else if(mx[x] != z) mxx[x] = max(mxx[x], z) ; 
}
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	int S = 0 ; 
	for(int d = 20; d >= 0; -- d) {
		int uS = ((S | (1 << d)) >> d) ; 
		int limit = (1 << (21 - d)) - 1 ; 
		rep( i, 0, limit ) mi[i] = mx[i] = mxx[i] = 0 ; 
		rep( i, 1, n ) b[i] = ((a[i] >> d) & limit) ; 
		rep( i, 1, n ) {
			if(!mi[b[i]]) mi[b[i]] = i ;
			mxx[b[i]] = mx[b[i]], mx[b[i]] = i ; 
		}
		int ret = 21 - d, flag = 0 ; 
		drep( i, 0, limit ) for(int j = 0; j < ret; ++ j) 
		if((1 << j) & i) upd(i ^ (1 << j), mx[i]), upd(i ^ (1 << j), mxx[i]) ; 
		rep( i, 0, limit ) {
			if(!mi[i]) continue ; 
			if((i & uS) != i) continue ; 
			if(mxx[i ^ uS] > mi[i]) flag = 1 ; 
		}
		if(flag) S = (S | (1 << d)) ; 
	}
	cout << S << endl ; 
	return 0 ;
}