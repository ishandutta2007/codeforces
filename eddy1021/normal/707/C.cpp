#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a , bs = 1;
void go( LL x ){
  if( x == 1 ) return;
  if( x == 4 ){
    printf( "%lld %lld\n" , 3 * bs , 5 * bs );
    exit( 0 );
  }
  if( x % 2 ){
    LL b = x * x / 2;
    LL c = x * x - b;
    printf( "%lld %lld\n" , b * bs , c * bs );
    exit( 0 );
  }
}
int main(){
  scanf( "%lld" , &a );
  while( true ){
    go( a );
    if( a % 2 ) break;
    a >>= 1; bs <<= 1;
  }
  puts( "-1" );
}