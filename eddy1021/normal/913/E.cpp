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
#define E 0
#define F 1
#define T 2
string ans[ 3 ][ 1 << 8 ];
inline int to_int( const string& ss ){
  int ret = 0;
  for( int i = 0 ; i < 8 ; i ++ )
    ret = (ret << 1) | (ss[ i ] - '0');
  return ret;
}
#define MSK ((1 << 8) - 1)
inline int Not( int x ){ return x ^ MSK; }
inline int And( int x , int y ){ return x & y; }
inline int Or( int x , int y ){ return x | y; }
queue< pair<int,int> > Q;
vector< pair<int,int> > wt;
bool inq[ 3 ][ 1 << 8 ];
bool gt[ 3 ][ 1 << 8 ];
void Set( int id , int x , const string& cc ){
  if( ans[ id ][ x ].empty() or 
      cc.length() < ans[ id ][ x ].length() or
      ( cc.length() == ans[ id ][ x ].length() and cc < ans[ id ][ x ] ) ){
    ans[ id ][ x ] = cc;
    if( not inq[ id ][ x ] ){
      Q.push( { id , x } );
      inq[ id ][ x ] = true;
    }
    if( not gt[ id ][ x ] ){
      gt[ id ][ x ] = true;
      wt.push_back( { id , x } );
    }
  }
}
inline string to_f( int cur_type , const string& cans ){
  if( cur_type == F ) return cans;
  return "(" + cans + ")";
}
inline string to_t( int cur_type , const string& cans ){
  if( cur_type == E ) return "(" + cans + ")";
  return cans;
}
void build(){
  Set( F , to_int( "00001111" ) , "x" );
  Set( F , to_int( "00110011" ) , "y" );
  Set( F , to_int( "01010101" ) , "z" );
  while( Q.size() ){
    pair<int,int> qq = Q.front(); Q.pop();
    int type = qq.first;
    int val = qq.second;
    inq[ type ][ val ] = false;
    const string& cur = ans[ type ][ val ];
    if( type == F ){
      Set( F , Not( val ) , "!" + cur );
      Set( T , val , cur );
      Set( E , val , cur );
    }
    if( type == E )
      Set( F , val , "(" + cur + ")" );
    if( type == T )
      Set( E , val , cur );
    for( auto i : wt ){
      int his_type = i.first;
      int his_val = i.second;
      const string& his = ans[ his_type ][ his_val ];
      Set( E , Or( val , his_val ) , cur + "|" + to_t( his_type , his ) );
      Set( E , Or( his_val , val ) , his + "|" + to_t( type , cur ) );
      Set( T , And( val , his_val ) , to_t( type , cur ) + "&" + to_f( his_type , his ) );
      Set( T , And( his_val , val ) , to_t( his_type , his ) + "&" + to_f( type , cur ) );
    }
  }
  for( int j = 0 ; j < 3 ; j ++ )
    for( int i = 0 ; i < (1 << 8) ; i ++ )
      assert( gt[ j ][ i ] );
}
string ss;
void init(){
  cin >> ss;
}
void solve(){
  int id = to_int( ss );
  string bst = ans[ 0 ][ id ];
  for( int i = 1 ; i < 3 ; i ++ )
    if( ans[ i ][ id ].length() < bst.length() or
        (ans[ i ][ id ].length() == bst.length() and
         ans[ i ][ id ] < bst ) )
      bst = ans[ i ][ id ];
  printf( "%s\n" , bst.c_str() );
}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}