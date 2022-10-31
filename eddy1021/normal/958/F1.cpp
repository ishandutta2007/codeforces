#include <bits/stdc++.h>
using namespace std;
#define N 111
int n , m , a[ N ] , k[ N ] , ck[ N ];
bool okay( int l , int r ){
  for( int i = 1 ; i <= m ; i ++ )
    ck[ i ] = 0;
  for( int i = l ; i < r ; i ++ )
    ck[ a[ i ] ] ++;
  for( int i = 1 ; i <= m ; i ++ )
    if( ck[ i ] != k[ i ] )
      return false;
  return true;
}
int main(){
  cin >> n >> m;
  for( int i = 1 ; i <= n ; i ++ )
    cin >> a[ i ];
  for( int i = 1 ; i <= m ; i ++ )
    cin >> k[ i ];
  int tot = accumulate( k + 1 , k + m + 1 , 0 );
  for( int i = 1 ; i + tot - 1 <= n ; i ++ )
    if( okay( i , i + tot ) ){
      puts( "YES" );
      return 0;
    }
  puts( "NO" );
}