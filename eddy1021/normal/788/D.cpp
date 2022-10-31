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
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
#define dump(x) cerr<<"("<<#x<<"="<<x<<")"
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
#define N 303030
vector<int> qx , qy;
void build(){
#ifndef ONLINE_JUDGE
  int nx , ny;
  scanf( "%d%d" , &nx , &ny );
  for( int i = 0 ; i < nx ; i ++ )
    qx.push_back( getint() );
  for( int i = 0 ; i < ny ; i ++ )
    qy.push_back( getint() );
#endif
}
#define inf 100000000
#define inf2 200000003
inline int query( int x , int y ){
  if( x < -inf or x > inf or
      y < -inf or y > inf )
    return inf2;
#ifndef ONLINE_JUDGE
  int ret = inf2;
  for( auto i : qx )
    ret = min( ret , abs( x - i ) );
  for( auto i : qy )
    ret = min( ret , abs( y - i ) );
  return ret;
#endif
  printf( "0 %d %d\n" , x , y );
  fflush( stdout );
  int d; scanf( "%d" , &d );
  return d;
}
vector<int> vx , vy;
inline void Uniq( vector<int>& x ){
  sort( x.begin() , x.end() );
  x.resize( unique( x.begin() , x.end() ) - x.begin() );
}
inline void output( const vector<int>& x ){
  if( x.empty() ) puts( "" );
  for( size_t i = 0 ; i < x.size() ; i ++ )
    printf( "%d%c" , x[ i ] , " \n"[ i + 1 == x.size() ] );
}
inline void answer(){
  Uniq( vx );
  Uniq( vy );
  printf( "1 %d %d\n" , (int)vx.size() , (int)vy.size() );
  output( vx );
  output( vy );
  fflush( stdout );
  Bye;
}
void init(){
}
vector<int> cand;
void find_cand( int lb , int rb ){
  if( lb + 1 >= rb ) return;
  int mb = ( lb + rb ) >> 1;
  int qq = query( mb , mb );
  if( mb - qq > lb and query( mb - qq , mb - qq ) == 0 ){
    cand.push_back( mb - qq );
    find_cand( lb , mb - qq );
    find_cand( mb - qq , rb );
    return;
  }
  if( mb + qq < rb and query( mb + qq , mb + qq ) == 0 ){
    cand.push_back( mb + qq );
    find_cand( lb , mb + qq );
    find_cand( mb + qq , rb );
    return;
  }
}
void solve(){
  cand.push_back( -inf );
  cand.push_back( +inf );
  find_cand( -inf , +inf );
  int other = -inf;
  sort( cand.begin() , cand.end() );
  for( int i : cand ){
    if( other == i ) other ++;
    else break;
  }
  for( int i : cand ){
    if( query( i , other ) == 0 ) vx.push_back( i );
    if( query( other , i ) == 0 ) vy.push_back( i );
  }
  answer();
}
int main(){
  srand( 0x1021 );
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}