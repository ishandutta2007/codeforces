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
#define N 202020
int n , m;
vector<PII> v[ N ];
void build(){

}
void init(){
  n = getint();
  m = getint();
  for( int i = 0 ; i < m ; i ++ ){
    int ui = getint();
    int vi = getint();
    v[ vi ].PB( MP( ui , i ) );
  }
}
// < bdr
int deg[ N ];
int que[ N ] , f , t;
bool okay( int bdr ){
  for( int i = 1 ; i <= n ; i ++ )
    deg[ i ] = 0;
  f = t = 0;
  for( int i = 1 ; i <= n ; i ++ )
    for( size_t j = 0 ; j < v[ i ].size() ; j ++ )
      if( v[ i ][ j ].SE < bdr )
        deg[ v[ i ][ j ].FI ] ++;
  for( int i = 1 ; i <= n ; i ++ )
    if( deg[ i ] == 0 )
      que[ t ++ ] = i;
  while( t - f > 0 ){
    if( t - f > 1 ) return false;
    int now = que[ f ++ ];
    for( size_t i = 0 ; i < v[ now ].size() ; i ++ ){
      if( v[ now ][ i ].SE >= bdr ) continue;
      deg[ v[ now ][ i ].FI ] --;
      if( deg[ v[ now ][ i ].FI ] == 0 ){
        que[ t ++ ] = v[ now ][ i ].FI;
      }
    }
  }
  return true;
}
void solve(){
  int ans = -1 , l = 1 , r = m , mid;
  while( l <= r ){
    mid = ( l + r ) >> 1;
    if( okay( mid ) ) ans = mid , r = mid - 1;
    else l = mid + 1;
  }
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