#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 1000000007;
inline LL add( LL a , LL b ){
  a += b;
  return a >= mod ? a - mod : a;
}
inline LL mul( LL a , LL b ){
  a *= b;
  return a >= mod ? a % mod : a;
}
LL pw( LL a , LL b ){
  if( b == 0 ) return 1;
  LL ret = pw( mul( a , a ) , b >> 1 );
  if( b & 1 ) ret = mul( ret , a );
  return ret;
}
#define N 1000001
#define K 21
bool p[ N ];
int f[ N ][ K ] , c[ N ][ K ];
void build(){
  for( int i = 0 ; i < K ; i ++ )
    f[ 0 ][ i ] = 2 - ( i == 0 );
  for( int i = 1 ; i < N ; i ++ )
    for( int j = 0 ; j < K ; j ++ ){
      f[ i ][ j ] = f[ i - 1 ][ j ];
      if( j )
        f[ i ][ j ] = add( f[ i ][ j ] , f[ i ][ j - 1 ] );
    }
  for( int i = 2 ; i < N ; i ++ ) if( !p[ i ] )
    for( int j = i ; j < N ; j += i ){
      p[ j ] = true;
      int cc = 0 , k = j;
      while( k % i == 0 ) cc ++ , k /= i;
      c[ j ][ cc ] ++;
    }
}
int main(){
  build();
  int t; scanf( "%d" , &t ); while( t -- ){
    int r , n , a = 1; scanf( "%d%d" , &r , &n );
    for( int i = 0 ; i < K ; i ++ )
      a = mul( a , pw( f[ r ][ i ] , c[ n ][ i ] ) );
    printf( "%d\n" , a );
  }
}