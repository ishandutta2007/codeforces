#include <cstdio>
#include <cstring>

#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
   int a, b, c;
   edge() { a = b = c = 0; }
   edge( int A, int B, int C ) 
      { a = A; b = B; c = C; }
   friend bool operator<( const edge &x, const edge &y ) {
      return ( x.c < y.c );
   }
};

int N, M;
int q[ 1001 ];
int a, b, c;

int dis[ 1001 ];
int bio[ 1001 ];
int taken[ 1001 ];
int cookie;

vector< edge > E;
vector< edge > G[ 1001 ];

stack< int > s;

void topsort( int n ) {
   if( dis[n] ) return;
   dis[n] = 1;
   for( int i = 0; i < G[n].size(); ++i )
      topsort( G[n][i].b );
   s.push( n );
}

int dfs( int n ) {
   if( bio[n] == cookie ) return 0;
   bio[n] = cookie;
   int ret = 1;
   for( int i = 0; i < G[n].size(); ++i ) 
      ret += dfs( G[n][i].b );
   return ret;
}

int main( void )
{
   scanf( "%d", &N );

   for( int i = 0; i < N; ++i )
      scanf( "%d", q+i );
   
   scanf( "%d", &M );
   
   for( int i = 0; i < M; ++i ) {
      scanf( "%d%d%d", &a, &b, &c );
      G[a].push_back( edge( a, b, c ) );
      E.push_back( edge( a, b, c ) );
   }

   sort( E.begin(), E.end() );
   
   for( int i = 1; i <= N; ++i )
      if( !dis[i] ) topsort( i );
   
   cookie = 1;
   int reach = dfs( s.top() );
   s.pop();

   if( reach != N ) { printf( "-1\n" ); return 0; }

   while( !s.empty() ) {
      ++cookie;
      if( dfs( s.top() ) == reach ) { printf( "-1\n" ); return 0; }
      s.pop();
   }

   int Sol = 0;

   memset( taken, 0, sizeof taken );

   for( int i = 0; i < E.size(); ++i ) {
      if( taken[E[i].b] ) continue;
      taken[E[i].b] = 1;
      Sol += E[i].c;
   }

   printf( "%d\n", Sol );

   return 0;
}