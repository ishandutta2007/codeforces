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
void build(){

}
#define N 101010
int n , m;
vector<int> v[ N ];
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= n ; i ++ )
    v[ i ].clear();
  while( m -- ){
    int ui = getint();
    int vi = getint();
    v[ ui ].push_back( vi );
    v[ vi ].push_back( ui );
  }
}
LL ans[ N ];
bool vst[ N ] , tag;
vector<int> vv;
void go( int now , int prt ){
  vst[ now ] = true;
  vv.push_back( now );
  for( auto i : v[ now ] ){
    if( i == prt ) continue;
    if( not vst[ i ] )
      go( i , now );
    else
      tag = true;
  }
}
void yes(){
  puts( "YES" );
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%lld%c" , ans[ i ] , " \n"[ i == n ] );
}
bool ok;
int stk[ N ];
void gogo( int now , int dep ){
  vst[ now ] = true;
  vv.push_back( now );
  stk[ dep ] = now;
  if( dep and (int)v[ now ].size() > 2 ){
    for( int i : v[ stk[ 0 ] ] )
      ans[ i ] = 1;
    for( int i : v[ now ] )
      ans[ i ] = 1;
    for( int i = 0 ; i <= dep ; i ++ )
      ans[ stk[ i ] ] = 2;
    ok = true;
    yes();
    return;
  }
  for( auto i : v[ now ] ){
    if( vst[ i ] ) continue;
    gogo( i , dep + 1 );
    if( ok ) return;
  }
}
LL bal;
LL MX = 6 * 5 * 4 * 3 * 2 * 1;
LL gogo2( int now , int prt , int dep ){
  bool leaf = true;
  LL ret = 0;
  ans[ now ] = 0;
  if( dep < 5 ){
    for( auto son : v[ now ] ){
      if( son == prt ) continue;
      ret = gogo2( son , now , dep + 1 );
      ans[ now ] = max( (LL)ans[ now ] , ans[ son ] + ret );
      leaf = false;
    }
    for( auto son : v[ now ] ){
      if( son == prt ) continue;
      bal += ans[ now ] * ans[ son ];
    }
  }
  if( leaf ){
    LL per = MX / ( dep + 1 );
    ans[ now ] = per;
    bal -= ans[ now ] * ans[ now ];
    return per;
  }
  bal -= ans[ now ] * ans[ now ];
  return ret;
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ ){
    ans[ i ] = 0;
    vst[ i ] = false;
  }
  for( int i = 1 ; i <= n ; i ++ ){
    if( vst[ i ] ) continue;
    vv.clear();
    tag = false;
    go( i , i );
    if( tag ){
      for( auto j : vv )
        ans[ j ] = 1;
      yes();
      return;
    }
  }
  for( int i = 1 ; i <= n ; i ++ )
    if( (int)v[ i ].size() > 3 ){
      ans[ i ] = 2;
      for( auto j : v[ i ] )
        ans[ j ] = 1;
      yes();
      return;
    }
  for( int i = 1 ; i <= n ; i ++ )
    vst[ i ] = false;
  ok = false;
  for( int i = 1 ; i <= n ; i ++ ){
    if( vst[ i ] ) continue;
    if( (int)v[ i ].size() > 2 ){
      vv.clear();
      gogo( i , 0 );
      if( ok ) return;
      bal = 0;
      gogo2( i , i , 0 );
      if( bal >= 0 ){
        yes();
        return;
      }
      for( auto j : vv )
        ans[ j ] = 0;
    }
  }
  puts( "NO" );
}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}