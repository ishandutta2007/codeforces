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
#define N 202020
int n , q , BIT[ N ];
int lb( int x ){ return x & (-x); }
void modify( int x ){
  for( int i = x ; i <= n ; i += lb( i ) )
    BIT[ i ] ++;
}
int query( int x ){
  int ret = 0;
  for( int i = x ; i ; i -= lb( i ) )
    ret += BIT[ i ];
  return ret;
}
vector< pair< pair<int,int> , pair< pair<int,int> , int > > > qry[ N ];
int p[ N ];
int l[ N ] , r[ N ] , d[ N ] , u[ N ];
void init(){
  n = getint();
  q = getint();
  for( int i = 1 ; i <= n ; i ++ )
    p[ i ] = getint();
  for( int i = 0 ; i < q ; i ++ ){
    l[ i ] = getint();
    d[ i ] = getint();
    r[ i ] = getint();
    u[ i ] = getint();
    qry[ l[ i ] - 1 ].push_back( { { i , 0 } , { { 1 , d[ i ] - 1 } , +1 } } );
    qry[ l[ i ] - 1 ].push_back( { { i , 1 } , { { d[ i ] , u[ i ] } , +1 } } );
    qry[ l[ i ] - 1 ].push_back( { { i , 2 } , { { u[ i ] + 1 , n } , +1 } } );

    qry[ l[ i ] - 1 ].push_back( { { i , 3 } , { { 1 , d[ i ] - 1 } , -1 } } );
    qry[ l[ i ] - 1 ].push_back( { { i , 4 } , { { u[ i ] + 1 , n } , -1 } } );
    qry[ r[ i ] - 0 ].push_back( { { i , 3 } , { { 1 , d[ i ] - 1 } , +1 } } );
    qry[ r[ i ] - 0 ].push_back( { { i , 4 } , { { u[ i ] + 1 , n } , +1 } } );

    qry[ r[ i ] - 0 ].push_back( { { i , 5 } , { { 1 , d[ i ] - 1 } , -1 } } );
    qry[ r[ i ] - 0 ].push_back( { { i , 6 } , { { d[ i ] , u[ i ] } , -1 } } );
    qry[ r[ i ] - 0 ].push_back( { { i , 7 } , { { u[ i ] + 1 , n } , -1 } } );
    qry[ n ].push_back( { { i , 5 } , { { 1 , d[ i ] - 1 } , +1 } } );
    qry[ n ].push_back( { { i , 6 } , { { d[ i ] , u[ i ] } , +1 } } );
    qry[ n ].push_back( { { i , 7 } , { { u[ i ] + 1 , n } , +1 } } );
  }
}
LL c[ N ][ 9 ];
LL C2( LL x ){
  return x * ( x - 1 ) / 2;
}
LL cal( int id ){
  LL ret = 0;
  for( int i = 0 ; i < 8 ; i ++ )
    ret += C2( c[ id ][ i ] );
  for( int i = 0 ; i < 8 ; i ++ )
    for( int j = i + 1 ; j < 8 ; j ++ ){
      if( i == 0 and j == 4 ) continue;
      if( i == 0 and j >= 6 ) continue;
      if( i == 1 and j > 2 ) break;
      if( i == 2 and j != 4 and j != 7 ) continue;
      if( i == 3 and j != 5 ) continue;
      if( i == 4 and j != 7 ) continue;
      ret += c[ id ][ i ] * c[ id ][ j ];
    }
  return ret;
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ ){
    modify( p[ i ] );
    for( auto j : qry[ i ] ){
      int id = j.first.first;
      int at = j.first.second;
      int lb = j.second.first.first;
      int rb = j.second.first.second;
      int tms = j.second.second;
      if( lb > rb ) continue;
      int vl = query( rb ) - query( lb - 1 );
      c[ id ][ at ] += vl * tms;
    }
  }
  LL tot = (LL)n * ( n - 1 ) / 2;
  for( int i = 0 ; i < q ; i ++ )
    printf( "%lld\n" , tot - cal( i ) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}