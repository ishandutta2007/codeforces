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
#define N 303030
int n , m , k;
set<int> s[ N ];
void build(){

}
void init(){
  n = getint(); m = getint(); k = getint();
  while( m -- ){
    int ai = getint();
    int bi = getint();
    s[ ai ].insert( bi );
    s[ bi ].insert( ai );
  }
}
set<int> wt;
typedef set<int>::iterator si;
queue<int> Q;
bool vst[ N ];
inline void go( int st ){
  Q.push( st ); wt.erase( st );
  while( Q.size() ){
    int tn = Q.front(); Q.pop();
    vector<int> tv;
    for( si it = wt.begin() ; it != wt.end() ; it ++ )
      if( s[ tn ].count( *it ) == 0 ){
        tv.PB( *it );
        Q.push( *it );
      }
    for( size_t i = 0 ; i < tv.size() ; i ++ )
      wt.erase( tv[ i ] );
  }
}
void solve(){
  Q.push( 1 );
  for( int i = 2 ; i <= n ; i ++ )
    wt.insert( i );
  while( Q.size() ){
    int tn = Q.front(); Q.pop();
    vector<int> tv;
    for( si it = wt.begin() ; it != wt.end() ; it ++ )
      if( s[ tn ].count( *it ) == 0 ){
        tv.PB( *it );
        Q.push( *it );
      }
    for( size_t i = 0 ; i < tv.size() ; i ++ )
      wt.erase( tv[ i ] );
  }
  if( (int)wt.size() ){
    puts( "impossible" );
    exit( 0 );
  }
  for( int i = 2 ; i <= n ; i ++ )
    wt.insert( i );
  int mn = 0;
  for( int i = 2 ; i <= n ; i ++ )
    if( s[ 1 ].count( i ) == 0 &&
        wt.count( i ) ){
      mn ++;
      go( i );
    }
  int mx = n - 1 - (int)s[ 1 ].size();
  // printf( "%d %d\n" , mn , mx );
  puts( mn <= k && k <= mx ? "possible" : "impossible" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}