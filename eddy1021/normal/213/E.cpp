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
#define N 202020
int BIT[ N ];
int lb( int x ){ return x & (-x); }
void modify_BIT( int p , int d ){
  for( int i = p ; i < N ; i += lb(i) )
    BIT[ i ] += d;
}
int query_BIT( int p ){
  int ret = 0;
  for( int i = p ; i ; i -= lb(i) )
    ret += BIT[ i ];
  return ret;
}
const int BS = 999983;
#define K 3
const int mods[ K ] = { mod7 , mod9 , 100102021 };
struct hsvl{
  int v[ K ];
  hsvl( int vv = 0 ){
    for( int i = 0 ; i < K ; i ++ )
      v[ i ] = vv;
  }
  hsvl operator+( const hsvl& he ) const{
    hsvl ret;
    for( int i = 0 ; i < K ; i ++ )
      ret.v[ i ] = add( he.v[ i ] , v[ i ] , mods[ i ] );
    return ret;
  }
  hsvl operator-( const hsvl& he ) const{
    hsvl ret;
    for( int i = 0 ; i < K ; i ++ )
      ret.v[ i ] = sub( v[ i ] , he.v[ i ] , mods[ i ] );
    return ret;
  }
  hsvl operator*( const hsvl& he ) const{
    hsvl ret;
    for( int i = 0 ; i < K ; i ++ )
      ret.v[ i ] = mul( he.v[ i ] , v[ i ] , mods[ i ] );
    return ret;
  }
  bool operator==( const hsvl& he ) const{
    for( int i = 0 ; i < K ; i ++ )
      if( v[ i ] != he.v[ i ] )
        return false;
    return true;
  }
  void print(){
    for( int i = 0 ; i < K ; i ++ )
      printf( "%d%c" , v[ i ] , " \n"[ i + 1 == K ] );
  }
};
hsvl st[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void modify( int no , int l , int r , int p , hsvl d ){
  if( l == r ){
    st[ no ] = st[ no ] + d;
    return;
  }
  if( p <= mid )
    modify( L( no ) , l , mid , p , d );
  else
    modify( R( no ) , mid + 1 , r , p , d );
  st[ no ] = st[ L( no ) ] + st[ R( no ) ];
}
hsvl query( int no , int l , int r , int ql , int qr ){
  if( r < ql or l > qr or ql > qr ) return hsvl(0);
  if( ql <= l and r <= qr ) return st[ no ];
  return query( L( no ) , l , mid , ql , qr ) +
         query( R( no ) , mid + 1 , r , ql , qr );
}
hsvl bs[ N ] , bsv;
void build(){
  bsv = hsvl( BS );
  bs[ 0 ] = hsvl( 1 );
  for( int i = 1 ; i < N ; i ++ )
    bs[ i ] = bs[ i - 1 ] * bsv;
}
int n , m , a[ N ] , b[ N ];
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ getint() ] = i;;
  for( int i = 1 ; i <= m ; i ++ )
    b[ getint() ] = i;
}
void solve(){
  //for( int i = 0 ; i <= 4 ; i ++ ){
    //printf( "%d : \n" , i );
    //bs[ i ].print();
  //}
  hsvl tar( 0 );
  for( int i = 1 ; i <= n ; i ++ )
    tar = tar + bs[ i ] * hsvl( a[ i ] );
  int ans = 0;
  hsvl cur( 0 );
  for( int i = 1 ; i <= n ; i ++ ){
    //printf( "mod %d\n" , b[ i ] );
    modify( 1 , 1 , m , b[ i ] , bs[ i ] );
    cur = cur + bs[ i ];
    modify_BIT( b[ i ] , +1 );
  }
  for( int i = 1 ; i <= n ; i ++ )
    cur = cur + query( 1 , 1 , m , b[ i ] + 1 , m );
  for( int i = n ; i <= m ; i ++ ){
    //cur.print();
    //(tar * bs[ i - n ]).print();
    if( cur == tar * bs[ i - n ] ) ans ++;
    if( i == m ) break;
    //printf( "========= %d ============\n" , i );
    {
      //cur.print();
      //printf( "que %d %d\n" , b[ i - n + 1 ] + 1 , m );
      //cur.print();
      //query( 1 , 1 , m , b[ i - n + 1 ] , m ).print();
      cur = cur - query( 1 , 1 , m , b[ i - n + 1 ] + 1 , m );
      //cur.print();
      int cc = query_BIT( b[ i - n + 1 ] );
      cur = cur - hsvl( cc ) * bs[ i - n + 1 ];
      //printf( "eliminating %d\n" , i - n + 1 );
      //cur.print();
      modify_BIT( b[ i - n + 1 ] , -1 );
      modify( 1 , 1 , m , b[ i - n + 1 ] , hsvl( 0 ) - bs[ i - n + 1 ] );
    }
    {
      modify( 1 , 1 , m , b[ i + 1 ] , bs[ i + 1 ] );
      modify_BIT( b[ i + 1 ] , +1 );
      int cc = query_BIT( b[ i + 1 ] );
      cur = cur + hsvl( cc ) * bs[ i + 1 ];
      cur = cur + query( 1 , 1 , m , b[ i + 1 ] + 1 ,  m );
      //printf( "adding %d\n" , i + 1 );
      //cur.print();
    }
  }
  printf( "%d\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}