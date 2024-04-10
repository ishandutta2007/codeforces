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
#define N 101010
void build(){

}
char s[ N ];
char t[ N ];
int fl[ N ];
int ls , lt;
int to[ N ][ 26 ];
void init(){
  scanf( "%s" , s );
  ls = strlen( s );
  scanf( "%s" , t );
  lt = strlen( t );
  fl[ 0 ] = -1;
  for( int i = 1 , pre = -1 ; i < lt ; i ++ ){
    while( pre >= 0 and t[ pre + 1 ] != t[ i ] )
      pre = fl[ pre ];
    if( t[ pre + 1 ] == t[ i ] ) pre ++;
    fl[ i ] = pre;
  }
  for( int i = 0 ; i < lt ; i ++ )
    for( int j = 0 ; j < 26 ; j ++ ){
      int ni = i - 1;
      if( t[ ni + 1 ] == j + 'a' )
        to[ i ][ j ] = ni + 2;
      else if( i == 0 )
        to[ i ][ j ] = 0;
      else
        to[ i ][ j ] = to[ fl[ ni ] + 1 ][ j ];
    }
}
int dp[ 2 ][ N ];
void solve(){
  dp[ 0 ][ 0 ] = 0;
  for( int i = 1 ; i < lt ; i ++ )
    dp[ 0 ][ i ] = -INF;
  for( int i = 1 ; i <= ls ; i ++ ){
    int now = i & 1 , pre = 1 - now;
    for( int j = 0 ; j < lt ; j ++ )
      dp[ now ][ j ] = -INF;
    if( s[ i - 1 ] == '?' ){
      for( int j = lt - 1 ; j >= 0 ; j -- ){
        if( dp[ pre ][ j ] < 0 ) continue;
        if( j )
          dp[ pre ][ fl[ j - 1 ] + 1 ] = max( dp[ pre ][ fl[ j - 1 ] + 1 ] ,
                                              dp[ pre ][ j ] );
      }
      for( int j = 0 ; j < lt ; j ++ ){
        if( dp[ pre ][ j ] < 0 ) continue;
        int nxt = j + 1;
        int bns = 0;
        if( nxt == lt ) bns ++ , nxt = fl[ nxt - 1 ] + 1;
        dp[ now ][ nxt ] = max( dp[ now ][ nxt ] ,
                                dp[ pre ][ j ] + bns );
      }
    }else{
      for( int j = 0 ; j < lt ; j ++ ){
        if( dp[ pre ][ j ] < 0 ) continue;
        int c = s[ i - 1 ] - 'a';
        int nxt = to[ j ][ c ];
        int bns = 0;
        if( nxt == lt ) bns ++ , nxt = fl[ nxt - 1 ] + 1;
        dp[ now ][ nxt ] = max( dp[ now ][ nxt ] ,
                                dp[ pre ][ j ] + bns );
      }
    }
  }
  int ans = 0;
  for( int i = 0 ; i < lt ; i ++ )
    ans = max( ans , dp[ ls & 1 ][ i ] );
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