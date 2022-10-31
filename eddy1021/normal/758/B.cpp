#include <bits/stdc++.h>
using namespace std;
int cnt[ 4 ] , at[ 256 ];
char cc[ 111 ];
int main(){
  scanf( "%s" , cc );
  for( int i = 0 ; cc[ i ] ; i ++ )
    if( cc[ i ] == '!' )
      cnt[ i & 3 ] ++;
    else
      at[ (int)cc[ i ] ] = i & 3;
  for( char c : { 'R' , 'B' , 'Y' , 'G' } )
    printf( "%d " , cnt[ at[ (int)c ] ] );
  puts( "" );
}