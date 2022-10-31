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
#define N 100010
int n , h[ N ] , q , v[ N ];
void build(){

}
void init(){
  n = getint(); q = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    h[ i ] = getint();
    if( i > 1 ) v[ i - 1 ] = abs( h[ i ] - h[ i - 1 ] );
  }
}
deque<int> d;
ll dpl[ N ] , dpr[ N ];
void solve(){
  while( q -- ){
    int li = getint();
    int ri = getint();
    d.clear();
    dpl[ li ] = 1;
    d.PB( li );
    for( int i = li + 1 ; i < ri ; i ++ ){
      while( d.size() && v[ i ] >= v[ d.back() ] ) d.pop_back();
      if( d.size() ) dpl[ i ] = i - d.back();
      else dpl[ i ] = i - li + 1;
      d.PB( i );
    }
    d.clear();
    dpr[ ri - 1 ] = 1;
    d.PB( ri - 1 );
    for( int i = ri - 2 ; i >= li ; i -- ){
      while( d.size() && v[ i ] > v[ d.back() ] ) d.pop_back();
      if( d.size() ) dpr[ i ] = d.back() - i;
      else dpr[ i ] = ri - i;
      d.PB( i );
    }
    ll ans = 0;
    for( int i = li ; i < ri ; i ++ )
      ans += dpl[ i ] * dpr[ i ] * v[ i ];
    cout << ans << endl;
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