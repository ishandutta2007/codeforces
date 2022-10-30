#include <stdio.h>
#include <algorithm>
#define N 8
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
struct XD{
	int x , y;
}bx[ N ];
bool cmp1( XD x , XD y ){ return x.x < y.x; }
bool cmp2( XD x , XD y ){ return x.y < y.y; }
int pre , xt , yt , cntx[ N ] , cnty[ N ];
bool test(){
	std::sort( bx , bx + N , cmp1 );
	xt = yt = pre = -1;
	for( int i = 0 ; i < N ; i ++ ){
		if( i && bx[ i ].x == bx[ i - 1 ].x && bx[ i ].y == bx[ i - 1 ].y )
			return false;
		if( bx[ i ].x != pre ){
			xt ++; pre = bx[ i ].x;
			cntx[ xt ] = 1;
		}else cntx[ xt ] ++;
	}
	if( xt != 2 || cntx[ 1 ] != 2 ) return false;
	std::sort( bx , bx + N , cmp2 );
	pre = -1;
	for( int i = 0 ; i < N ; i ++ )
		if( bx[ i ].y != pre ){
			yt ++; pre = bx[ i ].y;
			cnty[ yt ] = 1;
		}else cnty[ yt ] ++;
	if( yt != 2 || cnty[ 1 ] != 2 ) return false;
	return true;
}
int main(){
	for( int i = 0 ; i < 8 ; i ++ ){
		bx[ i ].x = getint();
		bx[ i ].y = getint();
	}
	if( test() ) puts( "respectable" );
	else puts( "ugly" );
}