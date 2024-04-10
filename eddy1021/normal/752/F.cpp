// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
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
#define N 202020
void build(){

}
int n , k;
vector< int > v[ N ];
bool tag[ N ];
void init(){
  n = getint();
  k = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int ui = getint();
    int vi = getint();
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
  for( int i = 0 ; i < k + k ; i ++ )
    tag[ getint() ] = true;
}
int cnt[ N ] , mxsz[ N ];
void go( int now , int prt ){
  if( tag[ now ] ) cnt[ now ] = 1;
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    go( son , now );
    mxsz[ now ] = max( mxsz[ now ] , cnt[ son ] );
    cnt[ now ] += cnt[ son ];
  }
}
vector<int> S[ N ];
int id[ N ];
inline int com( int id1 , int id2 ){
  if( S[ id1 ].size() < S[ id2 ].size() )
    swap( id1 , id2 );
  for( auto i : S[ id2 ] )
    S[ id1 ].push_back( i );
  S[ id2 ].clear();
  return id1;
}
void go2( int now , int prt ){
  id[ now ] = now;
  S[ now ].clear();
  if( tag[ now ] ) S[ now ].push_back( now );
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    go2( son , now );
    id[ now ] = com( id[ now ] , id[ son ] );
  }
}
void solve(){
  go( 1 , 1 );
  for( int i = 1 ; i <= n ; i ++ )
    mxsz[ i ] = max( mxsz[ i ] , cnt[ 1 ] - cnt[ i ] );
  int bst = 1;
  for( int i = 1 ; i <= n ; i ++ )
    if( mxsz[ i ] < mxsz[ bst ] )
      bst = i;
  assert( mxsz[ bst ] <= k );
  printf( "1\n%d\n" , bst );
  vector< pair<int,int> > vv;
  for( int son : v[ bst ] ){
    go2( son , bst );
    vv.push_back( { (int)S[ id[ son ] ].size() , id[ son ] } );
  }
  if( tag[ bst ] ){
    id[ bst ] = bst;
    S[ bst ].push_back( bst );
    vv.push_back( { 1 , id[ bst ] } );
  }
  sort( vv.begin() , vv.end() );
  vector<int> ret;
  for( auto i : vv )
    for( auto j : S[ i.second ] )
      ret.push_back( j );
  for( int i = 0 ; i < k ; i ++ )
    printf( "%d %d %d\n" , ret[ i ] , ret[ i + k ] , bst );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}