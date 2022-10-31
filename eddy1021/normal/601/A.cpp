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
#define N 514
int n, m;
int cnt[ N ][ N ];
// 0 for bus 1 for train
void build(){

}
void init(){
  n = getint();
  m = getint();
  while( m -- ){
    int ui = getint();
    int vi = getint();
    cnt[ ui ][ vi ] =
    cnt[ vi ][ ui ] = 1;
  }
}
bool usd[ N ];
queue<int> Q;
int dst[ N ];
int cal( int type ){
  dst[ 1 ] = 0;
  Q.push( 1 );
  usd[ 1 ] = true;
  dst[ n ] = -1;
  while( Q.size() ){
    int tn = Q.front(); Q.pop();
    for( int i = 1 ; i <= n ; i ++ )
      if( i != tn && cnt[ tn ][ i ] == type && !usd[ i ] ){
        usd[ i ] = true;
        dst[ i ] = dst[ tn ] + 1;
        Q.push( i );
      }
  }
  return dst[ n ];
}
void solve(){
  printf( "%d\n" , cal( 1 - cnt[ 1 ][ n ] ) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}