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
#define N 404040
#define MXN 404040
struct DisjointSet {
  // save() is like recursive
  // undo() is like return
  int n, fa[MXN], sz[MXN];
  vector<pair<int*,int>> h;
  vector<int> sp;
  void init(int tn) {
    n=tn;
    for (int i=1; i<=n; i++) {
      fa[i]=i;
      sz[i]=1;
    }
    sp.clear(); h.clear();
  }
  void assign(int *k, int v) {
    h.PB({k, *k});
    *k=v;
  }
  void save() { sp.PB(SZ(h)); }
#define F first
#define S second
  void undo() {
    assert(!sp.empty());
    int last=sp.back(); sp.pop_back();
    while (SZ(h)!=last) {
      auto x=h.back(); h.pop_back();
      *x.F=x.S;
    }
  }
  int f(int x) {
    while (fa[x]!=x) x=fa[x];
    return x;
  }
  void uni(int x, int y) {
    x=f(x); y=f(y);
    if (x==y) return ;
    if (sz[x]<sz[y]) swap(x, y);
    assign(&sz[x], sz[x]+sz[y]);
    assign(&fa[y], x);
  }
};
struct BccEdge {
  struct Edge { int v,eid; };
  int n,m,step,par[MXN],dfn[MXN],low[MXN];
  vector<Edge> E[MXN];
  DisjointSet djs;
  void init(int _n) {
    n = _n; m = 0;
    for (int i=1; i<=n; i++) E[i].clear();
    djs.init(n);
  }
  void add_edge(int u, int v) {
    E[u].PB({v, m});
    E[v].PB({u, m});
    m++;
  }
  void DFS(int u, int f, int f_eid) {
    par[u] = f;
    dfn[u] = low[u] = step++;
    for (auto it:E[u]) {
      if (it.eid == f_eid) continue;
      int v = it.v;
      if (dfn[v] == -1) {
        DFS(v, u, it.eid);
        low[u] = min(low[u], low[v]);
      } else {
        low[u] = min(low[u], dfn[v]);
      }
    }
  }
  void solve() {
    step = 0;
    memset(dfn, -1, sizeof(int)*(n+1));
    for (int i=1; i<=n; i++) {
      if (dfn[i] == -1) DFS(i, i, -1);
    }
    djs.init(n);
    for (int i=1; i<=n; i++) {
      if (low[i] < dfn[i]) djs.uni(i, par[i]);
    }
  }
} graph;
void build(){

}
int n , m , u[ N ] , v[ N ];
set< pair<int,int> > s;
void init(){
  scanf( "%d%d" , &n , &m );
  graph.init( n );
  for( int i = 0 ; i < m ; i ++ ){
    u[ i ] = getint();
    v[ i ] = getint();
    graph.add_edge( u[ i ] , v[ i ] );
  }
  graph.solve();
}
vector< int > e2[ N ];
vector< pair< int , pair<int,int> > > e[ N ];
int sz[ N ];
set< pair<int,int> > ans;
void tree( int now , int prt ){
  for( auto i : e[ now ] ){
    if( i.first == prt ) continue;
    ans.insert( { i.second.second , i.second.first } );
    tree( i.first , now );
  }
}
bool vst[ N ];
void con( int now ){
  vst[ now ] = true;
  for( auto i : e2[ now ] ){
    if( ans.count( { now , i } ) == 0 &&
        ans.count( { i , now } ) == 0 )
      ans.insert( { now , i } );
    if( vst[ i ] ) continue;
    con( i );
  }
}
void solve(){
  for( int i = 0 ; i < m ; i ++ )
    if( graph.djs.f( u[ i ] ) == 
        graph.djs.f( v[ i ] ) ){
      e2[ u[ i ] ].push_back( v[ i ] );
      e2[ v[ i ] ].push_back( u[ i ] );
    }else{
      e[ graph.djs.f( u[ i ] ) ].push_back( { graph.djs.f( v[ i ] ) , { u[ i ] , v[ i ] } } );
      e[ graph.djs.f( v[ i ] ) ].push_back( { graph.djs.f( u[ i ] ) , { v[ i ] , u[ i ] } } );
    }
  int bst = -1 , mx = -1;
  for( int i = 1 ; i <= n ; i ++ )
    if( i == graph.djs.f( i ) ){
      sz[ i ] = graph.djs.sz[ i ];
      if( sz[ i ] > mx ){
        mx = sz[ i ];
        bst = i;
      }
      con( i );
    }
  tree( bst , bst );
  printf( "%d\n" , mx );
  for( int i = 0 ; i < m ; i ++ )
    if( ans.count( { u[ i ] , v[ i ] } ) )
      printf( "%d %d\n" , u[ i ] , v[ i ] );
    else
      printf( "%d %d\n" , v[ i ] , u[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}