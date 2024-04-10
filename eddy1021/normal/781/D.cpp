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
#define N 514
#define lgK 60
typedef unsigned long long ULL;
void build(){

}
ULL  ok[ lgK ][ N ][ 9 ][ 2 ];
ULL vok[ lgK ][ N ][ 9 ][ 2 ];
int n , m;
void init(){
  n = getint();
  m = getint(); while( m -- ){
    int ui = getint();
    int vi = getint();
    int ti = getint();
     ok[ 0 ][ ui ][ vi / 64 ][ ti ] |= 1llu << ( vi & 63 );
    vok[ 0 ][ vi ][ ui / 64 ][ ti ] |= 1llu << ( ui & 63 );
  }
}
inline int highbit( LL x ){
  int ret = 0;
  if( x & 0xFFFFFFFF00000000LL ) ret += 32 , x >>= 32;
  if( x & 0x00000000FFFF0000LL ) ret += 16 , x >>= 16;
  if( x & 0x000000000000FF00LL ) ret +=  8 , x >>=  8;
  if( x & 0x00000000000000F0LL ) ret +=  4 , x >>=  4;
  if( x & 0x000000000000000CLL ) ret +=  2 , x >>=  2;
  if( x & 0x0000000000000002LL ) ret +=  1 , x >>=  1;
  return ret;
}
set< pair<int,LL> > good[ 2 ];
set< pair<int,LL> > bad[ 2 ];
bool isok( int bt , int st , int to , int tp ){
  if( ( ok[ bt ][ st ][ to / 64 ][ tp ] >> ( to & 63 ) ) & 1llu )
    return true;
  return false;
}
bool okay( int now , LL dst , int tp ){
  if( dst == 0 ) return true;
  if( good[ tp ].count( { now , dst } ) ) return true;
  if( bad[ tp ].count( { now , dst } ) ) return false;
  int hb = highbit( dst );
  bool okk = false;
  for( int i = 1 ; i <= n ; i ++ )
    if( isok( hb , now , i , tp ) ){
      if( okay( i , dst - ( 1ll << hb ) , 1 - tp ) ){
        okk = true;
        break;
      }
    }
  if( okk ){
    good[ tp ].insert( { now , dst } );
    return true;
  }else{
    bad[ tp ].insert( { now , dst } );
    return false;
  }
}
void solve(){
  for( int lg = 1 ; lg < lgK ; lg ++ ){
    for( int i = 1 ; i <= n ; i ++ )
      for( int j = 1 ; j <= n ; j ++ )
        for( int t = 0 ; t < 2 ; t ++ ){
          bool tok = false;
          for( int k = 0 ; k <= n / 64 ; k ++ ){
            ULL ret = ok[ lg - 1 ][ i ][ k ][ t ] &
                     vok[ lg - 1 ][ j ][ k ][ 1 - t ];
            if( ret > 0 ){
              tok = true;
              break;
            }
          }
          if( tok ){
             ok[ lg ][ i ][ j / 64 ][ t ] |= 1llu << ( j & 63 );
            vok[ lg ][ j ][ i / 64 ][ t ] |= 1llu << ( i & 63 );
          }
        }
  }
  LL bl = 0 , br = 1000000000000000001LL , ba = 0;
  while( bl <= br ){
    LL mid = ( bl + br ) >> 1;
    if( okay( 1 , mid , 0 ) )
      ba = mid , bl = mid + 1;
    else br = mid - 1;
  }
  if( ba > 1000000000000000000LL )
    puts( "-1" );
  else
    printf( "%lld\n" , ba );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}