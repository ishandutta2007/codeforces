// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 10210
const LL mod = 1000000007;
LL mul( LL x , LL y ){
  LL ret = x * y;
  return ret >= mod ? ret % mod : ret;
}
LL sub( LL x , LL y ){
  LL ret = x - y;
  return ret < 0 ? ret + mod : ret;
}
LL mypow( LL x , LL y ){
  if( y == 0 ) return 1;
  LL ret = mypow( mul( x , x ) , y >> 1 );
  if( y & 1ll ) ret = mul( ret , x );
  return ret;
}
int n , k;
vector< int > v[ N ];
map< int , int > M[ N ];
void init(){
  scanf( "%d%d" , &n , &k );
  for( int i = 1 ; i <= k ; i ++ )
    for( int j = 1 ; j <= k ; j ++ ){
      M[ i ][ j ] = ( i == j ? k - 1 : mod - 1 );
      if( i > j ) v[ i ].push_back( j );
    }
  for( int i = k + 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= k ; j ++ ){
      int vi; scanf( "%d" , &vi );
      M[ vi ][ i ] = M[ i ][ vi ] = mod - 1;
      M[ i ][ i ] ++; M[ vi ][ vi ] ++;
      v[ i ].push_back( vi );
    }
}
void solve(){
  int ans = 1;
  for( int i = n - 1 ; i >= 1 ; i -- ){
    ans = mul( ans , M[ i ][ i ] );
    LL inv = mypow( M[ i ][ i ] , mod - 2 );
    for( int x : v[ i ] )
      M[ i ][ x ] = mul( M[ i ][ x ] , inv );
    for( int x : v[ i ] ){
      LL dlt = M[ x ][ i ];
      for( int y : v[ i ] )
        M[ x ][ y ] = sub( M[ x ][ y ] , mul( M[ i ][ y ] , dlt ) );
    }
  }
  printf( "%d\n" , ans );
}
int main(){
  init();
  solve();
}