#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define N 131072
char c[ N ] , t[ N ];
int len;
bitset<N> a[ 26 ] , all , cur;
int main(){
  scanf( "%s" , c + 1 );
  len = strlen( c + 1 );
  for( int i = 0 ; i < len ; i ++ )
    all[ i ] = 1;
  for( int i = 1 ; i <= len ; i ++ )
    a[ c[ i ] - 'a' ][ i ] = 1;
  int q; scanf( "%d" , &q ); while( q -- ){
    int cmd; scanf( "%d" , &cmd );
    if( cmd == 1 ){
      int ii; char buf[ 8 ];
      scanf( "%d%s" , &ii , buf );
      a[ c[ ii ] - 'a' ][ ii ] = 0;
      c[ ii ] = buf[ 0 ];
      a[ c[ ii ] - 'a' ][ ii ] = 1;
    }else{
      int l , r; scanf( "%d%d%s" , &l , &r , t + 1 );
      int tlen = strlen( t + 1 );
      if( l > r - tlen + 1 ){
        printf( "0\n" );
        continue;
      }
      cur = all;
      for( int i = 1 ; i <= tlen ; i ++ )
        cur &= (a[t[i] - 'a'] >> i);
      printf( "%d\n" , (int)(cur >> (l - 1)).count() -
                       (int)(cur >> (r - tlen + 1)).count() );
    }
  }
}