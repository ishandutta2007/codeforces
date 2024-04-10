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
#define N 101010
#define K 20
void build(){

}
int n , p[ N ] , t[ N ];
int spec[ K ][ N ] , deps[ N ];
int part[ K ][ N ] , depp[ N ];
bool is_p_spec( int prt , int son ){
  if( deps[ prt ] >= deps[ son ] ) return false;
  int dlt = deps[ son ] - deps[ prt ];
  while( dlt ){
    int bt = __lg( dlt );
    son = spec[ bt ][ son ];
    dlt ^= (1 << bt);
  }
  return son == prt;
}
bool is_p_part( int prt , int son ){
  if( depp[ prt ] >= depp[ son ] ) return false;
  int dlt = depp[ son ] - depp[ prt ];
  while( dlt ){
    int bt = __lg( dlt );
    son = part[ bt ][ son ];
    dlt ^= (1 << bt);
  }
  return son == prt;
}
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    p[ i ] = getint();
    t[ i ] = getint();
    spec[ 0 ][ i ] = i;
    part[ 0 ][ i ] = i;
    deps[ i ] = depp[ i ] = 0;
    if( t[ i ] == 0 ){
      spec[ 0 ][ i ] = p[ i ];
      deps[ i ] = deps[ p[ i ] ] + 1;
    }else if( t[ i ] == 1 ){
      part[ 0 ][ i ] = p[ i ];
      depp[ i ] = depp[ p[ i ] ] + 1;
    }
  }
  for( int i = 1 ; i < K ; i ++ )
    for( int j = 1 ; j <= n ; j ++ ){
      spec[ i ][ j ] = spec[ i - 1 ][ spec[ i - 1 ][ j ] ];
      part[ i ][ j ] = part[ i - 1 ][ part[ i - 1 ][ j ] ];
    }
}
void solve(){
  int q = getint(); while( q -- ){
    int cmd = getint();
    int ui = getint();
    int vi = getint();
    if( ui == vi ){
      puts( "NO" );
      continue;
    }
    if( cmd == 1 )
      puts( is_p_spec( ui , vi ) ? "YES" : "NO" );
    else{
      bool ok = false;
      {
        int prtv = part[ K - 1 ][ vi ];
        if( is_p_spec( prtv , ui ) or prtv == ui )
          ok = true;
      }
      {
        int prtu = spec[ K - 1 ][ ui ];
        if( is_p_part( prtu , vi ) )
          ok = true;
      }
      if( part[ 0 ][ vi ] == vi )
        ok = false;
      puts( ok ? "YES" : "NO" );
    }
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