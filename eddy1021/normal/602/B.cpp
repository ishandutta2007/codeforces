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
void build(){

}
int n , a[ N ] , ans;
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
}
deque<int> dmax;
deque<int> dmin;
void solve(){
  ans = 1;
  dmax.PB( 1 );
  dmin.PB( 1 );
  for( int i = 2 ; i <= n ; i ++ ){
    while( dmax.size() && a[ i ] > a[ dmax.back() ] ) dmax.pop_back();
    while( dmin.size() && a[ i ] < a[ dmin.back() ] ) dmin.pop_back();
    dmax.PB( i );
    dmin.PB( i );
    while( a[ dmax[ 0 ] ] - a[ dmin[ 0 ] ] > 1 ){
      if( dmax[ 0 ] < dmin[ 0 ] ) dmax.pop_front();
      else dmin.pop_front();
    }
    ans = max( ans , i - min( dmax[ 0 ] , dmin[ 0 ] ) + 1 );
  }
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