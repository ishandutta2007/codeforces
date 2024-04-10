//by tzupengwang
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

ll l , r ;

void init() {
	scanf( "%I64d%I64d" , &l , &r ) ;
}

ll mpow( ll exp ) {
	ll ret = 1 ;
	for ( int i = 0 ; i < exp ; i ++ ) ret *= 10 ;
	return ret ;
}

ll cal( ll a ) {
	if ( a < 10 ) return a ;
	ll ret = 9 ;
	ll cnt = 0 , tmp = a , hib , lob ;
	while ( tmp ) cnt ++ , hib = tmp , tmp /= 10 ;
	for ( ll i = 0 ; i < cnt - 2 ; i ++ ) {
		ret += mpow( i ) * 9 ;
	}
	ret += mpow( cnt - 2 ) * ( hib - 1 ) ;
	lob = a % 10 ;
	tmp = ( a - hib * mpow( cnt - 1 ) ) / 10 + 1 ;
	if ( lob < hib ) tmp -- ;
	ret += tmp ;
	return ret ;
}

void process() {
	printf( "%I64d\n" , cal( r ) - cal( l - 1 ) ) ;
}

int main() {
	init() ;
	process() ;
	return 0 ;
}