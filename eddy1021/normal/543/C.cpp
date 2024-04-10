// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
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
int __ = 1 , cs;
/*********default*********/
#define N 22
void build(){

}
int n , m;
char c[ N ][ N ];
int a[ N ][ N ];
int b[ N ][ N ];
int bm[ N ][ N ];
void init(){
  n = getint();
  m = getint();
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%s" , c[ i ] + 1 );
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      a[ i ][ j ] = getint();
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ ){
      int tcst = 0 , tmx = 0 , tmsk = 0;
      for( int k = 0 ; k < n ; k ++ )
        if( c[ i ][ j ] == c[ k ][ j ] ){
          tmsk |= ( 1 << k );
          tcst += a[ k ][ j ];
          tmx = max( tmx , a[ k ][ j ] );
        }
      b[ i ][ j ] = tcst - tmx;
      bm[ i ][ j ] = tmsk;
    }
}
int dp[ 1 << N ];
void solve(){
  for( int i = 1 ; i < ( 1 << n ) ; i ++ ){
    int lb = round( log2( i & -i ) );
    dp[ i ] = INF;
    for( int j = 1 ; j <= m ; j ++ ){
      dp[ i ] = min( dp[ i ] , dp[ i & (~bm[ lb ][ j ]) ] + b[ lb ][ j ] );
      dp[ i ] = min( dp[ i ] , dp[ i ^ ( 1 << lb ) ] + a[ lb ][ j ] );
    }
  }
  printf( "%d\n" , dp[ ( 1 << n ) - 1 ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}