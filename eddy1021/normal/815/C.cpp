// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
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
#define N 5140
void build(){

}
LL n , b , c[ N ] , d[ N ];
vector<int> son[ N ];
void init(){
  n = getint();
  b = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    c[ i ] = getint();
    d[ i ] = c[ i ] - getint();
    if( i > 1 ){
      int pi = getint();
      son[ pi ].push_back( i );
    }
  }
}
int ans;
LL dp[ N ][ N ][ 2 ];
int sz[ N ];
LL tmp[ N ][ 2 ];
void go( int now ){
  sz[ now ] = 1;
  for( int s : son[ now ] ){
    go( s );
    sz[ now ] += sz[ s ];
  }
  for( int i = 0 ; i <= sz[ now ] ; i ++ )
    dp[ now ][ i ][ 0 ] = 
    dp[ now ][ i ][ 1 ] = INF16;
  dp[ now ][ 0 ][ 0 ] = 0;
  dp[ now ][ 1 ][ 0 ] = c[ now ];
  dp[ now ][ 1 ][ 1 ] = d[ now ];
  int atmst = 1;
  for( int s : son[ now ] ){
    for( int i = 0 ; i <= atmst ; i ++ ){
      tmp[ i ][ 0 ] = dp[ now ][ i ][ 0 ];
      tmp[ i ][ 1 ] = dp[ now ][ i ][ 1 ];
    }
    for( int i = 0 ; i <= sz[ s ] ; i ++ )
      dp[ now ][ i ][ 0 ] = min( dp[ now ][ i ][ 0 ] ,
                                 dp[ s ][ i ][ 0 ] );
    for( int i = 0 ; i <= atmst ; i ++ )
      for( int j = 0 ; j <= sz[ s ] ; j ++ ){
        { // to 0
          dp[ now ][ i + j ][ 0 ] = min( dp[ now ][ i + j ][ 0 ] ,
                                         tmp[ i ][ 0 ] + dp[ s ][ j ][ 0 ] );
        }
        { // to 1
          dp[ now ][ i + j ][ 1 ] = min( dp[ now ][ i + j ][ 1 ] ,
                                         tmp[ i ][ 1 ] + min( dp[ s ][ j ][ 0 ],
                                                              dp[ s ][ j ][ 1 ] ) );
        }
      }
    atmst += sz[ s ];
  }
}
void solve(){
  go( 1 );
  for( int i = 1 ; i <= sz[ 1 ] ; i ++ )
    if( dp[ 1 ][ i ][ 0 ] <= b or
        dp[ 1 ][ i ][ 1 ] <= b )
      ans = i;
  printf( "%d\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}