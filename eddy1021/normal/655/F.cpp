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
#define N 1000001
int n , k , q , fac[ N ] , ifac[ N ] , a[ N ] , c[ N ];
vector<int> Div[ N ];
void build(){
  ifac[ 0 ] = fac[ 0 ] = 1ll;
  for( int i = 1 ; i < N ; i ++ ){
    fac[ i ] = mul( fac[ i - 1 ] , i );
    ifac[ i ] = mypow( fac[ i ] , mod7 - 2 , mod7 );
  }
  for( int i = 2 ; i < N ; i ++ )
    for( int j = i ; j < N ; j += i )
      Div[ j ].PB( i );
}
inline ll C( ll ta , ll tb ){
  if( ta < tb ) return 0ll;
  return mul( fac[ ta ] , mul( ifac[ tb ] , ifac[ ta - tb ] ) );
}
int co[ N ] , cnt[ N ];
void init(){
  n = getint();
  k = getint();
  q = getint();
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = getint();
  for( int i = 0 ; i < q ; i ++ )
    c[ i ] = getint();
}
ll ans , tcnt;
inline void add( int xx ){
  int tsum = 0;
  for( int i = (int)Div[ xx ].size() - 1 ; i >= 0 ; i -- ){
    int tDiv = Div[ xx ][ i ];
    co[ tDiv ] = C( cnt[ tDiv ] , k - 1 );
    for( int j = (int)Div[ xx / tDiv ].size() - 1 ; j >= 0 ; j -- )
      co[ tDiv ] = sub( co[ tDiv ] , co[ tDiv * Div[ xx / tDiv ][ j ] ] );
    ans = add( ans , mul( co[ tDiv ] , tDiv ) );
    tsum = add( tsum , co[ tDiv ] );
  }
  co[ 1 ] = C( tcnt , k - 1 );
  co[ 1 ] = sub( co[ 1 ] , tsum );
  ans = add( ans , co[ 1 ] );
  for( size_t i = 0 ; i < Div[ xx ].size() ; i ++ )
    cnt[ Div[ xx ][ i ] ] ++;
  tcnt ++;
}
inline void solve(){
  for( int i = 0 ; i < n ; i ++ )
    add( a[ i ] );
  for( int i = 0 ; i < q ; i ++ ){
    add( c[ i ] );
    printf( "%lld\n" , ans );
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