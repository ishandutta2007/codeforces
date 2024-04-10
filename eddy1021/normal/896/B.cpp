#include <bits/stdc++.h>
using namespace std;
#define N 1021
int n , m , c , v[ N ];
bool gt[ N ];
inline bool win(){
  for( int i = 1 ; i <= n ; i ++ )
    if( not gt[ i ] )
      return false;
  for( int i = 2 ; i <= n ; i ++ )
    if( v[ i ] < v[ i - 1 ] )
      return false;
  return true;
}
int main(){
  cin >> n >> m >> c;
  c >>= 1;
  while( m -- ){
    int tv; cin >> tv;
    if( tv <= c ){
      for( int i = 1 ; i <= n ; i ++ )
        if( i == n or not gt[ i ] or tv < v[ i ] ){
          cout << i << endl;
          v[ i ] = tv;
          gt[ i ] = true;
          break;
        }
      if( win() ) exit(0);
    }else{
      for( int i = n ; i >= 1 ; i -- )
        if( i == 1 or not gt[ i ] or tv > v[ i ] ){
          cout << i << endl;
          v[ i ] = tv;
          gt[ i ] = true;
          break;
        }
      if( win() ) exit(0);
    }
  }
  assert( false );
}