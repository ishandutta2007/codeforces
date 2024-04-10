//by tzupengwang
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

int n , a , b ;
int s[ 20 ] ;

void init() {
	scanf( "%d%d%d" , &n , &a , &b ) ;
	for ( int i = 0 ; i < n ; i ++ ) scanf( "%d" , &s[ i ] ) ;
}

vector< int > ans , out ;

void mod( int pos , bool type ) {
	if ( type ) ans.push_back( pos ) , s[ pos ] -= a , s[ pos - 1 ] -= b , s[ pos + 1 ] -= b ;
	else ans.pop_back() , s[ pos ] += a , s[ pos - 1 ] += b , s[ pos + 1 ] += b ;
}

void dfs( int now ) {
	if ( now == n - 1 ) {
		if ( (int)out.size() == 0 || ans.size() < out.size() ) {
			out.clear() ; FO( it , ans ) out.push_back( *it ) ;
		} return ;
	}
	int cnt = 0 , cnt2 = 0 ;
	while ( s[ now - 1 ] >= 0 ) {
		mod( now , 1 ) ; cnt2 ++ ;
	}
	dfs( now + 1 ) ;
	while ( s[ now ] >= 0 ) {
		mod( now , 1 ) ; cnt ++ ;
		dfs( now + 1 ) ;
	}
	while ( cnt -- ) mod( now , 0 ) ;
	while ( cnt2 -- ) mod( now , 0 ) ;
}

void process() {
	while ( s[ 0 ] >= 0 ) mod( 1 , 1 ) ;
	while ( s[ n - 1 ] >= 0 ) mod( n - 2 , 1 ) ;
	dfs( 1 ) ;
	printf( "%d\n" , (int)out.size() ) ;
	FO( it , out ) printf( "%d " , *it + 1 ) ;
	puts( "" ) ;
}

int main() {
	init() ;
	process() ;
	return 0 ;
}