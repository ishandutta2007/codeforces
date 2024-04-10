#include <cstdio>
#include <cstring>

struct num {
   int p[ 1000 ], n;
   num() { n = 1; p[0] = 1; }
   inline void mult( int x ) {
      for( int i = 0; i < n; ++i ) p[i] *= x;
      for( int i = 0; i < n; ++i ) {
	 p[i+1] += p[i]/10;
	 p[i] %= 10;
	 if( p[i+1] ) ++n;
      }
      while( n && !p[n-1] ) --n;
   }
   inline void print() {
      for( int i = n-1; i >= 0; --i )
	 printf( "%d", p[i] );
      putchar( '\n' );
   }
} pp;

int pr[ 1000 ];
int N;

int main( void )
{
   scanf( "%d", &N );

   if( N == 2 ) { printf( "-1\n" ); return 0; }

   int cnt = 0;
   for( int i = 3; cnt < 50; ++i ) {
      bool ok = 1;
      for( int j = 2; j*j <= i; ++j )
	 if( i % j == 0 ) { ok = 0; break; }
      if( !ok ) continue;
      pr[cnt++] = i;
   }

   for( int i = 0; i < N-1; ++i ) {
      printf( "%d\n", 2*pr[i] );
      pp.mult( pr[i] );
   }

   pp.print();

   return 0;
}