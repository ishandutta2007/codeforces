#include <cstdio>
#include <cstring>

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100005
#define MAXM 100005

int N, M, Q, CN;
int a, b;

int uf[ MAXN ];

int find( int x ) { return x == uf[x] ? x : uf[x] = find( uf[x] ); }

int dep[ MAXN ];
int dad[ MAXN ];
int dis[ MAXN ];
int low[ MAXN ];
int cut[ MAXN ];
int com[ MAXN ];
int now;

int A[ MAXM ];
int B[ MAXM ];
int top;

vector< int > G[ MAXN ];

int tdep[ 2*MAXN ];
int tdad[ 2*MAXN ];
int tbio[ 2*MAXN ];
int link[ 2*MAXN ][ 19 ];
int comp[ 2*MAXN ][ 19 ];

int good[ 2*MAXN ];
vector< int > T[ 2*MAXN ];

vector< int > g[ MAXN ];
vector< pair< int, int > > E;
queue< int > q;

int color[ MAXN ];

bool bicolorable() {
  for( int i = 0; i < E.size(); ++i ) {
    g[E[i].first].clear();
    color[E[i].first] = 0;
    g[E[i].second].clear();
    color[E[i].second] = 0;
  }

  while( !q.empty() ) q.pop();
  int source = 0;

  for( int i = 0; i < E.size(); ++i ) {
    source = E[i].first;
    g[E[i].first].push_back( E[i].second );
    g[E[i].second].push_back( E[i].first );
  }

  q.push( source );
  color[source] = 1;

  while( !q.empty() ) {
    int n = q.front(); q.pop();
    for( int i = 0; i < g[n].size(); ++i ) {
      if( color[g[n][i]] && color[g[n][i]] != 3 - color[n] ) return 0;
      if( !color[g[n][i]] ) q.push( g[n][i] );
      color[g[n][i]] = 3 - color[n];
    }
  }

  return 1;
}

void dfs( int n, int d ) {
  dep[n] = d;
  dis[n] = low[n] = ++now;

  for( int i = 0; i < G[n].size(); ++i ) {
    if( G[n][i] == dad[n] ) continue;

    if( dis[G[n][i]] && dis[G[n][i]] < dis[n] ) {
      A[top] = n;
      B[top] = G[n][i];
      ++top;

      low[n] = min( low[n], dis[G[n][i]] );
    }
    else if( !dis[G[n][i]] ){
      int fa = find( n );
      int fb = find( G[n][i] );
      if( fa != fb ) uf[fa] = fb;

      A[top] = n;
      B[top] = G[n][i];
      ++top;


      dad[G[n][i]] = n;
      dfs( G[n][i], d+1 );
      low[n] = min( low[n], low[G[n][i]] );

      if( low[G[n][i]] >= dis[n] ) {
	cut[n] = 1;

	E.clear();
	++CN;

	//printf( "komponenta\n" );

	while( A[top] != n || B[top] != G[n][i] ) {
	  //printf( "brid %d %d\n", A[top-1], B[top-1] );

	  if( cut[A[top-1]] || G[A[top-1]].size() == 1 ) {
	    T[A[top-1]].push_back( CN );
	    T[CN].push_back( A[top-1] );
	    //printf( "tree brid %d %d\n", A[top-1], CN );
	  }

	  if( cut[B[top-1]] || G[B[top-1]].size() == 1 ) {
	    T[B[top-1]].push_back( CN );
	    T[CN].push_back( B[top-1] );
	    //printf( "tree brid %d %d\n", B[top-1], CN );
	  }

	  com[A[top-1]] = com[B[top-1]] = CN;

	  E.push_back( make_pair( A[top-1], B[top-1] ) );
	  --top;
	}

	good[ CN ] = !bicolorable();

      }
    }
  }
}

void tdfs( int n, int d ) {
  tdep[n] = d;

  for( int i = 0; i < T[n].size(); ++i ) {
    if( tbio[T[n][i]] || T[n][i] == tdad[n] ) continue;
    tbio[T[n][i]] = 1;
    tdad[T[n][i]] = n;
    tdfs( T[n][i], d+1 );
  }
}

int main( void )
{
  scanf( "%d%d", &N, &M );

  for( int i = 1; i <= N; ++i )
    uf[i] = i;

  for( int i = 0; i < M; ++i ) {
    scanf( "%d%d", &a, &b );
    G[a].push_back( b );
    G[b].push_back( a );
  }

  CN = N;

  for( int i = 1; i <= N; ++i ) {
    if( dis[i] ) continue;
    cut[i] = 1;
    dfs( i, 1 ); 
    tdfs( i, 1 );
  }

  for( int i = 1; i <= CN; ++i ) {
    link[i][0] = tdad[i];
    comp[i][0] |= good[tdad[i]];
  }

  for( int i = 1; i <= 18; ++i ) {
    for( int j = 1; j <= CN; ++j ) {
      link[j][i] = link[link[j][i-1]][i-1];
      comp[j][i] = comp[j][i-1] || comp[link[j][i-1]][i-1];
    }
  }
  /*

  for( int i = 1; i <= 20; ++i ) {
    if( i == 15 || i == 13 || i == 10 || i == 14 ) continue;
    if( i == 5 || i == 4 || i == 6 || i == 1 ) continue;

    if( find( i ) != find( 5 ) ) {
      printf( "bug %d %d\n", i, 5 );
      break;
    }

    a = i; 
    b = 5;
    printf( " ide %d %d\n", a, b );

    if( dep[a]%2 != dep[b]%2 ) continue;
      
    if( !cut[ a ] ) a = com[ a ];
    if( !cut[ b ] ) b = com[ b ];

    bool good_comp = good[a] || good[b];
    if( tdep[a] < tdep[b] ) swap( a, b );

    for( int i = 18; i >= 0; --i ) {
      if( tdep[link[a][i]] >= tdep[b] ) {
	good_comp |= comp[a][i];
	a = link[a][i];
      }
    }

    for( int i = 18; i >= 0; --i ) {
      if( link[a][i] == link[b][i] ) continue;
      good_comp |= comp[a][i];
      good_comp |= comp[b][i];
      a = link[a][i];
      b = link[b][i];
    }

    if( a != b ) good_comp = good_comp || good[dad[a]];

    if( !good_comp ) {
      printf( "bug %d %d\n", a, b );
      break;
    }

  }
  */


  scanf( "%d", &Q );

  for( int i = 0; i < Q; ++i ) {
    scanf( "%d%d", &a, &b );

    if( a == b ) puts( "No" );
    else if( find( a ) != find( b ) ) puts( "No" );
    else if( dep[ a ] % 2 != dep[ b ] % 2 ) puts( "Yes" );
    else {
      if( !cut[ a ] ) a = com[ a ];
      if( !cut[ b ] ) b = com[ b ];

      bool good_comp = good[a] || good[b];
      if( tdep[a] < tdep[b] ) swap( a, b );
      /*

      printf( "u pocetku imam %d\n", good_comp );
      printf( "cvorovi %d i %d\n", a, b );
      printf( "dubine %d i %d\n", tdep[a], tdep[b] );

      printf( "%d %d\n", a, link[a][0] );
      printf( "%d\n", link[a][1] );
      */

      for( int i = 18; i >= 0; --i ) {
	if( tdep[link[a][i]] >= tdep[b] ) {
	  good_comp |= comp[a][i];
	  a = link[a][i];
	}
      }
      /*

      printf( "sada %d\n", good_comp );
      printf( "cvorovi %d i %d\n", a, b );
      printf( "dubine %d i %d\n", tdep[a], tdep[b] );
      */

      for( int i = 18; i >= 0; --i ) {
	if( link[a][i] == link[b][i] ) continue;
	good_comp |= comp[a][i];
	good_comp |= comp[b][i];
	a = link[a][i];
	b = link[b][i];
      }

      if( a != b ) good_comp = good_comp || good[tdad[a]];

      puts( good_comp ? "Yes" : "No" );
    }
  }

  return 0;
}