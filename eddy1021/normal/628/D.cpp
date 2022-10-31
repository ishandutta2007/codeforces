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
#define N 2020
int m , d , len;
char c[ 2 ][ N ];
void build(){

}
void init(){
  m = getint();
  d = getint();
  scanf( "%s%s" , c[ 0 ] , c[ 1 ] );
  len = strlen( c[ 0 ] );
}
ll dp[ 2 ][ N ][ N ][ 2 ];
ll cal( int idx ){
  for( int i = 1 ; i <= c[ idx ][ 0 ] - '0' ; i ++ ){
    if( i == d ) continue;
    dp[ idx ][ 0 ][ i % m ][ i == c[ idx ][ 0 ] - '0' ] ++;
  }
  for( int i = 0 ; i < len - 1 ; i ++ )
    for( int j = 0 ; j < m ; j ++ )
      for( int k = 0 ; k < 2 ; k ++ ){
        if( dp[ idx ][ i ][ j ][ k ] == 0 ) continue;
        if( k ){ // bound
          for( int l = 0 ; l <= c[ idx ][ i + 1 ] - '0' ; l ++ ){
            if( ( i % 2 == 1 ) && l == d ) continue;
            if( ( i % 2 == 0 ) && l != d ) continue;
            dp[ idx ][ i + 1 ][ ( j * 10 + l ) % m ][ l == c[ idx ][ i + 1 ] - '0' ] =
              add( dp[ idx ][ i + 1 ][ ( j * 10 + l ) % m ][ l == c[ idx ][ i + 1 ] - '0' ] ,
                   dp[ idx ][ i ][ j ][ k ] );
          }
        }else{
          for( int l = 0 ; l < 10 ; l ++ ){
            if( ( i % 2 == 1 ) && l == d ) continue;
            if( ( i % 2 == 0 ) && l != d ) continue;
            dp[ idx ][ i + 1 ][ ( j * 10 + l ) % m ][ 0 ] =
              add( dp[ idx ][ i + 1 ][ ( j * 10 + l ) % m ][ 0 ] ,
                   dp[ idx ][ i ][ j ][ k ] );
          }
        }
      }
  ll ans = add( dp[ idx ][ len - 1 ][ 0 ][ 0 ] ,
                dp[ idx ][ len - 1 ][ 0 ][ 1 ] );
  return ans;
}
bool good( int idx ){
  ll md = 0;
  for( int i = 0 ; i < len ; i ++ ){
    if( i & 1 ){
      if( c[ idx ][ i ] - '0' != d ) return false;
    }else{
      if( c[ idx ][ i ] - '0' == d ) return false;
    }
    md = ( md * 10 + (ll)( c[ idx ][ i ] - '0' ) ) % m;
  }
  return md == 0;
}
void solve(){
  ll ans = sub( cal( 1 ) , cal( 0 ) );
  if( good( 0 ) ) ans = add( ans , 1 );
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}