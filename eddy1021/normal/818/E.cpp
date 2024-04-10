#include <bits/stdc++.h>
using namespace std;
#define N 101010
typedef long long LL;
int n , k , a[ N ] , t[ N ];
bool p[ N ];
void init(){
  cin >> n >> k;
  for( int i = 0 ; i < n ; i ++ )
    cin >> a[ i ];
}
int g[ N ];
void go( int pp ){
  int nd = 0;
  while( k % pp == 0 )
    nd ++, k /= pp;
  for( int i = 0 ; i < n ; i ++ ){
    g[ i ] = 0;
    while( a[ i ] % pp == 0 )
      g[ i ] ++, a[ i ] /= pp;
  }
  for( int i = 0 , j = -1 , c = 0 ; i < n ; i ++ ){
    while( j < n and c < nd ) c += g[ ++ j ];
    t[ i ] = max( t[ i ] , j );
    c -= g[ i ];
  }
}
void solve(){
  if( k == 1 ){
    cout << (LL)( n + 1 ) * n / 2 << endl;
    return;
  }
  for( int i = 2 ; i < N ; i ++ ) if( !p[ i ] ){
    if( k % i == 0 ) go( i );
    for( int j = i ; j < N ; j += i )
      p[ j ] = true;
  }
  if( k > 1 ) go( k );
  LL ans = 0;
  for( int i = 0 ; i < n ; i ++ )
    ans += n - t[ i ];
  cout << ans << endl;
}
int main(){
  init();
  solve();
}