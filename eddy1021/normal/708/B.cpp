// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
void build(){

}
LL a00 , a01 , a10 , a11;
void init(){
  a00 = getint();
  a01 = getint();
  a10 = getint();
  a11 = getint();
}
inline LL go( LL x ){
  LL l = 1 , r = 1000000;
  while( l <= r ){
    LL mid = ( l + r ) / 2;
    LL vl = ( mid * ( mid - 1 ) ) / 2;
    if( vl == x ) return mid;
    if( vl < x ) l = mid + 1;
    else r = mid - 1;
  }
  puts( "Impossible" );
  exit( 0 );
}
#define N 1010101
int v[ N ];
void solve(){
  LL all = a00 + a01 + a10 + a11;
  LL n = go( all );
  if( a00 == 0 ){
    if( a01 == 0 && a10 == 0 ){
      for( int i = 0 ; i < n ; i ++ )
        putchar( '1' );
    }else{
      go( a11 );
      for( int i = 0 ; i < a10 ; i ++ )
        putchar( '1' );
      putchar( '0' );
      for( int i = 0 ; i < a01 ; i ++ )
        putchar( '1' );
    }
    exit( 0 );
  }
  if( a11 == 0 ){
    if( a01 == 0 && a10 == 0 ){
      for( int i = 0 ; i < n ; i ++ )
        putchar( '0' );
    }else{
      go( a00 );
      for( int i = 0 ; i < a01 ; i ++ )
        putchar( '0' );
      putchar( '1' );
      for( int i = 0 ; i < a10 ; i ++ )
        putchar( '0' );
    }
    exit( 0 );
  }
  LL n0 = go( a00 );
  LL n1 = go( a11 );
  if( n0 + n1 != n ){
    puts( "Impossible" );
    exit( 0 );
  }
  for( LL i = 0 ; i < n1 ; i ++ ){
    LL tk = min( n0 , a01 );
    a01 -= tk;
    v[ tk ] ++;
  }
  for( int i = 0 ; i <= n0 ; i ++ ){
    if( i ) putchar( '0' );
    while( v[ i ] -- ) putchar( '1' );
  }
  puts( "" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}