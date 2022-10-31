// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF 1023456789
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-7
int getint(){
    int _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 210
#define M 100010
#define P 20010
bool p[ P ];
void build(){
    for( int i = 2 ; i < P ; i ++ ) if( !p[ i ] )
        for( int j = P / i ; j >= i ; j -- )
            p[ i * j ] = true;
}
int n;
vector<PII> even , odd;
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        int tmp = getint();
        if( tmp % 2 ) odd.PB( MP( tmp , i ) );
        else even.PB( MP( tmp , i ) );
    }
}
const int MAXN = 210;

int s, t;

struct Edge
{
  int v, c, r;
  Edge(int _v, int _c, int _r)
  {v = _v, c = _c, r = _r;}
};

vector<Edge> G[MAXN*2];
int iter[MAXN*2], d[MAXN*2], gap[MAXN*2], tot;

inline void flowinit(int x)
{
  tot = x;
  for(int i = 0; i <= x; i++)
  {
    G[i].clear();
    iter[i] = d[i] = gap[i] = 0;
  }
}

void inline addEdge(int u, int v, int c)
{
  G[u].push_back(Edge(v, c, (int)G[v].size() ));
  G[v].push_back(Edge(u, 0, (int)G[u].size() - 1));
}

int dfs(int tp, int flow)
{
  if(tp == t) return flow;
  for(int &i = iter[tp]; i < (int)G[tp].size(); i++)
  {
    Edge &e = G[tp][i];
    if(e.c > 0 && d[tp] == d[e.v]+1)
    {
      int f = dfs(e.v, min(flow, e.c));
      if(f)
      {
        e.c -= f;
        G[e.v][e.r].c += f;
        return f;
      }
    }
  }
  if( (--gap[d[tp]]) == 0) d[s] = tot;
  else
  {
    d[tp]++;
    iter[tp] = 0;
    ++gap[d[tp]];
  }
  return 0;
}

int inline maxflow()
{
  //puts("MF");
  int res = 0;
  gap[0] = tot;
  for(res = 0; d[s] < tot; res += dfs(s, INF));
  return res;
}

void go(){
    flowinit( n + 2 );
    s = n + 1; t = n + 2;
    for( int i = 0 ; i < (int)odd.size() ; i ++ )
        for( int j = 0 ; j < (int)even.size() ; j ++ )
            if( !p[ odd[ i ].FI + even[ j ].FI ] )
                addEdge( odd[ i ].SE , even[ j ].SE , 1 );
    for( int i = 0 ; i < (int)odd.size() ; i ++ )
        addEdge( s , odd[ i ].SE , 2 );
    for( int i = 0 ; i < (int)even.size() ; i ++ )
        addEdge( even[ i ].SE , t , 2 );
}
vector<int> v2[ N ];
vector< vector<int> > ans;
bool got[ N ];
vector<int> tans;
bool good[ N ][ N ];
void find( int idx ){
    int now = idx;
    got[ now ] = true; tans.PB( now ); 
    for( int i = 0 ; i < (int)v2[ now ].size() ; i ++ )
        if( !got[ v2[ now ][ i ] ] ){
            find( v2[ now ][ i ] );
            break;
        }
}
void find_ans(){
    for( int k = 0 ; k < (int)odd.size() ; k ++ ){
        int i = odd[ k ].SE;
        for( int j = 0 ; j < (int)G[ i ].size() ; j ++ )
            if( G[ i ][ j ].c == 0 ){
                if( G[ i ][ j ].v > n ) continue;
//                printf( "%d %d\n" , i , G[ i ][ j ].v );
                v2[ i ].PB( G[ i ][ j ].v );
                v2[ G[ i ][ j ].v ].PB( i );
            }
    }
    for( int i = 1 ; i <= n ; i ++ )
        if( !got[ i ] ){
            tans.clear();
            find( i );
            ans.PB( tans );
        }
    printf( "%d\n" , (int)ans.size() );
    for( int i = 0 ; i < (int)ans.size() ; i ++ ){
        printf( "%d" , (int)ans[ i ].size() );
        for( int j = 0 ; j < (int)ans[ i ].size() ; j ++ )
            printf( " %d" , ans[ i ][ j ] );
        puts( "" );
    }
}
void solve(){
    if( (int)odd.size() != (int)even.size() )
        puts( "Impossible" );
    else{
        go();
        if( maxflow() != n ) puts( "Impossible" );
        else find_ans();
    }
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}