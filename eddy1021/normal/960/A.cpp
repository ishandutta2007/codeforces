#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 101010
char c[ N ];
int cnt[ 3 ];
void no(){
  puts( "NO" );
  exit(0);
}
int main(){
  scanf( "%s" , c );
  int len = strlen( c );
  for( int i = 0 ; i < len ; i ++ ){
    if( c[ i ] < 'a' or c[ i ] > 'c' )
      no();
    if( i and c[ i ] < c[ i - 1 ] )
      no();
    cnt[ c[ i ] - 'a' ] ++;
  }
  if( cnt[ 0 ] == 0 or cnt[ 1 ] == 0 )
    no();
  if( cnt[ 2 ] != cnt[ 0 ] and cnt[ 2 ] != cnt[ 1 ] )
    no();
  puts( "YES" );
}