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
#define N 101010
void build(){

}
char c[ N ];
int len , a[ N ];
void init(){
  scanf( "%s" , c + 2 );
  len = strlen( c + 2 ) + 2;
  for( int i = 2 ; i < len ; i ++ )
    a[ i ] = c[ i ] - '0';
}
int ans[ N ];
int cand[ 3 ] = { 0 , 4 , 7 };
void print(){
  int pp = 0;
  while( !ans[ pp ] ) pp ++;
  for( int i = pp ; i < len ; i ++ )
    printf( "%d" , ans[ i ] );
  puts( "" );
  exit(0);
}
void go2( int now , int c4 , int c7 ){
  int res = len - now;
  if( ( c4 + c7 + res ) & 1 )
    return;
  int hf = ( c4 + c7 + res ) / 2;
  if( c4 > hf or c7 > hf )
    return;
  int n4 = hf - c4;
  int n7 = hf - c7;
  while( n4 -- )
    ans[ now ++ ] = 4;
  while( n7 -- )
    ans[ now ++ ] = 7;
  print();
}
void go( int now , int c4 , int c7 , int st ){
  if( now >= len ){
    if( st and c4 == c7 )
      print();
    return;
  }
  if( st ){
    if( ( c4 + c7 + len - now ) & 1 )
      return;
    int hf = ( c4 + c7 + len - now ) / 2;
    if( c4 > hf ) return;
    if( c7 > hf ) return;
  }
  for( int i = st ; i < 3 ; i ++ ){
    if( cand[ i ] < a[ now ] )
      continue;
    ans[ now ] = cand[ i ];
    if( cand[ i ] == a[ now ] ){
      if( cand[ i ] == 4 )
        go( now + 1 , c4 + 1 , c7 , 1 );
      else if( cand[ i ] == 7 )
        go( now + 1 , c4 , c7 + 1 , 1 );
      else
        go( now + 1 , c4 , c7 , 0 );
    }else{
      if( cand[ i ] == 4 ){
        go2( now + 1 , c4 + 1 , c7 );
      }else if( cand[ i ] == 7 ){
        go2( now + 1 , c4 , c7 + 1 );
      }else
        assert( false );
    }
  }
}
void solve(){
  go( 0 , 0 , 0 , 0 );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}