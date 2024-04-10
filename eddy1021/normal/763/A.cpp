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
int n , c[ N ];
vector<int> vv[ N ];
void build(){

}
void init(){
  n = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int ui = getint();
    int vi = getint();
    vv[ ui ].push_back( vi );
    vv[ vi ].push_back( ui );
  }
  for( int i = 1 ; i <= n ; i ++ )
    c[ i ] = getint();
}
vector<int> cand;
void go( int now , int fr ){
  for( int x : vv[ now ] ){
    if( x == fr ) continue;
    if( c[ x ] == c[ now ] )
      go( x , now );
    else
      cand.push_back( x );
  }
}
void check_root( int st ){
  cand.clear();
  for( int x : vv[ st ] )
    go( x , st );
  if( cand.empty() ){
    puts( "YES" );
    printf( "%d\n" , st );
    Bye;
  }
}
void solve(){
  int cand1 = 1 , cand2 = 1;
  for( int i = 1 ; i <= n ; i ++ ){
    bool ok = false;
    for( int j : vv[ i ] )
      if( c[ i ] != c[ j ] ){
        cand1 = i;
        cand2 = j;
        ok = true;
        break;
      }
    if( ok ) break;
  }
  check_root( cand1 );
  check_root( cand2 );
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