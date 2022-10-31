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
#define N 301010
int p[ N ] , p2[ N ];
int n , a[ N ];
void init(){
  n = getint();
  n ++;
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = getint();
}
bool ok;
void solve(){
  vector<int> pp;
  pp = { 1 };
  int c = 1;
  for( int i = 1 ; i < n ; i ++ ){
    int l = c + 1 , r = c + a[ i ];
    for( int j = l ; j <= r ; j ++ )
      p2[ j ] = pp[ 0 ];
    //printf( "%d %d\n" , l , r );
    if( a[ i ] > 1 and pp.size() > 1u ){
      ok = true;
      p[ l ] = pp[ 0 ];
      for( int j = l + 1 ; j <= r ; j ++ )
        p[ j ] = pp[ 1 ];
      pp = { l , l + 1 };
    }else{
      for( int j = l ; j <= r ; j ++ )
        p[ j ] = pp[ min( j - l , (int)pp.size() - 1 ) ];
      if( l == r )
        pp = { l };
      else
        pp = { l , l + 1 };
    }
    c = r;
  }
  if( ok ){
    puts( "ambiguous" );
    for( int i = 1 ; i <= c ; i ++ )
      printf( "%d%c" , p[ i ] , " \n"[ i == c ] );
    for( int i = 1 ; i <= c ; i ++ )
      printf( "%d%c" , p2[ i ] , " \n"[ i == c ] );
  }else
    puts( "perfect" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}