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
#define N 202020
#define MXN 202020
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
int n , m , out[ N ] , s;
void init(){
  n = getint();
  m = getint(); // for what..?
  graph.init( n );
  for( int i = 1 ; i <= n ; i ++ ){
    int ci = getint();
    out[ i ] = ci;
    while( ci -- )
      graph.add_edge( i , getint() );
  }
  graph.solve();
  s = getint();
}
bool can_draw;
int sz[ N ];
bool got[ N ];
int bk[ N ];
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    sz[ graph.bln[ i ] ] ++;
  queue< int > Q;
  Q.push( s );
  got[ s ] = true;
  while( Q.size() ){
    int tn = Q.front(); Q.pop();
    int sft = (tn <= n ? n : 0);
    int _me = tn <= n ? tn : tn - n;
    for( int nxt : graph.E[ _me ] ){
      int rnxt = nxt + sft;
      if( got[ rnxt ] ) continue;
      got[ rnxt ] = true;
      bk[ rnxt ] = tn;
      Q.push( rnxt );
    }
  }
  for( int i = 1 ; i <= n ; i ++ )
    if( out[ i ] == 0 and got[ i + n ] ){
      puts( "Win" );
      int now = i + n;
      vector<int> ans;
      while( now != s ){
        ans.push_back( now > n ? now - n : now );
        now = bk[ now ];
      }
      ans.push_back( s );
      reverse( ans.begin() , ans.end() );
      for( size_t j = 0 ; j < ans.size() ; j ++ )
        printf( "%d%c" , ans[ j ] , " \n"[ j + 1 == ans.size() ] );
      Bye;
    }else if( (got[ i ] or got[ i + n ]) and sz[ graph.bln[ i ] ] > 1 )
      can_draw = true;
  puts( can_draw ? "Draw" : "Lose" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}