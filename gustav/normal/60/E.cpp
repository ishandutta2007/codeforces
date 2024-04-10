#include <cstdio>
#include <cstring>

#include <iostream>
#include <algorithm>

using namespace std;
typedef long long llint;

#define MAXN 1000005

int N; 
llint P;
llint x, y;

llint a[ MAXN ];

inline llint modsq( llint x ) { return ( x*x )%P; }

llint modpow( llint x, llint n ) {
  if( n == 0 ) return 1LL;
  if( n % 2 == 0 ) return modsq( modpow( x, n/2 ) );
  return ( ( modsq( modpow( x, n/2 ) ) )*x )%P;
}

inline void mult( llint *a00, llint *a01, llint *a10, llint *a11, 
   llint b00, llint b01, llint b10, llint b11 ) {
  llint c00 = ( (*a00*b00)%P + (*a01*b10)%P ) % P;
  llint c01 = ( (*a00*b01)%P + (*a01*b11)%P ) % P;
  llint c10 = ( (*a10*b00)%P + (*a11*b10)%P ) % P;
  llint c11 = ( (*a10*b01)%P + (*a11*b11)%P ) % P;
  *a00 = c00;
  *a01 = c01;
  *a10 = c10;
  *a11 = c11;
}

void go( llint *a00, llint *a01, llint *a10, llint *a11, llint n ) {
  if( n == 0 ) {
    *a00 = 1;
    *a01 = 0;
    *a10 = 0;
    *a11 = 1;
    return;
  }

  if( n % 2 == 1 ) {
    llint b00 = *a00;
    llint b01 = *a01;
    llint b10 = *a10;
    llint b11 = *a11;

    go( a00, a01, a10, a11, n/2 );
    mult( a00, a01, a10, a11, *a00, *a01, *a10, *a11 );
    mult( a00, a01, a10, a11, b00, b01, b10, b11 );
  }
  else {
    go( a00, a01, a10, a11, n/2 );
    mult( a00, a01, a10, a11, *a00, *a01, *a10, *a11 );
  }
}



int main( void )
{
  //scanf( "%d%lld%lld%lld", &N, &x, &y, &P );
  cin >> N >> x >> y >> P;


  if( x == 0 ) swap( x, y );

  for( int i = 0; i < N; ++i ) {
    //scanf( "%lld", a+i );
    cin >> a[i];
    a[i] %= P;
  }
  
  if( N == 1 ) {
    //printf( "%lld\n", a[0]%P );
    cout << a[0]%P << "\n";
    return 0;
  }

  llint a00 = +3;
  llint a01 = +0;
  llint a10 = P-1;
  llint a11 = +1;

  go( &a00, &a01, &a10, &a11, x );
  
  llint b00 = +3;
  llint b01 = +0;
  llint b10 = P-1;
  llint b11 = +1;
  
  go( &b00, &b01, &b10, &b11, y );
  
  llint c00 = +0;
  llint c01 = +1;
  llint c10 = +1;
  llint c11 = +1;
  
  go( &c00, &c01, &c10, &c11, x+1 );

  llint g = ( (a00*b00)%P + (a01*b10)%P + (a10*b00)%P + (a11*b10)%P ) % P;
  llint f = ( modpow( 3, x ) * modpow( 3, y ) ) % P;

  llint g0 = ( b00 + b10 ) % P;

  llint Sol = 0;

  for( int i = 1; i < N-1; ++i ) {
    Sol = ( Sol + (f*a[i])%P ) % P;
  }

  Sol = ( Sol + (g*a[0])%P ) % P;
  Sol = ( Sol + (g*a[N-1])%P ) % P;

  llint best = ( (c00*( a[N-2] ))%P + (c10*( a[N-1] ))%P ) % P;

  if( y ) {
    Sol = ( Sol + P - ( ( g0*a[N-1] )%P ) ) % P;
    Sol = ( Sol + P - ( ( modpow( 3, y )*best )%P ) ) % P;
    Sol = ( Sol + (g0*best)%P ) % P;
    Sol = ( Sol + (modpow( 3, y )*a[N-1])%P ) % P;
  }

  //printf( "%llu\n", Sol );
  cout << Sol << "\n";

  return 0;
}