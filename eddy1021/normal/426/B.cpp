#include <bits/stdc++.h>
using namespace std;
#define N 111
int n , m;
bitset<N> b[ N ];
bool okay( int x ){
  for( int i = 0 ; i < x - i - 1 ; i ++ )
    if( b[ i ] != b[ x - i - 1 ] )
      return false;
  return true;
}
int main(){
  cin >> n >> m;
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 , x ; j < m ; j ++ ){
      cin >> x;
      if( x ) b[ i ][ j ] = x;
    }
  while( n % 2 == 0 and okay( n ) )
    n >>= 1;
  cout << n << endl;
}