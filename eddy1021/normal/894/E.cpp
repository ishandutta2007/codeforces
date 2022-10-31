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
#define MXN 1000010
#define PB push_back
#define FZ(X) memset(X,0,sizeof(X))
struct Scc{
  int n, nScc, vst[MXN], id[MXN];
  vector<int> E[MXN], rE[MXN], vec;
  void init(int _n){
    n = _n;
    for (int i=1; i<=n; i++){
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
    id[u] = nScc;
    for (auto v : rE[u])
      if (!vst[v]) rDFS(v);
  }
  void solve(){
    nScc = 0;
    vec.clear();
    FZ(vst);
    for (int i=1; i<=n; i++)
      if (!vst[i]) DFS(i);
    reverse(vec.begin(),vec.end());
    FZ(vst);
    for (auto v : vec){
      if (!vst[v]){
        rDFS(v);
        nScc++;
      }
    }
  }
} graph;
void build(){ 

}
#define N MXN
int n , m , s;
vector< pair<int,int> > v[ N ] , e[ N ];
void init(){
  n = getint();
  m = getint();
  graph.init( n );
  while( m -- ){
    int ui = getint();
    int vi = getint();
    int wi = getint();
    graph.add_edge( ui , vi );
    v[ ui ].push_back( { vi , wi } );
  }
  s = getint();
  graph.solve();
}
LL dp[ N ] , w[ N ];
bool ok[ N ];
int deg[ N ] , que[ N ] , qt;
inline LL weight( LL tw ){
  LL bl = 0 , br = tw , ba = 0;
  while( bl <= br ){
    LL bmid = (bl + br) >> 1;
    if( bmid * (bmid + 1) / 2 < tw )
      ba = bmid , bl = bmid + 1;
    else
      br = bmid - 1;
  }
  return tw * (ba + 1) - ba * (ba + 1) * (ba + 2) / 6;
}
void solve(){
  int tot = graph.nScc;
  for( int i = 0 ; i < tot ; i ++ )
    dp[ i ] = -INF16;
  for( int i = 1 ; i <= n ; i ++ )
    for( auto ee : v[ i ] ){
      int to = ee.first;
      int wi = ee.second;
      if( graph.id[ i ] == graph.id[ to ] )
        w[ graph.id[ i ] ] += weight( wi );
      else{
        e[ graph.id[ i ] ].push_back( { graph.id[ to ] , wi } );
        deg[ graph.id[ to ] ] ++;
      }
    }
  ok[ graph.id[ s ] ] = true;
  dp[ graph.id[ s ] ] = 0;
  LL ans = 0;
  for( int i = 0 ; i < tot ; i ++ )
    if( deg[ i ] == 0 )
      que[ qt ++ ] = i;
  for( int _ = 0 ; _ < qt ; _ ++ ){
    int now = que[ _ ];
    if( ok[ now ] ){
      dp[ now ] += w[ now ];
      ans = max( ans , dp[ now ] );
    }
    for( auto ee : e[ now ] ){
      if( ok[ now ] ){
        ok[ ee.first ] = true;
        dp[ ee.first ] = max( dp[ ee.first ] , dp[ now ] + ee.second );
      }
      deg[ ee.first ] --;
      if( deg[ ee.first ] == 0 )
        que[ qt ++ ] = ee.first;
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