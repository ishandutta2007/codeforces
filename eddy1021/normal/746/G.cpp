// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
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
int n , t , k;
int d[ N ];
void init(){
  n = getint();
  t = getint();
  k = getint();
  for( int i = 1 ; i <= t ; i ++ )
    d[ i ] = getint();
}
int idl[ N ] , idr[ N ];
int mn[ N ] , mx[ N ];
vector< pair<int,int> > e;
void go( int dep , int req ){
  if( dep == t ){
    assert( req == d[ dep ] );
    return;
  }
  int tmn = d[ dep ] - min( d[ dep ] , d[ dep + 1 ] );
  int tmx = d[ dep ] - 1;
  for( int i = tmn ; i <= min( req , tmx ) ; i ++ )
    if( mn[ dep + 1 ] <= req - i && req - i <= mx[ dep + 1 ] ){
      int res = d[ dep ] - i;
      int lft = idl[ dep ] , rgt = lft + res - 1;
      for( int j = idl[ dep + 1 ] ; j <= idr[ dep + 1 ] ; j ++ ){
        e.push_back( { lft , j } );
        lft = min( lft + 1 , rgt );
      }
      go( dep + 1 , req - i );
      return;
    }
  puts( "-1" );
  Bye;
}
void solve(){
  int id = 1;
  d[ 0 ] = 1;
  idl[ 0 ] = idr[ 0 ] = 1;
  for( int i = 1 ; i <= t ; i ++ ){
    idl[ i ] = id + 1;
    idr[ i ] = id + d[ i ];
    id += d[ i ];
  }
  mn[ t ] = mx[ t ] = d[ t ];
  for( int i = t - 1 ; i >= 0 ; i -- ){
    mn[ i ] = d[ i ] - min( d[ i ] , d[ i + 1 ] ) + mn[ i + 1 ];
    mx[ i ] = d[ i ] - 1 + mx[ i + 1 ];
  }
  if( k < mn[ 0 ] || k > mx[ 0 ] ){
    puts( "-1" );
    Bye;
  }
  go( 0 , k );
  printf( "%d\n" , n );
  for( auto i : e )
    printf( "%d %d\n" , i.first , i.second );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}