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
#define N 101010
ll n;
vector<PLL> v;
void build(){

}
ll liy[ N ] , lay[ N ];
ll riy[ N ] , ray[ N ];
inline void construct(){
  sort( ALL( v ) );
  liy[ 0 ] = lay[ 0 ] = v[ 0 ].Y;
  for( int i = 1 ; i < n ; i ++ ){
    liy[ i ] = min( liy[ i - 1 ] , v[ i ].Y );
    lay[ i ] = max( lay[ i - 1 ] , v[ i ].Y );
  }
  riy[ n - 1 ] = ray[ n - 1 ] = v[ n - 1 ].Y;
  for( int i = n - 2 ; i >= 0 ; i -- ){
    riy[ i ] = min( riy[ i + 1 ] , v[ i ].Y );
    ray[ i ] = max( ray[ i + 1 ] , v[ i ].Y );
  }
}
inline void Swap(){
  for( int i = 0 ; i < n ; i ++ )
    swap( v[ i ].X , v[ i ].Y );
}
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    v.PB( MP( getint() , getint() ) );
}
inline ll sqr( ll xx ){ return xx * xx; }
inline bool okay( ll xx ){
  for( int l = 0 ; l < n && v[ l ].X <= 0 ; l ++ ){
    ll bl = l , br = n - 1 , bmid , r = l;
    while( bl <= br ){
      bmid = ( bl + br ) >> 1;
      if( abs( v[ bmid ].X ) <= abs( v[ l ].X ) &&
          sqr( v[ bmid ].X - v[ l ].X ) <= xx )
        r = bmid , bl = bmid + 1;
      else br = bmid - 1;
    }
    ll tiy = INF16 , tay = -INF16;
    if( l != 0 ){
      tiy = min( tiy , liy[ l - 1 ] );
      tay = max( tay , lay[ l - 1 ] );
    }
    if( r != n - 1 ){
      tiy = min( tiy , riy[ r + 1 ] );
      tay = max( tay , ray[ r + 1 ] );
    }
    if( r - l == n - 1 ) return true;
    if( sqr( tay - tiy ) <= xx &&
        sqr( tay ) + sqr( v[ l ].X ) <= xx &&
        sqr( tiy ) + sqr( v[ l ].X ) <= xx )
      return true;
  }
  for( int r = n - 1 ; r >= 0 && v[ r ].X >= 0 ; r -- ){
    ll bl = 0 , br = r , bmid , l = r;
    while( bl <= br ){
      bmid = ( bl + br ) >> 1;
      if( abs( v[ bmid ].X ) <= abs( v[ r ].X ) &&
          sqr( v[ bmid ].X - v[ r ].X ) <= xx )
        l = bmid , br = bmid - 1;
      else bl = bmid + 1;
    }
    ll tiy = INF16 , tay = -INF16;
    if( l != 0 ){
      tiy = min( tiy , liy[ l - 1 ] );
      tay = max( tay , lay[ l - 1 ] );
    }
    if( r != n - 1 ){
      tiy = min( tiy , riy[ r + 1 ] );
      tay = max( tay , ray[ r + 1 ] );
    }
    if( r - l == n - 1 ) return true;
    if( sqr( tay - tiy ) <= xx &&
        sqr( tay ) + sqr( v[ r ].X ) <= xx &&
        sqr( tiy ) + sqr( v[ r ].X ) <= xx )
      return true;
  }
  return false;
}
void solve(){
  ll ans = INF16 * 100ll;
  for( int _ = 0 ; _ < 2 ; _ ++ ){
    construct();
    ll l = 0 , r = sqr( v.back().X - v[ 0 ].X ) , mid;
    while( l <= r ){
      mid = ( l + r ) >> 1;
      if( okay( mid ) ) ans = min( ans , mid ) , r = mid - 1;
      else l = mid + 1;
    }
    if( _ == 0 ) Swap();
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