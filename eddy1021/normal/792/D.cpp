#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 102110
inline LL lb( LL x ){
  return x & (-x);
}
LL n , q;
inline LL prt( LL x ){
  LL stp = lb( x );
  if( x == stp ){
    x <<= 1;
    return x > n ? x >> 1 : x;
  }
  if( x & ( stp << 1 ) )
    return x ^ stp;
  return x + stp;
}
inline LL lc( LL x ){
  LL stp = lb( x );
  if( stp == 1 ) return x;
  return x - ( stp >> 1 );
}
inline LL rc( LL x ){
  LL stp = lb( x );
  if( stp == 1 ) return x;
  return x + ( stp >> 1 );
}
char c[ N ];
int main(){
  scanf( "%lld%lld" , &n , &q );
  while( q -- ){
    LL x; scanf( "%lld" , &x );
    scanf( "%s" , c );
    for( int i = 0 ; c[ i ] ; i ++ ){
      if( c[ i ] == 'U' ) x = prt( x );
      if( c[ i ] == 'L' ) x = lc( x );
      if( c[ i ] == 'R' ) x = rc( x );
    }
    printf( "%lld\n" , x );
  }
}