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
#define N 303030
struct Nd{
  Nd *chd[ 2 ];
  int cnt;
  Nd(){
    cnt = 0;
    chd[ 0 ] = chd[ 1 ] = NULL;
  }
};
Nd *root;
void ins( Nd* now , int val , int bt ){
  now->cnt ++;
  if( bt < 0 ) return;
  int nbt = (val >> bt) & 1;
  if( !now->chd[ nbt ] )
    now->chd[ nbt ] = new Nd();
  ins( now->chd[ nbt ] , val , bt - 1 );
}
int bst;
void query( Nd* now , int val , int bt ){
  now->cnt --;
  if( bt < 0 ) return;
  int goal = (val >> bt) & 1;
  if( now->chd[ goal ] and now->chd[ goal ]->cnt > 0 ){
    if( goal == 1 )
      bst |= (1 << bt);
    query( now->chd[ goal ] , val , bt - 1 );
    return;
  }
  if( goal == 0 )
    bst |= (1 << bt);
  query( now->chd[ 1 - goal ] , val , bt - 1 );
}
void build(){

}
int n , a[ N ] , b[ N ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = getint();
  for( int i = 0 ; i < n ; i ++ )
    b[ i ] = getint();
}
void solve(){
  root = new Nd();
  for( int i = 0 ; i < n ; i ++ )
    ins( root , b[ i ] , 29 );
  for( int i = 0 ; i < n ; i ++ ){
    bst = 0;
    query( root , a[ i ] , 29 );
    printf( "%d%c" , a[ i ] ^ bst , " \n"[ i + 1 == n ] );
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