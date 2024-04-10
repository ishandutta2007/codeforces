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
#define N 202020
void build(){

}
int n , m , xx[ N ] , yy[ N ];
vector<int> v[ N ];
bool got[ N ];
int tag[ N ];
void init(){
  n = getint(); m = getint();
  for( int i = 0 ; i < m ; i ++ ){
    int ui = getint();
    int vi = getint();
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
    xx[ i ] = ui;
    yy[ i ] = vi;
  }
}
vector<int> ans[ 2 ];
inline void go( int st ){
  queue< PII > Q;
  got[ st ] = true;
  tag[ st ] = 0;
  Q.push( { st , 0 } );
  while( Q.size() ){
    PII tp = Q.front(); Q.pop();
    int now = tp.FI , clr = tp.SE;
    for( int nxt : v[ now ] ){
      if( got[ nxt ] ) continue;
      got[ nxt ] = true;
      tag[ nxt ] = 1 - clr;
      Q.push( { nxt , 1 - clr } );
    }
  }
}
inline bool okay(){
  for( int i = 0 ; i < m ; i ++ )
    if( tag[ xx[ i ] ] == tag[ yy[ i ] ] )
      return false;
  return true;
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    if( !got[ i ] )
      go( i );
  if( !okay() ) puts( "-1" );
  else{
    for( int i = 1 ; i <= n ; i ++ )
      ans[ tag[ i ] ].push_back( i );
    for( int i = 0 ; i < 2 ; i ++ ){
      printf( "%d\n" , (int)ans[ i ].size() );
      for( size_t j = 0 ; j < ans[ i ].size() ; j ++ )
        printf( "%d%c" , ans[ i ][ j ] , " \n"[ j + 1 == ans[ i ].size() ] );
    }
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