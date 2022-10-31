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
// +a -b => +2x
// +a +b => +x - b , b small better
// -a -b => +x - x , a small better
// -a +b => about -2x
// ------ +++++
#define N 131073
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
struct Nd{
  bool pn;
  LL npa , npb , pp , nn , lft , rgt , ans;
  Nd( LL vl = 0 ){
    pn = false;
    npa = -1;
    npb = -1;
    pp = -1;
    nn = -1;
    lft = rgt = vl;
    ans = abs( vl );
  }
  Nd operator+( const Nd& he ) const{
    Nd ret;
    if( pn or he.pn or ( rgt >= 0 and he.lft <= 0 ) )
      ret.pn = true;
    if( rgt < 0 and he.lft > 0 ){
      ret.npa = -rgt;
      ret.npb = he.lft;
    }else if( npa != -1 ){
      ret.npa = npa;
      ret.npb = npb;
    }else if( he.npa != -1 ){
      ret.npa = he.npa;
      ret.npb = he.npb;
    }
    if( pp != -1 ) ret.pp = pp;
    if( nn != -1 ) ret.nn = nn;
    if( he.pp != -1 and (ret.pp == -1 or he.pp < ret.pp) )
      ret.pp = he.pp;
    if( he.nn != -1 and (ret.nn == -1 or he.nn < ret.nn) )
      ret.nn = he.nn;
    if( rgt >= 0 and he.lft >= 0 ){
      if( ret.pp == -1 or he.lft < ret.pp )
        ret.pp = he.lft;
    }
    if( rgt <= 0 and he.lft <= 0 ){
      if( ret.nn == -1 or -rgt < ret.nn )
        ret.nn = -rgt;
    }
    ret.ans = ans + he.ans;
    ret.lft = lft;
    ret.rgt = he.rgt;
    return ret;
  }
} st[ N << 1 ];
void modify( int no , int l , int r , int p , LL v ){
  if( l == r ){
    st[ no ] = Nd( v );
    return;
  }
  if( p <= mid ) 
    modify( L( no ) , l , mid , p , v );
  else
    modify( R( no ) , mid + 1 , r , p , v );
  st[ no ] = st[ L( no ) ] + st[ R( no ) ];
}
Nd query( int no , int l , int r , int ql , int qr ){
  if( l == ql and r == qr ) return st[ no ];
  if( qr <= mid ) return query( L( no ) , l , mid , ql , qr );
  if( mid < ql ) return query( R( no ) , mid + 1 , r , ql , qr );
  return query( L( no ) , l , mid , ql , mid ) +
         query( R( no ) , mid + 1 , r , mid + 1 , qr );
}
void build(){

}
int n , a[ N ];
LL d[ N ];
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  for( int i = 1 ; i < n ; i ++ ){
    d[ i ] = a[ i + 1 ] - a[ i ];
    modify( 1 , 1 , n - 1 , i , d[ i ] );
  }
}
void solve(){
  int q = getint(); while( q -- ){
    int cmd = getint();
    int ql = getint();
    int qr = getint();
    int qx = getint();
    if( cmd == 1 ){
      Nd ret = query( 1 , 1 , n - 1 , ql - 1 , qr );
      LL bst = -1;
      if( ret.pn ) bst = max( bst , st[ 1 ].ans + qx + qx );
      if( ret.pp != -1 )
        bst = max( bst , st[ 1 ].ans + qx - ret.pp + abs(ret.pp - qx) );
      if( ret.nn != -1 )
        bst = max( bst , st[ 1 ].ans + qx - ret.nn + abs(ret.nn - qx) );
      if( ret.npa != -1 )
        bst = max( bst , st[ 1 ].ans - ret.npa - ret.npb
                                     + abs(ret.npa - qx) + abs(ret.npb - qx) );
      printf( "%lld\n" , bst );
// +a -b => +2x
// +a +b => +x - b , b small better
// -a -b => +x - x , a small better
// -a +b => about -2x
// ------ +++++
    }else{
      d[ ql - 1 ] += qx;
      d[ qr     ] -= qx;
      modify( 1 , 1 , n - 1 , ql - 1 , d[ ql - 1 ] );
      modify( 1 , 1 , n - 1 , qr     , d[ qr     ] );
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