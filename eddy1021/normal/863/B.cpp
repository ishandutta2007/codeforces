/********************************************************/
/*             _      _          _   __      __      _  */
/*            ( )    ( )       /' )/' _`\  /'__`\  /' ) */
/*    __     _| |   _| | _   _(_, || ( ) |(_)  ) )(_, | */
/*  /'__`\ /'_` | /'_` |( ) ( ) | || | | |   /' /   | | */
/* (  ___/( (_| |( (_| || (_) | | || (_) | /' /( )  | | */
/* `\____)`\__,_)`\__,_)`\__, | (_)`\___/'(_____/'  (_) */
/*                      ( )_| |                         */
/*                      `\___/'                         */
/*                                                      */
/********************************************************/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define N 1021
int n , w[ N ];
int main(){
  cin >> n;
  n *= 2;
  for( int i = 0 ; i < n ; i ++ )
    cin >> w[ i ];
  int ans = N;
  for( int i = 0 ; i < n ; i ++ )
    for( int j = i + 1 ; j < n ; j ++ ){
      vector<int> v;
      for( int k = 0 ; k < n ; k ++ )
        if( i != k and j != k )
          v.push_back( w[ k ] );
      sort( v.begin() , v.end() );
      int tans = 0;
      for( size_t k = 1 ; k < v.size() ; k += 2 )
        tans += v[ k ] - v[ k - 1 ];
      ans = min( ans , tans );
    }
  cout << ans << endl;
}