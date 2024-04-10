#include <bits/stdc++.h>
using namespace std;
#define N 1021
#define K 55
int n , p , k;
int ac[ 2 ][ N ];
void init(){
  scanf( "%d%d%d" , &n , &p , &k );
  for( int i = 0 ; i < 2 ; i ++ ){
    int _, x; scanf( "%d" , &_ ); while( _ -- ){
      scanf( "%d" , &x ); ac[ i ][ x ] = 1;
    }
  }
  if( ( p / 2 ) * k >= n ){
    int nac = 0;
    for( int i = 1 ; i <= n ; i ++ )
      if( ac[ 0 ][ i ] or ac[ 1 ][ i ] )
        nac ++;
    printf( "%d\n" , nac );
    exit(0);
  }
}
short pdp[ N ][ K ][ K ][ 2 ];
short pna[ N ][ K ][ K ][ 2 ];
short pnb[ N ][ K ][ K ][ 2 ];
short dp[ 2 ][ N ][ K ][ K ];
void solve(){
  for( int i = 0 ; i < n ; i ++ )
    for( int a = 0 ; a < k ; a ++ )
      for( int b = 0 ; b < k ; b ++ )
        for( int nxt = 0 ; nxt < 2 ; nxt ++ ){
          int nac = 0;
          for( int j = 1 ; j < k and i + 1 - j > 0 ; j ++ ){
            if( j > a and j > b ) break;
            if( j <= a and j <= b ){
              if( ac[ nxt ][ i + 1 - j ] )
                nac ++;
              continue;
            }
            if( j <= a and ac[ 1 ][ i + 1 - j ] ) continue;
            if( j <= b and ac[ 0 ][ i + 1 - j ] ) continue;
            if( j <= a and ac[ 0 ][ i + 1 - j ] and nxt == 0 ) nac ++;
            if( j <= b and ac[ 1 ][ i + 1 - j ] and nxt == 1 ) nac ++;
          }
          if( ac[ nxt ][ i + 1 ] ) nac ++;
          int na = nxt == 0 ? 0 : min( a + 1 , k - 1 );
          int nb = nxt == 1 ? 0 : min( b + 1 , k - 1 );
          pdp[ i ][ a ][ b ][ nxt ] = nac;
          pna[ i ][ a ][ b ][ nxt ] = na;
          pnb[ i ][ a ][ b ][ nxt ] = nb;
        }
  for( int i = 0 ; i < n ; i ++ ){
    int now = i & 1 , nxt = 1 - now;
    for( int j = 0 ; j <= p ; j ++ )
      for( int a = 0 ; a < k ; a ++ )
        for( int b = 0 ; b < k ; b ++ )
          dp[ nxt ][ j ][ a ][ b ] = 0;
    for( int j = 0 ; j <= p ; j ++ )
      for( int a = 0 ; a < k ; a ++ )
        for( int b = 0 ; b < k ; b ++ ){
          {
            int na = min( a + 1 , k - 1 );
            int nb = min( b + 1 , k - 1 );
            dp[ nxt ][ j ][ na ][ nb ] =
              max( dp[ nxt ][ j ][ na ][ nb ] ,
                   dp[ now ][ j ][ a ][ b ] );
          }
          if( j == p ) continue;
          for( int who = 0 ; who < 2 ; who ++ ){
            short na = pna[ i ][ a ][ b ][ who ];
            short nb = pnb[ i ][ a ][ b ][ who ];
            short nc = pdp[ i ][ a ][ b ][ who ];
            dp[ nxt ][ j + 1 ][ na ][ nb ] =
              max( (int)dp[ nxt ][ j + 1 ][ na ][ nb ] ,
                   dp[ now ][ j ][ a ][ b ] + nc );
          }
        }
  }
  int ans = 0;
  for( int j = 0 ; j <= p ; j ++ )
    for( int a = 0 ; a < k ; a ++ )
      for( int b = 0 ; b < k ; b ++ )
        ans = max( ans , (int)dp[ n & 1 ][ j ][ a ][ b ] );
  printf( "%d\n" , ans );
}
int main(){
  init();
  solve();
}