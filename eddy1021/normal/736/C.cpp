// eddy1021
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
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
inline void bye(){ exit(0); }
int __ = 1 , _cs;
/*********default*********/
#define N 111
void build(){

}
int n , k;
vector< int > v[ N ];
void init(){
  n = getint();
  k = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int ui = getint();
    int vi = getint();
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
}
int dp[ N ][ 23 ][ 23 ];
int tdp[ N ][ 23 ][ 23 ];
void DP( int now , int prt ){
  if( prt != -1 && (int)v[ now ].size() == 1 ){
    dp[ now ][ 0 ][ 0 ] = 1; // black
    dp[ now ][ k + 1 ][ 1 ] = 1; // white
    return;
  }
  bool first = true;
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    DP( son , now );
    if( first ){
      for( int i = 0 ; i <= k + 1 ; i ++ )
        for( int j = 0 ; j <= k + 2 ; j ++ ){
          int nxti = min( i + 1 , k + 1 );
          int nxtj = min( j == 0 ? 0 : j + 1 , k + 2 );
          dp[ now ][ nxti ][ nxtj ] = add( dp[ now ][ nxti ][ nxtj ],
                                           dp[ son ][ i ][ j ] );
        }
      first = false;
      continue;
    }
    for( int i = 0 ; i <= k + 1 ; i ++ )
      for( int j = 0 ; j <= k + 2 ; j ++ )
        tdp[ now ][ i ][ j ] = 0;
    for( int i1 = 0 ; i1 <= k + 1 ; i1 ++ )
      for( int j1 = 0 ; j1 <= k + 2 ; j1 ++ ){
        if( dp[ now ][ i1 ][ j1 ] == 0 ) continue;
        for( int i2 = 0 ; i2 <= k + 1 ; i2 ++ )
          for( int j2 = 0 ; j2 <= k + 2 ; j2 ++ ){
            if( dp[ son ][ i2 ][ j2 ] == 0 ) continue;
            int nxti = min( min( i1 , i2 + 1 ) , k + 1 );
            int nxtj1 = j1;
            int nxtj2 = ( j2 == 0 ? 0 : j2 + 1 );
            if( i1 + nxtj2 - 1 <= k ) nxtj2 = 0;
            if( i2 + 1 + nxtj1 - 1 <= k ) nxtj1 = 0;
            int nxtj = min( k + 2 , max( nxtj1 , nxtj2 ) );
            tdp[ now ][ nxti ][ nxtj ] =
              add( tdp[ now ][ nxti ][ nxtj ] ,
                   mul( dp[ now ][ i1 ][ j1 ] , dp[ son ][ i2 ][ j2 ] ) );
          }
      }
    for( int i = 0 ; i <= k + 1 ; i ++ )
      for( int j = 0 ; j <= k + 2 ; j ++ )
        dp[ now ][ i ][ j ] = tdp[ now ][ i ][ j ];
  }
  for( int i = 0 ; i <= k + 1 ; i ++ )
    for( int j = 0 ; j <= k + 2 ; j ++ )
      tdp[ now ][ i ][ j ] = 0;
  for( int i = 0 ; i <= k + 1 ; i ++ )
    for( int j = 0 ; j <= k + 2 ; j ++ ){
      if( dp[ now ][ i ][ j ] == 0 ) continue;
      { // black
        int nxti = 0 , nxtj = j;
        if( j <= k + 1 ) nxtj = 0;
        //printf( "black %d %d -> %d %d\n" , i , j , nxti , nxtj );
        tdp[ now ][ nxti ][ nxtj ] = add( tdp[ now ][ nxti ][ nxtj ] ,
                                          dp[ now ][ i ][ j ] );
      }
      { // white
        int nxti = i , nxtj = j;
        if( nxti > k ) nxtj = max( nxtj , 1 );
        //printf( "white %d %d -> %d %d\n" , i , j , nxti , nxtj );
        tdp[ now ][ nxti ][ nxtj ] = add( tdp[ now ][ nxti ][ nxtj ] ,
                                          dp[ now ][ i ][ j ] );
      }
    }
  for( int i = 0 ; i <= k + 1 ; i ++ )
    for( int j = 0 ; j <= k + 2 ; j ++ ){
      dp[ now ][ i ][ j ] = tdp[ now ][ i ][ j ];
      //if( dp[ now ][ i ][ j ] )
        //printf( "%d %d %d : %d\n" , now , i , j , dp[ now ][ i ][ j ] );
    }
}
void solve(){
  if( n == 1 || k == 0 ){
    puts( "1" );
    bye();
  }
  DP( 1 , -1 );
  int ans = 0;
  for( int i = 0 ; i <= k + 1 ; i ++ )
    for( int j = 1 ; j <= k + 2 ; j ++ )
      ans = add( ans , dp[ 1 ][ i ][ j ] );
  int oans = 1;
  for( int i = 0 ; i < n ; i ++ )
    oans = mul( oans , 2 );
  printf( "%d\n" , (int)sub( oans , ans ) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}