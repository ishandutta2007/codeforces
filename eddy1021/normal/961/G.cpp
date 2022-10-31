#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 202020
const int mod = 1000000007;
inline int add( int x , int y ){
  x += y;
  return x >= mod ? x - mod : x;
}
inline int sub( int x , int y ){
  x -= y;
  return x < 0 ? x + mod : x;
}
inline int mul( LL x , int y ){
  x *= y;
  return x >= mod ? x % mod : x;
}
inline int mpow( int a , int b ){
  int ret = 1;
  while( b ){
    if( b & 1 ) ret = mul( ret , a );
    a = mul( a , a );
    b >>= 1;
  }
  return ret;
}
int fac[ N ] , ifac[ N ];
inline int C( int a , int b ){
  return mul( fac[ a ] , mul( ifac[ b ] , ifac[ a - b ] ) );
}
inline int S( int n , int k ){
  if( n < k ) return 0;
  int ret = 0;
  for( int i = 1 ; i <= k ; i ++ ){
    int tmp = C( k , i );
    tmp = mul( tmp , mpow( i , n ) );
    if( (k - i) & 1 )
      ret = sub( ret , tmp );
    else
      ret = add( ret , tmp );
  }
  return mul( ret , ifac[ k ] );
}
int n , k;
int main(){
  fac[ 0 ] = ifac[ 0 ] = 1;
  for( int i = 1 ; i < N ; i ++ ){
    fac[ i ] = mul( fac[ i - 1 ] , i );
    ifac[ i ] = mpow( fac[ i ] , mod - 2 );
  }
  scanf( "%d%d" , &n , &k );
  int bns = add( S( n , k ) , mul( n - 1 , S( n - 1 , k ) ) );
  int sum = 0;
  for( int i = 0 , x ; i < n ; i ++ ){
    scanf( "%d" , &x );
    sum = add( sum , x );
  }
  printf( "%d\n" , mul( sum , bns ) );
}