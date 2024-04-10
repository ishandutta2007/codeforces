#include <bits/stdc++.h>
using namespace std;
#define N 101010
map<string,int> M;
int n , k , m , a[ N ] , bst[ N ] , at[ N ];
char buf[ 64 ];
int main(){
  scanf( "%d%d%d" , &n , &k , &m );
  for( int i = 1 ; i <= n ; i ++ ){
    scanf( "%s" , buf );
    M[ string(buf) ] = i;
  }
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &a[ i ] );
  for( int i = 1 ; i <= k ; i ++ ){
    bst[ i ] = 1e9 + 10;
    int x; scanf( "%d" , &x ); while( x -- ){
      int y; scanf( "%d" , &y );
      bst[ i ] = min( bst[ i ] , a[ y ] );
      at[ y ] = i;
    }
  }
  long long ans = 0;
  while( m -- ){
    scanf( "%s" , buf );
    ans += bst[ at[ M[ string( buf ) ] ] ];
  }
  cout << ans << endl;
}