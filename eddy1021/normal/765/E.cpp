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
int n;
vector<int> v[ N ];
void init(){
  n = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int ui = getint();
    int vi = getint();
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
}
int far , dst;
void go( int now , int prt , int curd ){
  if( curd > dst ){
    far = now;
    dst = curd;
  }
  for( int x : v[ now ] ){
    if( x == prt ) continue;
    go( x , now , curd + 1 );
  }
}
vector<int> cand;
bool go2( int now , int prt , int curd ){
  if( curd == dst ) return true;
  int mn = min( curd , dst - curd );
  for( int x : v[ now ] ){
    if( x == prt ) continue;
    if( go2( x , now , curd + 1 ) ){
      if( mn + mn + 2 >= dst )
        cand.push_back( now );
      return true;
    }
  }
  return false;
}
int ans = -1;
int gogo( int now , int prt ){
  set<int> S;
  for( int x : v[ now ] ){
    if( x == prt ) continue;
    int ret = gogo( x , now );
    if( ret == -1 ) return -1;
    S.insert( ret + 1 );
  }
  if( S.empty() ) return 0;
  if( S.size() == 2u and now == prt )
    return *S.begin() + *--S.end();
  if( S.size() > 1u )
    return -1;
  return *S.begin();
}
void test( int now ){
  int ret = gogo( now , now );
  //printf( "%d %d\n" , now , ret );
  if( ret == -1 ) return;
  while( ret % 2 == 0 ) ret >>= 1;
  if( ans == -1 or ret < ans )
    ans = ret;
}
void solve(){
  far = 1;
  for( int i = 0 ; i < 2 ; i ++ )
    go( far , far , 0 );
  go2( far , far , 0 );
  for( int x : cand )
    test( x );
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