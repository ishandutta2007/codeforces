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
#define N 131072
double st[ N << 1 ] , ad[ N << 1 ] , ml[ N << 1 ];
int n , q , a[ N ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void build_st( int no , int l , int r ){
  ml[ no ] = 1;
  if( l == r ){
    st[ no ] = a[ l ];
    return;
  }
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
  st[ no ] = st[ L( no ) ] + st[ R( no ) ];
}
void push( int no , int l , int r ){
  if( not equal( ml[ no ] , 1 ) ){
    for( int id : { L( no ) , R( no ) } ){
      st[ id ] *= ml[ no ];
      ml[ id ] *= ml[ no ];
      ad[ id ] *= ml[ no ];
    }
    ml[ no ] = 1;
  }
  if( not equal( ad[ no ] , 0 ) ){
    st[ L( no ) ] += (mid - l + 1) * ad[ no ];
    ad[ L( no ) ] += ad[ no ];
    st[ R( no ) ] += (r - mid) * ad[ no ];
    ad[ R( no ) ] += ad[ no ];
    ad[ no ] = 0;
  }
}
double query( int no , int l , int r , int ql , int qr ){
  if( r < ql or l > qr ) return 0;
  if( ql <= l and r <= qr ) return st[ no ];
  push( no , l , r );
  return query( L( no ) , l , mid , ql , qr ) +
         query( R( no ) , mid + 1 , r , ql , qr );
}
void multiply( int no , int l , int r , int ql , int qr , double mm ){
  if( r < ql or l > qr ) return;
  if( ql <= l and r <= qr ){
    st[ no ] *= mm;
    ml[ no ] *= mm;
    ad[ no ] *= mm;
    return;
  }
  push( no , l , r );
  multiply( L( no ) , l , mid , ql , qr , mm );
  multiply( R( no ) , mid + 1 , r , ql , qr , mm );
  st[ no ] = st[ L( no ) ] + st[ R( no ) ];
}
void addition( int no , int l , int r , int ql , int qr , double aa ){
  if( r < ql or l > qr ) return;
  if( ql <= l and r <= qr ){
    st[ no ] += (r - l + 1) * aa;
    ad[ no ] += aa;
    return;
  }
  push( no , l , r );
  addition( L( no ) , l , mid , ql , qr , aa );
  addition( R( no ) , mid + 1 , r , ql , qr , aa );
  st[ no ] = st[ L( no ) ] + st[ R( no ) ];
}
void build(){

}
void init(){
  n = getint();
  q = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  build_st( 1 , 1 , n );
}
void solve(){
  while( q -- ){
    int cmd = getint();
    if( cmd == 1 ){
      int l1 = getint();
      int r1 = getint();
      int l2 = getint();
      int r2 = getint();
      double exp1 = query( 1 , 1 , n , l1 , r1 ) / (r1 - l1 + 1);
      double exp2 = query( 1 , 1 , n , l2 , r2 ) / (r2 - l2 + 1);
      multiply( 1 , 1 , n , l1 , r1 , (double)( r1 - l1 ) / (double)( r1 - l1 + 1 ) );
      multiply( 1 , 1 , n , l2 , r2 , (double)( r2 - l2 ) / (double)( r2 - l2 + 1 ) );
      addition( 1 , 1 , n , l1 , r1 , exp2 / (double)( r1 - l1 + 1 ) );
      addition( 1 , 1 , n , l2 , r2 , exp1 / (double)( r2 - l2 + 1 ) );
    }else{
      int ql = getint();
      int qr = getint();
      printf( "%.9f\n" , query( 1 , 1 , n , ql , qr ) );
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