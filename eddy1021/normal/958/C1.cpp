#include <bits/stdc++.h>
using namespace std;
#define N 101010
int n , a[ N ] , p , l[ N ] , r[ N ];
int main(){
  cin >> n >> p;
  for( int i = 1 ; i <= n ; i ++ )
    cin >> a[ i ];
  for( int i = 1 ; i <= n ; i ++ )
    l[ i ] = (l[ i - 1 ] + a[ i ]) % p;
  for( int i = n ; i >= 1 ; i -- )
    r[ i ] = (r[ i + 1 ] + a[ i ]) % p;
  int ans = 0;
  for( int i = 1 ; i < n ; i ++ )
    ans = max( ans , l[ i ] + r[ i + 1 ] );
  cout << ans << endl;
}