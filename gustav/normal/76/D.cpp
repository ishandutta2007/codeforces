#include <cstdio>
#include <cstring>

typedef unsigned long long lluint;

lluint A, B;

int main( void )
{
  scanf( "%I64d%I64d", &A, &B );

  lluint AmX = 0;
  lluint BxX = 0;

  for( int i = 63; i >= 0; --i ) {
    int ba = ( ( A >> i )&1 );
    int bb = ( ( B >> i )&1 );

    //printf( "%d", ba );

    lluint CAmX = AmX;
    lluint CBxX = BxX;

    AmX ^= ( lluint( ba ) << i );
    BxX ^= ( lluint( bb ) << i );

    if( ba == 0 && bb == 0 && CAmX > CBxX ) {
      AmX -= ( 1LLU << i );
      BxX ^= ( 1LLU << i );
    }
    
    if( ba == 1 && bb == 0 && CAmX > CBxX ) {
      AmX -= ( 1LLU << i );
      BxX ^= ( 1LLU << i );
    }
  }

  if( AmX != BxX ) printf( "-1\n" );
  else printf( "%I64d %I64d\n", A - AmX, AmX );

  return 0;
}