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
#define N 101010
void build(){

}
int n , m , r[ N ];
vector<int> sw[ N ] , dr[ N ];
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= n ; i ++ )
    r[ i ] = getint();
  for( int i = 0 ; i < m ; i ++ ){
    int _ = getint(); while( _ -- ){
      int x = getint();
      dr[ i ].push_back( x );
      sw[ x ].push_back( i );
    }
  }
}
int tag[ N ] , stmp , st[ N ];
bool ok[ N ] , gg;
inline bool open( int id ){
  return ( r[ id ] + st[ sw[ id ][ 0 ] ] + st[ sw[ id ][ 1 ] ] ) % 2;
}
void go( int now ){
  for( int i = 0 ; i < 2 ; i ++ )
    for( int j = 0 ; j < 2 ; j ++ )
      if( ( r[ now ] + i + j ) % 2 ){
        ++ stmp; gg = false;
        st[ sw[ now ][ 0 ] ] = i;
        st[ sw[ now ][ 1 ] ] = j;
        tag[ sw[ now ][ 0 ] ] = stmp;
        tag[ sw[ now ][ 1 ] ] = stmp;
        queue<int> Q;
        Q.push( sw[ now ][ 0 ] );
        Q.push( sw[ now ][ 1 ] );
        while( Q.size() && !gg ){
          int tn = Q.front(); Q.pop();
          for( int id : dr[ tn ] ){
            if( tag[ sw[ id ][ 0 ] ] == stmp and
                tag[ sw[ id ][ 1 ] ] == stmp ){
              if( !open( id ) ){
                gg = true;
                break;
              }
            }else{
              for( int k = 0 ; k < 2 ; k ++ )
                if( tag[ sw[ id ][ k ] ] != stmp ){
                  tag[ sw[ id ][ k ] ] = stmp;
                  st[ sw[ id ][ k ] ] = ( 1 + r[ id ] + st[ tn ] ) % 2;
                  Q.push( sw[ id ][ k ] );
                  break;
                }
            }
          }
        }
        if( gg ) continue;
        ++ stmp;
        ok[ now ] = true;
        tag[ sw[ now ][ 0 ] ] = stmp;
        tag[ sw[ now ][ 1 ] ] = stmp;
        while( Q.size() ) Q.pop();
        Q.push( sw[ now ][ 0 ] );
        Q.push( sw[ now ][ 1 ] );
        while( Q.size() ){
          int tn = Q.front(); Q.pop();
          for( int id : dr[ tn ] ){
            ok[ id ] = true;
            for( int k = 0 ; k < 2 ; k ++ )
              if( tag[ sw[ id ][ k ] ] != stmp ){
                tag[ sw[ id ][ k ] ] = stmp;
                Q.push( sw[ id ][ k ] );
              }
          }
        }
        return;
      }
  puts( "NO" );
  Bye;
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    if( !ok[ i ] )
      go( i );
  puts( "YES" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}