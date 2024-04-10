#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 55
const LL inf = 10000000000000000LL;
LL n , k , M , dp[ N * N ] , t[ N ];
int main(){
  cin >> n >> k >> M;
  for( int i = 0 ; i < k ; i ++ )
    cin >> t[ i ];
  sort( t , t + k );
  for( int i = 1 ; i < k ; i ++ )
    t[ i ] += t[ i - 1 ];
  for( int i = 1 ; i <= n * ( k + 1 ) ; i ++ )
    dp[ i ] = inf;
  for( int _ = 0 ; _ < n ; _ ++ ){
    for( int i = n * ( k + 1 ) ; i >= 0 ; i -- ){
      if( dp[ i ] == inf ) continue;
      for( int solved = 1 ; solved <= k ; solved ++ ){
        LL tdp = dp[ i ] + t[ solved - 1 ];
        int ii = i + solved + (solved == k);
        dp[ ii ] = min( dp[ ii ] , tdp );
      }
    }
  }
  int ans = 0;
  for( int i = 1 ; i <= n * ( k + 1 ) ; i ++ )
    if( dp[ i ] <= M )
      ans = i;
  cout << ans << endl;
}