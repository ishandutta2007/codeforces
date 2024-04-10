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
//#include <bits/extc++.h>
//using namespace __gnu_pbds;
//#include <ext/pb_ds/assoc_container.hpp>
//typedef cc_hash_table<LL,int> umap_t;
//umap_t GCD;
int gcd( int x , int y ){
    return __gcd(x, y);
//  if( x > y ) swap( x , y );
//  LL hsh = ((LL)x << 31 ) | y;
//  auto it = GCD.find( hsh );
//  if( it != GCD.end() ) return it->second;
//  return GCD[ hsh ] = __gcd( x , y );
}
#define N 505050
int st[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
int n , a[ N ];
void build_st( int no , int l , int r ){
  if( l == r ){
    st[ no ] = a[ l ];
    return;
  }
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
  st[ no ] = gcd( st[ L( no ) ] , st[ R( no ) ] );
}
void modify( int no , int l , int r , int p , int x ){
  if( l == r ){
    st[ no ] = x;
    return;
  }
  if( p <= mid )
    modify( L( no ) , l , mid , p , x );
  else
    modify( R( no ) , mid + 1 , r , p , x );
  st[ no ] = gcd( st[ L( no ) ] , st[ R( no ) ] );
}
int til( int no , int l , int r , int ql , int qr , int g ){
  //printf( "%d %d %d %d %d %d st=%d\n" , no , l , r , ql , qr , g , st[ no ] );
  if( l == ql and r == qr ){
    if( st[ no ] % g == 0 ) return qr;
    if( l == r ) return 0;
    if( st[ L( no ) ] % g == 0 )
      return max( mid , til( R( no ) , mid + 1 , r , mid + 1 , qr , g ) );
    return til( L( no ) , l , mid , ql , mid , g );
  }
  if( qr <= mid )
    return til( L( no ) , l , mid , ql , qr , g );
  if( mid < ql )
    return til( R( no ) , mid + 1 , r , ql , qr , g );
  int lret = til( L( no ) , l , mid , ql , mid , g );
  if( lret == mid ) return max( lret , 
                                til( R( no ) , mid + 1 , r , mid + 1 , qr , g ) );
  return lret;
}
void build(){

}
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  build_st( 1 , 1 , n );
}
inline bool ok( int ql , int qr , int qx ){
  if( ql == qr ) return true;
  int ntil = max( ql - 1 ,
                  til( 1 , 1 , n , ql , n , qx ) );
  //printf( "%d %d %d %d\n" , ql , qr , qx , ntil );
  if( ntil >= qr - 1 ) return true;
  return til( 1 , 1 , n , ntil + 2 , n , qx ) >= qr;
}
void solve(){
  int q = getint(); while( q -- ){
    int cmd = getint();
    if( cmd == 2 ){
      int i = getint();
      int y = getint();
      modify( 1 , 1 , n , i , y );
    }else{
      int ql = getint();
      int qr = getint();
      int qx = getint();
      puts( ok( ql , qr , qx ) ? "YES" : "NO" );
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