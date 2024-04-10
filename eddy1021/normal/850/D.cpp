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
struct Maxflow {
  static const int MAXV = 210;
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
    //printf( "%d -(%d)-> %d\n" , u , c , v );
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
int m , a[ 32 ] , s , sa[ 32 ];
clock_t sc;
void init(){
  srand( time(0) );
  //srand( 514 * 0x1021 );
  sc = clock();
#ifdef TEST
  for( int i = 0 ; i < 31 ; i ++ )
    if( rand() % 5 )
      a[ m ++ ] = i;
#else
  m = getint();
  for( int i = 0 ; i < m ; i ++ )
    a[ i ] = getint();
#endif
  sort( a , a + m );
  s = accumulate( a , a + m , 0 );
  for( int i = m - 1 ; i >= 0 ; i -- )
    sa[ i ] = sa[ i + 1 ] + a[ i ];
}
int d[ 111 ] , cn , tar;
int f( int x ){
  return x * ( x - 1 ) / 2;
}
int od[ 111 ] , id[ 111 ];
int ans[ 111 ][ 111 ] , pp[ 111 ];
pair<int,int> wt[ 111 ];
void gogo( bool flag ){
  vector< pair<int,int> > v;
  for( int i = 0 , sd = 0 ; i < cn ; i ++ ){
    sd += d[ i ];
    assert( sd >= f( i + 1 ) );
    if( i + 1 == cn )
      assert( sd == f( i + 1 ) );
  }
  //for( int i = 0 ; i < cn ; i ++ )
    //printf( "%d%c" , d[ i ] , " \n"[ i + 1 == cn ] );
  //printf( "%d\n" , cn );
  for( int i = 0 ; i < cn ; i ++ )
    for( int j = 0 ; j < cn ; j ++ )
      ans[ i ][ j ] = 0;
  for( int i = 0 ; i < cn ; i ++ )
    v.push_back( { d[ i ] , i } );
  while( v.size() ){
    sort( v.begin() , v.end() );
    int nd = v.back().first;
    int who = v.back().second;
    v.pop_back();
    assert( nd <= (int)v.size() );
    for( size_t i = 0 ; i < v.size() ; i ++ )
      if( i < nd )
        ans[ who ][ v[ i ].second ] = 1;
      else{
        ans[ v[ i ].second ][ who ] = 1;
        v[ i ].first --;
      }
  }

  //flow.init( cn + cn );
  //for( int i = 0 ; i < cn ; i ++ )
    //pp[ i ] = i;
  //for( int i = 0 ; i < cn ; i ++ ){
    //if( od[ i ] )
      //flow.addEdge( flow.s , i , od[ i ] );
    //if( id[ i ] )
      //flow.addEdge( i + cn , flow.t , id[ i ] );
    //if( flag )
      //random_shuffle( pp , pp + cn );
    //for( int j = 0 ; j < cn ; j ++ ) if( i != pp[ j ] )
      //flow.addEdge( i , pp[ j ] + cn , 1 );
  //}
  //bool nd = true;
  //for( int i = 0 ; i < cn ; i ++ )
    //for( int j = 0 ; j < cn ; j ++ )
      //ans[ i ][ j ] = 0;
  //bool first = true;
  //int ntar = tar;
  //while( nd ){
    //nd = false;
    //if( flow.solve() != ntar )
      //return;
    //first = false;
    ////puts( "====" );
    //int wtc = 0;
    //for( int i = 0 ; i < cn ; i ++ )
      //for( auto e : flow.G[ i ] ){
        ////if( e.c == 0 )
          ////cerr << i << " " << e.v << endl;
        //if( e.c == 0 and cn <= e.v and e.v < cn + cn ){
          //int j = e.v - cn;
          ////cerr << i << " " << j << endl;
          //if( ans[ j ][ i ] ){
            //nd = true;
            //wt[ wtc ++ ] = { i , j };
          //}else
            //ans[ i ][ j ] = 1;
        //}
      //}
    //if( nd ){
      //flow.init( cn + cn );
      ////if( wtc & 1 )
        ////return;
      //ntar = wtc;
      //for( int k = 0 ; k < wtc ; k ++ ){
        //pair<int,int>& i = wt[ k ];
        //flow.addEdge( flow.s , i.first , 1 );
        //flow.addEdge( i.second + cn , flow.t , 1 );
      //}
      //for( int i = 0 ; i < cn ; i ++ )
        //for( int j = 0 ; j < cn ; j ++ )
          //if( i != j and !ans[ i ][ j ] and !ans[ j ][ i ] )
            //flow.addEdge( i , j + cn , 1 );
    //}
  //}
  for( int i = 0 ; i < cn ; i ++ )
    for( int j = 0 ; j < cn ; j ++ )
      if( i != j and ans[ i ][ j ] == ans[ j ][ i ] ){
        //cerr << "gg i j " << ans[ i ][ j ] << endl;
        return;
      }
  vector<int> vv;
  for( int i = 0 ; i < cn ; i ++ ){
    int cnt = 0;
    ans[ i ][ i ] = 0;
    for( int j = 0 ; j < cn ; j ++ )
      cnt += ans[ i ][ j ];
    vv.push_back( cnt );
  }
  sort( vv.begin() , vv.end() );
  vv.resize( unique( vv.begin() , vv.end() ) - vv.begin() );
  if( (int)vv.size() != m ){
    //cerr << "gg m" << endl;
    //for( auto i : vv )
      //cerr << i << " ";
    //cerr << endl;
    return;
  }
  for( int i = 0 ; i < m ; i ++ )
    if( vv[ i ] != a[ i ] ){
      //cerr << "gg i" << endl;
      return;
    }
  printf( "%d\n" , cn );
  for( int i = 0 ; i < cn ; i ++ , puts( "" ) )
    for( int j = 0 ; j < cn ; j ++ )
      printf( "%d" , ans[ i ][ j ] );
  exit(0);
}
void go( int now , int ptr , int sumd ){
  //printf( "%d %d %d\n" , now , ptr , sumd );
  if( now == cn ){
    if( clock() - sc > 1.9 * CLOCKS_PER_SEC ){
      puts( "=(" );
      Bye;
    }
    if( ptr == m and sumd == tar )
      gogo( false );
    return;
  }
  if( ptr == m )
    return;
  for( int i = 1 ; ; i ++ ){
    if( a[ ptr ] == 0 and i > 1 ) break;
    if( a[ ptr ] + 1 == cn and i > 1 ) break;
    d[ now ] = a[ ptr ];
    sumd += d[ now ];
    if( sumd < f( now + 1 ) ) break;
    if( now + m - ptr - 1 > cn ) break;
    if( sumd + sa[ ptr + 1 ] > tar ) break;
    go( now + 1 , ptr + 1 , sumd );
    now ++;
  }
}
void solve(){
  for( int i = a[ m - 1 ] + 1 ; ; i ++ ){
    int nd = ( i * ( i - 1 ) ) / 2;
    if( s + ( i - m ) * a[ m - 1 ] < nd ) break;
    if( s > nd ) continue;
    tar = nd; cn = i;
    go( 0 , 0 , 0 );
  }
  puts( "=(" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}