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
#define N 101010
void build(){

}
int n , m , x;
void init(){
  scanf( "%d%d%d" , &n , &m , &x );
}
vector< vector< int > > dp[ 2 ];
void solve(){
  if( n > m ){
    puts( "0" );
    exit( 0 );
  }
  for( int b = 0 ; b < 2 ; b ++ ){
    dp[ b ].resize( n + 1 );
    for( int i = 0 ; i <= n ; i ++ ){
      dp[ b ][ i ].resize( n + 1 );
      for( int j = 0 ; j <= n ; j ++ )
        dp[ b ][ i ][ j ] = 0;
    }
  }
  dp[ 0 ][ 0 ][ 0 ] = 1;
  for( int i = 1 ; i <= m ; i ++ ){
    int now = i & 1 , pre = 1 - now;
    for( int j = 0 ; j <= n ; j ++ )
      for( int k = 0 ; k <= n ; k ++ )
        dp[ now ][ j ][ k ] = 0;
    for( int j = 0 ; j <= n ; j ++ )
      for( int k = 0 ; k <= n ; k ++ ){
        if( !dp[ pre ][ j ][ k ] ) continue;
        if( i != x ){
          dp[ now ][ j ][ k ] = add( dp[ now ][ j ][ k ],
                                     dp[ pre ][ j ][ k ] );
        }
        if( j + 1 <= n && k + 1 <= n )
          dp[ now ][ j + 1 ][ k + 1 ] = add( dp[ now ][ j + 1 ][ k + 1 ] ,
                                             dp[ pre ][ j ][ k ] );
        if( i != x && k )
          dp[ now ][ j ][ k - 1 ] = add( dp[ now ][ j ][ k - 1 ] ,
                                         dp[ pre ][ j ][ k ] );
        if( k && j + 1 <= n )
          dp[ now ][ j + 1 ][ k ] = add( dp[ now ][ j + 1 ][ k ],
                                         dp[ pre ][ j ][ k ] );
        if( j + 1 <= n && k == 0 )
          dp[ now ][ j + 1 ][ k ] = add( dp[ now ][ j + 1 ][ k ],
                                         dp[ pre ][ j ][ k ] );
      }
  }
  int ans = dp[ m & 1 ][ n ][ 0 ];
  for( int i = 1 ; i <= n ; i ++ )
    ans = mul( ans , i );
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