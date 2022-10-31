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
#define N 111
void build(){

}
int n , vl[ N ][ N ] , MX , nd[ 1 << 21 ];
char c[ N ];
int sl[ N ];
inline int Cal( int vv ){
  int cc = 0 , sv = vv;
  while( vv ){
    cc ++;
    vv >>= 1;
  }
  sl[ sv ] = cc;
  return cc;
}
void init(){
  n = getint();
  scanf( "%s" , c + 1 );
  int sum = 0;
  for( int i = 1 ; ; i ++ ){
    sum += Cal( i );
    if( sum > n ) break;
    MX = i;
  }
  for( int i = 1 ; i <= n ; i ++ ){
    int tvl = 0;
    for( int j = i ; j <= n ; j ++ ){
      tvl = ( tvl << 1 ) + c[ j ] - '0';
      if( tvl > MX ) tvl = MX + 1;
      vl[ i ][ j ] = tvl;
    }
  }
  for( int i = 1 ; i < ( 1 << MX ) ; i ++ ){
    int ii = i << 1;
    int mx = 0;
    for( int j = MX ; j >= 1 ; j -- )
      if( ( ii >> j ) & 1 ){
        mx = j;
        break;
      }
    for( int j = mx ; j >= 1 ; j -- ){
      if( ( ii >> j ) & 1 ) continue;
      nd[ ii ] += sl[ j ];
    }
  }
}
typedef int Msk;
inline void Set( Msk& m , int pos ){
  m |= ( 1 << pos );
}
inline int Val( const Msk& m , int pos ){
  return ( m >> pos ) & 1;
}
int tag[ 1 << 21 ];
inline bool valid( const Msk& m ){
  if( tag[ m ] ) return tag[ m ] - 1;
  bool ze = false;
  for( int i = 1 ; i <= MX ; i ++ ){
    if( Val( m , i ) ){
      if( ze ){
        tag[ m ] = 1;
        return 0;
      }
    }else ze = true;
  }
  tag[ m ] = 2;
  return 1;
}
int dp[ N ][ 1 << 20 ];
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = i ; j <= n ; j ++ ){
      if( vl[ i ][ j ] == 0 || vl[ i ][ j ] > MX ) continue;
      Msk tmsk = 0;
      Set( tmsk , vl[ i ][ j ] );
      dp[ j ][ tmsk >> 1 ] ++;
    }
  int ans = 0;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 0 ; j < ( 1 << MX ) ; j ++ ){
      if( dp[ i ][ j ] == 0 ) continue;
      if( valid( j << 1 ) ) ans = add( ans , dp[ i ][ j ] );
      if( i + nd[ j << 1 ] > n ) continue;
      for( int ri = i + 1 ; ri <= n ; ri ++ ){
        if( vl[ i + 1 ][ ri ] > MX ) break;
        if( vl[ i + 1 ][ ri ] == 0 ) continue;
        int nmsk = j << 1;
        Set( nmsk , vl[ i + 1 ][ ri ] );
        dp[ ri ][ nmsk >> 1 ] = add( dp[ ri ][ nmsk >> 1 ] ,
                                dp[ i ][ j ] ); 
      }
    }
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