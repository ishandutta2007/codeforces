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
#define N 101010
int n , ai[ N ] , k;
void build(){

}
int sg[ 62500010 ];
int mx;
void init(){
  n = getint(); k = getint(); k &= 1;
  mx = 0;
  for( int i = 0 ; i < n ; i ++ ){
    ai[ i ] = getint();
    mx = max( mx , ai[ i ] );
  }
  sort( ai , ai + n );
}
int tk( int x ){
  return ( sg[ x >> 4 ] >> ( ( x & 15 ) << 1 ) ) & 3;
}
void as( int x , int vl ){
  sg[ x >> 4 ] |= ( vl << ( ( x & 15 ) << 1 ) );
}
void solve(){
  int ans = 0 , ptr = 0 , tsg = 0;
  for( int i = 0 ; i < n ; i ++ ){
    while( ptr < ai[ i ] ){
      int vl1 = tsg , vl2 = 2; ptr ++;
      if( !( ptr & 1 ) ) vl2 = k ? tk( ptr >> 1 ) : 0;
      if( vl1 && vl2 ) tsg = 0;
      else if( vl1 ) tsg = 3 - vl1;
      else if( vl2 ) tsg = 3 - vl2;
      else tsg = 1;
      // debug( "%d %d\n" , ptr , tsg );
      as( ptr , tsg );
    }
    ans ^= tsg;
  }
  puts( ans ? "Kevin" : "Nicky" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}