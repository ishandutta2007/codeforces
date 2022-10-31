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
LL bi , li , ri;
void init(){
  bi = getint();
  li = getint();
  ri = getint();
}
#define N 100
int bt[ N ] , bc;
LL sv[ 11 ][ N ][ 1 << 11 ];
bool gt[ 11 ][ N ][ 1 << 11 ];
LL go( int now , int msk , bool bnd , bool st ){
  if( st and not bnd and gt[ bi ][ now ][ msk ] )
    return sv[ bi ][ now ][ msk ];
  if( now < 0 ){
    if( not st ) return 0;
    return msk == 0 ? 1 : 0;
  }
  LL ret = 0;
  if( not st ){
    if( now + 1 == bc ){
      ret += go( now - 1 , 0 , false , false );
      for( int i = 1 ; i <= bt[ now ] ; i ++ )
        ret += go( now - 1 , msk ^ (1 << i) , i == bt[ now ] , true );
    }else{
      ret += go( now - 1 , 0 , false , false );
      for( int i = 1 ; i < bi ; i ++ )
        ret += go( now - 1 , msk ^ (1 << i) , false , true );
    }
  }else if( not bnd ){
    for( int i = 0 ; i < bi ; i ++ )
      ret += go( now - 1 , msk ^ (1 << i) , false , true );
  }else{
    for( int i = 0 ; i <= bt[ now ] ; i ++ )
      ret += go( now - 1 , msk ^ (1 << i) , i == bt[ now ] , true );
  }
  if( st and not bnd ){
    gt[ bi ][ now ][ msk ] = true;
    sv[ bi ][ now ][ msk ] = ret;
  }
  return ret;
}
LL cal( LL vv ){
  if( vv == 0 ) return 0;
  bc = 0;
  while( vv ){
    bt[ bc ++ ] = vv % bi;
    vv /= bi;
  }
  return go( bc - 1 , 0 , false , false );
}
void solve(){
  LL ans = cal( ri ) - cal( li - 1 );
  printf( "%lld\n" , ans );
}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}