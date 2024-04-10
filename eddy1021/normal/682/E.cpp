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
#define eps 1e-3
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
#define N 5140
inline PLL operator+( const PLL& p1 , const PLL& p2 ){
  return { p1.X + p2.X , p1.Y + p2.Y };
}
inline PLL operator-( const PLL& p1 , const PLL& p2 ){
  return { p1.X - p2.X , p1.Y - p2.Y };
}
inline LL operator^( const PLL& p1 , const PLL& p2 ){
  return p1.X * p2.Y - p1.Y * p2.X;
}
inline LL area( const PLL& p1 , const PLL& p2 , const PLL& p3 ){
  return abs( ( p1 ^ p2 ) + ( p2 ^ p3 ) + ( p3 ^ p1 ) );
}
LL n , s;
vector< PLL > p , ch;
void build(){
}
inline void convexHull(){
  sort( ALL( p ) );
  size_t psz = 0 , csz = 0;
  for( int _ = 0 ; _ < 2 ; _ ++ ){
    for( size_t i = 0 ; i < p.size() ; i ++ ){
      while( csz - psz > 1 && ( ( ch[ csz - 1 ] - ch[ csz - 2 ] ) ^
                                ( p[ i ] - ch[ csz - 2 ] ) ) <= 0 ){
        ch.pop_back(); csz --;
      }
      ch.push_back( p[ i ] ); csz ++;
    }
    psz = ch.size() - 1;
    reverse( ALL( p ) );
  }
}
void init(){
  n = getint();
  s = getint();
  for( int i = 0 ; i < n ; i ++ ){
    LL tx = getint();
    LL ty = getint();
    p.PB( { tx , ty } );
  }
  if( n == 3 ){
    for( size_t i = 0 ; i < p.size() ; i ++ )
      printf( "%lld %lld\n" , p[ i ].X , p[ i ].Y );
    exit( 0 );
  }
  convexHull();
}
void solve(){
  ch.pop_back();
  size_t sz = ch.size();
  for( size_t i = 0 ; i < sz ; i ++ ) ch.push_back( ch[ i ] );
  for( size_t i = 0 ; i < sz ; i ++ ) ch.push_back( ch[ i ] );
  for( size_t i = 0 ; i < sz ; i ++ ) ch.push_back( ch[ i ] );
  int n1 = 0 , n2 = 0 , n3 = 0; LL bst = -1;
  for( size_t i = 0 , j = 0 , k = 0 ; i < sz ; i ++ ){
    if( j <= i ) j = i + 1;
    if( k <= j ) k = j + 1;
    while( area( ch[ i ] , ch[ j ] , ch[ k + 1 ] ) >
           area( ch[ i ] , ch[ j ] , ch[ k ] ) ) k ++;
    while( area( ch[ i ] , ch[ k ] , ch[ j + 1 ] ) >
           area( ch[ i ] , ch[ k ] , ch[ j ] ) ) j ++;
    LL narea = area( ch[ i ] , ch[ j ] , ch[ k ] );
    if( narea > bst ){
      bst = narea;
      n1 = i;
      n2 = j;
      n3 = k;
    }
  }
  PLL a1 = ch[ n1 ] + ( ch[ n3 ] - ch[ n2 ] );
  PLL a2 = ch[ n2 ] + ( ch[ n1 ] - ch[ n3 ] );
  PLL a3 = ch[ n3 ] + ( ch[ n2 ] - ch[ n1 ] );
  printf( "%lld %lld\n" , a1.X , a1.Y );
  printf( "%lld %lld\n" , a2.X , a2.Y );
  printf( "%lld %lld\n" , a3.X , a3.Y );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}