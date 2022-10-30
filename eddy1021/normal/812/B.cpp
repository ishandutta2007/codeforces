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
#define N 111
void build(){

}
int n , m , lft[ N ] , rgt[ N ];
char c[ N ];
bool nd[ N ];
void init(){
  n = getint();
  m = getint();
  for( int i = n ; i ; i -- ){
    scanf( "%s" , c );
    for( int j = 1 ; j <= m ; j ++ )
      if( c[ j ] == '1' ){
        nd[ i ] = true;
        if( !lft[ i ] ) lft[ i ] = j;
        rgt[ i ] = j;
      }
  }
}
int dp[ 2 ];
void solve(){
  int atmst = n;
  while( atmst and !nd[ atmst ] ) atmst --;
  if( atmst == 0 ){
    puts( "0" );
    Bye;
  }
  if( atmst == 1 ){
    printf( "%d\n" , rgt[ 1 ] );
    Bye;
  }
  dp[ 1 ] = m + 1;
  if( nd[ 1 ] ) dp[ 0 ] = 2 * rgt[ 1 ];
  for( int i = 2 ; i < atmst ; i ++ ){
    dp[ 0 ] ++;
    dp[ 1 ] ++;
    if( !nd[ i ] ) continue;
    int nxt0 = min( dp[ 0 ] + 2 * rgt[ i ] ,
                    dp[ 1 ] + m + 1 );
    int nxt1 = min( dp[ 1 ] + 2 * ( m + 1 - lft[ i ] ) ,
                    dp[ 0 ] + m + 1 );
    dp[ 0 ] = nxt0;
    dp[ 1 ] = nxt1;
  }
  int ans = min( dp[ 0 ] + 1 + rgt[ atmst ] ,
                 dp[ 1 ] + 1 + m + 1 - lft[ atmst ] );
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