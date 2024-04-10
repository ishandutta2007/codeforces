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
void build(){

}
int n;
inline PLL operator-( const PLL& p1 , const PLL& p2 ){
  return MP( p1.X - p2.X , p1.Y - p2.Y );
}
inline LL operator^( const PLL& p1 , const PLL& p2 ){
  return p1.X * p2.Y - p1.Y * p2.X;
}
vector< pair<PLL,int> > v;
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ ){
    ll xx = getint();
    ll yy = getint();
    v.PB( MP( MP( xx , yy ) , i + 1 ) );
  }
  sort( ALL( v ) );
}
bool good( int idx ){
  if( ( ( v[ idx ].FI - v[ idx - 1 ].FI ) ^ ( v[ idx ].FI - v[ idx - 2 ].FI ) ) == 0 )
    return false;
  return true;
}
void solve(){
  for( int i = 2 ; i < n ; i ++ )
    if( good( i ) ){
      printf( "%d %d %d\n" , v[ i - 2 ].SE ,
                             v[ i - 1 ].SE ,
                             v[ i ].SE );
      exit( 0 );
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