#include <cstdio>

int main( void )
{
   long long n, m, a;
   scanf( "%I64d%I64d%I64d", &n, &m, &a );
   printf( "%I64d\n", (( n+a-1 )/a)*(( m+a-1 )/a) );

   return 0;
}