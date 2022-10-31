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
#define N 202020
void build(){

}
char a[ N ] , b[ N ];
int la , lb;
void init(){
  scanf( "%s" , a + 1 );
  la = strlen( a + 1 );
  scanf( "%s" , b + 1 );
  lb = strlen( b + 1 );
}
int ndl[ N ] , ndr[ N ];
void solve(){
  int ptr = 1;
  for( int i = 1 ; i <= lb ; i ++ ){
    while( ptr <= la && a[ ptr ] != b[ i ] ) ptr ++;
    ndl[ i ] = ptr;
    if( ptr <= la ) ptr ++;
  }
  ptr = la;
  for( int i = lb ; i >= 1 ; i -- ){
    while( ptr > 0 && a[ ptr ] != b[ i ] ) ptr --;
    ndr[ i ] = ptr;
    if( ptr > 0 ) ptr --;
  }
  int ans = N , al = -1 , ar = -1;
  for( int i = 1 ; i <= lb ; i ++ ){
    if( ndl[ i ] <= la ){
      if( lb - i < ans ){
        ans = lb - i;
        al = i; ar = lb + 1;
      }
    }
    if( ndr[ i ] > 0 ){
      if( i - 1 < ans ){
        ans = i - 1;
        al = 0; ar = i;
      }
    }
  }
  for( int pl = 0 , pr = 1 ; pr <= lb ; pr ++ ){
    if( ndr[ pr ] == 0 ) continue;
    while( pl + 1 < pr && ndl[ pl + 1 ] < ndr[ pr ] ) pl ++;
    int bye = pr - pl - 1;
    if( bye < ans ){
      ans = bye;
      al = pl; ar = pr;
    }
  }
  if( ans == N )
    puts( "-" );
  else{
    for( int i = 1 ; i <= al ; i ++ ) putchar( b[ i ] );
    for( int i = ar ; i <= lb ; i ++ ) putchar( b[ i ] );
    puts( "" );
  }
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}