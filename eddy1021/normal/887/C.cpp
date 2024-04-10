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
void build(){

}
int fuck[ 25 ];
void init(){
  for( int i = 1 ; i <= 24 ; i ++ )
    fuck[ i ] = getint();
}
inline bool shit( int a0 , int a1 , int a2 , int a3 ){
  return fuck[ a0 ] == fuck[ a1 ] and
         fuck[ a0 ] == fuck[ a2 ] and
         fuck[ a0 ] == fuck[ a3 ];
}
inline bool wtf( vector<int> v1 ,
                 vector<int> v2 ){
  for( int dir = -2 ; dir <= 2 ; dir += 4 ){
    bool ok = true;
    for( int i = 0 ; i < 8 ; i += 2 )
      if( not shit( v1[ i ] , v1[ i + 1 ] ,
                    v2[ ( i + 8 + dir ) & 7 ] ,
                    v2[ ( i + 9 + dir ) & 7 ] ) ){
        ok = false;
        break;
      }
    if( ok ) return true;
  }
  return false;
}
inline bool shit_problem(){
  if( wtf( { 1 , 3 , 5 , 7 , 9 , 11 , 24 , 22 } ,
           { 2 , 4 , 6 , 8 , 10 , 12 , 23 , 21 } ) and
      shit( 13 , 14 , 15 , 16 ) and
      shit( 17 , 18 , 19 , 20 ) )
    return true;   
  if( wtf( { 5 , 6 , 17 , 18 , 21 , 22 , 13 , 14 } ,
           { 7 , 8 , 19 , 20 , 23 , 24 , 15 , 16 } ) and
      shit( 1 , 2 , 3 , 4 ) and
      shit( 9 , 10 , 11 , 12 ) )
    return true;
  if( wtf( { 4 , 3 , 14 , 16 , 9 , 10 , 19 , 17 } ,
           { 2 , 1 , 13 , 15 , 11 , 12 , 20 , 18 } ) and
      shit( 5 , 6 , 7 , 8 ) and
      shit( 21 , 22 , 23 , 24 ) )
    return true;
  return false;
}
void solve(){
  puts( shit_problem() ? "YES" : "NO" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}