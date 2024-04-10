// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
int n , x , y;
int p1 , p2;
void build(){
}
int asked;
int ask( const vector<int>& v ){
  assert( ++ asked <= 19 );
#ifdef LOCAL
  int ret = 0;
  for( auto ii : v )
    if( ii == p1 or ii == p2 ) ret ^= y;
    else ret ^= x;
  return ret;
#else
  if( v.empty() ) return 0;
  printf( "? %d" , (int)v.size() );
  for( auto i : v )
    printf( " %d" , i );
  puts( "" );
  fflush( stdout );
  int ret; scanf( "%d" , &ret );
  return ret;
#endif
}
int p[ 2 ];
void answer(){
  if( p[ 0 ] > p[ 1 ] ) swap( p[ 0 ] , p[ 1 ] );
  printf( "! %d %d\n" , p[ 0 ] , p[ 1 ] );
  fprintf( stderr , "ask %d times\n" , asked );
  fflush( stdout );
  exit(0);
}
void init(){
  n = getint();
  x = getint();
  y = getint();
#ifdef LOCAL
  p1 = getint();
  p2 = getint();
#endif
}
bool has_1( int sz , int ret ){
  if( sz & 1 ) return ret == y;
  return ret == ( x ^ y );
}
bool d[ 11 ];
void solve(){
  int dif = 0 , df = -1;
  for( int i = 0 ; i < 10 ; i ++ ){
    vector<int> cand;
    for( int j = 1 ; j <= n ; j ++ )
      if( !((j>>i) & 1) )
        cand.push_back( j );
    if( has_1( cand.size() , ask( cand ) ) ){
      dif |= (1 << i), df = i;
      d[ i ] = true;
    }
  }
  assert( df != -1 );
  for( int i = 0 ; i < 10 ; i ++ ){
    if( i == df ) continue;
    vector<int> cand;
    for( int j = 1 ; j <= n ; j ++ )
      if( !((j >> df) & 1) and
          !((j >> i) & 1) )
        cand.push_back( j );
    if( !has_1( cand.size() , ask( cand ) ) )
      p[ 0 ] |= (1 << i);
  }
  p[ 1 ] = p[ 0 ] ^ dif;
  answer();
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}