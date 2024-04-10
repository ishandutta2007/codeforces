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
#define N 200020
#define K 64
#define MAGIC 6
#define MSK 63
void build(){

}
unsigned long long bt[ 111 ][ ( N + N ) / K ];
int n;
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    bt[ getint() ][ i >> MAGIC ] |= (1LL << (i & MSK));
}
int a[ N ];
void solve(){
  int q = getint(); while( q -- ){
    int ql = getint();
    int qr = getint() + 1;
    int qa = getint();
    int qb = getint();
    if( qa == qb ) continue;
    for( ; (ql & MSK) and ql != qr ; ){
      if( bt[ qa ][ ql >> MAGIC ] & (1LL << (ql & MSK)) ){
        bt[ qa ][ ql >> MAGIC ] ^= (1LL << (ql & MSK));
        bt[ qb ][ ql >> MAGIC ] |= (1LL << (ql & MSK));
      }
      ql ++;
    }
    for( ; (qr & MSK) and ql != qr ; ){
      qr --;
      if( bt[ qa ][ qr >> MAGIC ] & (1LL << (qr & MSK)) ){
        bt[ qa ][ qr >> MAGIC ] ^= (1LL << (qr & MSK));
        bt[ qb ][ qr >> MAGIC ] |= (1LL << (qr & MSK));
      }
    }
    for( ; ql < qr ; ql += K ){
    //for( int i = (ql >> MAGIC) ; i < (qr >> MAGIC) ; i ++ ){
      bt[ qb ][ ql >> MAGIC ] |= bt[ qa ][ ql >> MAGIC ];
      bt[ qa ][ ql >> MAGIC ] = 0;
      //bt[ qb ][ i ] = bt[ qb ][ i ] | bt[ qa ][ i ];
      //bt[ qa ][ i ] = 0LL;
    }
  }
  for( int i = 1 ; i < 101 ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      if( bt[ i ][ j >> MAGIC ] & (1LL << (j & MSK)) )
        a[ j ] = i;
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%d%c" , a[ i ] , " \n"[ i == n ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}