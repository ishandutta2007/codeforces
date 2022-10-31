#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 1021
LL n , w , b , x , c[ N ] , cst[ N ];
LL dp[ 2 ][ N * 10 ];
pair<LL,LL> dq[ N * 10 ];
int dqf , dqt;
int main(){
  scanf( "%lld%lld%lld%lld" , &n , &w , &b , &x );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%lld" , &c[ i ] );
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%lld" , &cst[ i ] );
  LL tot = accumulate( c , c + n , 0LL );
  dp[ 1 ][ 0 ] = w;
  for( int i = 1 ; i <= tot ; i ++ )
    dp[ 1 ][ i ] = -1;
  for( int i = 0 ; i < n ; i ++ ){
    int now = i & 1 , pre = 1 ^ now;
    dqf = dqt = 0;
    for( int j = 0 ; j <= tot ; j ++ ){
      if( dp[ pre ][ j ] != -1 ){
        LL vl = min( dp[ pre ][ j ] + x , w + b * j ) + j * cst[ i ];
        while( dqf < dqt and dq[ dqt - 1 ].second <= vl )
          dqt --;
        dq[ dqt ++ ] = {j, vl};
      }
      while( dqf < dqt and dq[ dqf ].first < j - c[ i ] )
        dqf ++;
      if( dqf == dqt )
        dp[ now ][ j ] = -1;
      else
        dp[ now ][ j ] = max( -1LL , dq[ dqf ].second - j * cst[ i ] ); 
    }
  }
  int ans = 0;
  int lst = (n + 1) & 1;
  for( int i = 1 ; i <= tot ; i ++ ){
    if( dp[ lst ][ i ] == -1 ) continue;
    ans = i;
  }
  printf( "%d\n" , ans );
}