// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
// typedef pair<LD,LD> Pt;
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
#define N 123456
typedef pair<ll,ll> Pt;
void build(){

}
ll C( ll a , ll b ){
  if( a < b ) return 0;
  ll res = 1;
  for( ll x = a , y = 1 ; y <= b ; x -- , y ++ ) res *= x;
  for( ll x = a , y = 1 ; y <= b ; x -- , y ++ ) res /= y;
  return res;
}
Pt operator-( const Pt& p1 , const Pt& p2 ){
  return MP( p1.X - p2.X , p1.Y - p2.Y );
}
ll operator*( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.Y - p1.Y * p2.X;
}
D ang( const Pt& tp ){
  return atan2( tp.Y , tp.X );
}
bool cmp( Pt x , Pt y ){
  return ang( x ) < ang( y );
}
ll n;
vector<Pt> p;
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ ){
    Pt pp;
    scanf( "%lld%lld" , &pp.X , &pp.Y );
    p.PB( pp );
  }
  if( ( p[ 1 ] - p[ 0 ] ) * ( p[ 2 ] - p[ 1 ] ) < 0 )
    reverse( ALL( p ) );
}
vector<Pt> v;
void solve(){
  int q = getint(); while( q -- ){
    v.clear();
    Pt x; scanf( "%lld%lld" , &x.X , &x.Y );
    for( int i = 0 ; i < n ; i ++ )
      v.PB( p[ i ] - x );
    // sort( ALL( v ) , cmp );
    for( int i = 0 ; i < n ; i ++ ) v.PB( v[ i ] );
    // for( int i = 0 ; i < (int)v.size() ; i ++ )
      // debug( "%lld %lld\n" , v[ i ].X , v[ i ].Y );
    ll ans = C( n , 3 ) , tans = 0;
    int ptr = 1;
    for( int i = 0 ; i < n ; i ++ ){
      ptr = max( ptr , i + 1 );
      while( ptr < i + n && v[ i ] * v[ ptr ] >= 0 ) ptr ++;
      if( ptr == i + n ){
        tans = ans; break;
      }
      tans += C( ptr - i - 1 , 2 );
    }
    printf( "%lld\n" , ans - tans );
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