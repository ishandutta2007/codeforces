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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
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
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 101010
char c[ N ];
int n , ans[ N ] , s[ N ] , tmp[ N ];
void build(){

}
void init(){
  scanf( "%s" , c + 1 );
  n = strlen( c + 1 );
}
void test(){
  for( int i = 1 ; i <= n ; i ++ )
    tmp[ i ] = s[ i ];
  for( int i = 1 ; i <= n / 2 ; ){
    int ii = n - i + 1;
    if( tmp[ i ] == tmp[ ii ] ) i ++;
    else if( tmp[ i ] == tmp[ ii ] + 1 ||
             tmp[ i ] == tmp[ ii ] + 11 ){
      tmp[ i ] --;
      tmp[ i + 1 ] += 10;
    }else if( tmp[ i ] == tmp[ ii ] + 10 ){
      tmp[ ii - 1 ] --;
      tmp[ ii ] += 10;
    }else return;
  }
  if( n & 1 ){
    int ii = n / 2 + 1;
    if( ( tmp[ ii ] % 2 ) ||
        tmp[ ii ] > 18 ||
        tmp[ ii ] < 0 )
      return;
    ans[ ii ] = tmp[ ii ] / 2;
  }
  for( int i = 1 ; i <= n / 2 ; i ++ ){
    if( tmp[ i ] > 18 ||
        tmp[ i ] < 0 ) return;
    ans[ i ] = tmp[ i ] / 2 + tmp[ i ] % 2;
    ans[ n - i + 1 ] = tmp[ i ] - ans[ i ];
  }
  if( ans[ 1 ] == 0 ) return;
  for( int i = 1 ; i <= n ; i ++ )
    putchar( ans[ i ] + '0' );
  puts( "" );
  exit( 0 );
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    s[ i ] = c[ i ] - '0';
  test();
  if( n > 1 && c[ 1 ] == '1' ){
    for( int i = 1 ; i < n ; i ++ )
      s[ i ] = c[ i + 1 ] - '0';
    s[ 1 ] += 10; n --;
    test();
  }
  puts( "0" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}