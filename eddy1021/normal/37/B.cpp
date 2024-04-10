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
#define N 1021
ll n , mx , reg , p[ N ] , d[ N ];
vector<PLL> v;
void build(){

}
void init(){
  n = getint();
  mx = getint();
  reg = getint();
  for( int i = 0 ; i < n ; i ++ ){
    p[ i ] = getint();
    d[ i ] = getint();
    v.PB( MP( p[ i ] , i ) );
  }
  sort( ALL( v ) );
  reverse( ALL( v ) );
}
vector<PLL> ans;
priority_queue<PLL> heap;
void solve(){
  ll hp = mx , l = 0 , ds = 0 , t;
  for( t = 0 ; hp > 0 ; t ++ ){
    while( l < n && hp * 100 <= mx * v[ l ].FI ){
      heap.push( MP( d[ v[ l ].SE ] , v[ l ].SE ) );
      l ++;
    }
    if( ds <= reg && heap.empty() ){
      puts( "NO" );
      exit( 0 );
    }
    if( heap.size() ){
      ans.PB( MP( t , heap.top().SE + 1 ) );
      ds += heap.top().FI;
      heap.pop();
    }
    hp -= ds; hp += reg;
    hp = min( hp , mx );
  }
  puts( "YES" );
  printf( "%lld %d\n" , t , (int)ans.size() );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%lld %lld\n" , ans[ i ].FI , ans[ i ].SE );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}