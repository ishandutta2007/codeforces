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
// #define INF  1023456789ll
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
#define N 505050
struct Maxflow {
  static const int MAXV = 200010;
  static const int INF  = 1000000;
  struct Edge {
    int v, c, r;
    Edge(int _v, int _c, int _r):
      v(_v), c(_c), r(_r) {}
  };
  int s, t;
  vector<Edge> G[MAXV*2];
  int iter[MAXV*2], d[MAXV*2], gap[MAXV*2], tot;
  void init(int x) {
    tot = x+2;
    s = x+1, t = x+2;
    for(int i = 0; i <= tot; i++) {
      G[i].clear();
      iter[i] = d[i] = gap[i] = 0;
    }
  }
  void addEdge(int u, int v, int c) {
    G[u].push_back(Edge(v, c, SZ(G[v]) ));
    G[v].push_back(Edge(u, 0, SZ(G[u]) - 1));
  }
  int dfs(int p, int flow) {
    if(p == t) return flow;
    for(int &i = iter[p]; i < SZ(G[p]); i++) {
      Edge &e = G[p][i];
      if(e.c > 0 && d[p] == d[e.v]+1) {
        int f = dfs(e.v, min(flow, e.c));
        if(f) {
          e.c -= f;
          G[e.v][e.r].c += f;
          return f;
        }
      }
    }
    if( (--gap[d[p]]) == 0) d[s] = tot;
    else {
      d[p]++;
      iter[p] = 0;
      ++gap[d[p]];
    }
    return 0;
  }
  int maxflow() {
    //puts("MF");
    int res = 0;
    gap[0] = tot;
    for(res = 0; d[s] < tot; res += dfs(s, INF));
    return res;
  }
} flow;
struct DisjointSet{
  // save() is like recursive
  // undo() is like return
  int n, fa[ N ], sz[ N ] , tot;
  vector< pair<int*,int> > h;
  vector<int> sp;
  void init( int tn ){
    n=tn;
    for( int i = 1 ; i <= n ; i ++ ){
      fa[ i ]=i;
      sz[ i ]=1;
    }
    tot = n;
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
    tot --;
  }
}djs;
void build(){

}
int n , m , u[ N ] , v[ N ];
int s , t , ds , dt;
void init(){
  scanf( "%d%d" , &n , &m );
  for( int i = 0 ; i < m ; i ++ )
    scanf( "%d%d" , &u[ i ] , &v[ i ] );
  scanf( "%d%d%d%d" , &s , &t , &ds , &dt );
  if( s > t ){
    swap( s , t );
    swap( ds , dt );
  }     
}
vector< pair<int,int> > e , es , et;
bool st;
vector< pair<int,int> > ans;
inline void naive(){
  djs.save();
  vector< pair<int,int> > va;
  int ss = 0 , sst = 0;
  for( auto i : es ){
    if( djs.f( i.first ) == djs.f( i.second ) )
      continue;
    if( ( i.first == s || i.second == s ) &&
        ss + 1 > ds ) continue;
    if( ( i.first == t || i.second == t ) &&
        sst + 1 > dt ) continue;
    djs.uni( i.first , i.second );
    if( i.first == s || i.second == s ) ss ++;
    if( i.first == t || i.second == t ) sst ++;
    va.push_back( i );
  }
  for( auto i : et ){
    if( djs.f( i.first ) == djs.f( i.second ) )
      continue;
    if( ( i.first == s || i.second == s ) &&
        ss + 1 > ds ) continue;
    if( ( i.first == t || i.second == t ) &&
        sst + 1 > dt ) continue;
    djs.uni( i.first , i.second );
    if( i.first == s || i.second == s ) ss ++;
    if( i.first == t || i.second == t ) sst ++;
    va.push_back( i );
  }
  if( st && djs.f( s ) != djs.f( t ) ){
    djs.uni( s , t );
    ss ++; sst ++;
    va.push_back( { s , t } );
  }
  djs.undo();
  if( ss > ds || sst > dt || djs.tot > 1 ) return;
  for( auto i : va ) ans.push_back( i );
  puts( "Yes" );
  for( auto i : ans )
    printf( "%d %d\n" , i.first , i.second );
  exit( 0 );
}
int id[ N ];
void solve1(){
  vector< int > vv;
  for( int i = 1 ; i <= n ; i ++ )
    if( i == djs.f( i ) ){
      if( i == s || i == t ) continue;
      id[ i ] = (int)vv.size();
      vv.push_back( i );
    }
  int vsz = (int)vv.size();
  flow.init( vsz + 2 );
  flow.addEdge( flow.s , vsz + 1 , ds - 1 );
  flow.addEdge( flow.s , vsz + 2 , dt - 1 );
  map< int , int > gs , gt;
  for( auto i : es ){
    int fa = id[ djs.f( i.second ) ];
    if( gs.count( fa ) ) continue;
    gs[ fa ] = i.second;
    flow.addEdge( vsz + 1 , fa + 1 , 1 );
  }
  for( auto i : et ){
    int fa = id[ djs.f( i.second ) ];
    if( gt.count( fa ) ) continue;
    gt[ fa ] = i.second;
    flow.addEdge( vsz + 2 , fa + 1 , 1 );
  }
  for( int i = 1 ; i <= vsz ; i ++ )
    flow.addEdge( i , flow.t , 1 );
  int ret = flow.maxflow();
  if( ret != vsz ) return;
  vector< pair<int,int> > va;
  va.push_back( { s , t } );
  for( auto i : flow.G[ vsz + 1 ] )
    if( i.c == 0 ){
      if ( i.v == flow.s ) continue;
      va.push_back( { s , gs[ i.v - 1 ] } );
    }
  for( auto i : flow.G[ vsz + 2 ] )
    if( i.c == 0 ){
      if ( i.v == flow.s ) continue;
      va.push_back( { t , gs[ i.v - 1 ] } );
    }
  for( auto i : va ) ans.push_back( i );
  puts( "Yes" );
  for( auto i : ans )
    printf( "%d %d\n" , i.first , i.second );
  exit( 0 );
}
void solve2(){
  vector< int > vv;
  for( int i = 1 ; i <= n ; i ++ )
    if( i == djs.f( i ) ){
      if( i == s || i == t ) continue;
      id[ i ] = (int)vv.size();
      vv.push_back( i );
    }
  int vsz = (int)vv.size();
  map< int , int > gs , gt;
  for( auto i : es ){
    int fa = id[ djs.f( i.second ) ];
    if( gs.count( fa ) ) continue;
    gs[ fa ] = i.second;
  }
  for( auto i : et ){
    int fa = id[ djs.f( i.second ) ];
    if( gt.count( fa ) ) continue;
    gt[ fa ] = i.second;
  }
  // int ret = flow.maxflow();
  // if( ret != vsz + 1 ) return;
  vector< pair<int,int> > va;
  for( int i = 0 ; i < vsz ; i ++ )
    if( gs.count( i ) == 0 && gt.count( i ) == 0 )
      return;
    else if( gs.count( i ) == 0 ){
      va.push_back( { t , gt[ i ] } );
      dt --;
      if( dt < 0 ) return;
    }else if( gt.count( i ) == 0 ){
      va.push_back( { s , gs[ i ] } );
      ds --;
      if( ds < 0 ) return;
    }
  bool flag = false;
  for( int i = 0 ; i < vsz ; i ++ )
    if( gs.count( i ) && gt.count( i ) ){
      if( !flag ){
        va.push_back( { s , gs[ i ] } );
        va.push_back( { t , gt[ i ] } );
        flag = true;
        ds --; dt --;
        if( ds < 0 || dt < 0 ) return;
        continue;
      }
      if( ds )
        va.push_back( { s , gs[ i ] } ) , ds --;
      else if( dt )
        va.push_back( { t , gt[ i ] } ) , dt --;
      else
        return;
    }
  if( !flag ) return;
  for( auto i : va ) ans.push_back( i );
  puts( "Yes" );
  for( auto i : ans )
    printf( "%d %d\n" , i.first , i.second );
  exit( 0 );
}
void solve(){
  for( int i = 0 ; i < m ; i ++ ){
    if( u[ i ] > v[ i ] ) swap( u[ i ] , v[ i ] );
    if( u[ i ] == s && v[ i ] == t )
      st = true;
    else if( u[ i ] == s || v[ i ] == s ){
      if( v[ i ] == s ) swap( u[ i ] , v[ i ] );
      es.push_back( { u[ i ] , v[ i ] } );
    }else if( u[ i ] == t || v[ i ] == t ){
      if( v[ i ] == t ) swap( u[ i ] , v[ i ] );
      et.push_back( { u[ i ] , v[ i ] } );
    }else
      e.push_back( { u[ i ] , v[ i ] } );
  } 
  djs.init( n );
  for( auto i : e ){
    if( djs.f( i.first ) == djs.f( i.second ) )
      continue;
    djs.uni( i.first , i.second );
    ans.push_back( i );
  }
  naive();
  if( st ) solve1();
  solve2();
  puts( "No" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}