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
#define K 22
#define N 101010
void build(){

}
//#include <bits/extc++.h>
//using namespace __gnu_pbds;
//#include <ext/pb_ds/assoc_container.hpp>
//typedef cc_hash_table<LL,LL> umap_t;
//umap_t hsh;
int n , k , a[ N ];
int cnt[ N ] , lb , rb;
LL tans;
void add( int pos ){
  tans += cnt[ a[ pos ] ];
  cnt[ a[ pos ] ] ++;
}
void sub( int pos ){
  cnt[ a[ pos ] ] --;
  tans -= cnt[ a[ pos ] ];
}
inline LL query( int ql , int qr ){
  //LL hq = (LL)ql * N + qr;
  //auto it = hsh.find( hq );
  //if( it != hsh.end() ) return it->second;
  while( lb > ql ) add( -- lb );
  while( rb < qr ) add( ++ rb );
  while( lb < ql ) sub( lb ++ );
  while( rb > qr ) sub( rb -- );
  return tans;
  //return hsh[ hq ] = tans;
}
void init(){
  n = getint();
  k = getint();
  //n = 100000;
  //k = 20;
  for( int i = 1 ; i <= n ; i ++ ){
    a[ i ] = getint();
    //a[ i ] = rand() % n + 1;
  }
}
LL dp[ 2 ][ N ];
void go( int now , int l , int r , int bl , int br ){
  if( l > r ) return;
  int mid = (l + r) >> 1;
  int bst = bl;
  int cur = now & 1 , pre = 1 - cur;
  LL ba = INF16;
  for( int i = bl ; i <= min( mid - 1 , br ) ; i ++ ){
    LL tdp = dp[ pre ][ i ] + query( i + 1 , mid );
    if( tdp < ba ){
      ba = tdp;
      bst = i;
    }
  }
  dp[ cur ][ mid ] = ba;
  go( now , l , mid - 1 , bl , bst );
  go( now , mid + 1 , r , bst , br );
}
void solve(){
  lb = rb = 1;
  add( 1 );
  for( int i = 1 ; i <= n ; i ++ )
    dp[ 1 ][ i ] = query( 1 , i );
  for( int i = 2 ; i <= k ; i ++ )
    go( i , i , n , i - 1 , n - 1 );
  printf( "%lld\n" , dp[ k & 1 ][ n ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}