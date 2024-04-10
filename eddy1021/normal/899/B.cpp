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
#define N 1000
int n , a[ N ];
int dy[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool okay( bool leap , int month , int dd ){
  if( leap and month == 2 ) return dd == 29;
  return dy[month] == dd;
}
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = getint();
}
bool ok(){
  for( int l = 0 ; l < 2 ; l ++ )
    for( int l2 = 0 ; l2 < 2 ; l2 ++ )
      for( int l3 = 0 ; l3 < 2 ; l3 ++ ){
        if( l + l2 + l3 > 1 ) continue;
        for( int s = 1 ; s < 13 ; s ++ ){
          bool good = true;
          int now = s , cnt = 0 , nl = l;
          for( int i = 0 ; i < n and good ; i ++ ){
            if( not okay( nl , now , a[ i ] ) )
              good = false;
            now ++;
            if( now > 12 ){
              if( cnt == 0 ) nl = l2;
              else if( cnt == 1 ) nl = l3;
              cnt ++;
              now = 1;
            }
          }
          if( good ) return true;
        }
      }
  return false;
}
void solve(){
  puts( ok() ? "YES" : "NO" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}