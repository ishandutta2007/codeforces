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
#define N 25250
char c[ 4 ][ N ];
void build(){

}
int n , k;
bool aabb , abab , abba , aaaa;
void init(){
  aabb = abab = abba = aaaa = true;
  n = getint(); k = getint();
}
char v[]="aeiou";
inline bool vowel( char ctmp ){
  for( int i = 0 ; i < 5 ; i ++ )
    if( ctmp == v[ i ] )
      return true;
  return false;
}
void solve(){
  for( int i = 0 ; i < n ; i ++ ){
    for( int j = 0 ; j < 4 ; j ++ )
      scanf( "%s" , c[ j ] );
    string s[ 4 ] = { "" , "" , "" , "" };
    bool got[ 4 ] = {};
    for( int j = 0 ; j < 4 ; j ++ ){
      int len = strlen( c[ j ] ) , cnt = 0;
      for( int l = len - 1 ; l >= 0 ; l -- ){
        s[ j ] += c[ j ][ l ];
        if( vowel( c[ j ][ l ] ) ){
          cnt ++;
          if( cnt == k ){
            got[ j ] = true;
            break;
          }
        }
      }
    }
    for( int l = 0 ; l < 4 ; l ++ )
      if( !got[ l ] )
        aaaa = aabb = abab = abba = false;
    if( !( s[ 0 ] == s[ 1 ] && s[ 1 ] == s[ 2 ] && s[ 2 ] == s[ 3 ] ) )
      aaaa = false;
    if( !( s[ 0 ] == s[ 1 ] && s[ 2 ] == s[ 3 ] ) )
      aabb = false;
    if( !( s[ 0 ] == s[ 2 ] && s[ 1 ] == s[ 3 ] ) )
      abab = false;
    if( !( s[ 0 ] == s[ 3 ] && s[ 2 ] == s[ 1 ] ) )
      abba = false;
  }
  if( aaaa ) puts( "aaaa" );
  else if( aabb ) puts( "aabb" );
  else if( abab ) puts( "abab" );
  else if( abba ) puts( "abba" );
  else puts( "NO" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}