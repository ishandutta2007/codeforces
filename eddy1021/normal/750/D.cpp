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
#define N 1021
#define M 500
bool gg[ N ][ N ];
int n , t[ N ];
int dx[]={0, 1, 1, 1, 0, -1, -1, -1};
int dy[]={1, 1, 0, -1, -1, -1, 0, 1};
inline int Lft( int x ){
  return ( x + 7 ) % 8;
}
inline int Rgt( int x ){
  return ( x + 1 ) % 8;
}
void build(){

}
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    t[ i ] = getint();
}
vector< pair< PII , int > > v[ 100 ];
void solve(){
  v[ 0 ].push_back( { { M , M } , 0 } );
  for( int i = 0 ; i < n ; i ++ ){
    sort( v[ i ].begin() , v[ i ].end() );
    v[ i ].resize( unique( v[ i ].begin() , v[ i ].end() ) - v[ i ].begin() );
    for( auto j : v[ i ] ){
      int nx = j.first.first;
      int ny = j.first.second;
      int dir = j.second;
      for( int k = 0 ; k < t[ i ] ; k ++ ){
        gg[ nx ][ ny ] = true;
        if( k + 1 < t[ i ] ){
          nx += dx[ dir ];
          ny += dy[ dir ];
        }
      }
      {
        int lft = Lft( dir );
        int nxtx = nx + dx[ lft ];
        int nxty = ny + dy[ lft ];
        v[ i + 1 ].push_back( { { nxtx , nxty } , lft } );
      }
      {
        int rgt = Rgt( dir );
        int nxtx = nx + dx[ rgt ];
        int nxty = ny + dy[ rgt ];
        v[ i + 1 ].push_back( { { nxtx , nxty } , rgt } );
      }
    }
  }
  int ans = 0;
  for( int i = 0 ; i < N ; i ++ )
    for( int j = 0 ; j < N ; j ++ )
      if( gg[ i ][ j ] )
        ans ++;
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