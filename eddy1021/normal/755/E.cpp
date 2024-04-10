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
void build(){

}
int n , k;
void init(){
  n = getint();
  k = getint();
}
void solve(){
  if( n <= 3 || k > 3 || k == 1 ){
    puts( "-1" );
    Bye;
  }
  if( n == 4 ){
    if( k == 3 ){
      printf( "3\n" );
      printf( "1 2\n" );
      printf( "2 3\n" );
      printf( "3 4\n" );
    }else
      puts( "-1" );
    Bye;
  }
  if( k == 2 ){
    printf( "%d\n" , n - 1 );
    for( int i = 1 ; i + 1 <= n ; i ++ )
      printf( "%d %d\n" , i , i + 1 );
    Bye;
  }
  if( k == 3 ){
    vector< pair<int,int> > e;
    e.push_back( { 1 , 2 } );
    e.push_back( { 2 , 3 } );
    for( int i = 3 ; i <= n ; i ++ )
      for( int j = i + 1 ; j <= n ; j ++ )
        e.push_back( { i , j } );
    printf( "%d\n" , (int)e.size() );
    for( auto i : e )
      printf( "%d %d\n" , i.first , i.second );
    Bye;
  }
  puts( "-1" );
  Bye;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}