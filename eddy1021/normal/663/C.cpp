// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 202020
int n , m , got[ 2 ];
vector<PII> v[ N ];
void build(){

}
void init(){
  n = getint(); m = getint();
  while( m -- ){
    int x = getint();
    int y = getint();
    char clr[ 10 ];
    scanf( "%s" , clr );
    int tclr = clr[ 0 ] == 'R' ? 0 : 1;
    v[ x ].PB( MP( y , tclr ) );
    v[ y ].PB( MP( x , tclr ) );
    got[ tclr ] = 1;
  }
}
bool cc[ N ] , tag[ N ] , flag , tag2[ N ];
vector<int> hh;
void Tag( int now ){
  if( tag[ now ] ) return;
  tag[ now ] = true;
  hh.PB( now );
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ )
    Tag( v[ now ][ i ].FI );
}
bool checker;
void gogogo( int now , int clr ){
  for( size_t i = 0 ; i < v[ now ].size() && checker ; i ++ )
    if( tag2[ v[ now ][ i ].FI ] ){
      if( v[ now ][ i ].SE == clr ){
        if( cc[ now ] != cc[ v[ now ][ i ].FI ] ){
          checker = false;
          return;
        }
      }else{
        if( cc[ now ] == cc[ v[ now ][ i ].FI ] ){
          checker = false;
          return;
        }
      }
    }else{
      if( v[ now ][ i ].SE == clr ){
        tag2[ v[ now ][ i ].FI ] = true;
        cc[ v[ now ][ i ].FI ] = cc[ now ];
        gogogo( v[ now ][ i ].FI , clr );
      }else{
        tag2[ v[ now ][ i ].FI ] = true;
        cc[ v[ now ][ i ].FI ] = !cc[ now ];
        gogogo( v[ now ][ i ].FI , clr );
      }
    }
}
void gogo( int now , int clr ){
  hh.clear();
  Tag( now );
  if( (int)v[ now ].size() == 0 ) return;
  int nnn = v[ now ].back().FI;
  int ccc = v[ now ].back().SE;
  v[ now ].pop_back();
  if( ccc == clr ){
    int cnt1 = 0 , cnt2 = 0; bool okay = false;

    for( size_t i = 0 ; i < hh.size() ; i ++ )
      tag2[ hh[ i ] ] = false;
    tag2[ now ] = tag2[ nnn ] = true;
    cc[ now ] = cc[ nnn ] = false;
    checker = true;
    gogogo( now , clr );
    if( checker )
      gogogo( nnn , clr );
    if( checker ){
      okay = true;
      for( size_t i = 0 ; i < hh.size() ; i ++ )
        if( cc[ hh[ i ] ] )
          cnt1 ++;
    }

    for( size_t i = 0 ; i < hh.size() ; i ++ )
      tag2[ hh[ i ] ] = false;
    tag2[ now ] = tag2[ nnn ] = true;
    cc[ now ] = cc[ nnn ] = true;
    checker = true;
    gogogo( now , clr );
    if( checker )
      gogogo( nnn , clr );
    if( checker ){
      okay = true;
      for( size_t i = 0 ; i < hh.size() ; i ++ )
        if( cc[ hh[ i ] ] )
          cnt2 ++;
    }
    if( !okay ) flag = false;
    if( cnt1 < cnt2 ){
      for( size_t i = 0 ; i < hh.size() ; i ++ )
        tag2[ hh[ i ] ] = false;
      tag2[ now ] = tag2[ nnn ] = true;
      cc[ now ] = cc[ nnn ] = false;
      gogogo( now , clr );
      gogogo( nnn , clr );
    }
  }else{
    int cnt1 = 0 , cnt2 = 0; bool okay = false;

    for( size_t i = 0 ; i < hh.size() ; i ++ )
      tag2[ hh[ i ] ] = false;
    tag2[ now ] = tag2[ nnn ] = true;
    cc[ now ] = true;
    cc[ nnn ] = false;
    checker = true;
    gogogo( now , clr );
    if( checker )
      gogogo( nnn , clr );
    if( checker ){
      okay = true;
      for( size_t i = 0 ; i < hh.size() ; i ++ )
        if( cc[ hh[ i ] ] )
          cnt1 ++;
    }

    for( size_t i = 0 ; i < hh.size() ; i ++ )
      tag2[ hh[ i ] ] = false;
    tag2[ now ] = tag2[ nnn ] = true;
    cc[ now ] = false;
    cc[ nnn ] = true;
    checker = true;
    gogogo( now , clr );
    if( checker )
      gogogo( nnn , clr );
    if( checker ){
      okay = true;
      for( size_t i = 0 ; i < hh.size() ; i ++ )
        if( cc[ hh[ i ] ] )
          cnt2 ++;
    }
    if( !okay ) flag = false;
    if( cnt1 < cnt2 ){
      for( size_t i = 0 ; i < hh.size() ; i ++ )
        tag2[ hh[ i ] ] = false;
      tag2[ now ] = tag2[ nnn ] = true;
      cc[ now ] = true;
      cc[ nnn ] = false;
      gogogo( now , clr );
      gogogo( nnn , clr );
    }
  }
  v[ now ].PB( MP( nnn , ccc ) );
}
vector<int> fans;
bool gotfans;
void test( int clr ){
  flag = true;
  for( int i = 1 ; i <= n ; i ++ )
    tag[ i ] = false;
  for( int i = 1 ; i <= n ; i ++ )
    if( !tag[ i ] ){
      gogo( i , clr );
      if( !flag ) return;
    }
  vector<int> ans;
  for( int i = 1 ; i <= n ; i ++ )
    if( cc[ i ] )
      ans.PB( i );
  if( !gotfans || ans.size() < fans.size() ){
    gotfans = true;
    fans = ans;
  }
}
void solve(){
  if( got[ 0 ] == 0 || got[ 1 ] == 0 ){
    puts( "0" );
    exit( 0 );
  }
  test( 0 );
  test( 1 );
  if( gotfans ){
    printf( "%d\n" , (int)fans.size() );
    for( size_t i = 0 ; i < fans.size() ; i ++ )
      printf( "%d%c" , fans[ i ] , " \n"[ i + 1 == fans.size() ] );
  }else puts( "-1" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}