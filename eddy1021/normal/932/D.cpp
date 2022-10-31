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
void sleep( double sec = 1021 ){
  clock_t s = clock();
  while( clock() - s < CLOCKS_PER_SEC * sec );
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 404040
#define lgN 20
void build(){

}
int p[ lgN ][ N ];
int w[ lgN ][ N ];
int rp[ lgN ][ N ];
LL rsum[ N ];
int q , cnt = 1 , wt[ N ] , dep[ N ];
LL lst;
void init(){
}
int find_prt( int now ){
  int cur = now;
  for( int i = lgN - 1 ; i >= 0 ; i -- )
    if( w[ i ][ cur ] < wt[ now ] )
      cur = p[ i ][ cur ];
  cur = p[ 0 ][ cur ];
  return wt[ cur ] >= wt[ now ] ? cur : now;
}
int query( LL qr , LL qx ){
  if( wt[ qr ] > qx ) return 0;
  int ans = 0 , cur = qr;
  for( int i = lgN - 1 ; i >= 0 ; i -- ){
    int pp = rp[ i ][ cur ];
    if( rsum[ cur ] - rsum[ pp ] <= qx ){
      qx -= rsum[ cur ] - rsum[ pp ];
      ans += dep[ cur ] - dep[ pp ];
      cur = pp;
    }
  }
  if( wt[ cur ] <= qx )
    ans ++;
  return ans;
}
void solve(){
  for( int i = 0 ; i < lgN ; i ++ ){
    p[ i ][ 1 ] = 1;
    rp[ i ][ 1 ] = 1;
  }
  q = getint();
  while( q -- ){
    int cmd = getint();
    LL pi = getint();
    LL qi = getint();
    if( cmd == 1 ){
      LL qr = pi ^ lst;
      LL qw = qi ^ lst;
      wt[ ++ cnt ] = qw;
      p[ 0 ][ cnt ] = qr;
      w[ 0 ][ cnt ] = wt[ qr ];
      for( int i = 1 ; i < lgN ; i ++ ){
        p[ i ][ cnt ] = p[ i - 1 ][ p[ i - 1 ][ cnt ] ];
        w[ i ][ cnt ] = max( w[ i - 1 ][ cnt ] ,
                             w[ i - 1 ][ p[ i - 1 ][ cnt ] ] );
      }
      int dpp = find_prt( cnt );
      if( dpp != cnt ) dep[ cnt ] = dep[ dpp ] + 1;
      rp[ 0 ][ cnt ] = dpp;
      rsum[ cnt ] += rsum[ dpp ];
      rsum[ cnt ] += wt[ cnt ];
      for( int i = 1 ; i < lgN ; i ++ )
        rp[ i ][ cnt ] = rp[ i - 1 ][ rp[ i - 1 ][ cnt ] ];
    }else{
      LL qr = pi ^ lst;
      LL qx = qi ^ lst;
      lst = query( qr , qx );
      printf( "%lld\n" , lst );
    }
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