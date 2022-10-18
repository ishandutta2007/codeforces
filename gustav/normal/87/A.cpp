#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long llint;

int a, b;

int main( void )
{
  scanf( "%d%d", &a, &b );

  llint L = llint( a ) * ( llint( b ) / __gcd( (llint)a, (llint)b ) );

  llint A = L / a;
  llint B = L / b;

  if( a > b ) --B;
  else --A;

  if( A == B ) printf( "Equal\n" );
  else if( A > B ) printf( "Dasha\n" );
  else if( A < B ) printf( "Masha\n" );

  return 0;
}