#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 105
const int mod = 1000000007;
int add( int x , int y ){
  x += y;
  return x >= mod ? x - mod : x;
}
int mul( LL x , int y ){
  x *= y;
  return x >= mod ? x % mod : x;
}
struct Mat{
  int n , a[ N ][ N ];
  Mat( int _n = 0 ){
    n = _n;
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < n ; j ++ )
        a[ i ][ j ] = 0;
  }
  Mat operator*( const Mat& he ) const{
    Mat ret( n );
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < n ; j ++ )
        for( int k = 0 ; k < n ; k ++ )
          ret.a[ i ][ j ] = add( ret.a[ i ][ j ] ,
                                 mul( a[ i ][ k ] , he.a[ k ][ j ] ) );
    return ret;
  }
  void print(){
    for( int i = 0 ; i < n ; i ++ , puts( "" ) )
      for( int j = 0 ; j < n ; j ++ )
        printf( "%d " , a[ i ][ j ] );
  }
};
int f[ N ] , n , x;
char s[ N ];
bool gt[ N ];
Mat dp[ N ];
int main(){
  cin >> n >> x;
  cin >> s;
  f[ 0 ] = -1;
  for( int i = 1 , fl = -1 ; i < n ; i ++ ){
    while( fl >= 0 and s[ fl + 1 ] != s[ i ] ) fl = f[ fl ];
    if( s[ fl + 1 ] == s[ i ] ) fl ++;
    f[ i ] = fl;
  }
  for( int i = 0 ; i <= x ; i ++ )
    dp[ i ] = Mat( n + 1 );
  for( int b = 0 ; b < 2 ; b ++ ){
    for( int i = 0 ; i <= n ; i ++ ){
      dp[ b ].a[ i ][ i ] = 1;
      if( i == n ){
        dp[ b ].a[ i ][ i ] ++;
        continue;
      }
      int fl = i - 1;
      while( fl >= 0 and s[ fl + 1 ] - '0' != b ) fl = f[ fl ];
      if( s[ fl + 1 ] - '0' == b ) fl ++;
      dp[ b ].a[ i ][ fl + 1 ] ++;
      if( fl + 1 == n )
        dp[ b ].a[ i ][ f[ fl ] + 1 ] ++;
    }
    //dp[ b ].print();
  }
  for( int i = 2 ; i <= x ; i ++ )
    dp[ i ] = dp[ i - 1 ] * dp[ i - 2 ];
  printf( "%d\n" , dp[ x ].a[ 0 ][ n ] );
}