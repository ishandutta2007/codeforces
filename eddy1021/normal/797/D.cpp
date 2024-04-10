#include <bits/stdc++.h>
using namespace std;
#define N 101010
int n , v[ N ] , l[ N ] , r[ N ] , ind[ N ];
set<int> found;
void go( int now , int vl , int vr ){
  if( now == -1 or vl > vr ) return;
  if( vl <= v[ now ] and v[ now ] <= vr )
    found.insert( v[ now ] );
  go( l[ now ] , vl , min( vr , v[ now ] - 1 ) );
  go( r[ now ] , max( vl , v[ now ] + 1 ) , vr );
}
int main(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ ){
    scanf( "%d%d%d" , &v[ i ] , &l[ i ] , &r[ i ] );
    if( l[ i ] != -1 ) ind[ l[ i ] ] ++;
    if( r[ i ] != -1 ) ind[ r[ i ] ] ++;
  }
  int root = 1;
  for( int i = 1 ; i <= n ; i ++ )
    if( ind[ i ] == 0 ){
      root = i;
      break;
    }
  go( root , 0 , 1000000000 );
  int ans = n;
  for( int i = 1 ; i <= n ; i ++ )
    if( found.count( v[ i ] ) )
      ans --;
  printf( "%d\n" , ans );
}