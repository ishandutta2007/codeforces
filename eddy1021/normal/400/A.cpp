#include <stdio.h>
#define N 15
char c[ N ]; int t , k , ans;
int main(){
	scanf( "%d" , &t ); while( t -- ){
		scanf( "%s" , c + 1 ); ans = 0;
		for( int i = 1 ; i <= 12 ; i ++ )
			if( !( 12 % i ) ){
				bool chk = false;
				for( int j = 1 ; j <= 12 / i ; j ++ ){
					bool chk2 = true;
					for( int k = j ; k <= 12 ; k += 12 / i )
						if( c[ k ] == 'O' )
							chk2 = false;
					if( chk2 ) chk = true;
				}
				if( chk ) ans ++;
			}
		printf( "%d" , ans );
		for( int i = 1 ; i <= 12 ; i ++ )
			if( !( 12 % i ) ){
				bool chk = false;
				for( int j = 1 ; j <= 12 / i ; j ++ ){
					bool chk2 = true;
					for( int k = j ; k <= 12 ; k += 12 / i )
						if( c[ k ] == 'O' )
							chk2 = false;
					if( chk2 ) chk = true;
				}
				if( chk ) printf( " %dx%d" , i , 12 / i );
			}
		puts( "" );
	}
}