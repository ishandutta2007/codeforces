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
#define N 155
void build(){

}
int n , a[ N ][ 5 ];
bool solved[ 5 ];
int score( int pts , int mn ){
  return pts * ( 250 - mn ) / 250;
}
int ac[ 5 ] , cur_sc[ 5 ] , o[ 5 ];
int tot( int id ){
  int sum = 0;
  for( int i = 0 ; i < 5 ; i ++ )
    if( a[ id ][ i ] >= 0 )
      sum += score( cur_sc[ i ] , a[ id ][ i ] );
  return sum;
}
clock_t s;
void init(){
  s = clock();
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 0 ; j < 5 ; j ++ ){
      a[ i ][ j ] = getint();
      if( a[ i ][ j ] >= 0 )
        ac[ j ] ++;
    }
  for( int i = 0 ; i < 5 ; i ++ )
    solved[ i ] = ( a[ 1 ][ i ] >= 0 );
  for( int i = 0 ; i < 5 ; i ++ ){
    int bns = 6;
    for( int j = 1 ; j <= 5 ; j ++ )
      if( ac[ i ] * ( 1 << j ) > n ){
        bns = j; break;
      }
    o[ i ] = cur_sc[ i ] = bns * 500;
  }
  if( tot( 1 ) > tot( 2 ) ){
    puts( "0" );
    Bye;
  }
}
int tar[ 5 ] , ans , tac[ 5 ];
void cal(){
  //for( int i = 0 ; i < 5 ; i ++ ){
    //if( i < 2 and tar[ i ] != 1000 )
      //return;
    //if( i >= 2 and tar[ i ] != 500 )
      //return;
  //}
  for( int i = 0 ; i < 5 ; i ++ )
    tac[ i ] = ac[ i ];
  for( int ad = 1 ;  ; ad ++ ){
    if( ans != -1 and ad >= ans ) break;
    clock_t t = clock();
    if( ( t - s ) > 1.8 * CLOCKS_PER_SEC ){
      puts( "-1" );
      Bye;
    }
    bool ok = true;
    for( int j = 0 ; j < 5 ; j ++ ){
      if( tar[ j ] < o[ j ] and not solved[ j ] )
        return;
      int tot = n + ad;
      int cand = tar[ j ] / 500;
      int lb = 0 , rb = 0;
      if( cand <= 5 ){
        lb = tot / ( 1 << cand );
        while( lb * ( 1 << cand ) <= tot ) lb ++;
        rb = tot / ( 1 << ( cand - 1 ) );
        while( rb * ( 1 << ( cand - 1 ) ) > tot ) rb --;
      }else{
        lb = 0;
        rb = tot / ( 1 << 5 );
        while( rb * ( 1 << 5 ) > tot ) rb --;
      }
      lb -= tac[ j ];
      rb -= tac[ j ];
      lb = max( lb , 0 );
      if( lb > rb ){
        ok = false;
        break;
      }
      if( lb > 0 and not solved[ j ] )
        return ;
      if( lb > ad )
        ok = false;
      cur_sc[ j ] = tar[ j ];
    }
    if( not ok ) continue;
    if( tot( 1 ) > tot( 2 ) ){
      if( ans == -1 or ad < ans )
        ans = ad;
    }
    break;
  }
}
void go( int now ){
  if( now == 5 ){
    cal();
    return;
  }
  for( int ttar = 1 ; ttar <= 6 ; ttar ++ ){
    tar[ now ] = ttar * 500;
    go( now + 1 );
  }
}
void solve(){
  ans = -1;
  go( 0 );
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