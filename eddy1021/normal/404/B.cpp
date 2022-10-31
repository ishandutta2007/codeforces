#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define db double
db a , d , n , x , y;
void init(){
	scanf( "%lf%lf%lf" , &a , &d , &n );
}
void process(){
	int tmp = int( d / ( 4 * a ) );
	d -= 4 * tmp * a;
//	printf( "%.8lf\n" , d );
	for( int i = 0 ; i < n ; i ++ ){
		db td = d;
		bool tag = false;
		while( td > 0 && !tag ){
			if( y == 0 && x < a ){
				db lft = a - x;
				if( lft <= td ){
					td -= lft;
					x = a; y = 0;
				}else{
					x += td;
					printf( "%.8lf %.8lf\n" , x , y );
					tag = true; break;
				}
			}else if( x == a && y < a ){
				db lft = a - y;
				if( lft <= td ){
					td -= lft;
					x = a; y = a;
				}else{
					y += td;
					printf( "%.8lf %.8lf\n" , x , y );
					tag = true; break;
				}
			}else if( y == a && x > 0 ){
				db lft = x;
				if( lft <= td ){
					td -= lft;
					x = 0; y = a;
				}else{
					x -= td;
					printf( "%.8lf %.8lf\n" , x , y );
					tag = true; break;
				}
			}else{
				db lft = y;
				if( lft <= td ){
					td -= lft;
					x = 0; y = 0;
				}else{
					y -= td;
					printf( "%.8lf %.8lf\n" , x , y );
					tag = true; break;
				}
			}
		}
		if( !tag ) printf( "%.8lf %.8lf\n" , x , y );
	}
}
int main(){
	init();
	process();
}