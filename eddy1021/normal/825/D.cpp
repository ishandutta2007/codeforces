#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 1010101
char s[ N ] , t[ N ];
int cs[ 26 ] , ct[ 26 ] , q , cc[ 99 ];
int main(){
  scanf( "%s%s" , s , t );
  for( int i = 0 ; s[ i ] ; i ++ )
    if( s[ i ] == '?' ) q ++;
    else cs[ s[ i ] - 'a' ] ++;
  for( int i = 0 ; t[ i ] ; i ++ )
    ct[ t[ i ] - 'a' ] ++;
  int bl = 0 , br = N , ba = 0;
  while( bl <= br ){
    int bmid = (bl + br) >> 1;
    LL nd = 0;
    for( int i = 0 ; i < 26 ; i ++ )
      if( ct[ i ] )
        nd += max( 0LL , (LL)ct[ i ] * bmid - cs[ i ] );
    if( nd <= q ) ba = bmid , bl = bmid + 1;
    else br = bmid - 1;
  }
  for( int i = 0 ; i < 26 ; i ++ )
    if( ct[ i ] )
      cc[ i ] = max( 0LL , (LL)ct[ i ] * ba - cs[ i ] );
  for( int i = 0 , ptr = 0 ; s[ i ] ; i ++ )
    if( s[ i ] == '?' ){
      while( ptr < 26 and cc[ ptr ] == 0 ) ptr ++;
      s[ i ] = ( ptr % 26 ) + 'a';
      cc[ ptr ] --;
    }
  puts( s );
}