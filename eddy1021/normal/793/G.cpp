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
#define INF16 10000000000000000LL
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
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define x1 sdfjklsj
#define x2 sdfjklsk
#define y1 sdfjklsl
#define y2 sdfjklsm
#define N 10101
struct Maxflow {
  static const int MAXV = 100010;
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
    //printf( "%d %d -> %d\n" , u , v , c );
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
  int solve() {
    //puts("MF");
    int res = 0;
    gap[0] = tot;
    for(res = 0; d[s] < tot; res += dfs(s, INF));
    return res;
  }
} flow;
int tg[ N << 2 ];
int mn[ N << 2 ] , mx[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void push( int no , int l , int r ){
  if( !tg[ no ] ) return;
  tg[ L( no ) ] += tg[ no ];
  mn[ L( no ) ] += tg[ no ];
  mx[ L( no ) ] += tg[ no ];
  tg[ R( no ) ] += tg[ no ];
  mn[ R( no ) ] += tg[ no ];
  mx[ R( no ) ] += tg[ no ];
  tg[ no ] = 0;
}
void modify( int no , int l , int r , int ql , int qr , int qd ){
  if( r < ql or l > qr ) return;
  if( ql <= l and r <= qr ){
    tg[ no ] += qd;
    mn[ no ] += qd;
    mx[ no ] += qd;
    return;
  }
  push( no , l , r );
  modify( L( no ) , l , mid , ql , qr , qd );
  modify( R( no ) , mid + 1 , r , ql , qr , qd );
  mn[ no ] = min( mn[ L( no ) ] , mn[ R( no ) ] );
  mx[ no ] = max( mx[ L( no ) ] , mx[ R( no ) ] );
}
int id[ N << 2 ] , stmp;
void mark( int no , int l , int r ){
  id[ no ] = ++ stmp;
  if( l == r ) return;
  mark( L( no ) , l , mid );
  mark( R( no ) , mid + 1 , r );
}
void build_edge( int no , int l , int r ){
  if( l == r ){
    flow.addEdge( flow.s , id[ no ] , 1 );
    flow.addEdge( id[ no ] + stmp , flow.t , 1 );
    return;
  }
  flow.addEdge( id[ L( no ) ] , id[ no ] , N );
  flow.addEdge( id[ R( no ) ] , id[ no ] , N );
  flow.addEdge( id[ no ] + stmp , id[ L( no ) ] + stmp , N );
  flow.addEdge( id[ no ] + stmp , id[ R( no ) ] + stmp , N );
  build_edge( L( no ) , l , mid );
  build_edge( R( no ) , mid + 1 , r );
}
void build(){

}
int n , m;
vector< pair< pair<int,int> , int > > dlt[ N ];
vector<int> candx;
void init(){
  n = getint();
  mark( 1 , 1 , n );
  flow.init( stmp + stmp );
  build_edge( 1 , 1 , n );
  m = getint(); while( m -- ){
    int x1 = getint();
    int y1 = getint();
    int x2 = getint();
    int y2 = getint();
    dlt[ x1     ].push_back( { { y1 , y2 } , +1 } );
    dlt[ x2 + 1 ].push_back( { { y1 , y2 } , -1 } );
    candx.push_back( x1 );
    candx.push_back( x2 + 1 );
  }
}
vector<int> lid;
void find_id( int no , int l , int r , int ql , int qr ){
  if( r < ql or l > qr ) return;
  if( ql <= l and r <= qr ){
    lid.push_back( id[ no ] );
    return;
  }
  find_id( L( no ) , l , mid , ql , qr );
  find_id( R( no ) , mid + 1 , r , ql , qr );
}
void gogo( int no , int l , int r ){
  if( mn[ no ] > 0 ) return;
  if( mx[ no ] == 0 ){
    for( auto ii : lid )
      flow.addEdge( ii , id[ no ] + stmp , N );
    return;
  }
  if( l == r ) return;
  push( no , l , r );
  gogo( L( no ) , l , mid );
  gogo( R( no ) , mid + 1 , r );
}
void solve(){
  if( candx.empty() ){
    printf( "%d\n" , n );
    Bye;
  }
  sort( candx.begin() , candx.end() );
  candx.resize( unique( candx.begin() , candx.end() ) - candx.begin() );
  if( candx[ 0 ] > 1 ){
    lid.clear();
    find_id( 1 , 1 , n , 1 , candx[ 0 ] - 1 );
    gogo( 1 , 1 , n );
  }
  for( size_t _ = 0 ; _ < candx.size() ; _ ++ ){
    int x = candx[ _ ];
    int til = _ + 1 < candx.size() ? candx[ _ + 1 ] - 1 : n;
    for( auto i : dlt[ x ] )
      modify( 1 , 1 , n , i.first.first , i.first.second , i.second );
    lid.clear();
    find_id( 1 , 1 , n , x , til );
    gogo( 1 , 1 , n );
  }
  printf( "%d\n" , flow.solve() );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}