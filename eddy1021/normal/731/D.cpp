// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
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
int __ = 1 , _cs;
/*********default*********/
#define N 1010101
void build(){

}
int n , c , l[ N ];
vector< int > v[ N ];
void init(){
  scanf( "%d%d" , &n , &c );
  for( int i = 0 ; i < n ; i ++ ){
    l[ i ] = getint();
    for( int j = 0 ; j < l[ i ] ; j ++ )
      v[ i ].push_back( getint() );
  }
}
int nok[ N ];
inline void bye(){
  puts( "-1" );
  exit( 0 );
}
void gogo( int id1 , int id2 , int pos ){
  if( l[ id1 ] == pos && l[ id2 ] > pos ) return;
  if( l[ id1 ] > pos && l[ id2 ] == pos ) bye();
  if( l[ id1 ] <= pos && l[ id2 ] <= pos ) return;
  if( v[ id1 ][ pos ] == v[ id2 ][ pos ] ) return;
  if( v[ id1 ][ pos ] < v[ id2 ][ pos ] ){
    int ql = c - v[ id2 ][ pos ] + 1;
    int qr = c - v[ id1 ][ pos ] + 1;
    nok[ ql ] ++;
    nok[ qr ] --;
  }
  if( v[ id1 ][ pos ] > v[ id2 ][ pos ] ){
    int ql = c - v[ id1 ][ pos ] + 1;
    nok[ 0 ] ++; nok[ ql ] --;
    int qr = c - v[ id2 ][ pos ] + 1;
    nok[ qr ] ++; 
  }
}
void go( int ql , int qr , int p ){
  if( ql >= qr ) return;
  for( int i = ql ; i < qr ; i ++ )
    gogo( i , i + 1 , p );
  while( ql <= qr && l[ ql ] == p ) ql ++;
  for( int rl = ql , rr = ql ; rl <= qr ; rl = rr ){
    while( rr <= qr && v[ rl ][ p ] == v[ rr ][ p ] ) rr ++;
    go( rl , rr - 1 , p + 1 );
  }
}
void solve(){
  go( 0 , n - 1 , 0 );
  for( int i = 0 ; i < c ; i ++ ){
    if( i ) nok[ i ] += nok[ i - 1 ];
    if( nok[ i ] == 0 ){
      printf( "%d\n" , i );
      exit( 0 );
    }
  }
  bye();
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}