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
#define INF  1000000LL
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
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 10210
struct Maxflow {
  static const int MAXV = 20010;
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
  int solve() {
    int res = 0;
    gap[0] = tot;
    for(res = 0; d[s] < tot; res += dfs(s, INF));
    return res;
  }
} flow;
void build(){

}
int n , m , s , t;
int ui[ N ] , vi[ N ] , gi[ N ];
vector<int> g[ N ] , rg[ N ];
void init(){
  n = getint();
  m = getint();
  s = getint();
  t = getint();
  flow.init( n );
  for( int i = 0 ; i < m ; i ++ ){
    ui[ i ] = getint();
    vi[ i ] = getint();
    gi[ i ] = getint();
    g[ ui[ i ] ].push_back( i );
    rg[ vi[ i ] ].push_back( i );
    if( gi[ i ] ){
      flow.addEdge( ui[ i ] , vi[ i ] , 1 );
      flow.addEdge( vi[ i ] , ui[ i ] , INF );
    }else
      flow.addEdge( ui[ i ] , vi[ i ] , INF );
  }
  flow.addEdge( flow.s , s , INF );
  flow.addEdge( t , flow.t , INF );
}
set<int> reachable;
bool tg[ N ] , sat[ N ];
int f[ N ] , c[ N ];
int sbk[ N ] , sbke[ N ];
int tbk[ N ] , tbke[ N ];
bool vst[ N ] , vst2[ N ];
int fucktag[ N ] , fuck;
bool go_to_s( int cur ){
  assert( vst[ cur ] );
  ++ fuck;
  int st = cur;
  while( cur != s ){
    if( fucktag[ sbke[ cur ] ] == fuck )
      return false;
    fucktag[ sbke[ cur ] ] = fuck;
    f[ sbke[ cur ] ] ++;
    //printf( "to s %d\n" , sbke[ cur ] );
    cur = sbk[ cur ];
    if( cur == st )
      return false;
  }
  return true;
}
bool go_to_t( int cur ){
  assert( vst2[ cur ] );
  ++ fuck;
  int st = cur;
  while( cur != t ){
    if( fucktag[ tbke[ cur ] ] == fuck )
      return false;
    fucktag[ tbke[ cur ] ] = fuck;
    f[ tbke[ cur ] ] ++;
    //printf( "to t %d\n" , tbke[ cur ] );
    cur = tbk[ cur ];
    if( cur == st )
      return false;
  }
  return true;
}
int ss[ N ] , stmp;
int who[ N ] , ee[ N ];
bool find_cycle( int now , int st , int dep = 0 ){
  ss[ now ] = stmp;
  who[ dep ] = now;
  for( auto eid : g[ now ] ){
    if( gi[ eid ] == 0 ) continue;
    int nxt = vi[ eid ];
    if( nxt == st ){
      sbke[ st ] = eid;
      sbk[ st ] = now;
      vst[ st ] = true;
      for( int i = 1 ; i <= dep ; i ++ ){
        sbk[ who[ i ] ] = who[ i - 1 ];
        vst[ who[ i ] ] = true;
        sbke[ who[ i ] ] = ee[ i - 1 ];
      }
      return true;
    }
    if( ss[ nxt ] == stmp ) continue;
    ee[ dep ] = eid;
    if( find_cycle( nxt , st , dep + 1 ) )
      return true;
  }
  return false;
}
bool find_cycle2( int now , int st , int dep = 0 ){
  ss[ now ] = stmp;
  who[ dep ] = now;
  for( auto eid : rg[ now ] ){
    if( gi[ eid ] == 0 ) continue;
    int nxt = ui[ eid ];
    if( nxt == st ){
      tbke[ st ] = eid;
      tbk[ st ] = now;
      vst2[ st ] = true;
      for( int i = 1 ; i <= dep ; i ++ ){
        tbk[ who[ i ] ] = who[ i - 1 ];
        vst2[ who[ i ] ] = true;
        tbke[ who[ i ] ] = ee[ i - 1 ];
      }
      return true;
    }
    if( ss[ nxt ] == stmp ) continue;
    ee[ dep ] = eid;
    if( find_cycle2( nxt , st , dep + 1 ) )
      return true;
  }
  return false;
}
void pre_build(){
  {
    vst[ s ] = true;
    queue<int> Q;
    Q.push( s );
    while( Q.size() ){
      int tn = Q.front(); Q.pop();
      for( auto eid : g[ tn ] ){
        if( gi[ eid ] == 0 ) continue;
        if( vst[ vi[ eid ] ] ) continue;
        vst[ vi[ eid ] ] = true;
        sbk[ vi[ eid ] ] = ui[ eid ];
        sbke[ vi[ eid ] ] = eid;
        Q.push( vi[ eid ] );
      }
    }
    for( int i = 1 ; i <= n ; i ++ ){
      if( !vst[ i ] ){
        ++ stmp;
        if( find_cycle( i , i ) )
          vst[ i ] = true;
      }
    }
  }
  {
    vst2[ t ] = true;
    queue<int> Q;
    Q.push( t );
    while( Q.size() ){
      int tn = Q.front(); Q.pop();
      for( auto eid : rg[ tn ] ){
        if( gi[ eid ] == 0 ) continue;
        if( vst2[ ui[ eid ] ] ) continue;
        vst2[ ui[ eid ] ] = true;
        tbk[ ui[ eid ] ] = vi[ eid ];
        tbke[ ui[ eid ] ] = eid;
        Q.push( ui[ eid ] );
      }
    }
    for( int i = 1 ; i <= n ; i ++ )
      if( !vst2[ i ] ){
        ++ stmp;
        if( find_cycle2( i , i ) )
          vst2[ i ] = true;
      }
  }
}
int ff[ N ];
void solve(){
  int ans = flow.solve();
  queue<int> Q;
  reachable.insert( s );
  tg[ s ] = true;
  Q.push( s );
  while( Q.size() ){
    int tn = Q.front(); Q.pop();
    for( auto e : flow.G[ tn ] ){
      if( e.c == 0 ) continue;
      if( 1 <= e.v and e.v <= n and !tg[ e.v ] ){
        tg[ e.v ] = true;
        Q.push( e.v );
        reachable.insert( e.v );
      }
    }
  }
  int cc = 0;
  for( int i = 0 ; i < m ; i ++ )
    if( reachable.find( ui[ i ] ) != reachable.end() and
        reachable.find( vi[ i ] ) == reachable.end() ){
      sat[ i ] = true;
      ++ cc;
    }
  assert( cc == ans );
  pre_build();
  for( int i = 0 ; i < m ; i ++ ){
    if( f[ i ] ) continue;
    if( gi[ i ] == 0 ) continue;
    bool x = go_to_s( ui[ i ] );
    bool y = go_to_t( vi[ i ] );
    if( x and y )
      f[ i ] ++;
    if( f[ i ] == 0 ) f[ i ] = 1;
  }
  for( int i = 0 ; i < m ; i ++ ){
    if( gi[ i ] == 0 )
      c[ i ] = INF;
    else{
      c[ i ] = f[ i ];
      if( !sat[ i ] )
        c[ i ] ++;
    }
  }
  ans = 0;
  for( int i = 0 ; i < m ; i ++ )
    if( f[ i ] == c[ i ] )
      ans ++;
  printf( "%d\n" , ans );
  for( int i = 0 ; i < m ; i ++ ){
    //assert( ( f[ i ] > 0 ) == ( gi[ i ] > 0 ) );
    printf( "%d %d\n" , f[ i ] , c[ i ] );
    ff[ ui[ i ] ] -= f[ i ];
    ff[ vi[ i ] ] += f[ i ];
  }
  //for( int i = 1 ; i <= n ; i ++ )
    //if( i == s )
      //assert( ff[ i ] <= 0 );
    //else if( i == t )
      //assert( ff[ i ] >= 0 );
    //else
      //assert( ff[ i ] == 0 );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}