#include <bits/stdc++.h>
using namespace std;
#define N 1021
int n , a[ N ] , b[ N ] , p[ N ];
vector<int> dif;
bool g[ N ];
void output(){
  for( int i = 0 ; i < n ; i ++ )
    cout << p[ i ] << " \n"[ i + 1 == n ];
  exit(0);
}
int main(){
  cin >> n;
  for( int i = 0 ; i < n ; i ++ ) cin >> a[ i ];
  for( int i = 0 ; i < n ; i ++ ) cin >> b[ i ];
  for( int i = 0 ; i < n ; i ++ )
    if( a[ i ] == b[ i ] ){
      p[ i ] = a[ i ];
      g[ a[ i ] ] = true;
    }else
      dif.push_back( i );
  if( dif.size() == 1u ){
    for( int i = 1 ; i <= n ; i ++ )
      if( not g[ i ] )
        p[ dif[ 0 ] ] = i;
    output();
  }
  assert( dif.size() == 2u );
  for( int i = 0 ; i < 2 ; i ++ )
    for( int j = 0 ; j < 2 ; j ++ ){
      int ai = ( i == 0 ? a[ dif[ 0 ] ] : b[ dif[ 0 ] ] );
      int bi = ( j == 0 ? a[ dif[ 1 ] ] : b[ dif[ 1 ] ] );
      if( ai == bi ) continue;
      if( not g[ ai ] and not g[ bi ] ){
        p[ dif[ 0 ] ] = ai;
        p[ dif[ 1 ] ] = bi;
        output();
      }
    }
  assert( false );
}