#include <bits/stdc++.h>
using namespace std;
#define x1 aaax1
#define y1 aaay1
#define x2 aaax2
#define y2 aaay2
#define N 111
int getint(){
  int ret; scanf( "%d" , &ret );
  return ret;
}
int n , q , c;
int cc[ 11 ][ N ][ N ];
int main(){
  n = getint();
  q = getint();
  c = getint() + 1;
  while( n -- ){
    int xi = getint();
    int yi = getint();
    int si = getint();
    cc[ si ][ xi ][ yi ] ++;
  }
  for( int i = 0 ; i < c ; i ++ )
    for( int x = 0 ; x < N ; x ++ )
      for( int y = 0 ; y < N ; y ++ ){
        if( x ) cc[ i ][ x ][ y ] += cc[ i ][ x - 1 ][ y ];
        if( y ) cc[ i ][ x ][ y ] += cc[ i ][ x ][ y - 1 ];
        if( x and y )
          cc[ i ][ x ][ y ] -= cc[ i ][ x - 1 ][ y - 1 ];
      }
  while( q -- ){
    int ti = getint();
    int x1 = getint();
    int y1 = getint();
    int x2 = getint();
    int y2 = getint();
    int ans = 0;
    for( int i = 0 ; i < c ; i ++ ){
      int nc = ( i + ti ) % c;
      int cnt = cc[ i ][ x2 ][ y2 ] - cc[ i ][ x1 - 1 ][ y2 ]
                                    - cc[ i ][ x2 ][ y1 - 1 ]
                                    + cc[ i ][ x1 - 1 ][ y1 - 1 ];
      ans += nc * cnt;
    }
    printf( "%d\n" , ans );
  }
}