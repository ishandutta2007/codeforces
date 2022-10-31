// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
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
int __ = 1 , _cs;
/*********default*********/
#define N 202020
struct DisjointSet{
  // save() is like recursive
  // undo() is like return
  int n, fa[ N ], sz[ N ];
  vector< pair<int*,int> > h;
  vector<int> sp;
  void init( int tn ){
    n=tn;
    for( int i = 1 ; i <= n ; i ++ ){
      fa[ i ]=i;
      sz[ i ]=1;
    }
    sp.clear(); h.clear();
  }
  void assign( int *k, int v ){
    h.PB( {k, *k} );
    *k = v;
  }
  void save(){ sp.PB(SZ(h)); }
  void undo(){
    assert(!sp.empty());
    int last=sp.back(); sp.pop_back();
    while( SZ(h)!=last ){
      auto x=h.back(); h.pop_back();
      *x.first = x.second;
    }
  }
  int f( int x ){
    while( fa[ x ] != x ) x = fa[ x ];
    return x;
  }
  void uni( int x , int y ){
    x = f( x ); y = f( y );
    if( x == y ) return;
    if( sz[ x ] < sz[ y ] ) swap( x, y );
    assign( &sz[ x ] , sz[ x ] + sz[ y ] );
    assign( &fa[ y ] , x);
  }
} djs;
void build(){

}
int n , m , w[ N ] , c[ N ] , a[ N ] , b[ N ] , k;
void init(){
  scanf( "%d%d" , &n , &m );
  for( int i = 1 ; i <= m ; i ++ )
    scanf( "%d" , &w[ i ] );
  for( int i = 1 ; i <= m ; i ++ )
    scanf( "%d" , &c[ i ] );
  for( int i = 1 ; i <= m ; i ++ )
    scanf( "%d%d" , &a[ i ] , &b[ i ] );
  scanf( "%d" , &k );
}
vector< pair< int , int > > e;
void yo( int who ){
  djs.init( n );
  LL ans = w[ who ] - k / c[ who ];
  djs.uni( a[ who ] , b[ who ] );
  vector< pair< int , int > > va;
  va.push_back( { who , ans } );
  for( auto i : e ){
    if( djs.f( a[ i.second ] ) ==
        djs.f( b[ i.second ] ) )
      continue;
    djs.uni( a[ i.second ] , b[ i.second ] );
    ans += i.first;
    va.push_back( { i.second , i.first } );
  }
  printf( "%lld\n" , ans );
  for( auto i : va )
    printf( "%d %d\n" , i.first , i.second );
}
vector< PII > tr[ N ];
#define K 20
int dep[ N ] , pp[ N ][ K ] , cc[ N ][ K ];
int mxcst( int ai , int bi ){
  if( dep[ ai ] > dep[ bi ] ) swap( ai , bi );
  int ccccc = 0 , dlt = dep[ bi ] - dep[ ai ];
  for( int i = 0 ; i < K ; i ++ )
    if( ( dlt >> i ) & 1 ){
      ccccc = max( ccccc , cc[ bi ][ i ] );
      bi = pp[ bi ][ i ];
    }
  if( ai == bi ) return ccccc;
  for( int i = K - 1 ; i >= 0 ; i -- )
    if( pp[ ai ][ i ] != pp[ bi ][ i ] ){
      ccccc = max( ccccc , cc[ ai ][ i ] );
      ccccc = max( ccccc , cc[ bi ][ i ] );
      ai = pp[ ai ][ i ];
      bi = pp[ bi ][ i ];
    }
  return max( ccccc , max( cc[ ai ][ 0 ] , cc[ bi ][ 0 ] ) );
}
void go( int now , int prt , int cst , int tdep ){
  dep[ now ] = tdep;
  pp[ now ][ 0 ] = prt;
  cc[ now ][ 0 ] = cst;
  for( auto i : tr[ now ] ){
    int who = i.first;
    int ccc = i.second;
    if( who == prt ) continue;
    go( who , now , ccc , tdep + 1 );
  }
}
void solve(){
  for( int i = 1 ; i <= m ; i ++ )
    e.push_back( { w[ i ] , i } );
  sort( e.begin() , e.end() );
  djs.init( n );
  for( auto i : e ){
    if( djs.f( a[ i.second ] ) ==
        djs.f( b[ i.second ] ) )
      continue;
    djs.uni( a[ i.second ] , b[ i.second ] );
    tr[ a[ i.second ] ].push_back( { b[ i.second ] , i.first } );
    tr[ b[ i.second ] ].push_back( { a[ i.second ] , i.first } );
  }
  go( 1 , 1 , 0 , 0 );
  for( int i = 1 ; i < K ; i ++ )
    for( int j = 1 ; j <= n ; j ++ ){
      pp[ j ][ i ] = pp[ pp[ j ][ i - 1 ] ][ i - 1 ];
      cc[ j ][ i ] = max( cc[ j ][ i - 1 ] ,
                          cc[ pp[ j ][ i - 1 ] ][ i - 1 ] );
    }
  int dlt = 1 , who = 0;
  for( int i = 1 ; i <= m ; i ++ ){
    int ncst = w[ i ] - k / c[ i ] - mxcst( a[ i ] , b[ i ] );
    if( ncst < dlt ){
      dlt = ncst;
      who = i;
    }
  }
  yo( who );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}