//by tzupengwang
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

int n ;
ll s[ 100005 ] ;

void init() {
	scanf( "%d" , &n ) ;
	for ( int i = 0 ; i < n ; i ++ ) scanf( "%I64d" , &s[ i ] ) ;
}

void process() {
	ll a( 0 ) , b( 0 ) ;
	int l = 0 , r = n - 1 ;
	while ( l <= r ) {
		if ( a <= b ) a += s[ l ++ ] ;
		else b += s[ r -- ] ;
	}
	printf( "%d %d\n" , l , n - l ) ;
}

int main() {
	init() ;
	process() ;
	return 0 ;
}