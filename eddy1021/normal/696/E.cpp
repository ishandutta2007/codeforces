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
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 101010
#define REP(i, s, e) for(int i = (s); i <= (e); i++)
#define REPD(i, s, e) for(int i = (s); i >= (e); i--)
typedef tuple< int , int > tii;
const int LOG  = 19;
struct HLD{
  int n;
  vector<int> g[ N ];
  int sz[ N ], dep[ N ];
  int ts, tid[ N ], tdi[ N ], tl[ N ], tr[ N ];
  //  ts : timestamp , useless after yutruli
  //  tid[ u ] : pos. of node u in the seq.
  //  tdi[ i ] : node at pos i of the seq.
  //  tl , tr[ u ] : subtree interval in the seq. of node u
  int mom[ N ][ LOG ], head[ N ];
  // head[ u ] : head of the chain contains u
  void dfssz(int u, int p){
    dep[u] = dep[p] + 1;
    mom[u][0] = p;
    sz[u] = 1;
    head[u] = u;
    for(int& v:g[u]) if(v != p){
      dep[v] = dep[u] + 1;
      dfssz(v, u);
      sz[u] += sz[v];
    }
  }
  void dfshl(int u){
    //printf("dfshl %d\n", u);
    ts++;
    tid[u] = tl[u] = tr[u] = ts;
    tdi[tid[u]] = u;
    sort(ALL(g[u]), [&](int a, int b){return sz[a] > sz[b];});
    bool flag = 1;
    for(int& v:g[u]) if(v != mom[u][0]){
      if(flag) head[v] = head[u], flag = 0;
      dfshl(v);
      tr[u] = tr[v];
    }
  }
  inline int lca(int a, int b){
    if(dep[a] > dep[b]) swap(a, b);
    //printf("lca %d %d\n", a, b);
    int diff = dep[b] - dep[a];
    REPD(k, LOG-1, 0) if(diff & (1<<k)){
      //printf("b %d\n", mom[b][k]);
      b = mom[b][k];
    }
    if(a == b) return a;
    REPD(k, LOG-1, 0) if(mom[a][k] != mom[b][k]){
      a = mom[a][k];
      b = mom[b][k];
    }
    return mom[a][0];
  }
  void init( int _n ){
    n = _n;
    REP( i , 1 , n ) g[ i ].clear();
  }
  void addEdge( int u , int v ){
    g[ u ].push_back( v );
    g[ v ].push_back( u );
  }
  void yutruli(){
    dfssz(1, 0);
    ts = 0;
    dfshl(1);
    REP(k, 1, LOG-1) REP(i, 1, n)
      mom[i][k] = mom[mom[i][k-1]][k-1];
  }
  vector< tii > getPath( int u , int v ){
    vector< tii > res;
    while( tid[ u ] < tid[ head[ v ] ] ){
      res.push_back( tii( tid[ head[ v ] ] , tid[ v ] ) );
      v = mom[ head[ v ] ][ 0 ];
    }
    res.push_back( tii( tid[ u ] , tid[ v ] ) );
    reverse( ALL( res ) );
    return res;
    /*
     * res : list of intervals from u to v
     * u must be ancestor of v
     * usage :
     * vector< tii >& path = tree.getPath( u , v )
     * for( tii tp : path ) {
     *   int l , r;tie( l , r ) = tp;
     *   upd( l , r );
     *   uu = tree.tdi[ l ] , vv = tree.tdi[ r ];
     *   uu ~> vv is a heavy path on tree
     * }
     */
  }
} tree;
void build(){
  
}
queue<int> tmp[ N ];
LL tag[ N << 2 ];
PLL st[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void build_st( int no , int l , int r ){
  if( l == r ){
    if( tmp[ l ].empty() )
      st[ no ] = { INF16 , INF16 };
    else
      st[ no ] = { tmp[ l ].front() , tree.tdi[ l ] };
    return;
  }
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
  st[ no ] = min( st[ L( no ) ] , st[ R( no ) ] );
}
inline void push( int no , int l , int r ){
  if( tag[ no ] ){
    tag[ L( no ) ] += tag[ no ];
    st[ L( no ) ].FI += tag[ no ];
    tag[ R( no ) ] += tag[ no ];
    st[ R( no ) ].FI += tag[ no ];
  }
  tag[ no ] = 0;
}
PLL query( int no , int l , int r , int ql , int qr ){
  if( r < ql || l > qr || ql > qr ) return { INF16 , INF16 };
  if( ql <= l && r <= qr ) return st[ no ];
  push( no , l , r );
  return min( query( L( no ) , l , mid , ql , qr ) ,
              query( R( no ) , mid + 1 , r , ql , qr ) );
}
void Add( int no , int l , int r , int ql , int qr , LL dlt ){
  if( r < ql || l > qr || ql > qr ) return;
  if( ql <= l && r <= qr ){
    tag[ no ] += dlt;
    st[ no ].FI += dlt;
    return;
  }
  push( no , l , r );
  Add( L( no ) , l , mid , ql , qr , dlt );
  Add( R( no ) , mid + 1 , r , ql , qr , dlt );
  st[ no ] = min( st[ L( no ) ] , st[ R( no ) ] );
}
void Del( int no , int l , int r , int p ){
  if( l == r ){
    assert( !tmp[ l ].empty() );
    tmp[ l ].pop();
    if( tmp[ l ].empty() )
      st[ no ] = { INF16 , INF16 };
    else
      st[ no ] = { tmp[ l ].front() + tag[ no ] , tree.tdi[ l ] };
    return;
  }
  push( no , l , r );
  if( p <= mid ) Del( L( no ) , l , mid , p );
  else Del( R( no ) , mid + 1 , r , p );
  st[ no ] = min( st[ L( no ) ] , st[ R( no ) ] );
}
int n , m , q;
void init(){
  n = getint(); m = getint(); q = getint();
  tree.init( n );
  for( int i = 1 ; i < n ; i ++ ){
    int u = getint();
    int v = getint();
    tree.addEdge( u , v );
  }
  tree.yutruli();
  for( int i = 1 ; i <= m ; i ++ )
    tmp[ tree.tid[ getint() ] ].push( i );
  build_st( 1 , 1 , n );
}
void solve(){
  while( q -- ){
    int cmd = getint();
    if( cmd == 1 ){
      int v = getint();
      int u = getint();
      int k = getint();
      int lca = tree.lca( v , u );
      vector< tii > p1 = tree.getPath( lca , u );
      vector< tii > p2 = tree.getPath( lca , v );
      typedef pair< PLL , tii > type;
      priority_queue< type , vector< type > , greater< type > > heap;
      for( tii tp : p1 ){
        PLL xp = query( 1 , 1 , n , get<0>( tp ) , get<1>( tp ) );
        if( xp.SE != INF16 )
          heap.push( { xp , tp } );
      }
      for( tii tp : p2 ){
        PLL xp = query( 1 , 1 , n , get<0>( tp ) , get<1>( tp ) );
        if( xp.SE != INF16 )
          heap.push( { xp , tp } );
      }
      vector< int > ans; int got = 0;
      while( heap.size() && got < k ){
        type xp = heap.top(); heap.pop();
        PLL ap = xp.FI;
        tii tp = xp.SE;
        PLL cp = query( 1 , 1 , n , get<0>( tp ) , get<1>( tp ) );
        if( cp != ap ){
          if( cp.SE != INF16 )
            heap.push( { cp , tp } );
          continue;
        }
        got ++;
        ans.push_back( tmp[ tree.tid[ ap.SE ] ].front() );
        Del( 1 , 1 , n , tree.tid[ ap.SE ] );
        ap = query( 1 , 1 , n , get<0>( tp ) , get<1>( tp ) );
        if( ap.SE != INF16 )
          heap.push( { ap , tp } );
      }
      if( ans.empty() ) puts( "0" );
      else{
        printf( "%d " , (int)ans.size() );
        for( size_t i = 0 ; i < ans.size() ; i ++ )
          printf( "%d%c" , ans[ i ] , " \n"[ i + 1 == ans.size() ] );
      }
    }else{
      int v = getint();
      int k = getint();
      Add( 1 , 1 , n , tree.tl[ v ] , tree.tr[ v ] , k );
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