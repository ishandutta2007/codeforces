// eddy1021
#include <bits/stdc++.h>
using namespace std;
#define N 202020
typedef long long LL;
const LL mod7 = 1000000007LL;
inline LL mul( int x , int y ){
  LL res = (LL)x * (LL)y;
  return res >= mod7 ? res % mod7 : res;
}
inline LL add( int x , int y ){
  LL res = x + y;
  return res >= mod7 ? res - mod7 : res;
}
inline LL sub( int x , int y ){
  LL res = x - y;
  return res < 0 ? res + mod7 : res;
}
int n , a[ N ] , two[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &a[ i ] );
  two[ 0 ] = 1;
  for( int i = 1 ; i <= n ; i ++ )
    two[ i ] = mul( two[ i - 1 ] , 2 );
}
int tag[ N ] , stmp;
bool got[ N ];
int ans;
bool on_cyc[ N ];
void go( int now ){
  ++ stmp;
  while( !got[ now ] ){
    got[ now ] = true;
    tag[ now ] = stmp;
    now = a[ now ];
  }
  if( tag[ now ] != stmp ) return;
  int cnt = 0;
  while( !on_cyc[ now ] ){
    on_cyc[ now ] = true;
    cnt ++;
    now = a[ now ];
  }
  ans = mul( ans , sub( two[ cnt ] , 2 ) );
}
void solve(){
  ans = 1;
  for( int i = 1 ; i <= n ; i ++ )
    if( !got[ i ] )
      go( i );
  int not_on_cyc = 0;
  for( int i = 1 ; i <= n ; i ++ )
    if( !on_cyc[ i ] )
      not_on_cyc ++;
  ans = mul( ans , two[ not_on_cyc ] );
  printf( "%d\n" , ans );
}
int main(){
  init();
  solve();
}