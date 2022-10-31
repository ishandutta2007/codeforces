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
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
int st[ N << 2 ] , tag[ N << 2 ];
void push( int no , int l , int r ){
  if( tag[ no ] == 0 ) return;
  st[ L( no ) ] += tag[ no ];
  st[ R( no ) ] += tag[ no ];
  tag[ L( no ) ] += tag[ no ];
  tag[ R( no ) ] += tag[ no ];
  tag[ no ] = 0;
}
void modify( int no , int l , int r , int ql , int qr , int dlt ){
  if( r < ql || l > qr ) return;
  if( ql <= l && r <= qr ){
    tag[ no ] += dlt;
    st[ no ] += dlt;
    return;
  }
  push( no , l , r );
  modify( L( no ) , l , mid , ql , qr , dlt );
  modify( R( no ) , mid + 1 , r , ql , qr , dlt );
  st[ no ] = max( st[ L( no ) ] , st[ R( no ) ] );
}
int query( int no , int l , int r ){
  if( st[ no ] <= 0 ) return -1;
  if( l == r ) return l;
  push( no , l , r );
  if( st[ R( no ) ] > 0 ) return query( R( no ) , mid + 1 , r );
  return query( L( no ) , l , mid );
}
void build(){

}
int m , vl[ N ];
void init(){
  m = getint();
}
void solve(){
  for( int i = 0 ; i < m ; i ++ ){
    int pi = getint();
    int ti = getint();
    if( ti == 0 )
      modify( 1 , 1 , m , 1 , pi , -1 );
    else{
      vl[ pi ] = getint();
      modify( 1 , 1 , m , 1 , pi , +1 );
    }
    int pos = query( 1 , 1 , m );
    printf( "%d\n" , pos == -1 ? pos : vl[ pos ] );
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