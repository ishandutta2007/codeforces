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
#define N 404040
void build(){

}
int BIT[ N ] , n;
int lb( int x ){ return x & (-x); }
void modify( int x , int dlt ){
  for( int i = x ; i < N ; i += lb( i ) )
    BIT[ i ] += dlt;
}
int query( int x ){
  int ret = 0;
  for( int i = x ; i ; i -= lb( i ) )
    ret += BIT[ i ];
  return ret;
}
int a[ N ] , b[ N ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ ){
    a[ i ] = getint();
    b[ i ] = getint();
    if( a[ i ] > b[ i ] )
      swap( a[ i ] , b[ i ] );
  }
}
int cc[ N ][ 2 ];
void solve(){
  vector< pair<pair<int,int>,pair<int,int>> > vv;
  for( int i = 0 ; i < n ; i ++ ){
    vv.push_back( { { b[ i ] , a[ i ] } , { -1 , 0 } } );
    vv.push_back( { { a[ i ] + n + n , b[ i ] } , { -1 , 0 } } );
    vv.push_back( { { b[ i ] + n + n , a[ i ] + n + n } , { -1 , 0 } } );
    vv.push_back( { { b[ i ] , a[ i ] } , { i , 0 } } );
    vv.push_back( { { a[ i ] + n + n , b[ i ] } , { i , 1 } } );
  }
  sort( vv.begin() , vv.end() );
  int tmp = 0;
  for( auto j : vv ){
    if( j.second.first == -1 ){
      modify( j.first.second , 1 );
      tmp ++;
      continue;
    }
    int i = j.second.first;
    int which = j.second.second;
    cc[ i ][ which ] = tmp - query( j.first.second );
  }
  LL ans = (LL)n * ( n - 1 ) * ( n - 2 ) / 6;
  LL iii = 0 , ix = 0;
  for( int i = 0 ; i < n ; i ++ ){
    //printf( "%d %d\n" , cc[ i ][ 0 ] , cc[ i ][ 1 ] );
    iii += (LL)cc[ i ][ 0 ] * cc[ i ][ 1 ];
    LL inter = n - 1 - cc[ i ][ 0 ] - cc[ i ][ 1 ];
    ix += (LL)inter * ( cc[ i ][ 0 ] + cc[ i ][ 1 ] );
  }
  ans = ans - iii - ix / 2;
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}