#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 202020
const int mod = 1000000007;
int add( int x , int y ){
  x += y;
  return x >= mod ? x - mod : x;
}
int sub( int x , int y ){
  x -= y;
  return x < 0 ? x + mod : x;
}
int mul( LL x , int y ){
  x *= y;
  return x >= mod ? x % mod : x;
}
int n , a[ N ] , ans;
vector<int> v[ N ];
int dp[ N ][ 2 ];
int cnt[ N ][ 2 ];
void go( int now , int prt ){
  ans = add( ans , a[ now ] );
  dp[ now ][ 1 ] = a[ now ];
  cnt[ now ][ 1 ] = 1;
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    go( son , now );
    for( int i = 0 ; i < 2 ; i ++ ){
      int ret = 0;
      ret = add( ret , mul( dp[ now ][ i ] , cnt[ son ][ 1 - i ] ) );
      ret = add( ret , mul( dp[ son ][ i ] , cnt[ now ][ 1 - i ] ) );
      ret = add( ret , ret );
      ans = add( ans , ret );
    }
    cnt[ now ][ 0 ] = add( cnt[ now ][ 0 ] , cnt[ son ][ 1 ] );
    dp[ now ][ 0 ] = add( dp[ now ][ 0 ] ,
        add( dp[ son ][ 1 ] , mul( cnt[ son ][ 1 ] , sub( 0 , a[ now ] ) ) ) );
    cnt[ now ][ 1 ] = add( cnt[ now ][ 1 ] , cnt[ son ][ 0 ] );
    dp[ now ][ 1 ] = add( dp[ now ][ 1 ] ,
        add( dp[ son ][ 0 ] , mul( cnt[ son ][ 0 ] , a[ now ] ) ) );
  }
}
int main(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ ){
    scanf( "%d" , &a[ i ] );
    if( a[ i ] < 0 ) a[ i ] += mod;
  }
  for( int i = 1 ; i < n ; i ++ ){
    int ui , vi;
    scanf( "%d%d" , &ui , &vi );
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
  go( 1 , 1 );
  printf( "%d\n" , ans );
}