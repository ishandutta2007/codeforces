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
string s[ 3 ];
int len[ 3 ];
string pos[ 6 ];
int ii;
inline char tol( char ctmp ){
  return ctmp - 'A' + 'a';
}
inline void con( int i1 , int i2 , int i3 ){
  pos[ ii ] = "";
  for( int i = 0 ; i < len[ i1 ] ; i ++ ){
    if( s[ i1 ][ i ] >= 'A' && s[ i1 ][ i ] <= 'Z' )
      pos[ ii ] = pos[ ii ] + tol( s[ i1 ][ i ] );
    if( s[ i1 ][ i ] >= 'a' && s[ i1 ][ i ] <= 'z' )
      pos[ ii ] = pos[ ii ] + s[ i1 ][ i ] ;
  }
  for( int i = 0 ; i < len[ i2 ] ; i ++ ){
    if( s[ i2 ][ i ] >= 'A' && s[ i2 ][ i ] <= 'Z' )
      pos[ ii ] = pos[ ii ] + tol( s[ i2 ][ i ] );
    if( s[ i2 ][ i ] >= 'a' && s[ i2 ][ i ] <= 'z' )
      pos[ ii ] = pos[ ii ] + s[ i2 ][ i ] ;
  }
  for( int i = 0 ; i < len[ i3 ] ; i ++ ){
    if( s[ i3 ][ i ] >= 'A' && s[ i3 ][ i ] <= 'Z' )
      pos[ ii ] = pos[ ii ] + tol( s[ i3 ][ i ] );
    if( s[ i3 ][ i ] >= 'a' && s[ i3 ][ i ] <= 'z' )
      pos[ ii ] = pos[ ii ] + s[ i3 ][ i ] ;
  }
  ii ++;
}
void init(){
  cin >> s[ 0 ] >> s[ 1 ] >> s[ 2 ];
  len[ 0 ] = s[ 0 ].length();
  len[ 1 ] = s[ 1 ].length();
  len[ 2 ] = s[ 2 ].length();
  con( 0 , 1 , 2 );
  con( 0 , 2 , 1 );
  con( 1 , 0 , 2 );
  con( 1 , 2 , 0 );
  con( 2 , 0 , 1 );
  con( 2 , 1 , 0 );
}
string tmp;
inline bool okay(){
  int tlen = tmp.length();
  string nn = "";
  for( int i = 0 ; i < tlen ; i ++ ){
    if( tmp[ i ] >= 'A' && tmp[ i ] <= 'Z' )
      nn = nn + tol( tmp[ i ] );
    if( tmp[ i ] >= 'a' && tmp[ i ] <= 'z' )
      nn = nn + tmp[ i ];
  }
  tlen = nn.length();
  for( int i = 0 ; i < 6 ; i ++ ){
    if( tlen != (int)pos[ i ].length() ) continue;
    bool good = true;
    for( int j = 0 ; j < tlen && good ; j ++ )
      if( pos[ i ][ j ] != nn[ j ] )
        good = false;
    if( good ) return true;
  }
  return false;
}
void solve(){
  int q = getint(); while( q -- ){
    cin >> tmp;
    puts( okay() ? "ACC" : "WA" );
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