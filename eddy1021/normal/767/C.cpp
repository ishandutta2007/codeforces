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
#define N 1010101
void build(){

}
int n , rt , p[ N ] , t[ N ] , sum;
vector<int> v[ N ];
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    p[ i ] = getint();
    t[ i ] = getint();
    if( p[ i ] ) v[ p[ i ] ].push_back( i );
    else rt = i;
    sum += t[ i ];
  }
}
int go2( int now ){
  int tcand = -1;
  for( int son : v[ now ] ){
    int ret = go2( son );
    t[ now ] += t[ son ];
    if( ret != -1 ){
      if( tcand != -1 ){
        printf( "%d %d\n" , ret , tcand );
        Bye;
      }
      tcand = ret;
    }
  }
  if( t[ now ] == sum + sum and tcand != -1 and now != rt ){
    printf( "%d %d\n" , tcand , now );
    Bye;
  }
  if( t[ now ] == sum ) tcand = now;
  return tcand;
}
void solve(){
  if( sum % 3 ){
    puts( "-1" );
    Bye;
  }
  sum /= 3;
  go2( rt );
  puts( "-1" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}