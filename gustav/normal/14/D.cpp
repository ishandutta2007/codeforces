#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;
typedef long long llint;

#define MAXN 100005

int dad[ MAXN ];

llint sol;

int N, a, b;

int up[ MAXN ];
int down[ MAXN ];
int best[ MAXN ];

vector< int > T[ MAXN ];

inline bool cmpf( int a, int b ) {
   if( down[a] != down[b] ) return ( down[a] > down[b] );
   return ( a < b );
}

struct max2 {
   vector< int > v;
   inline void insert( int x ) {
      v.push_back( x );
      sort( v.rbegin(), v.rend() );
      if( v.size() == 3 ) v.pop_back();
   }
   inline llint get() { return llint( v[0] )*v[1]; }
};

void explore( int n ) { // mogu samo dad, down i best
   int wdad = 0;
   max2 maks;
   for( int i = 0; i < T[n].size(); ++i ) {
      if( T[n][i] == dad[n] ) { wdad = i; continue; }
      dad[ T[n][i] ] = n;
      explore( T[n][i] );
      best[n] = max( best[n], best[T[n][i]] );
      maks.insert( best[T[n][i]] );
   }
   swap( T[n][T[n].size()-1], T[n][wdad] );
   sort( T[n].begin(), T[n].end()-1+(n==1), cmpf );
   if( T[n].size() > 1 || n == 1 && T[n].size() >= 1 ) down[n] = down[T[n][0]]+1;
   if( T[n].size() > 2 || n == 1 && T[n].size() >= 2 ) best[n] = max( best[n], down[T[n][0]]+down[T[n][1]]+2 );
   best[n] = max( best[n], down[n] );
   if( maks.v.size() == 2 ) sol = max( sol, maks.get() );
}
void solve( int n ) {
   int mbest = 0;
   for( int i = 0; i < T[n].size()-1+(n==1); ++i ) {
      up[ T[n][i] ] = up[ n ]+1;
      if( i ) up[ T[n][i] ] = max( up[ T[n][i] ], down[ T[n][i-1] ]+2 );
      else if( i+1 < T[n].size()-1+(n==1) ) up[ T[n][i] ] = max( up[ T[n][i] ], down[ T[n][i+1] ]+2 );
      solve( T[n][i] );

      if( i ) sol = max( sol, llint(best[ T[n][i] ])*( down[ T[n][i-1] ]+1 ) );
      else if( i+1 < T[n].size()-1+(n==1) ) sol = max( sol, 
	 llint(best[ T[n][i] ])*( down[ T[n][i+1] ]+1 ) );

      // probaj dva
      if( i >= 2 ) sol = max( sol, llint( best[ T[n][i] ] )*best[n] );
      if( i == 1 && i+1 < T[n].size()-1+(n==1) ) sol = max( sol, 
	 llint( best[ T[n][i] ] )*(down[T[n][0]]+down[T[n][2]]+2) );
      if( i == 0 && i+2 < T[n].size()-1+(n==1) ) sol = max( sol,
	 llint( best[ T[n][i] ] )*(down[T[n][1]]+down[T[n][2]]+2) );

      // neka put ide kroz glavnog, a uzmem i ovo podstablo
      if( i ) sol = max( sol, llint(best[ T[n][i] ])*( up[n]+down[n] ) );
      else if( i+1 < T[n].size()-1+(n==1) ) sol = max( sol, 
	 llint(best[T[n][i]])*( up[n]+down[T[n][i+1]]+1 ) );

      mbest = max( mbest, best[ T[n][i] ] );
   }
   sol = max( sol, llint(up[n])*mbest );
}

int main( void )
{
   scanf( "%d", &N );

   for( int i = 0; i < N-1; ++i ) {
      scanf( "%d%d", &a, &b );
      T[a].push_back( b );
      T[b].push_back( a );
   }

   explore( 1 );
   solve( 1 );
   
   printf( "%lld\n", sol );

   return 0;
}