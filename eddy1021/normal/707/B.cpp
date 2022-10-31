#include <bits/stdc++.h>
using namespace std;
#define N 101010
int n , m , k , u[ N ] , v[ N ] , l[ N ];
bool s[ N ];
void init(){
  scanf( "%d%d%d" , &n , &m , &k );
  for( int i = 0 ; i < m ; i ++ )
    scanf( "%d%d%d" , &u[ i ] , &v[ i ] , &l[ i ] );
  while( k -- ){
    int x; scanf( "%d" , &x );
    s[ x ] = true;
  }
}
void solve(){
  int ans = -1;
  for( int i = 0 ; i < m ; i ++ )
    if( s[ u[ i ] ] ^ s[ v[ i ] ] ){
      if( ans == -1 || l[ i ] < ans )
        ans = l[ i ];
    }
  printf( "%d\n" , ans );
}
int main(){
  init();
  solve();
}