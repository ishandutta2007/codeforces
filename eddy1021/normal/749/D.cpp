// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
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
#define N 202020
void build(){

}
struct Nd{
  int sum , tl , tr;
  Nd(){
    sum = tl = tr = 0;
  }
} st[ N * 50 ];
int stp;
inline int new_node(){
  return ++ stp;
}
#define mid ((l+r)>>1)
inline int Sum( int x ){
  return st[ x ].sum;
}
void modify( int now , int l , int r , int pos ){
  if( l == r ){
    st[ now ].sum ++;
    return;
  }
  if( pos <= mid ){
    if( !st[ now ].tl ) st[ now ].tl = new_node();
    modify( st[ now ].tl , l , mid , pos );
  }else{
    if( !st[ now ].tr ) st[ now ].tr = new_node();
    modify( st[ now ].tr , mid + 1 , r , pos );
  }
  st[ now ].sum = Sum( st[ now ].tl ) + Sum( st[ now ].tr );
}
int query( int now , int l , int r , int ql , int qr ){
  if( !now || qr < l || ql > r ) return 0;
  if( ql <= l && r <= qr ) return st[ now ].sum;
  return query( st[ now ].tl , l , mid , ql , qr ) +
         query( st[ now ].tr , mid + 1 , r , ql , qr );
}
int n , who[ N ] , bid[ N ] , sz[ N ];
int rt[ N ];
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    who[ i ] = getint();
    bid[ i ] = getint();
  }
  set< int > S;
  for( int i = n ; i >= 1 ; i -- ){
    S.insert( who[ i ] );
    sz[ i ] = (int)S.size();
  }
  for( int i = 1 ; i <= n ; i ++ )
    rt[ i ] = new_node();
  for( int i = 1 ; i <= n ; i ++ )
    modify( rt[ who[ i ] ] , 1 , n , i );
}
int k , v[ N ];
void solve(){
  int q = getint(); while( q -- ){
    k = getint();
    for( int i = 0 ; i < k ; i ++ )
      v[ i ] = getint();
    int ai = 0 , ans = 0;
    int bl = 1 , br = n , ba = 0;
    while( bl <= br ){
      int bmid = ( bl + br ) >> 1;
      int sum = 0;
      for( int i = 0 ; i < k ; i ++ )
        if( query( rt[ v[ i ] ] , 1 , n , bmid , n ) )
          sum ++;
      if( sz[ bmid ] - sum > 1 )
        bl = bmid + 1;
      else if( sz[ bmid ] - sum == 1 )
        ba = bmid , br = bmid - 1;
      else
        br = bmid - 1;
    }
    if( ba ){
      bl = ba; br = n; int ba2 = ba;
      while( bl <= br ){
        int bmid = ( bl + br ) >> 1;
        int sum = 0;
        for( int i = 0 ; i < k ; i ++ )
          sum += query( rt[ v[ i ] ] , 1 , n , ba , bmid );
        //printf( "  %d %d %d\n" , ba , bmid , sum );
        if( bmid - ba + 1 - sum > 0 )
          ba2 = bmid , br = bmid - 1;
        else
          bl = bmid + 1;
      }
      ai = who[ ba2 ];
      ans = bid[ ba2 ];
    }
    printf( "%d %d\n" , ai , ans );
//#ifndef ONLINE_JUDGE
    //int ai2 = 0 , ans2 = 0 , lst = 0;
    //for( int i = n ; i >= 1 ; i -- ){
      //bool bb = false;
      //for( int j = 0 ; j < k ; j ++ )
        //if( who[ i ] == v[ j ] ){
          //bb = true;
          //break;
        //}
      //if( bb ) continue;
      //if( lst != 0 && lst != who[ i ] ) break;
      //lst = who[ i ];
      //ai2 = who[ i ];
      //ans2 = bid[ i ];
    //}
      //assert( ai2 == ai && ans2 == ans );
//#endif
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