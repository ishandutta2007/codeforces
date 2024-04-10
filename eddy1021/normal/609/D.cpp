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
#define N 222222
ll n , m , k , s;
ll a[ N ] , b[ N ];
ll t[ N ] , c[ N ];
ll pa[ N ] , pb[ N ];
ll pai[ N ] , pbi[ N ];
void build(){

}
void init(){
  n = getint();
  m = getint();
  k = getint();
  s = getint();
  for( int i = 1 ; i <= n ; i ++ ) a[ i ] = getint();
  for( int i = 1 ; i <= n ; i ++ ) b[ i ] = getint();
  pa[ 1 ] = a[ 1 ]; pb[ 1 ] = b[ 1 ];
  pai[ 1 ] = 1; pbi[ 1 ] = 1;
  for( int i = 2 ; i <= n ; i ++ ){
    pa[ i ] = a[ i ]; pb[ i ] = b[ i ];
    pai[ i ] = i; pbi[ i ] = i;
    if( pa[ i - 1 ] < pa[ i ] ){
      pa[ i ] = pa[ i - 1 ];
      pai[ i ] = pai[ i - 1 ];
    }
    if( pb[ i - 1 ] < pb[ i ] ){
      pb[ i ] = pb[ i - 1 ];
      pbi[ i ] = pbi[ i - 1 ];
    }
  }
  for( int i = 1 ; i <= m ; i ++ ){
    t[ i ] = getint();
    c[ i ] = getint();
  }
}
vector< pair<ll,ll> > v;
bool okay( int tdy ){
  ll ma = pa[ tdy ];
  ll mb = pb[ tdy ];
  v.clear();
  for( int i = 1 ; i <= m ; i ++ )
    if( t[ i ] == 1 ) v.PB( MP( ma * c[ i ] , i ) );
    else v.PB( MP( mb * c[ i ] , i ) );
  sort( ALL( v ) );
  ll cst = 0;
  for( int i = 0 ; i < k ; i ++ ){
    cst += v[ i ].FI;
    // printf( "%lld\n" , v[ i ].FI );
  }
  // printf( "%d %lld %lld\n" , tdy , cst , s );
  return cst <= s;
}
void find_ans( int dy ){
  ll ma = pa[ dy ];
  ll mb = pb[ dy ];
  int aii = pai[ dy ];
  int bii = pbi[ dy ];
  v.clear();
  for( int i = 1 ; i <= m ; i ++ ){
    if( t[ i ] == 1 ) v.PB( MP( ma * c[ i ] , +i ) );
    else v.PB( MP( mb * c[ i ] , -i ) );
  }
  sort( ALL( v ) );
  for( int i = 0 ; i < k ; i ++ )
    printf( "%lld %d\n" , abs( v[ i ].SE ) , v[ i ].SE > 0 ? aii : bii );
}
void solve(){
  int bl = 1 , br = n , bmid , ba = -1;
  while( bl <= br ){
    bmid = ( bl + br ) >> 1;
    if( okay( bmid ) ) ba = bmid , br = bmid - 1;
    else bl = bmid + 1;
  }
  printf( "%d\n" , ba );
  if( ba != -1 ) find_ans( ba );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}