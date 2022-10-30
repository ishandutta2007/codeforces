#include <stdio.h>
#define L 20
char c[ L ];
bool judge(){
	for( int i = 0 ; c[ i ] ; i ++ ){
		if( c[ i ] == '1' ){
			if( c[ i + 1 ] && c[ i + 1 ] == '4' ) i ++;
			if( c[ i + 1 ] && c[ i + 1 ] == '4' ) i ++;
		}else return false;
	}
	return true;
}
int main(){
	scanf( "%s" , c );
	puts( judge() ? "YES" : "NO" );
}