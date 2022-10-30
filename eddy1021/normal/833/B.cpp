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
#define N 35353
struct Nd{
  int s;
  Nd *tl , *tr;
  Nd(){
    s = 0;
    tl = tr = NULL;
  }
};
Nd* copy( Nd* tmp ){
  Nd* ret = new Nd();
  if( tmp ){
    ret->s = tmp->s;
    ret->tl = tmp->tl;
    ret->tr = tmp->tr;
  }
  return ret;
}
int S( Nd* tn ){ return tn ? tn->s : 0; }
#define mid ((l+r)>>1)
void modify( Nd* now , int l , int r , int p , int d ){
  if( l == r ){
    now->s += d;
    return;
  }
  if( p <= mid ){
    now->tl = copy( now->tl );
    modify( now->tl , l , mid , p , d );
  }else{
    now->tr = copy( now->tr );
    modify( now->tr , mid + 1 , r , p , d );
  }
  now->s = S( now->tl ) + S( now->tr );
}
int query( Nd* now , int l , int r , int ql , int qr ){
  if( !now or r < ql or l > qr ) return 0;
  if( ql <= l and r <= qr ) return S( now );
  return query( now->tl , l , mid , ql , qr ) +
         query( now->tr , mid + 1 , r , ql , qr );
}
int n , k;
void build(){

}
int prv[ N ];
Nd* rt[ N ];
void init(){
  n = getint();
  k = getint();
  //n = 35000;
  //k = 50;
  for( int i = 1 ; i <= n ; i ++ ){
    int ai = getint();
    //int ai = i;
    //int ai = ( i + 2 ) / 3;
    //int ai = 1;
    rt[ i ] = copy( rt[ i - 1 ] );
    modify( rt[ i ] , 1 , n , i , 1 );
    if( prv[ ai ] )
      modify( rt[ i ] , 1 , n , prv[ ai ] , -1 );
    prv[ ai ] = i;
  }
}
#include <bits/extc++.h>
using namespace __gnu_pbds;
#include <ext/pb_ds/assoc_container.hpp>
typedef cc_hash_table<LL,int> umap_t;
umap_t hsh[ N ];
inline int query( int who , LL l , LL r ){
  LL vl = l * ( n + 1 ) + r;
  auto it = hsh[ who ].find( vl );
  if( it != hsh[ who ].end() ) return it->second;
  int ret = query( rt[ who ] , 1 , n , l , r );
  return hsh[ who ][ vl ] = ret;
}
#define K 52
int dp[ K ][ N ];
void go( int j , int l , int r , int pl , int pr ){
  if( l > r ) return;
  int bst = -1 , bi = -1;
  for( int i = pl ; i <= min( pr , mid - 1 ) ; i ++ ){
    int tdp = dp[ j - 1 ][ i ] +
      query( mid , i + 1 , n );
      //query( rt[ mid ] , 1 , n , i + 1 , mid );
    if( tdp > bst ){
      bst = tdp;
      bi = i;
    }
  }
  dp[ j ][ mid ] = bst;
  go( j , l , mid - 1 , pl , bi );
  go( j , mid + 1 , r , bi , pr );
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    dp[ 1 ][ i ] = S( rt[ i ] );
  for( int j = 2 ; j <= k ; j ++ )
    go( j , 1 , n , 0 , n - 1 );
  //for( int j = 2 ; j <= k ; j ++ )
    //for( int i = 1 ; i <= n ; i ++ ){
      //f[ j ][ i ] = f[ j - 1 ][ i ];
      //dp[ j ][ i ] = dp[ j - 1 ][ f[ j ][ i ] ] +
        //query( rt[ i ] , 1 , n , f[ j ][ i ] + 1 , i );
      //for( int ti = f[ j ][ i ] + 1 ; ti < i ; ti ++ ){
        //int tdp = dp[ j - 1 ][ ti ] + query( rt[ i ] , 1 , n , ti + 1 , i );
        //if( tdp > dp[ j ][ i ] ){
          //dp[ j ][ i ] = tdp;
          //f[ j ][ i ] = ti;
        //}
      //}
    //}
  printf( "%d\n" , dp[ k ][ n ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}