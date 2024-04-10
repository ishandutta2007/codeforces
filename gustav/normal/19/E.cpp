#include <cmath>
#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 10005
#define MAXM 10005

struct edge {
  int b, id;
  edge() { b = id = 0; }
  edge( int B, int ID ) { b = B; id = ID; }
};

int N, M;
int a, b;

int col[ MAXN ];
int dis[ MAXN ];
int dad[ MAXN ];
int now;

int f[ MAXM ];
int fcnt;

vector< edge > G[ MAXN ];

int bcnt[ MAXN ][ 2 ];
vector< int > v;

bool color( int n, int c ) {
  bool ret = 1;
  col[n] = c;

  for( int i = 0; i < G[n].size(); ++i ) {
    if( col[G[n][i].b] && col[G[n][i].b] != 3-c ) {
      if( !f[G[n][i].id] ) ++fcnt;
      f[G[n][i].id] = 1;
      ret = 0;
    }
    else if( !col[G[n][i].b] ) {
      if( !color( G[n][i].b, 3-c ) ) ret = 0;
    }
  }

  return ret;
}

void dfs( int n ) {
  dis[n] = ++now;

  for( int i = 0; i < G[n].size(); ++i ) {
    if( G[n][i].id == dad[n] ) continue;
    if( dis[G[n][i].b] ) {
      if( dis[G[n][i].b] < dis[n] ) ++bcnt[n][f[G[n][i].id]];
      if( dis[G[n][i].b] > dis[n] ) --bcnt[n][f[G[n][i].id]];
    }
    else {
      dad[G[n][i].b] = G[n][i].id;
      dfs( G[n][i].b );

      bcnt[n][0] += bcnt[G[n][i].b][0];
      bcnt[n][1] += bcnt[G[n][i].b][1];

      if( bcnt[G[n][i].b][1] == fcnt && bcnt[G[n][i].b][0] == 0 )
	v.push_back( G[n][i].id );
    }
  }
}

int mark;
int bcol[ MAXN ];

vector< int > B;

bool bcolor( int n, int c ) {
  bool ret = 1;
  bcol[n] = c;

  for( int i = 0; i < G[n].size(); ++i ) {
    if( G[n][i].id == mark ) continue;
    if( bcol[G[n][i].b] && bcol[G[n][i].b] != 3-c ) {
      ret = 0;
    }
    else if( !bcol[G[n][i].b] ) {
      if( !bcolor( G[n][i].b, 3-c ) ) ret = 0;
    }
  }

  return ret;
}


void brute() {
  for( int i = 0; i < M; ++i ) {
    mark = i;
    memset( bcol, 0, sizeof bcol );
    bool ccol = 1;
    for( int j = 1; j <= N; ++j )
      if( !bcol[j] && !bcolor( j, 1 ) ) ccol = 0;
    if( ccol ) B.push_back( i );
  }
}

int main( void )
{
  scanf( "%d%d", &N, &M );

  for( int i = 0; i < M; ++i ) {
    scanf( "%d%d", &a, &b );
    G[a].push_back( edge( b, i ) );
    G[b].push_back( edge( a, i ) );
  }

  int bad = -1;

  for( int i = 1; i <= N; ++i ) {
    if( col[i] ) continue;
    if( !color( i, 1 ) ) bad = i;
  }

  if( fcnt == 1 )
    for( int i = 0; i < M; ++i )
      if( f[i] ) v.push_back( i );

  if( bad == -1 ) {
    printf( "%d\n", M );
    for( int i = 1; i <= M; ++i )
      printf( "%d ", i );
    putchar( '\n' );
  }
  else {
    dad[bad] = -1;
    dfs( bad );
    sort( v.begin(), v.end() );
    /*

    printf( "::%d\n", bcnt[3][1] );
    printf( "::%d\n", bcnt[3][0] );
    */

    //if( v != B ) printf( "bug\n" );

    printf( "%d\n", v.size() );
    for( int i = 0; i < v.size(); ++i )
      printf( "%d ", v[i]+1 );
    putchar( '\n' );
    putchar( '\n' );
    
  }

  return 0;
}