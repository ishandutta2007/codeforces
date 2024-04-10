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
#define N 99
void build(){

}
int n , w , m , total , ave;
void init(){
  n = getint();
  w = getint();
  m = getint();
  total = n * w * m;
  ave = n * w;
  w *= m;
}
vector<PII> v[ N ];
int sum[ N ];
void test( int st ){
  for( int i = 0 ; i < m ; i ++ ){
    v[ i ].clear();
    sum[ i ] = 0;
  }
  if( st + ave < w ) return;
  v[ 0 ].PB( MP( 1 , st ) );
  sum[ 0 ] += st;
  v[ 1 ].PB( MP( 1 , w - st ) );
  sum[ 1 ] += w - st;
  int now = 1;
  for( int i = 2 ; i <= n ; i ++ ){
    int res = w;
    int cnt = 0;
    while( res ){
      while( sum[ now ] >= ave ) now = ( now + 1 ) % m;
      int nd = min( ave - sum[ now ] , res );
      cnt ++;
      v[ now ].PB( MP( i , nd ) );
      sum[ now ] += nd;
      res -= nd;
    }
    if( cnt > 2 ) return;
  }
  for( int i = 0 ; i < m ; i ++ )
    if( sum[ i ] != ave )
      return;
  puts( "YES" );
  for( int i = 0 ; i < m ; i ++ , puts( "" ) )
    for( size_t j = 0 ; j < v[ i ].size() ; j ++ )
      printf( "%d %.12f " , v[ i ][ j ].FI , (D)v[ i ][ j ].SE / (D)m );
  exit( 0 );
}
void solve(){
  for( int i = 1 ; i <= w ; i ++ )
    test( i );
  puts( "NO" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}