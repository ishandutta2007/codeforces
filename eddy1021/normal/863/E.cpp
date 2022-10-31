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
#define N 808080
int n , l[ N ] , r[ N ] , s[ N ];
int gg[ N ];
int main(){
  scanf( "%d" , &n );
  vector< int > vv;
  for( int i = 1 ; i <= n ; i ++ ){
    scanf( "%d%d" , &l[ i ] , &r[ i ] );
    vv.push_back( l[ i ] );
    vv.push_back( r[ i ] );
    vv.push_back( r[ i ] + 1 );
    vv.push_back( l[ i ] - 1 );
  }
  sort( vv.begin() , vv.end() );
  vv.resize( unique( vv.begin() , vv.end() ) - vv.begin() );
  for( int i = 1 ; i <= n ; i ++ ){
    l[ i ] = lower_bound( vv.begin() , vv.end() , l[ i ] ) - vv.begin() + 1;
    r[ i ] = lower_bound( vv.begin() , vv.end() , r[ i ] ) - vv.begin() + 1;
    s[ l[ i ] ] ++;
    s[ r[ i ] + 1 ] --;
  }
  int tot = (int)vv.size();
  for( int i = 1 ; i <= tot ; i ++ ){
    s[ i ] += s[ i - 1 ];
    gg[ i ] += gg[ i - 1 ];
    if( s[ i ] == 1 )
      gg[ i ] ++;
  }
  for( int i = 1 ; i <= n ; i ++ )
    if( gg[ r[ i ] ] - gg[ l[ i ] - 1 ] == 0 ){
      printf( "%d\n" , i );
      exit(0);
    }
  puts( "-1" );
}