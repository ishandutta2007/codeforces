#include <map>
#include <set>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 100010
#define inf 1000010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
map<int,int> M;
typedef map<int,int>::iterator mi;
int n , a[ N ] , b[ N ] , c[ N ] , idx;
int A[ N * 3 ] , B[ N * 3 ] , C[ N * 3 ] , no[ N * 3 ];
bool cmp( int a , int b ){ return A[ a ] > A[ b ]; }
void init(){
	n = getint();
	for( int i = 1 ; i <= n ; i ++ ){
		a[ i ] = getint();
		M[ a[ i ] ] = 1;
	}
	for( int i = 1 ; i <= n ; i ++ ){
		b[ i ] = getint();
		M[ b[ i ] ] = 1;
	}
	for( int i = 1 ; i <= n ; i ++ ){
		c[ i ] = getint();
		M[ c[ i ] ] = 1;
	}
	for( mi it = M.begin() ; it != M.end() ; it ++ )
		it->second = ++ idx;
}
void pre_build(){
	for( int i = 1 ; i <= idx ; i ++ ){
		A[ i ] = B[ i ] = C[ i ] = inf;
		no[ i ] = i;
	}
	for( int i = 1 ; i <= n ; i ++ )
		if( A[ M[ a[ i ] ] ] == inf )
			A[ M[ a[ i ] ] ] = i;
	for( int i = 1 ; i <= n ; i ++ )
		if( B[ M[ b[ i ] ] ] == inf )
			B[ M[ b[ i ] ] ] = i;
	for( int i = 1 ; i <= n ; i ++ )
		if( C[ M[ c[ i ] ] ] == inf )
			C[ M[ c[ i ] ] ] = i;
}
multiset<int> aS;
set< pair<int,int> > S;
typedef set< pair<int,int> >::iterator pi;
void insert( int tb , int tc ){
	pair<int,int> tmp = make_pair( tb , tc );
	pi l , now , r = S.lower_bound( tmp );
	if( r->second >= tmp.second ) return;
	l = now = S.insert( tmp ).first; l --;
	aS.erase( aS.lower_bound( l->first + r->second ) );
	aS.insert( now->first + r->second );
	while( l->second < now->second ){
		r = l --;
		aS.erase( aS.lower_bound( l->first + r->second ) );
		S.erase( r );
	}
	aS.insert( l->first + now->second );
}
void process(){
	sort( no + 1 , no + idx + 1 , cmp );
	S.insert( make_pair( 0 , inf * 2 ) );
	S.insert( make_pair( inf * 2 , 0 ) );
	aS.insert( 0 );
	int ans = A[ no[ 1 ] ]; A[ idx + 1 ] = 0;
	for( int i = 1 ; i <= idx ; i ++ ){
		insert( B[ no[ i ] ] , C[ no[ i ] ] );
		if( A[ no[ i + 1 ] ] + *aS.begin() < ans )
			ans = A[ no[ i + 1 ] ] + *aS.begin();
	}
	printf( "%d\n" , ans );
}
int main(){
	init();
	pre_build();
	process();
	S.clear(); aS.clear();
}