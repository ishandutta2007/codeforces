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
#define N 1000001
int n , m;
vector<PII> v;
vector<int> fac[ N ];
void build(){
}
void init(){
  n = getint();
  m = getint();
  for( int i = 2 ; i <= m ; i ++ )
    for( int j = i ; j <= m ; j += i )
      fac[ j ].PB( i );
  for( int i = 0 ; i < n ; i ++ ){
    int vl = getint();
    v.PB( MP( vl , i + 1 ) );
  }
  sort( ALL( v ) );
  while( v.size() && v.back().FI > m )
    v.pop_back();
}
int cnt[ N ];
void solve(){
  if( (int)v.size() == 0 ){
    puts( "1 0" );
    puts( "" );
    exit( 0 );
  }
  for( size_t i = 0 ; i < v.size() ; i ++ )
    cnt[ v[ i ].FI ] ++;
  int ans = 1 , ansc = cnt[ 1 ];
  for( int i = 2 ; i <= m ; i ++ ){
    int tans = cnt[ 1 ];
    for( size_t j = 0 ; j < fac[ i ].size() ; j ++ )
      tans += cnt[ fac[ i ][ j ] ];
    if( tans > ansc )
      ans = i , ansc = tans;
  }
  vector<int> vv;
  for( size_t i = 0 ; i < v.size() ; i ++ )
    if( ans % v[ i ].FI == 0 )
      vv.PB( v[ i ].SE );
  sort( ALL( vv ) );
  printf( "%d %d\n" , ans , (int)vv.size() );
  for( size_t i = 0 ; i < vv.size() ; i ++ )
    printf( "%d%c" , vv[ i ] , " \n"[ i + 1 == vv.size() ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}