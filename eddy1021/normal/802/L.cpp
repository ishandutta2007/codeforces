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
#define N 101010
inline int inv( int x ){
  return mypow( x , mod7 - 2 , mod7 );
}
void build(){

}
int n;
vector< pair<int,int> > v[ N ];
void init(){
  n = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int ui = getint();
    int vi = getint();
    int ci = getint();
    v[ ui ].push_back( { vi , ci } );
    v[ vi ].push_back( { ui , ci } );
  }
}
map<int,int> e[ N ];
int c[ N ];
// \sum e[i] E[i] = c[i]
void go( int now , int prt ){
  for( auto p : v[ now ] ){
    if( p.first == prt ) continue;
    go( p.first , now );
  }
  assert( e[ now ][ now ] );
  int dv = inv( e[ now ][ now ] );
  for( auto& i : e[ now ] )
    i.second = mul( i.second , dv );
  c[ now ] = mul( c[ now ] , dv );
  for( auto p : v[ now ] ){
    int who = p.first;
    if( e[ who ].count( now ) ){
      int bns = e[ who ][ now ];
      for( auto i : e[ now ] ){
        e[ who ][ i.first ] = sub( e[ who ][ i.first ] ,
                                   mul( i.second , bns ) );
        if( e[ who ][ i.first ] == 0 )
          e[ who ].erase( i.first );
      }
      c[ who ] = sub( c[ who ] , mul( c[ now ] , bns ) );
    }
  }
}
void solve(){
  for( int i = 0 ; i < n ; i ++ ){
    int deg = (int)v[ i ].size();
    e[ i ][ i ] = 1;
    if( deg == 1 ) continue;
    int pp = inv( deg );
    for( auto p : v[ i ] ){
      e[ i ][ p.first ] = sub( 0 , pp );
      c[ i ] = add( c[ i ] , mul( pp , p.second ) );
    }
  }
  go( 0 , 0 );
  printf( "%d\n" , c[ 0 ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}