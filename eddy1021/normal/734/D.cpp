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
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
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
int __ = 1 , _cs;
/*********default*********/
#define N 505050
map< int , int > x , y , xy , xmy;
vector< pair<int,int> > vx[ N ] , vy[ N ] , vxy[ N ] , vxmy[ N ];
int xc , yc , xyc , xmyc;
int n , ix[ N ] , iy[ N ] , type[ N ];
char c[ 9 ];
void build(){

}
void reorder(){
  for( int i = 0 ; i < xc ; i ++ )
    sort( vx[ i ].begin() , vx[ i ].end() );
  for( int i = 0 ; i < yc ; i ++ )
    sort( vy[ i ].begin() , vy[ i ].end() );
  for( int i = 0 ; i < xyc ; i ++ )
    sort( vxy[ i ].begin() , vxy[ i ].end() );
  for( int i = 0 ; i < xmyc ; i ++ )
    sort( vxmy[ i ].begin() , vxmy[ i ].end() );
}
void Add( int id , int _x , int _y ){
  if( x.count( _x ) == 0 ) x[ _x ] = xc ++;
  if( y.count( _y ) == 0 ) y[ _y ] = yc ++;
  if( xy.count( _x + _y ) == 0 ) xy[ _x + _y ] = xyc ++;
  if( xmy.count( _x - _y ) == 0 ) xmy[ _x - _y ] = xmyc ++;
  vx[ x[ _x ] ].push_back( { _y , id } );
  vy[ y[ _y ] ].push_back( { _x , id } );
  vxy[ xy[ _x + _y ] ].push_back( { _x , id } );
  vxmy[ xmy[ _x - _y ] ].push_back( { _x , id } );
}
void init(){
  scanf( "%d" , &n );
  scanf( "%d%d" , &ix[ 0 ] , &iy[ 0 ] );
  for( int i = 1 ; i <= n ; i ++ ){
    scanf( "%s%d%d" , c , &ix[ i ] , &iy[ i ] );
    if( c[ 0 ] == 'B' ) type[ i ] = 1;
    if( c[ 0 ] == 'R' ) type[ i ] = 2;
    if( c[ 0 ] == 'Q' ) type[ i ] = 3;
  }
  for( int i = 0 ; i <= n ; i ++ )
    Add( i , ix[ i ] , iy[ i ] );
  reorder();
}
bool bye( int id ){
  if( type[ id ] & 1 ){
    {
      int pid = xy[ ix[ id ] + iy[ id ] ];
      int pp = lower_bound( vxy[ pid ].begin() , vxy[ pid ].end() ,
                            make_pair( ix[ id ] , id ) ) - vxy[ pid ].begin();
      if( pp && vxy[ pid ][ pp - 1 ].second == 0 ) return true;
      if( pp + 1 < (int)vxy[ pid ].size() &&
          vxy[ pid ][ pp + 1 ].second == 0 ) return true;
    }
    {
      int pid = xmy[ ix[ id ] - iy[ id ] ];
      int pp = lower_bound( vxmy[ pid ].begin() , vxmy[ pid ].end() ,
                            make_pair( ix[ id ] , id ) ) - vxmy[ pid ].begin();
      if( pp && vxmy[ pid ][ pp - 1 ].second == 0 ) return true;
      if( pp + 1 < (int)vxmy[ pid ].size() &&
          vxmy[ pid ][ pp + 1 ].second == 0 ) return true;
    }
  }
  if( type[ id ] & 2 ){
    {
      int pid = x[ ix[ id ] ];
      int pp = lower_bound( vx[ pid ].begin() , vx[ pid ].end() ,
                            make_pair( iy[ id ] , id ) ) - vx[ pid ].begin();
      if( pp && vx[ pid ][ pp - 1 ].second == 0 ) return true;
      if( pp + 1 < (int)vx[ pid ].size() &&
          vx[ pid ][ pp + 1 ].second == 0 ) return true;
    }
    {
      int pid = y[ iy[ id ] ];
      int pp = lower_bound( vy[ pid ].begin() , vy[ pid ].end() ,
                            make_pair( ix[ id ] , id ) ) - vy[ pid ].begin();
      if( pp && vy[ pid ][ pp - 1 ].second == 0 ) return true;
      if( pp + 1 < (int)vy[ pid ].size() &&
          vy[ pid ][ pp + 1 ].second == 0 ) return true;
    }
  }
  return false;
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    if( bye( i ) ){
      puts( "YES" );
      exit( 0 );
    }
  puts( "NO" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}