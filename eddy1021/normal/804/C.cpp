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
#define N 303030
void build(){

}
int n , mxs , m;
vector<int> v[ N ] , s[ N ];
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    int si = getint();
    mxs = max( mxs , si ); while( si -- )
      s[ i ].push_back( getint() );
  }
  for( int i = 1 ; i < n ; i ++ ){
    int ai = getint();
    int bi = getint();
    v[ ai ].push_back( bi );
    v[ bi ].push_back( ai );
  }  
}
int clr[ N ];
void go( int now , int prt ){
  set<int> gc;
  for( int ii : s[ now ] )
    if( clr[ ii ] )
      gc.insert( clr[ ii ] );
  int nclr = 1;
  for( int ii : s[ now ] ){
    if( clr[ ii ] )
      continue;
    while( gc.count( nclr ) ) nclr ++;
    clr[ ii ] = nclr;
    gc.insert( nclr );
  }
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    go( son , now );
  }
}
int id[ N ];
bool cmp( int i , int j ){
  return s[ i ].size() > s[ j ].size();
}
void solve(){
  go( 1 , 1 );
  //for( int i = 1 ; i <= n ; i ++ )
    //id[ i ] = i;
  //sort( id + 1 , id + n + 1 , cmp );
  //for( int i = 1 ; i <= n ; i ++ )
    //go( id[ i ] );
  int ans = *max_element( clr + 1 , clr + m + 1 );
  assert( ans == 0 or ans == mxs );
  printf( "%d\n" , max( 1 , ans ) );
  for( int i = 1 ; i <= m ; i ++ )
    printf( "%d%c" , max( 1 , clr[ i ] ) , " \n"[ i == m ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}