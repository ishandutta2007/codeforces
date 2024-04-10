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
#define N 111
void build(){

}
int n;
vector< pair<int,int> > v[ N ];
int uu[ N ] , vv[ N ];
double x[ N ];
void init(){
  n = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int ui = getint();
    int vi = getint();
    v[ ui ].push_back( { vi , i } );
    v[ vi ].push_back( { ui , i } );
  }
}
void go( int now , int prt , double sft ){
  while( sft > 2. - 1e-9 ) sft -= 2.;
  double per = 2. / v[ now ].size();
  int cnt = 0;
  for( auto e : v[ now ] ){
    int son = e.first;
    int eid = e.second;
    if( son == prt ) continue;
    ++ cnt;
    sft += per;
    while( sft > 2. - 1e-9 ) sft -= 2.;
    //printf( "now = %d, son = %d, sft = %.5f\n" , now , son , sft );
    if( sft < 1. ){
      uu[ eid ] = son;
      vv[ eid ] = now;
      x[ eid ] = 1. - sft;
      go( son , now , 1. + sft );
    }else{
      uu[ eid ] = now;
      vv[ eid ] = son;
      x[ eid ] = 2. - sft;
      go( son , now , sft - 1. );
    }
  }
}
void solve(){
  go( 1 , 1 , 0 );
  printf( "%d\n" , n - 1 );
  for( int i = 1 ; i < n ; i ++ )
    printf( "1 %d %d %d %.9f\n" , i , uu[ i ] , vv[ i ] , x[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}