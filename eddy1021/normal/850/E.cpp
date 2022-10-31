#include <bits/stdc++.h>
using namespace std;
/* xor convolution:
 * x = (x0,x1) , y = (y0,y1)
 * z = ( x0y0 + x1y1 , x0y1 + x1y0 )
 * =>
 * x' = ( x0+x1 , x0-x1 ) , y' = ( y0+y1 , y0-y1 )
 * z' = ( ( x0+x1 )( y0+y1 ) , ( x0-x1 )( y0-y1 ) )
 * z = (1/2) * z''
 * or convolution:
 * x = (x0, x0+x1), inv = (x0, x1-x0) w/o final div
 * and convolution:
 * x = (x0+x1, x1), inv = (x0-x1, x1) w/o final div */
typedef long long LL;
const int MAXN = (1<<20)+10;
const LL MOD = 1e9+7;
inline LL pw( LL x , LL k ) {
  LL res = 1;
  for( LL bs = x ; k ; k >>= 1, bs = (bs * bs)%MOD ){
    if( k&1 ) res = ( res * bs ) % MOD;
  }
  return res;
}
inline LL Inv( LL x ) {
  return pw( x , MOD-2 );
}
inline void fwt( LL x[ MAXN ] , int N , bool inv=0 ) {
  for( int d = 1 ; d < N ; d <<= 1 ) {
    int d2 = d<<1;
    for( int s = 0 ; s < N ; s += d2 ) {
      for( int i = s , j = s+d ; i < s+d ; i++, j++ ){
        LL ta = x[ i ] , tb = x[ j ];
        x[ i ] = ta+tb;
        x[ j ] = ta-tb;
        if( x[ i ] >= MOD ) x[ i ] -= MOD;
        if( x[ j ] < 0 ) x[ j ] += MOD;
      }
    }
  }
  if( inv )
    for( int i = 0 ; i < N ; i++ ) {
      x[ i ] *= Inv( N );
      x[ i ] %= MOD;
    }
}
#define N 20
char buf[ (1 << N) + N ];
LL a[ 1 << (N + 1) ] , m;
int main(){
  scanf( "%lld" , &m );
  scanf( "%s" , buf );
  for( int i = 0 ; i < (1 << m) ; i ++ )
    a[ i ] = buf[ i ] - '0';
  fwt( a , 1 << m );
  for( int i = 0 ; i < (1 << m) ; i ++ )
    a[ i ] = a[ i ] * a[ i ] % MOD;
  fwt( a , 1 << m , true );
  LL ans = 0;
  for( int i = 0 ; i < (1 << m) ; i ++ )
    ans = (ans + a[ i ] * (1 << (m - __builtin_popcount( i ))) % MOD ) % MOD;
  ans = ans * 3 % MOD;
  printf( "%lld\n" , ans );
}