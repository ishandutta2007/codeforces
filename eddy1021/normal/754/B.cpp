#include <bits/stdc++.h>
using namespace std;
char c[ 9 ][ 9 ];
int dx[]={0,1,1,1};
int dy[]={1,0,1,-1};
int main(){
  for( int i = 0 ; i < 4 ; i ++ )
    scanf( "%s" , c[ i ] );
  for( int i = 0 ; i < 4 ; i ++ )
    for( int j = 0 ; j < 4 ; j ++ )
      for( int dir = 0 ; dir < 4 ; dir ++ ){
        int ii = i + dx[ dir ] + dx[ dir ];
        int jj = j + dy[ dir ] + dy[ dir ];
        if( ii < 0 || jj < 0 || ii > 3 || jj > 3 )
          continue;
        int x = 0 , o = 0;
        for( int k = 0 ; k < 3 ; k ++ ){
          if( c[ i + dx[ dir ] * k ][ j + dy[ dir ] * k ] == 'x' )
            x ++;
          if( c[ i + dx[ dir ] * k ][ j + dy[ dir ] * k ] == 'o' )
            o ++;
        }
        if( x == 2 && o == 0 ){
          puts( "YES" );
          exit( 0 );
        }
      }
  puts( "NO" );
}