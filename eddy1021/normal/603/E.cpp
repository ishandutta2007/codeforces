#include <bits/stdc++.h>
using namespace std;
#define N 303030
#define PB push_back
#define SZ(X) (int)((X).size())
struct DisjointSet{
  // save() is like recursive
  // undo() is like return
  int n , odd , fa[ N ] , sz[ N ];
  vector< pair<int*,int> > h;
  vector< int > so;
  vector< int > sp;
  void init( int tn ){
    odd = n = tn;
    for( int i = 1 ; i <= n ; i ++ ){
      fa[ i ]=i;
      sz[ i ]=1;
    }
    so.clear(); sp.clear(); h.clear();
  }
  void assign( int *k, int v ){
    so.push_back( odd );
    h.PB( {k, *k} );
    *k = v;
  }
  void save(){ sp.PB(SZ(h)); }
  void undo(){
    assert(!sp.empty());
    int last=sp.back(); sp.pop_back();
    while( SZ(h)!=last ){
      auto x=h.back(); h.pop_back();
      odd = so.back(); so.pop_back();
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
    int nodd = odd - sz[ x ] % 2 - sz[ y ] % 2;
    assign( &sz[ x ] , sz[ x ] + sz[ y ] );
    assign( &fa[ y ] , x);
    odd = nodd + sz[ x ] % 2;
  }
} djs;
const int INF = 1023456789;
int n , m;
typedef pair< pair<int,int> , pair<int,int> > edge;
#define C first.first
#define I first.second
#define A second.first
#define B second.second
vector< edge > v;
void init(){
  scanf( "%d%d" , &n , &m );
  for( int i = 0 ; i < m ; i ++ ){
    int ai , bi , li;
    scanf( "%d%d%d" , &ai , &bi , &li );
    v.push_back( { { li , i } , { ai , bi } } );
  }
  sort( v.begin() , v.end() );
}
int ans[ N ];
void find_ans( int id , const vector<edge>& tv ){
  for( auto e : tv )
    if( e.I <= id ){
      djs.uni( e.A , e.B );
      if( djs.odd == 0 ){
        ans[ id ] = e.C;
        return;
      }
    }
}
void go( int l , int r , int cl , int cr , const vector<edge>& tv ){
  if( l > r || cl > cr ) return;
  if( cl == cr ){
    for( int i = l ; i <= r ; i ++ )
      ans[ i ] = cl;
    return;
  }
  djs.save();
  vector< edge > wt;
  for( auto e : tv ){
    if( e.I < l && e.C < cl )
      djs.uni( e.A , e.B );
    else if( e.I <= r && e.C <= cr )
      wt.push_back( e );
  }
  int mid = ( l + r ) >> 1;
  ans[ mid ] = cr;
  djs.save();
  find_ans( mid , wt );
  djs.undo();
  go( l , mid - 1 , ans[ mid ] , cr , wt );
  go( mid + 1, r , cl , ans[ mid ] , wt );
  djs.undo();
}
void solve(){
  djs.init( n );
  go( 0 , m - 1 , 1 , INF , v );
  for( int i = 0 ; i < m ; i ++ )
    printf( "%d\n" , ans[ i ] == INF ? -1 : ans[ i ] );
}
int main(){
  init();
  solve();
}