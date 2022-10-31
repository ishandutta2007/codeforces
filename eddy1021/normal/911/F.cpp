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
int far , fd;
void go( int now , int prt , int dep ){
  if( dep > fd ){
    fd = dep;
    far = now;
  }
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    go( son , now , dep + 1 );
  }
}
LL ans;
vector< pair<int , pair<int,int> > > pv , pv2;
int fuck[ 2 ][ N ] , other;
void go3( int now , int prt , int dep ){
  if( dep == fd )
    other = now;
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    go3( son , now , dep + 1 );
  }
}
void go2( int id , int now , int prt , int dep ){
  fuck[ id ][ now ] = dep;
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    go2( id , son , now , dep + 1 );
  }
}
void solve(){
  fd = -1;
  go( 1 , 1 , 0 );
  go( far , far , 0 );
  go3( far , far , 0 );
  go2( 0 , far , far , 0 );
  go2( 1 , other , other , 0 );

  for( int i = 1 ; i <= n ; i ++ )
    if( fuck[ 0 ][ i ] + fuck[ 1 ][ i ] > fd ){
      if( fuck[ 0 ][ i ] > fuck[ 1 ][ i ] ){
        ans += fuck[ 0 ][ i ];
        pv.push_back( { fuck[ 0 ][ i ] , { far , i } } );
      }else{
        ans += fuck[ 1 ][ i ];
        pv.push_back( { fuck[ 1 ][ i ] , { other , i } } );
      }
    }
  for( int i = 1 ; i <= n ; i ++ )
    if( fuck[ 0 ][ i ] + fuck[ 1 ][ i ] == fd ){
      if( i == far ) continue;
      ans += fuck[ 0 ][ i ];
      pv2.push_back( { fuck[ 0 ][ i ] , { far , i } } );
    }
  sort( pv.begin() , pv.end() );
  reverse( pv.begin() , pv.end() );
  sort( pv2.begin() , pv2.end() );
  reverse( pv2.begin() , pv2.end() );
  for( auto i : pv2 )
    pv.push_back( i );

  printf( "%lld\n" , ans );
  for( auto i : pv )
    printf( "%d %d %d\n" , i.second.first , i.second.second , i.second.second );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}