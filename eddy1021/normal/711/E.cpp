// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod3 = 1000003LL;
#define N 1010101
inline LL add( LL x , LL y , LL mod ){
  LL res = x + y;
  return res >= mod ? res - mod : res;
}
inline LL sub( LL x , LL y , LL mod ){
  LL res = x - y;
  return res < 0 ? res + mod : res;
}
inline LL mul( LL x , LL y , LL mod ){
  LL res = x * y;
  return res >= mod ? res % mod : res;
}
LL mymul( LL a , LL b , LL mod ){
  if( b == 0 ) return 0;
  LL ret = mymul( a , b / 2 , mod );
  ret = add( ret , ret , mod );
  if( b & 1ll ) ret = add( ret , a , mod );
  return ret;
}
LL mypow( LL a , LL b , LL mod ){
  if( b == 0 ) return 1;
  LL ret = mypow( a , b / 2 , mod );
  ret = mymul( ret , ret , mod );
  if( b & 1ll ) ret = mymul( ret , a , mod );
  return ret;
}
LL fastpow( LL a , LL b , LL mod ){
  if( b == 0 ) return 1;
  LL ret = fastpow( a , b / 2 , mod );
  ret = ret * ret % mod;
  if( b & 1ll ) ret = ret * a % mod;
  return ret;
}
LL n , k , fac[ N ] , ifac[ N ];
inline LL C( LL a , LL b ){
  if( a < b ) return 0;
  return mul( fac[ a ] , mul( ifac[ a - b ] , ifac[ b ] , mod3 ) , mod3 );
}
inline LL fact( LL x ){
  LL ret = 1;
  while( x ){
    ret = mul( ret , fac[ x % mod3 ] , mod3 );
    x /= mod3;
  }
  return ret;
}
inline LL cal(){
  if( k >= mod3 ) return 0;
  LL b[ 3 ] , m[ 3 ];
  b[ 0 ] = 1; m[ 0 ] = mod3;
  for( int i = 1 ; i < 3 ; i ++ ){
    m[ i ] = m[ i - 1 ] * mod3;
    b[ i ] = b[ i - 1 ] * mod3;
  }
  LL ret = 1;
  for( int i = 0 ; i < 3 ; i ++ ){
    LL pa = mypow( 2 , n , m[ i ] ) / b[ i ];
    LL pb = k % m[ i ] / b[ i ];
    ret = mul( ret , C( pa , pb ) , mod3 );
  }
  return mul( ret , fact( k ) , mod3 );
}
void init(){
  scanf( "%lld%lld" , &n , &k );
  fac[ 0 ] = ifac[ 0 ] = 1;
  for( LL i = 1 ; i < mod3 ; i ++ ){
    fac[ i ] = mul( fac[ i - 1 ] , i , mod3 );
    ifac[ i ] = fastpow( fac[ i ] , mod3 - 2 , mod3 );
  }
}
inline LL take_out2(){
  LL ret = fastpow( 2 , n , mod3 ) , res = k - 1;
  for( LL i = 0 ; res > 0 ; i ++ ){
    LL out = res - res / 2;
    LL mr = fastpow( fastpow( 2 , out , mod3 ) , i , mod3 );
    ret = mul( ret , mr , mod3 );
    res -= out;
  }
  return ret;
}
void solve(){
  if( n < 62 && ( ( 1ll << n ) < k ) ){
    puts( "1 1" );
    exit( 0 );
  }
  LL p = cal();
  LL q = fastpow( fastpow( 2 , n , mod3 ) , k , mod3 );
  LL inv = fastpow( take_out2() , mod3 - 2 , mod3 );
  p = mul( p , inv , mod3 );
  q = mul( q , inv , mod3 );
  p = sub( q , p , mod3 );
  printf( "%lld %lld\n" , p , q );
}
int main(){
  init();
  solve();
}