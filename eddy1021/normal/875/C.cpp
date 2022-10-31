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
void sleep( double sec = 1021 ){
  clock_t s = clock();
  while( clock() - s < CLOCKS_PER_SEC * sec );
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 101010
void build(){

}
int n , m;
vector<int> v[ N ];
void imp(){
  puts( "No" );
  exit(0);
}
bool cap[ N ];
inline int ord( int x ){
  return cap[ x ] ? x - m : x ;
}
vector< int > g[ N ];
void output(){
  puts( "Yes" );
  vector<int> ans;
  for( int i = 1 ; i <= m ; i ++ )
    if( cap[ i ] )
      ans.push_back( i );
  printf( "%d\n" , (int)ans.size() );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%d%c" , ans[ i ] , " \n"[ i + 1 == ans.size() ] );
}
void recheck(){
  for( int i = 1 ; i < n ; i ++ ){
    bool eq = true;
    int len = min( v[ i - 1 ].size() , v[ i ].size() );
    for( int j = 0 ; j < len and eq ; j ++ )
      if( ord( v[ i - 1 ][ j ] ) > ord( v[ i ][ j ] ) )
        imp();
      else if( ord( v[ i - 1 ][ j ] ) < ord( v[ i ][ j ] ) )
        eq = false;
    if( not eq ) continue;
    if( v[ i - 1 ].size() > v[ i ].size() )
      imp();
  }
}
void init(){
  n = getint();
  m = getint();
  for( int i = 0 ; i < n ; i ++ ){
    int x = getint();
    v[ i ].resize( x );
    for( int j = 0 ; j < x ; j ++ )
      v[ i ][ j ] = getint();
  }
}
void go( int l , int r , int xx ){
  //cerr << l << " " << r << " " << xx << endl;
  while( l <= r and (int)v[ l ].size() < xx + 1 ) l ++;
  if( l > r ) return;
  for( int i = l ; i <= r ; i ++ )
    if( (int)v[ i ].size() < xx + 1 )
      imp();
  for( int i = l ; i < r ; i ++ )
    if( v[ i ][ xx ] < v[ i + 1 ][ xx ] )
      g[ v[ i + 1 ][ xx ] ].push_back( v[ i ][ xx ] );
  for( int i = l ; i < r ; i ++ )
    if( v[ i ][ xx ] > v[ i + 1 ][ xx ] ){
      for( int j = l ; j <= i ; j ++ )
        cap[ v[ j ][ xx ] ] = true;
      break;
    }
  for( int il = l , ir = l ; il <= r ; il = ir ){
    while( ir <= r and v[ ir ][ xx ] == v[ il ][ xx ] ) ir ++;
    go( il , ir - 1 , xx + 1 );
  }
}
void gogo( int now ){
  cap[ now ] = true;
  for( int x : g[ now ] )
    if( not cap[ x ] )
      gogo( x );
}
void solve(){
  go( 0 , n - 1 , 0 );
  for( int i = 1 ; i <= m ; i ++ )
    if( cap[ i ] )
      gogo( i );
  recheck();
  output();
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}