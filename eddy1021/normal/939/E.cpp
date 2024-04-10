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
#define N (1 << 20)
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
LL sum[ N ] , mx[ N ];
const LL inf = 1e9 + 10;
void build( int no , int l , int r ){
  if( l == r ){
    mx[ no ] = inf;
    sum[ no ] = inf;
    return;
  }
  build( L( no ) , l , mid );
  build( R( no ) , mid + 1 , r );
  sum[ no ] = sum[ L( no ) ] + sum[ R( no ) ];
  mx[ no ] = max( mx[ L( no ) ] , mx[ R( no ) ] );
}
void modify( int no , int l , int r , int p , LL v ){
  if( l == r ){
    sum[ no ] = mx[ no ] = v;
    return;
  }
  if( p <= mid ) modify( L( no ) , l , mid , p , v );
  else modify( R( no ) , mid + 1 , r , p , v );
  sum[ no ] = sum[ L( no ) ] + sum[ R( no ) ];
  mx[ no ] = max( mx[ L( no ) ] , mx[ R( no ) ] );
}
LL lst , psum , pcnt;
void query( int no , int l , int r ){
  if( l == r ){
    if( sum[ no ] * (pcnt + 1) < lst + psum ){
      psum += sum[ no ];
      pcnt ++;
    }
    return;
  }
  if( mx[ L( no ) ] * (pcnt + mid - l + 1 + 1) <= lst + psum + sum[ L( no ) ] ){
    psum += sum[ L( no ) ];
    pcnt += mid - l + 1;
    query( R( no ) , mid + 1 , r );
  }else{
    query( L( no ) , l , mid );
  }
}
void build(){

}
int q;
void init(){
  q = getint();
  build( 1 , 1 , q );
}
void solve(){
  int gt = 0;
  for( int _ = 0 ; _ < q ; _ ++ ){
    int cmd = getint();
    if( cmd == 1 ){
      lst = getint();
      modify( 1 , 1 , q , ++ gt , lst );
    }else{
      psum = pcnt = 0;
      query( 1 , 1 , q );
      printf( "%.12f\n" , lst - (psum + lst) * 1. / (pcnt + 1) );
    }
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