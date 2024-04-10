// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
}
bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 1010
int n , m;
char c[ N ][ N ];
void build(){

}
bool in( int xn , int xm ){
  return 1 <= xn && xn <= n &&
         1 <= xm && xm <= m;
}
int dn[]={0,0,1,-1};
int dm[]={1,-1,0,0};
bool got[ 3 ][ N ][ N ];
int dist[ 3 ][ N ][ N ];
int dst[ 3 ][ 3 ];
queue< pair<int,PII> > Q;
void init(){
  n = getint();
  m = getint();
  for( int u = 0 ; u < 3 ; u ++ )
    for( int i = 1 ; i <= n ; i ++ )
      for( int j = 1 ; j <= m ; j ++ )
        got[ u ][ i ][ j ] = false;
  for( int i = 0 ; i < 3 ; i ++ )
    for( int j = 0 ; j < 3 ; j ++ )
      dst[ i ][ j ] = -1;
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%s" , c[ i ] + 1 );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      if( c[ i ][ j ] >= '1' &&
          c[ i ][ j ] <= '3' ){
        got[ c[ i ][ j ] - '1' ][ i ][ j ] = true;
        dist[ c[ i ][ j ] - '1' ][ i ][ j ] = 0;
        Q.push( MP( c[ i ][ j ] - '1' , MP( i , j ) ) );
      }
  while( Q.size() ){
    pair<int,PII> tp = Q.front(); Q.pop();
    for( int i = 0 ; i < 4 ; i ++ ){
      int num = tp.FI;
      int nxtn = tp.SE.FI + dn[ i ];
      int nxtm = tp.SE.SE + dm[ i ];
      if( in( nxtn , nxtm ) && c[ nxtn ][ nxtm ] != '#' ){
        if( !got[ num ][ nxtn ][ nxtm ] ){
          dist[ num ][ nxtn ][ nxtm ] = 
            dist[ num ][ tp.SE.FI ][ tp.SE.SE ] + 1;
          got[ num ][ nxtn ][ nxtm ] = true;
          Q.push( MP( num , MP( nxtn , nxtm ) ) );
        }
      }
    }
  }
}
void solve(){
  int ans = -1;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ ){
      if( got[ 0 ][ i ][ j ] &&
          got[ 1 ][ i ][ j ] &&
          got[ 2 ][ i ][ j ] ){
        int tans = dist[ 0 ][ i ][ j ] +
                  dist[ 1 ][ i ][ j ] +
                  dist[ 2 ][ i ][ j ] - 2;
        if( ans == -1 || tans < ans )
          ans = tans;   
      }
      for( int x = 0 ; x < 3 ; x ++ )
        for( int y = x + 1 ; y < 3 ; y ++ ){
          if( got[ x ][ i ][ j ] &&
              got[ y ][ i ][ j ] ){
            int tans = dist[ x ][ i ][ j ] +
                       dist[ y ][ i ][ j ] - 1;
            if( dst[ x ][ y ] == -1 || tans < dst[ x ][ y ] )
              dst[ y ][ x ] = dst[ x ][ y ] = tans;
          }
        }
    }
  if( ans == -1 ) puts( "-1" );
  else{
    ans = min( ans , dst[ 0 ][ 1 ] + dst[ 0 ][ 2 ] );
    ans = min( ans , dst[ 0 ][ 1 ] + dst[ 1 ][ 2 ] );
    ans = min( ans , dst[ 0 ][ 2 ] + dst[ 1 ][ 2 ] );
    printf( "%d\n" , ans );
  }
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}