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
#define N 101010
#define K 18
//const int inf = 1000000000;
//struct Nd{
  //int tl , tr , s;
//} p[ N * K ];
//#define mid ((l+r)>>1)
//int pcnt;
//inline int new_node(){
  //++ pcnt;
  //p[ pcnt ].tl = 
  //p[ pcnt ].tr = 
  //p[ pcnt ].s = 0;
  //return pcnt;
//}
//void modify( int now , int l , int r , int pos ){
  //p[ now ].s ++;
  //if( l == r ) return;
  //if( pos <= mid ){
    //if( !p[ now ].tl ) p[ now ].tl = new_node();
    //modify( p[ now ].tl , l , mid , pos );
  //}else{
    //if( !p[ now ].tr ) p[ now ].tr = new_node();
    //modify( p[ now ].tr , mid + 1 , r , pos );
  //}
//}
//int query( int now , int l , int r , int ql , int qr ){
  //if( !now or r < ql or l > qr or ql > qr ) return 0;
  //if( ql <= l and r <= qr ) return p[ now ].s;
  //return query( p[ now ].tl , l , mid , ql , qr ) +
         //query( p[ now ].tr , mid + 1 , r , ql , qr );
//}
void build(){

}
int n , s1 , s2 , x[ N ];
int rmin[ K ][ N ] , rmax[ K ][ N ];
inline int query_min( int l , int r ){
  int bt = __lg( r - l + 1 );
  return min( rmin[ bt ][ l ] ,
              rmin[ bt ][ r - (1 << bt) + 1 ] );
}
inline int query_max( int l , int r ){
  int bt = __lg( r - l + 1 );
  return max( rmax[ bt ][ l ] ,
              rmax[ bt ][ r - (1 << bt) + 1 ] );
}
void init(){
  n = getint();
  s1 = getint();
  s2 = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    x[ i ] = getint();
    rmin[ 0 ][ i ] = rmax[ 0 ][ i ] = x[ i ];
  }
  for( int j = 1 ; j < K ; j ++ )
    for( int i = 1 ; i + (1 << j) - 1 <= n ; i ++ ){
      rmin[ j ][ i ] = min( rmin[ j - 1 ][ i ] ,
                            rmin[ j - 1 ][ i + (1 << (j - 1)) ] );
      rmax[ j ][ i ] = max( rmax[ j - 1 ][ i ] ,
                            rmax[ j - 1 ][ i + (1 << (j - 1)) ] );
    }
}
inline bool ok( int mnx , int mxx , int tar ){
  if( abs( mnx - s2 ) <= tar and
      abs( mxx - s2 ) <= tar )
    return true;
  if( abs( mnx - s1 ) <= tar and
      abs( mxx - s1 ) <= tar )
    return true;
  return false;
}
inline bool ok2( int mnx , int mxx , int tar , int sta ){
  return abs( mnx - sta ) <= tar and
         abs( mxx - sta ) <= tar;
}
int ps[ N ];
bool okay( int tar ){
  for( int i = 0 ; i <= n ; i ++ )
    ps[ i ] = 0;
  int bl = 1 , br = n , ba = 0;
  while( bl <= br ){
    int bmid = (bl + br) >> 1;
    if( ok( query_min( 1 , bmid ) , 
            query_max( 1 , bmid ) , tar ) )
      ba = bmid , bl = bmid + 1;
    else
      br = bmid - 1;
  }
  if( ba == 0 ) return false;
  ps[ 0 ] ++; ps[ ba + 1 ] --;
  for( int i = 1 ; i <= n ; i ++ ){
    ps[ i ] += ps[ i - 1 ];
    if( ps[ i ] == 0 ) continue;
    bl = i + 1 , br = n , ba = 0;
    while( bl <= br ){
      int bmid = (bl + br) >> 1;
      if( ok2( query_min( i + 1 , bmid ) , 
               query_max( i + 1 , bmid ) , tar , x[ i ] ) )
        ba = bmid , bl = bmid + 1;
      else
        br = bmid - 1;
    }
    if( ba == 0 ) continue;
    ps[ i ] ++;
    ps[ ba + 1 ] --;
  }
  return ps[ n ] > 0;
}
void solve(){
  int bl = abs( s1 - s2 ) , br = 1e9 , ba = br;
  while( bl <= br ){
    int bmid = (bl + br) >> 1;
    if( okay( bmid ) )
      ba = bmid , br = bmid - 1;
    else
      bl = bmid + 1;
  }
  printf( "%d\n" , ba );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}