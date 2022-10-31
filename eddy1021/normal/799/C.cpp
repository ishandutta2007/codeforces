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
#define N 101010
void build(){

}
int n , c[ 2 ] , b[ N ] , p[ N ] , t[ N ];
char cc[ 9 ];
vector< pair<int,int> > v[ 2 ];
void init(){
  n = getint();
  c[ 0 ] = getint();
  c[ 1 ] = getint();
  for( int i = 0 ; i < n ; i ++ ){
    b[ i ] = getint();
    p[ i ] = getint();
    scanf( "%s" , cc );
    t[ i ] = ( cc[ 0 ] == 'C' ? 0 : 1 );
    v[ t[ i ] ].push_back( { p[ i ] , b[ i ] } );
  }
  for( int i = 0 ; i < 2 ; i ++ )
    sort( v[ i ].begin() , v[ i ].end() );
}
int cal( const vector< pair<int,int> >& vv , int bud ){
  if( (int)vv.size() < 2 ) return 0;
  int bst = 0;
  multiset<int> pos;
  int ptr = 0;
  for( int i = (int)vv.size() - 1 ; i >= 0 ; i -- ){
    while( ptr < (int)vv.size() and vv[ ptr ].first + vv[ i ].first <= bud ){
      pos.insert( vv[ ptr ].second );
      ptr ++;
    }
    if( ptr > i ) pos.erase( pos.find( vv[ i ].second ) );
    if( pos.size() )
      bst = max( bst , ( *--pos.end() ) + vv[ i ].second );
    if( ptr > i ) pos.insert( vv[ i ].second );
  }
  return bst;
}
int pmx[ N ];
void solve(){
  int ans = 0;
  for( int i = 0 ; i < 2 ; i ++ )
    ans = max( ans , cal( v[ i ] , c[ i ] ) );
  int bst[ 2 ] = { -1 , -1 };
  for( int i = 0 ; i < 2 ; i ++ )
    for( auto j : v[ i ] )
      if( j.first <= c[ i ] )
        bst[ i ] = max( bst[ i ] , j.second );
  if( bst[ 0 ] != -1 and bst[ 1 ] != -1 )
    ans = max( ans , bst[ 0 ] + bst[ 1 ] );
  printf( "%d\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}