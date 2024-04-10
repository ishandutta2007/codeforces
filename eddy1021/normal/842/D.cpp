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
#define N 303030
#define K 20
struct Trie{
  int sum , c[ 2 ];
  Trie(){
    sum = c[ 0 ] = c[ 1 ] = 0;
  }
} p[ N * K ];
int pcnt;
void go( int now , int bt , int vl ){
  if( bt < 0 ){
    p[ now ].sum ++;
    return;
  }
  int at = (vl >> bt) & 1;
  if( !p[ now ].c[ at ] )
    p[ now ].c[ at ] = ++ pcnt;
  go( p[ now ].c[ at ] , bt - 1 , vl );
  p[ now ].sum = p[ p[ now ].c[ 0 ] ].sum +
                 p[ p[ now ].c[ 1 ] ].sum;
}
int query( int now , int bt , int x , int vl ){
  if( !now ) return vl;
  for( int i = 0 ; i < 2 ; i ++ ){
    int aa = i ^ ( (x >> bt) & 1 );
    if( p[ p[ now ].c[ aa ] ].sum < (1 << bt) )
      return query( p[ now ].c[ aa ] , bt - 1 , x , vl | ((1 << bt) * i) );
  }
  assert( false );
  return 0;
}
void build(){

}
int n , m , root;
void init(){
  n = getint();
  m = getint();
  root = ++ pcnt;
  vector<int> v;
  while( n -- )
    v.push_back( getint() );
  sort( v.begin() , v.end() );
  v.resize( unique( v.begin() , v.end() ) - v.begin() );
  for( auto i : v )
    go( root , K - 1 , i );
}
void solve(){
  int x = 0;
  while( m -- ){
    x ^= getint();
    printf( "%d\n" , query( root , K - 1 , x , 0 ) );
  }
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}