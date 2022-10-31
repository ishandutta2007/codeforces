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
struct Nd{
  int cnt , lc , rc;
  Nd(){
    cnt = lc = rc = 0;
  }
} st[ N * 40 ];
int tid;
int copy( int id ){
  ++ tid;
  st[ tid ] = st[ id ];
  return tid;
}
#define mid ((l+r)>>1)
inline int Cnt( int no ){
  return st[ no ].cnt;
}
void modify( int no , int l , int r , int p , int d ){
  if( l == r ){
    st[ no ].cnt += d;
    return;
  }
  if( p <= mid ){
    st[ no ].lc = copy( st[ no ].lc );
    modify( st[ no ].lc , l , mid , p , d );
  }else{
    st[ no ].rc = copy( st[ no ].rc );
    modify( st[ no ].rc , mid + 1 , r , p , d );
  }
  st[ no ].cnt = Cnt( st[ no ].lc ) + Cnt( st[ no ].rc );
}
int query( int no , int l , int r , int buf ){
  if( buf > Cnt( no ) ) return 0;
  if( no == 0 or l == r ) return l;
  int rclr = Cnt( st[ no ].rc );
  if( rclr >= buf ) return query( st[ no ].rc , mid + 1 , r , buf );
  return query( st[ no ].lc , l , mid , buf - rclr );
}
void build(){

}
int n , a[ N ] , rn;
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  rn = 1;
  for( int i = 2 ; i <= n ; i ++ ){
    if( a[ i ] == a[ i - 1 ] ) continue;
    a[ ++ rn ] = a[ i ];
  }
}
int rt[ N ] , pre[ N ];
int ans[ N ];
void solve(){
  for( int i = 1 ; i <= rn ; i ++ ){
    rt[ i ] = copy( rt[ i - 1 ] );
    if( pre[ a[ i ] ] )
      modify( rt[ i ] , 1 , rn , pre[ a[ i ] ] , -1 );
    modify( rt[ i ] , 1 , rn , i , +1 );
    pre[ a[ i ] ] = i;
  }
  for( int i = 2 ; i <= n ; i ++ ) ans[ i ] = 1;
  ans[ 1 ] = rn;
  for( int i = 2 ; i <= rn ; i ++ ){
    int now = rn , cc = 0;
    while( now > 0 ){
      cc ++;
      now = query( rt[ now ] , 1 , rn , i + 1 );
    }
    ans[ i ] = cc;
  }
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%d%c" , ans[ i ] , " \n"[ i == n ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}