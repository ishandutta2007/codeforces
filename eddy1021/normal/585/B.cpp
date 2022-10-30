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
int n , k;
char c[ 3 ][ N ];
bool m[ 3 ][ N ];
void build(){

}
bool good( int tr , int tc ){
  if( tc < 0 || tc >= n ) return true;
  return c[ tr ][ tc ] == '.' ||
         c[ tr ][ tc ] == 's';
}
bool safe( int tr , int tc ){
  return good( tr , tc * 3 ) &&
         good( tr , tc * 3 - 2 );
}
bool in( int tr , int tc ){
  return 0 <= tr && tr < 3 &&
         0 <= tc && tc < n;
}
void init(){
  n = getint();
  k = getint();
  for( int i = 0 ; i < 3 ; i ++ )
    scanf( "%s" , c[ i ] );
  for( int i = 0 ; i < 3 ; i ++ )
    for( int j = 0 ; j < n ; j ++ )
      m[ i ][ j ] = false;
}
void solve(){
  queue<PII> Q;
  for( int i = 0 ; i < 3 ; i ++ )
    if( c[ i ][ 0 ] == 's' ){
      Q.push( MP( i , 0 ) );
      m[ i ][ 0 ] = true;
    }
  while( Q.size() ){
    int tr = Q.front().FI;
    int tc = Q.front().SE; Q.pop();
    // printf( "%d %d\n" , tr , tc );
    if( tc == n - 1 ) break;
    if( in( tr - 1 , tc + 1 ) ){
      if( good( tr - 1 , ( tc + 1 ) * 3 ) &&
          good( tr - 1 , ( tc + 1 ) * 3 - 2 ) &&
          good( tr , ( tc + 1 ) * 3 - 2 ) &&
          !m[ tr - 1 ][ tc + 1 ] ){
        Q.push( MP( tr - 1 , tc + 1 ) );
        m[ tr - 1 ][ tc + 1 ] = true;
      }
    }
    if( in( tr , tc + 1 ) ){
      if( good( tr , ( tc + 1 ) * 3 ) &&
          good( tr , ( tc + 1 ) * 3 - 2 ) &&
          !m[ tr ][ tc + 1 ] ){
        Q.push( MP( tr , tc + 1 ) );
        m[ tr ][ tc + 1 ] = true;
      }
    }
    if( in( tr + 1 , tc + 1 ) ){
      if( good( tr + 1 , ( tc + 1 ) * 3 ) &&
          good( tr + 1 , ( tc + 1 ) * 3 - 2 ) &&
          good( tr , ( tc + 1 ) * 3 - 2 ) &&
          !m[ tr + 1 ][ tc + 1 ] ){
        Q.push( MP( tr + 1 , tc + 1 ) );
        m[ tr + 1 ][ tc + 1 ] = true;
      }
    }
  }
  for( int i = 0 ; i < 3 ; i ++ )
    if( m[ i ][ n - 1 ] ){
      puts( "YES" );
      return;
    }
  puts( "NO" );
}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}