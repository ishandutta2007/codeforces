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
#define N 77
void build(){

}
int n;
char c[ N ];
int who( char ctmp ){
  if( ctmp == 'V' ) return 0;
  if( ctmp == 'K' ) return 1;
  return 2;
}
void init(){
  scanf( "%d" , &n );
  scanf( "%s" , c );
}
int dp[ N ][ N ][ N ][ 3 ];
vector<int> v[ 3 ];
inline int Cost( int idx , int c0 , int c1 , int c2 , int me ){
  int cc[] = { c0 , c1 , c2 };
  int tcst = 0;
  for( int i = 0 ; i < 3 ; i ++ ){
    if( i == idx ) continue;
    int pos = lower_bound( v[ i ].begin() , v[ i ].end() , me ) - v[ i ].begin();
    tcst += max( 0 , cc[ i ] - pos );
  }
  //printf( "%d %d %d %d %d : %d\n" ,
          //idx , c0 , c1 , c2 , me , tcst );
  return tcst;
}
void solve(){
  for( int i = 0 ; i <= n ; i ++ )
    for( int j = 0 ; j <= n ; j ++ )
      for( int k = 0 ; k <= n ; k ++ )
        for( int t = 0 ; t < 3 ; t ++ )
          dp[ i ][ j ][ k ][ t ] = INF;
  for( int i = 0 ; i < n ; i ++ )
    v[ who( c[ i ] ) ].push_back( i );
  //for( int i = 0 ; i < 3 ; i ++ , puts( "" ) )
    //for( auto j : v[ i ] )
      //printf( "%d " , j );
  for( int i = 0 ; i < 3 ; i ++ ){
    int ni = 0 , nj = 0;
    if( i == 0 ) ni ++;
    if( i == 1 ) nj ++;
    if( v[ i ].empty() ) continue;
    dp[ 0 ][ ni ][ nj ][ i ] = 0;
  }
  for( int i = 0 ; i + 1 < n ; i ++ )
    for( int j = 0 ; j <= i + 1 ; j ++ )
      for( int k = 0 ; j + k <= i + 1 ; k ++ )
        for( int t = 0 ; t < 3 ; t ++ ){
          if( dp[ i ][ j ][ k ][ t ] == INF )
            continue;
          for( int nt = 0 ; nt < 3 ; nt ++ ){
            if( t == 0 and nt == 1 ) continue;
            int idx = 0 , nj = j , nk = k;
            if( nt == 0 ) idx = nj ++;
            else if( nt == 1 ) idx = nk ++;
            else idx = i + 1 - j - k;
            if( (int)v[ nt ].size() <= idx )
              continue;
            //printf( "%d %d\n" , nt , v[ nt ][ idx ] );
            int cst = Cost( nt , j , k , i + 1 - j - k , v[ nt ][ idx ] );
            //int cst = abs( v[ nt ][ idx ] - ( i + 1 ) );
            //printf( "%d %d %d %d -> %d %d %d %d : %d\n" ,
                    //i , j , k , t ,
                    //i + 1 , nj , nk , nt ,
                    //dp[ i ][ j ][ k ][ t ] + cst );
            dp[ i + 1 ][ nj ][ nk ][ nt ] =
              min( dp[ i + 1 ][ nj ][ nk ][ nt ] ,
                   dp[ i ][ j ][ k ][ t ] + cst );
          }
        }
  int c0 = (int)v[ 0 ].size();
  int c1 = (int)v[ 1 ].size();
  int ans = INF;
  for( int i = 0 ; i < 3 ; i ++ )
    ans = min( ans , dp[ n - 1 ][ c0 ][ c1 ][ i ] );
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