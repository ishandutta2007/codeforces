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
#define N 303030
#define MXN N
#define PB push_back
#define FZ(X) memset(X,0,sizeof(X))
struct Scc{
  int n, nScc, vst[MXN], bln[MXN];
  vector<int> E[MXN], rE[MXN], vec;
  void init(int _n){
    n = _n;
    for (int i=0; i<MXN; i++){
      E[i].clear();
      rE[i].clear();
    }
  }
  void add_edge(int u, int v){
    E[u].PB(v);
    rE[v].PB(u);
  }
  void DFS(int u){
    vst[u]=1;
    for (auto v : E[u])
      if (!vst[v]) DFS(v);
    vec.PB(u);
  }
  void rDFS(int u){
    vst[u] = 1;
    bln[u] = nScc;
    for (auto v : rE[u])
      if (!vst[v]) rDFS(v);
  }
  int solve(){
    nScc = 0;
    vec.clear();
    FZ(vst);
    for (int i=0; i<n; i++)
      if (!vst[i]) DFS(i);
    reverse(vec.begin(),vec.end());
    FZ(vst);
    for (auto v : vec){
      if (!vst[v]){
        rDFS(v);
        nScc++;
      }
    }
    return nScc;
  }
} graph;
void build(){

}
int n , m;
char c[ N ];
int *at;
int sz[ N ] , tot;
int ind[ N ];
vector<int> topo , e[ N ];
void topo_sort(){
  for( int i = 0 ; i < n ; i ++ )
    for( int nxt : graph.E[ i ] ){
      if( at[ i ] == at[ nxt ] ) continue;
      ind[ at[ nxt ] ] ++;
      e[ at[ i ] ].push_back( at[ nxt ] );
    }
  for( int i = 0 ; i < tot ; i ++ )
    if( ind[ i ] == 0 )
      topo.push_back( i );
  for( size_t i = 0 ; i < topo.size() ; i ++ ){
    int now = topo[ i ];
    for( int nxt : e[ now ] ){
      ind[ nxt ] --;
      if( ind[ nxt ] == 0 )
        topo.push_back( nxt );
    }
  }
}
void init(){
  n = getint();
  m = getint();
  scanf( "%s" , c );
  graph.init( n );
  while( m -- ){
    int ui = getint() - 1;
    int vi = getint() - 1;
    graph.add_edge( ui , vi );
    if( ui == vi ){
      puts( "-1" );
      // fuck this shit
      Bye;
    }
  }
  tot = graph.solve();
  at = graph.bln;
  for( int i = 0 ; i < n ; i ++ )
    sz[ at[ i ] ] ++;
}
int ans , dp[ N ] , bs[ N ];
void solve(){
  topo_sort();
  for( int cc = 0 ; cc < 26 ; cc ++ ){
    for( int i = 0 ; i < tot ; i ++ )
      dp[ i ] = bs[ i ] = 0;
    for( int i = 0 ; i < n ; i ++ )
      if( c[ i ] == cc + 'a' )
        bs[ at[ i ] ] ++;
    for( int i = 0 ; i < tot ; i ++ )
      dp[ i ] = bs[ i ];
    for( int i = 0 ; i < tot ; i ++ )
      if( bs[ i ] and sz[ i ] > 1 ){
        puts( "-1" );
        Bye;
      } 
    for( int i : topo ){
      for( int nxt : e[ i ] )
        dp[ nxt ] = max( dp[ nxt ] ,
                         dp[ i ] + bs[ nxt ] );
      ans = max( ans , dp[ i ] );
    }
  }
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}