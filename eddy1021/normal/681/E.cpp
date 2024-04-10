// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<D,D> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 101010
void build(){

}
#define O FI
#define R SE
inline Pt operator-( const Pt& p1 , const Pt& p2 ){
  return { p1.X - p2.X , p1.Y - p2.Y };
}
inline D operator*( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.X + p1.Y * p2.Y;
}
inline D norm( const Pt& tp ){
  return sqrt( tp * tp );
}
inline D angle( const Pt& tp ){
  return atan2( tp.Y , tp.X );
}
const D pi = acos( -1.0 );
typedef pair< Pt , D > Cir;
inline void scan( Pt& _p ){
  scanf( "%lf%lf" , &_p.X , &_p.Y );
}
inline void scan( Cir& _c ){
  scan( _c.O );
  scanf( "%lf" , &_c.R );
}
inline bool in( const Pt& tp , const Cir& tc ){
  return norm( tp - tc.O ) < tc.R + eps;
}
inline D sqr( const D& tk ){
  return tk * tk;
}
int n;
Pt o;
D v , t;
Cir c[ N ];
void init(){
  scan( o );
  scanf( "%lf%lf" , &v , &t );
  v *= t;
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    scan( c[ i ] );
}
vector< Pt > ans;
void Add( const D& sang , const D& eang ){
  if( sang < -pi ){
    ans.push_back( { sang + 2.0 * pi , pi } );
    ans.push_back( { -pi , eang } );
  }else if( eang > pi ){
    ans.push_back( { sang , pi } );
    ans.push_back( { -pi , eang - 2.0 * pi } );
  }else
    ans.push_back( { sang , eang } );
}
void Add( const Cir& tc ){
  D dst = norm( tc.O - o );
  if( dst - tc.R > v ) return;
  D tangd = sqrt( sqr( dst ) - sqr( tc.R ) );
  D ang = angle( tc.O - o );
  D theta = 0.0;
  if( tangd < v + eps )
    theta = asin( tc.R / dst );
  else
    theta = acos( ( sqr( v ) + sqr( dst ) - sqr( tc.R ) ) /
                  ( 2.0 * v * dst ) );
  Add( ang - theta , ang + theta );
}
void solve(){
  for( int i = 0 ; i < n ; i ++ )
    if( in( o , c[ i ] ) ){
      printf( "%.12f\n" , 1.0 );
      exit( 0 );
    }
  for( int i = 0 ; i < n ; i ++ )
    Add( c[ i ] );
  sort( ALL( ans ) );
  D sum = 0.0;
  if( ans.size() ){
    Pt pre = ans[ 0 ];
    for( size_t i = 1 ; i < ans.size() ; i ++ ){
      if( ans[ i ].FI < pre.SE )
        pre.SE = max( pre.SE , ans[ i ].SE );
      else{
        sum += pre.SE - pre.FI;
        pre = ans[ i ];
      }
    }
    sum += pre.SE - pre.FI;
  }
  printf( "%.12f\n" , sum / ( 2.0 * pi ) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}