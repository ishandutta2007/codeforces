#include <bits/stdc++.h>
using namespace std;
#define N 101010
char s[ N ] , t[ N ] , u[ N ];
int lens , lent , lenu;
int lst[ 26 ] , cnt[ 26 ];
int main(){
  scanf( "%s" , s );
  lens = strlen( s );
  for( int i = 0 ; i < 26 ; i ++ )
    lst[ i ] = -1;
  for( int i = 0 ; i < lens ; i ++ )
    lst[ s[ i ] - 'a' ] = i;
  int ptr = 0;
  for( int i = 0 ; i < 26 ; i ++ ){
    while( ptr <= lst[ i ] ){
      while( lent and t[ lent - 1 ] - 'a' <= i ){
        u[ lenu ++ ] = t[ lent - 1 ];
        cnt[ t[ lent - 1 ] - 'a' ] --;
        lent --;
      }
      t[ lent ++ ] = s[ ptr ];
      cnt[ s[ ptr ] - 'a' ] ++;
      ptr ++;
    }
    while( lent and t[ lent - 1 ] - 'a' <= i ){
      u[ lenu ++ ] = t[ lent - 1 ];
      cnt[ t[ lent - 1 ] - 'a' ] --;
      lent --;
    }
  }
  while( lent ){
    u[ lenu ++ ] = t[ lent - 1 ];
    cnt[ t[ lent - 1 ] - 'a' ] --;
    lent --;
  }
  u[ lenu ] = 0;
  puts( u );
}