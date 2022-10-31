#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int add( int a , int b ){
  a += b;
  return a >= mod ? a - mod : a;
}
#define N 256
int n , m;
char c[ N ][ N ] , cc[ N ][ N ];
void init(){
  scanf( "%d%d" , &n , &m );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%s" , c[ i ] );
  if( n > m ){
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < m ; j ++ )
        cc[ i ][ j ] = c[ i ][ j ];
    swap( n , m );
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < m ; j ++ )
        c[ i ][ j ] = cc[ j ][ i ];
  }
}
int dp[ 1 << 15 ][ 2 ][ 2 ];
int tdp[ 1 << 15 ][ 2 ][ 2 ];
void solve(){
  assert( n < 15 );
  dp[ 0 ][ 0 ][ 0 ] = 1;
  for( int j = 0 ; j < m ; j ++ )
    for( int i = 0 ; i < n ; i ++ ){
      for( int k = 0 ; k < (1 << n) ; k ++ )
        for( int dn = 0 ; dn < 2 ; dn ++ )
          for( int uu = 0 ; uu < 2 ; uu ++ ){
            tdp[ k ][ dn ][ uu ] = dp[ k ][ dn ][ uu ];
            dp[ k ][ dn ][ uu ] = 0;
          }
      for( int k = 0 ; k < (1 << n) ; k ++ )
        for( int dn = 0 ; dn < 2 ; dn ++ )
          for( int uu = 0 ; uu < 2 ; uu ++ ){
            if( tdp[ k ][ dn ][ uu ] == 0 ) continue;
            if( c[ i ][ j ] == 'x' ){
              int nk = k & (~(1 << i));
              int ndn = 0;
              int nuu = uu;
              int &ns = dp[ nk ][ ndn ][ nuu ];
              ns = add( ns , tdp[ k ][ dn ][ uu ] );
              continue;
            }
            { // put
              int nk = k | (1 << i);
              int ndn = ( i + 1 == n ? 0 : 1 );
              int nuu = uu;
              int &ns = dp[ nk ][ ndn ][ nuu ];
              ns = add( ns , tdp[ k ][ dn ][ uu ] );
            }
            { // no put
              int nk = k;
              int ndn = ( i + 1 == n ? 0 : dn );
              int nuu = uu;
              if( dn == 0 and ((k >> i) & 1) == 0 )
                nuu ++;
              if( nuu > 1 ) continue;
              int &ns = dp[ nk ][ ndn ][ nuu ];
              ns = add( ns , tdp[ k ][ dn ][ uu ] );
            }
          }
    }
  int ans = 0;
  for( int i = 0 ; i < (1 << n) ; i ++ )
    for( int j = 0 ; j < 2 ; j ++ )
      for( int k = 0 ; k < 2 ; k ++ )
        ans = add( ans , dp[ i ][ j ][ k ] );
  printf( "%d\n" , ans );
}
int main(){
  init();
  solve();
}