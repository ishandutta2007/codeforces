#include <bits/stdc++.h>
using namespace std;
#define N 1021
int n , k , dp[ N ] , mn , mx;
bool done[ N ];
int main(){
  mn = N , mx = -1;
  for( int i = 0 ; i < N ; i ++ )
    dp[ i ] = N;
  scanf( "%d%d" , &n , &k );
  while( k -- ){
    int ai; scanf( "%d" , &ai );
    dp[ ai ] = 1;
    mn = min( mn , ai );
    mx = max( mx , ai );
  }
  if( n < mn or n > mx ){
    puts( "-1" );
    exit(0);
  }
  for( int i = 0 ; i < N ; i ++ ){
    int bst = -1;
    for( int j = 0 ; j < N ; j ++ )
      if( not done[ j ] ){
        if( bst == -1 or dp[ j ] < dp[ bst ] )
          bst = j;
      }
    if( bst == -1 ) break;
    done[ bst ] = true;
    for( int j = 0 ; j < N ; j ++ ){
      int nxt = bst + j - n;
      if( nxt < 0 or nxt >= N ) continue;
      dp[ nxt ] = min( dp[ nxt ] ,
                       dp[ bst ] + dp[ j ] );
    }
  }
  printf( "%d\n" , dp[ n ] );
}