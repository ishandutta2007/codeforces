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
#define N 514
int n , a[ N ][ N ];
void build(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= n ; j ++ ){
      set<int> S;
      for( int ii = 1 ; ii < i ; ii ++ )
        S.insert( a[ ii ][ j ] );
      for( int jj = 1 ; jj < j ; jj ++ )
        S.insert( a[ i ][ jj ] );
      int tmp = 1;
      while( S.count( tmp ) ) tmp ++;
      a[ i ][ j ] = tmp;
    }
  for( int i = 1 ; i <= n ; i ++ , puts( "" ) )
    for( int j = 1 ; j <= n ; j ++ )
      printf( "%3d" , a[ i ][ j ] );
}
int q;
void init(){

}
int inv2 = ( mod7 + 1 ) / 2;
inline int Ar( int a0 , int an ){
  return mul( mul( add( a0 , an ) , an - a0 + 1 ) , inv2 );
}
int cal( int x , int y , int k ){
  if( x <= 0 or y <= 0 ) return 0;
  int ans = 0;
  while( x ){
    int xlb = x & (-x);
    int nxtx = x - xlb;
    int yy = y;
    while( yy ){
      int ylb = yy & (-yy);
      int nxty = yy - ylb;

      int sft = max( __lg( x & (-x) ) , __lg( yy & (-yy) ) );
      int lft = ( ( nxtx ^ nxty ) >> sft ) << sft;
      int rgt = min( lft + ( 1 << sft ) - 1 , k - 1 );
      int bns = ( ( (LL)( x - nxtx ) * (LL)( yy - nxty ) ) >> sft ) % mod7;
      if( lft <= rgt )
        ans = add( ans , mul( Ar( lft + 1 , rgt + 1 ) , bns ) );

      yy = nxty;
    }
    x = nxtx;
  }
  return ans;
}
#define x1 fsdfjklx1
#define y1 fsdfjkly1
#define x2 fsdfjklx2
#define y2 fsdfjkly2
void solve(){
#ifdef LOCAL
  q = 1;
#else
  q = getint();
#endif
  while( q -- ){
#ifdef LOCAL
    int x1 = (LL)rand() * rand() % 1000000000 + 1;
    int y1 = (LL)rand() * rand() % 1000000000 + 1;
    int x2 = (LL)rand() * rand() % 1000000000 + 1;
    int y2 = (LL)rand() * rand() % 1000000000 + 1;
    int k =  (LL)rand() * rand() % 2000000000 + 1;
    if( x1 > x2 ) swap( x1 , x2 );
    if( y1 > y2 ) swap( y1 , y2 );
#else
    int x1 = getint() - 1;
    int y1 = getint() - 1;
    int x2 = getint();
    int y2 = getint();
    int k =  getint();
#endif
    int ans = cal( x2 , y2 , k );
    ans = sub( ans , cal( x1 , y2 , k ) );
    ans = sub( ans , cal( x2 , y1 , k ) );
    ans = add( ans , cal( x1 , y1 , k ) );
    printf( "%d\n" , ans );
  }
}
int main(){
  //build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}