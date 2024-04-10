#include <bits/stdc++.h>
using namespace std;
#define N 1021
int n , a[ 2 ][ N ];
char c[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 0 ; i < 2 ; i ++ ){
    scanf( "%s" , c );
    for( int j = 0 ; j < n ; j ++ )
      a[ i ][ j ] = c[ j ] - '0';
    sort( a[ i ] , a[ i ] + n );
  }
}
inline int mn(){
  multiset<int> S;
  for( int i = 0 ; i < n ; i ++ )
    S.insert( a[ 1 ][ i ] );
  int ans = 0;
  for( int i = 0 ; i < n ; i ++ ){
    auto it = S.lower_bound( a[ 0 ][ i ] );
    if( it == S.end() ) break;
    S.erase( it );
    ans ++;
  }
  return n - ans;
}
inline int mx(){
  int bl = 0 , br = n , ba = 0;
  while( bl <= br ){
    int mid = ( bl + br ) >> 1;
    bool ok = true;
    for( int i = 0 , j = n - mid ; i < mid ; i ++ , j ++ )
      if( a[ 0 ][ i ] >= a[ 1 ][ j ] ){
        ok = false;
        break;
      }
    if( ok ) ba = mid , bl = mid + 1;
    else br = mid - 1;
  }
  return ba;
}
int main(){
  init();
  printf( "%d\n%d\n" , mn() , mx() );
}