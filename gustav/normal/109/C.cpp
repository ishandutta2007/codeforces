#include <cstdio>
#include <cstring>

typedef long long llint;

int N;
int a, b, c;
int uf[ 100005 ];
int cnt[ 100005 ];

int find( int a ) { if( uf[a] == a ) return a; return uf[a] = find( uf[a] ); }

int lucky( int x ) {
  while( x ) {
    if( x % 10 != 4 && x % 10 != 7 ) return 0;
    x /= 10;
  }
  return 1;
}

int main( void )
{
  scanf( "%d", &N );

  for( int i = 0; i < N; ++i ) uf[i] = i;
  for( int i = 0; i < N-1; ++i ) {
    scanf( "%d%d%d", &a, &b, &c ); --a; --b;

    if( lucky( c ) ) continue;

    int fa = find( a );
    int fb = find( b );

    uf[fa] = fb;
  }
  
  for( int i = 0; i < N; ++i )
    ++cnt[ find( i ) ];

  llint Sol = 0;

  for( int i = 0; i < N; ++i ) 
    Sol += (llint)cnt[i] * (llint)( N - cnt[i] ) * (llint) ( N - cnt[i] - 1 );

  printf( "%I64d\n", Sol );

  return 0;
}