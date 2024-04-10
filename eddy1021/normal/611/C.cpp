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
#define N 514
int n , m;
char c[ N ][ N ];
int dpl[ N ][ N ];
int dpu[ N ][ N ];
void build(){

}
void init(){
  n = getint(); m = getint();
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%s" , c[ i ] + 1 );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j < m ; j ++ )
      if( c[ i ][ j ] == '.' && c[ i ][ j + 1 ] == '.' )
        dpl[ i ][ j ] ++;
  for( int i = 1 ; i < n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      if( c[ i ][ j ] == '.' && c[ i + 1 ][ j ] == '.' )
        dpu[ i ][ j ] ++;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ ){
      dpl[ i ][ j ] += dpl[ i - 1 ][ j ] + dpl[ i ][ j - 1 ] - dpl[ i - 1 ][ j - 1 ];
      dpu[ i ][ j ] += dpu[ i - 1 ][ j ] + dpu[ i ][ j - 1 ] - dpu[ i - 1 ][ j - 1 ];
    }
}
void solve(){
  int q = getint();
  while( q -- ){
    int r1 = getint();
    int c1 = getint();
    int r2 = getint();
    int c2 = getint();
    int ans = 0;
    if( c1 != c2 )
      ans = dpl[ r2 ][ c2 - 1 ] - dpl[ r2 ][ c1 - 1 ] - dpl[ r1 - 1 ][ c2 - 1 ] + dpl[ r1 - 1 ][ c1 - 1 ];
    if( r1 != r2 )
      ans += dpu[ r2 - 1 ][ c2 ] - dpu[ r2 - 1 ][ c1 - 1 ] - dpu[ r1 - 1 ][ c2 ] + dpu[ r1 - 1 ][ c1 - 1 ];
    printf( "%d\n" , ans );
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