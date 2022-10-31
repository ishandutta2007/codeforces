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
#define N 202020
void build(){

}
int n , m , k;
vector<int> v[ N ];
void init(){
  n = getint();
  m = getint();
  k = getint();
  while( m -- ){
    int ui = getint();
    int vi = getint();
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
}
vector<int> vv;
bool vst[ N ];
void go( int now ){
  for( int i : v[ now ] ){
    if( vst[ i ] ) continue;
    vv.push_back( i );
    vst[ i ] = true;
    go( i );
    vv.push_back( now );
  }
}
void solve(){
  vv.push_back( 1 );
  vst[ 1 ] = true;
  go( 1 );
  int per = ( n + n ) / k;
  if( per * k < n + n ) per ++;
  size_t iter = 0;
  for( int i = 0 ; i < k ; i ++ ){
    vector<int> tans;
    int tper = 0;
    while( iter < vv.size() and tper < per ){
      tans.push_back( vv[ iter ++ ] );
      tper ++;
    }
    if( tans.empty() ) tans.push_back( 1 );
    printf( "%d " , (int)tans.size() );
    for( size_t j = 0 ; j < tans.size() ; j ++ )
      printf( "%d%c" , tans[ j ] , " \n"[ j + 1 == tans.size() ] );
  }
  assert( iter >= vv.size() );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}