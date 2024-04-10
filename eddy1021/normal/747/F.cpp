// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
LL C[ 200 ][ 200 ];
LL k , t;
const LL mx = 2000000020LL;
void build(){
  for( int i = 0 ; i < 200 ; i ++ )
    C[ i ][ 0 ] = C[ i ][ i ] = 1;
  for( int i = 2 ; i < 200 ; i ++ )
    for( int j = 1 ; j < i ; j ++ ){
      C[ i ][ j ] = C[ i - 1 ][ j - 1 ] + C[ i - 1 ][ j ];
      if( C[ i ][ j ] > mx ) C[ i ][ j ] = mx;
    }
}
void init(){
  k = getint();
  t = getint();
}
LL dp[ 17 ][ 200 ];
int ans[ 200 ] , atmst[ 17 ];
int go_dp( int len , bool okay = false ){
  if( len == 0 ) return 1;
  for( int i = 0 ; i <= 16 ; i ++ )
    for( int j = 0 ; j <= len ; j ++ )
      dp[ i ][ j ] = 0;
  dp[ 0 ][ 0 ] = 1;
  for( int i = 0 ; i < 16 ; i ++ )
    for( int j = 0 ; j <= len ; j ++ ){
      if( dp[ i ][ j ] == 0 ) continue;
      for( int u = 0 ; u <= atmst[ i ] ; u ++ ){
        if( j + u > len ) break;
        LL coe = C[ len - j ][ u ];
        if( !okay && i == 0 )
          coe = C[ len - 1 ][ u ];
        LL mr = dp[ i ][ j ] * coe;
        if( mr > mx ) mr = mx;
        dp[ i + 1 ][ j + u ] += mr;
        if( dp[ i + 1 ][ j + u ] > mx )
          dp[ i + 1 ][ j + u ] = mx;
      }
    }
  return dp[ 16 ][ len ];
}
void go( int len ){
  for( int i = len - 1 ; i >= 0 ; i -- )
    for( int j = 0 ; j < 16 ; j ++ ){
      if( i == len - 1 && j == 0 ) continue;
      if( atmst[ j ] == 0 ) continue;
      //for( int u = 0 ; u < 16 ; u ++ )
        //printf( "%d " , atmst[ u ] );
      //puts( "" );
      atmst[ j ] --;
      LL ret = go_dp( i , true );
      //printf( "len = %d, i = %d, j = %d, k = %lld, ret = %lld\n" , 
              //len , i , j , k , ret );
      if( ret < k ){
        atmst[ j ] ++;
        k -= ret;
        continue;
      }
      ans[ i ] = j;
      break;
    }
  for( int i = len - 1 ; i >= 0 ; i -- )
    putchar( ans[ i ] < 10 ? ans[ i ] + '0' : ans[ i ] - 10 + 'a' );
  puts( "" );
  Bye;
}
void solve(){
  for( int i = 0 ; i < 16 ; i ++ )
    atmst[ i ] = t;
  for( LL len = 1 ; ; len ++ ){
    LL ret = go_dp( len );
    if( ret < k ){
      k -= ret;
      continue;
    }
    go( len );
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