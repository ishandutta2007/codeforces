#include <stdio.h>
#define inf 10000000
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n , x1 , x2 , y1 , y2 , sum;
int minx , miny , maxx , maxy;
int main(){
	minx = miny = inf;
	maxx = maxy = -inf;
	n = getint(); while( n -- ){
		x1 = getint(); y1 = getint();
		x2 = getint(); y2 = getint();
		sum += ( x2 - x1 ) * ( y2 - y1 );
		if( x1 < minx ) minx = x1;
		if( y1 < miny ) miny = y1;
		if( x2 > maxx ) maxx = x2;
		if( y2 > maxy ) maxy = y2;
	}
	if( sum == ( maxx - minx ) * ( maxy - miny ) &&
			maxx - minx == maxy - miny ) puts( "YES" );
	else puts( "NO" );
}