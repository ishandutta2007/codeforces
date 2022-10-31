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
#define N 505050
#define PB push_back
struct DisjointSet{
  // save() is like recursive
  // undo() is like return
  int n, fa[ N ], sz[ N ];
  vector< pair<int*,int> > h;
  vector<int> sp;
  void init( int tn ){
    n=tn;
    for( int i = 0 ; i < n ; i ++ ){
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
int n , m , Q , u[ N ] , v[ N ] , w[ N ];
vector<int> e[ N ];
bool ans[ N ];
vector< pair<int, pair<int,int> > > q[ N ];
vector<int> qry[ N ];
bool cmp( int id1 , int id2 ){
  return w[ id1 ] < w[ id2 ];
}
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= m ; i ++ ){
    u[ i ] = getint();
    v[ i ] = getint();
    w[ i ] = getint();
    e[ w[ i ] ].push_back( i );
  }
  Q = getint();
  for( int i = 0 ; i < Q ; i ++ ){
    int ki = getint();
    qry[ i ].resize( ki );
    for( int j = 0 ; j < ki ; j ++ )
      qry[ i ][ j ] = getint();
    ans[ i ] = true;
  }
  for( int i = 0 ; i < Q ; i ++ ){
    sort( qry[ i ].begin() , qry[ i ].end() , cmp );
    for( size_t l = 0 , r = 0 ; l < qry[ i ].size() ; l = r ){
      while( r < qry[ i ].size() and
             w[ qry[ i ][ l ] ] ==
             w[ qry[ i ][ r ] ] ) r ++;
      q[ w[ qry[ i ][ l ] ] ].push_back( { i , { l , r } } );
    }
  }
}
void solve(){
  djs.init( n + 1 );
  for( int i = 1 ; i <= 500000 ; i ++ ){
    if( e[ i ].empty() ) continue;
    for( auto _ : q[ i ] ){
      int qid = _.first;
      int st = _.second.first;
      int ed = _.second.second;
      djs.save();
      bool ok = true;
      for( int j = st ; j < ed and ok ; j ++ ){
        int ui = u[ qry[ qid ][ j ] ];
        int vi = v[ qry[ qid ][ j ] ];
        if( djs.f( ui ) == djs.f( vi ) )
          ok = false;
        else
          djs.uni( ui , vi );
      }
      if( not ok )
        ans[ qid ] = false;
      djs.undo();
    }
    for( int eid : e[ i ] )
      djs.uni( u[ eid ] , v[ eid ] );
  }
  for( int i = 0 ; i < Q ; i ++ )
    puts( ans[ i ] ? "YES" : "NO" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}