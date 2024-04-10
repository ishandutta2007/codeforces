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
//#define INF  1023456789LL
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
#define N 1021
int n;
pair< pair<string,string> , int > name[ N ];
void build(){

}
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ ){
    string f , s; cin >> f >> s;
    name[ i ] = { { f.substr( 0 , 3 ) , f.substr( 0 , 2 ) + s[ 0 ] } , i };
  }
}
string ans[ N ];
bool ok[ N ];
set<string> fob;
map<string,int> M;
vector< int > fuck[ N + N ];
int pr[ N + N ];
//#define SZ(c) ((int)(c).size())
struct Maxflow {
  static const int MAXV = 20010;
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
  int solve() {
    //puts("MF");
    int res = 0;
    gap[0] = tot;
    for(res = 0; d[s] < tot; res += dfs(s, INF));
    return res;
  }
} flow;
//Maxflow::Edge e(1, 1, 1);
void solve(){
  sort( name , name + n );
  for( int l = 0 , r = 0 ; l < n ; l = r ){
    while( r < n and name[ l ].first.first == name[ r ].first.first ) r ++;
    if( r - l == 1 ) continue;
    for( int i = l ; i < r ; i ++ ){
      if( fob.count( name[ i ].first.second ) ){
        puts( "NO" );
        Bye;
      }
      ok[ i ] = true;
      ans[ name[ i ].second ] = name[ i ].first.second;
      fob.insert( name[ i ].first.second );
    }
  }
  int mid = 0;
  for( int i = 0 ; i < n ; i ++ ){
    if( ok[ i ] ) continue;
    if( fob.count( name[ i ].first.first ) == 0 ){
      if( M.count( name[ i ].first.first ) == 0 )
        M[ name[ i ].first.first ] = mid ++;
      //fuck[ M[ name[ i ].first.first ] ].push_back( i );
    }
    if( fob.count( name[ i ].first.second ) == 0 ){
      if( M.count( name[ i ].first.second ) == 0 )
        M[ name[ i ].first.second ] = mid ++;
      //fuck[ M[ name[ i ].first.second ] ].push_back( i );
    }
  }
  flow.init( n + mid );
  for( int i = 0 ; i < n ; i ++ )
    if( !ok[ i ] )
      flow.addEdge( flow.s , i , 1 );
  for( int i = 0 ; i < n ; i ++ ){
    if( ok[ i ] ) continue;
    if( fob.count( name[ i ].first.first ) == 0 )
      flow.addEdge( i , n + M[ name[ i ].first.first ] , 1 );
    if( fob.count( name[ i ].first.second ) == 0 )
      flow.addEdge( i , n + M[ name[ i ].first.second ] , 1 );
  }
  for( int i = 0 ; i < mid ; i ++ )
    flow.addEdge( n + i , flow.t , 1 );
  flow.solve();
  for( int i = 0 ; i < n ; i ++ )
    for( auto e : flow.G[ i ] )
      if( e.c == 0 ){
        if( fob.count( name[ i ].first.first ) == 0 and
          e.v == n + M[ name[ i ].first.first ] ){
          ans[ name[ i ].second ] = name[ i ].first.first;
          break;
        }
        if( fob.count( name[ i ].first.second ) == 0 and
          e.v == n + M[ name[ i ].first.second ] ){
          ans[ name[ i ].second ] = name[ i ].first.second;
          break;
        }
        puts( "NO" );
        Bye;
      }
  puts( "YES" );
  for( int i = 0 ; i < n ; i ++ )
    printf( "%s\n" , ans[ i ].c_str() );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}