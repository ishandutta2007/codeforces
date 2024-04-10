#include <bits/stdc++.h>
using namespace std;
struct DJS{
  vector< int > p;
  void init( int n ){
    p.resize( n );
    for( int i = 0 ; i < n ; i ++ )
      p[ i ] = i;
  }
  int find_p( int x ){ return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] ); }
  void Union( int x , int y ){ p[ find_p( x ) ] = find_p( y ); }
} djs;
struct Tree{
  vector< vector< int > > v;
  vector< int > ind, in, out;
  int n , stmp;
  void init( int _n ){
    n = _n;
    v.resize( n );
    ind.resize( n );
    in.resize( n );
    out.resize( n );
    for( int i = 0 ; i < n ; i ++ )
      ind[ i ] = in[ i ] = out[ i ] = 0;
    stmp = 0;
  }
  void add( int prt , int son ){
    v[ prt ].push_back( son );
    ind[ son ] ++;
  }
  void go( int now ){
    in[ now ] = ++ stmp;
    for( int son : v[ now ] )
      go( son );
    out[ now ] = stmp;
  }
  void mark(){
    for( int i = 0 ; i < n ; i ++ )
      if( ind[ i ] == 0 )
        go( i );
  }
  bool is_p( int a , int b ){
    return in[ a ] <= in[ b ] &&
           out[ b ] <= out[ a ];
  }
} tree;
struct Solver{
  int n , m;
  vector< int > cmd , x , y;
  vector< bool > ans;
  vector< vector< int > > qry;
  void init(){
    scanf( "%d%d", &n , &m );
    djs.init( n );
    tree.init( n );
    cmd.resize( m );
    x.resize( m );
    y.resize( m );
    ans.resize( m );
    qry.resize( m );
    for( int i = 0 ; i < m ; i ++ ){
      scanf( "%d" , &cmd[ i ] );
      if( cmd[ i ] == 1 ){
        scanf( "%d%d" , &x[ i ] , &y[ i ] );
        x[ i ] --; y[ i ] --;
        tree.add( y[ i ] , x[ i ] );
      }else if( cmd[ i ] == 2 ){
        scanf( "%d" , &x[ i ] );
        x[ i ] --;
      }else if( cmd[ i ] == 3 ){
        scanf( "%d%d" , &x[ i ] , &y[ i ] );
        x[ i ] --; y[ i ] --;
        qry[ y[ i ] ].push_back( i );
      }else assert( false );
    }
    tree.mark();
  }
  void solve(){
    int cnt = 0;
    for( int i = 0 ; i < m ; i ++ )
      if( cmd[ i ] == 1 )
        djs.Union( x[ i ] , y[ i ] );
      else if( cmd[ i ] == 2 ){
        for( int cand : qry[ cnt ] )
          ans[ cand ] = tree.is_p( x[ cand ] , x[ i ] ) &&
                        djs.find_p( x[ cand ] ) == djs.find_p( x[ i ] );
        cnt ++;
      }else puts( ans[ i ] ? "YES" : "NO" );
  }
} solver;
int main(){
  solver.init();
  solver.solve();
}