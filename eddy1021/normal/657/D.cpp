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
#define eps 1e-12
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
int n , p[ N ] , t[ N ];
vector<PLL> v;
ll sumt , psum[ N ];
void build(){

}
bool cmp( PLL p1 , PLL p2 ){
  if( p1.FI * p2.SE != p1.SE * p2.FI )
    return p1.FI * p2.SE > p1.SE * p2.FI;
  return p1.FI < p2.FI;
}
inline bool equal( PLL p1 , PLL p2 ){
  return p1.FI * p2.SE == p1.SE * p2.FI;
}
void adjust( int l , int r ){
  if( r - l <= 2 ) return;
  ll mindif = 1000000000ll , mi = -1;
  for( int i = l + 1 ; i < r ; i ++ ){
    ll tdif = v[ i ].FI - v[ i - 1 ].FI;
    if( tdif == 0 ) continue;
    if( mi == -1 || tdif < mindif ){
      mindif = tdif;
      mi = i;
    }
  }
  if( mi == -1 ) return;
  swap( v[ l ] , v[ mi - 1 ] );
  swap( v[ mi ] , v[ r - 1 ] );
}
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    p[ i ] = getint();
  for( int i = 0 ; i < n ; i ++ ){
    t[ i ] = getint();
    sumt += t[ i ];
  }
  for( int i = 0 ; i < n ; i ++ )
    v.PB( MP( p[ i ] , t[ i ] ) );
  sort( ALL( v ) , cmp );
  for( int l = 0 , r = 0 ; l < n ; l = r ){
    while( r < n && equal( v[ l ] , v[ r ] ) ) r ++;
    adjust( l , r );
  }
  psum[ 0 ] = v[ 0 ].SE;
  for( int i = 1 ; i < n ; i ++ )
    psum[ i ] = psum[ i - 1 ] + v[ i ].SE;
  // for( int i = 0 ; i < n ; i ++ )
    // printf( "%lld %lld\n" , v[ i ].FI , v[ i ].SE );
}
vector< pair<ll,LD> > vv , vv3;
bool okk( LD mid , int l , int r ){
  LD pdp = l ? psum[ l - 1 ] : 0;
  vector< pair<ll,LD> > vv2;
  for( int i = l ; i < r ; i ++ ){
    LD tsc = v[ i ].FI * ( 1.0 - mid * ( pdp + v[ i ].SE ) / (LD)sumt );
    vv2.PB( MP( v[ i ].FI , tsc ) );
    vv3.PB( MP( v[ i ].FI , tsc ) );
  }
  sort( ALL( vv2 ) );
  LD bst = vv2[ 0 ].SE; ll xx = vv2[ 0 ].FI;
  vv3.PB( MP( vv2[ 0 ].FI , vv2[ 0 ].FI * ( 1.0 - mid * psum[ r - 1 ] / (LD)sumt ) ) );
  for( size_t i = 1 ; i < vv2.size() ; i ++ ){
    LD ssc = vv2[ i ].FI * ( 1.0 - mid * psum[ r - 1 ] / (LD)sumt );
    // printf( "%lld %.6f %.6f\n" , vv2[ i ].FI , (D)ssc , (D)bst );
    if( ssc < bst && vv2[ i ].FI != xx ) return false;
    vv3.PB( MP( vv2[ i ].FI , ssc ) );
    if( vv2[ i ].SE > bst ){
      bst = max( bst , vv2[ i ].SE );
      xx = vv2[ i ].FI;
    }
  }
  return true;
}
bool okay( LD mid ){
  vv.clear(); vv3.clear();
  for( int i = 0 ; i < n ; i ++ ){
    LD sc = v[ i ].FI * ( 1.0 - mid * psum[ i ] / (LD)sumt );
    vv.PB( MP( v[ i ].FI , sc ) );
  }
  sort( ALL( vv ) );
  for( size_t i = 1 ; i < vv.size() ; i ++ )
    if( vv[ i - 1 ].SE > vv[ i ].SE )
      return false;
  for( int l = 0 , r = 0 ; l < n ; l = r ){
    while( r < n && equal( v[ l ] , v[ r ] ) ) r ++;
    if( !okk( mid , l , r ) )
      return false;
  }
  sort( ALL( vv3 ) );
  for( size_t i = 1 ; i < vv3.size() ; i ++ )
    if( vv3[ i - 1 ].SE > vv3[ i ].SE + eps )
      return false;
  return true;
}
void solve(){
  LD l = 0.0 , r = 1.0 , mid ;
  for( int i = 0 ; i < 30 ; i ++ ){
    mid = ( l + r ) * 0.5;
    if( okay( mid ) ) l = mid;
    else r = mid;
  }
  printf( "%.12f\n" , (D)mid );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}