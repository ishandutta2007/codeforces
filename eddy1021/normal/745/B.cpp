#include <bits/stdc++.h>
using namespace std;
int n , m;
char c[ 514 ];
int main(){
  scanf( "%d%d" , &n , &m );
  int mxn = 1 , mnn = n , mxm = 1 , mnm = m , cnt = 0;
  for( int i = 1 ; i <= n ; i ++ ){
    scanf( "%s" , c + 1 );
    for( int j = 1 ; j <= m ; j ++ )
      if( c[ j ] == 'X' ){
        cnt ++;
        mxn = max( mxn , i );
        mnn = min( mnn , i );
        mxm = max( mxm , j );
        mnm = min( mnm , j );
      }
  }
  if( ( mxn - mnn + 1 ) * ( mxm - mnm + 1 ) == cnt )
    puts( "YES" );
  else
    puts( "NO" );
}