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
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
pair<int,int> operator*( const pair<int,int>& p1,
                         const pair<int,int>& p2 ){
  return { mul( p1.first , p2.first , mod7 ) ,
           mul( p1.second , p2.second , mod9 ) };
}
pair<int,int> operator+( const pair<int,int>& p1,
                         const pair<int,int>& p2 ){
  return { add( p1.first , p2.first , mod7 ) ,
           add( p1.second , p2.second , mod9 ) };
}
pair<int,int> operator-( const pair<int,int>& p1,
                         const pair<int,int>& p2 ){
  return { sub( p1.first , p2.first , mod7 ) ,
           sub( p1.second , p2.second , mod9 ) };
}
bool operator==( const pair<int,int>& p1,
                 const pair<int,int>& p2 ){
  return p1.first == p2.first and
         p1.second == p2.second;
}
#define BS 13331
#define N 101010
struct Hash{
  pair<int,int> hsh[ N ];
  pair<int,int> bs[ N ];
  int len;
  void build( char* c ){
    len = strlen( c );
    bs[ 0 ] = { 1 , 1 };
    pair<int,int> bb = { BS , BS };
    for( int i = 1 ; i <= len ; i ++ )
      bs[ i ] = bs[ i - 1 ] * bb;
    hsh[ 0 ] = { 0 , 0 };
    for( int i = 1 ; i <= len ; i ++ )
      hsh[ i ] = ( hsh[ i - 1 ] * bb ) +
        make_pair( c[ i - 1 ] , c[ i - 1 ] );
  }
  pair<int,int> hs_vl( int l , int r ){
    return hsh[ r ] - ( hsh[ l - 1 ] * bs[ r - l + 1 ] );
  }
} hs , ht;
void build(){

}
char s[ N ] , t[ N ];
int n , m , x;
void init(){
  n = getint();
  scanf( "%s" , s );
  m = getint();
  scanf( "%s" , t );
  x = getint();
  hs.build( s );
  ht.build( t );
}
int dp[ N ][ 32 ];
void solve(){
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j <= x ; j ++ ){
      dp[ i + 1 ][ j ] = max( dp[ i + 1 ][ j ] , dp[ i ][ j ] );
      if( dp[ i ][ j ] == m ){
        puts( "YES" );
        Bye;
      }
      if( j == x ) continue;
      int bl = 1 , br = min( m - dp[ i ][ j ] , n - i ) , ba = -1;
      while( bl <= br ){
        int bmid = ( bl + br ) >> 1;
        pair<int,int> hss = hs.hs_vl( i + 1 , i + bmid );
        pair<int,int> hst = ht.hs_vl( dp[ i ][ j ] + 1 , dp[ i ][ j ] + bmid );
        if( hss == hst )
          ba = bmid , bl = bmid + 1;
        else
          br = bmid - 1;
      }
      if( ba == -1 ) continue;
      dp[ i + ba ][ j + 1 ] = max( dp[ i + ba ][ j + 1 ] , dp[ i ][ j ] + ba );
    }
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 0 ; j <= x ; j ++ )
      if( dp[ i ][ j ] == m ){
        puts( "YES" );
        Bye;
      }
  puts( "NO" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}