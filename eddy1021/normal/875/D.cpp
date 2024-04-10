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
#define N 202020
#define K 19
int n , a[ N ];
int rmq[ K ][ N ];
void build(){

}
inline int query( int l , int r ){
  int bt = __lg( r - l + 1 );
  return rmq[ bt ][ l ] |
         rmq[ bt ][ r - (1 << bt) + 1 ];
}
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = rmq[ 0 ][ i ] = getint();
  for( int j = 1 ; j < K ; j ++ )
    for( int i = 1 ; i + (1 << j) - 1 <= n ; i ++ )
      rmq[ j ][ i ] = rmq[ j - 1 ][ i ] |
                      rmq[ j - 1 ][ i + (1 << (j - 1)) ];
}
LL ans;
map<int,int> pre;
void solve(){
  ans = (LL)( n + 1 ) * n / 2;
  for( int i = 1 ; i <= n ; i ++ ){
    int al = i , ar = i;
    {
      int bl = 1 , br = i - 1 , ba = i;
      while( bl <= br ){
        int bmid = (bl + br) >> 1;
        if( ( query( bmid , i - 1 ) & (~a[ i ]) ) == 0 )
          ba = bmid , br = bmid - 1;
        else
          bl = bmid + 1;
      }
      al = ba;
    }
    {
      int bl = i + 1 , br = n , ba = i;
      while( bl <= br ){
        int bmid = (bl + br) >> 1;
        if( ( query( i + 1 , bmid ) & (~a[ i ]) ) == 0 )
          ba = bmid , bl = bmid + 1;
        else
          br = bmid - 1;
      }
      ar = ba;
    }
    al = max( al , pre[ a[ i ] ] + 1 );
    //cout << i << " " << al << " " << ar << endl;
    ans -= (LL)( i - al + 1 ) * (LL)( ar - i + 1 );
    pre[ a[ i ] ] = i;
  }
  printf( "%lld\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}