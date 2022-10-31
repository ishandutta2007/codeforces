#include <bits/stdc++.h>
using namespace std;
#define N 1021
int n , m , a[ N ][ N ];
int main(){
  scanf( "%d%d" , &n , &m );
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < m ; j ++ )
      scanf( "%d" , &a[ i ][ j ] );
  int ans = 0;
  for( int i = 0 ; i < n ; i ++ ){
    int ya = 0;
    for( int j = 0 ; j < m ; j ++ )
      if( a[ i ][ j ] ) ya = 1;
      else ans += ya;
    ya = 0;
    for( int j = m - 1 ; j >= 0 ; j -- )
      if( a[ i ][ j ] ) ya = 1;
      else ans += ya;
  }
  for( int j = 0 ; j < m ; j ++ ){
    int ya = 0;
    for( int i = 0 ; i < n ; i ++ )
      if( a[ i ][ j ] ) ya = 1;
      else ans += ya;
    ya = 0;
    for( int i = n - 1 ; i >= 0 ; i -- )
      if( a[ i ][ j ] ) ya = 1;
      else ans += ya;
  }
  printf( "%d\n" , ans );
}