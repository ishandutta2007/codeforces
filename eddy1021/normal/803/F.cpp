#include <bits/stdc++.h>
using namespace std;
#define N 101010
typedef long long LL;
const int mod = 1000000007;
inline int mul( LL a , LL b ){
  a *= b;
  return a >= mod ? a % mod : a;
}
inline int add( int a , int b ){
  a += b;
  return a >= mod ? a - mod : a;
}
inline int sub( int a , int b ){
  a -= b;
  return a < 0 ? a + mod : a;
}
int n , a[ N ] , two[ N ];
vector<int> di[ N ] , mu[ N ];
int main(){
  two[ 0 ] = 1;
  for( int i = 1 ; i < N ; i ++ )
    two[ i ] = mul( two[ i - 1 ] , 2 );
  for( int i = 1 ; i < N ; i ++ )
    for( int j = i ; j < N ; j += i ){
      di[ j ].push_back( i );
      mu[ i ].push_back( j );
    }
  scanf( "%d" , &n );
  for( int i = 0 , x ; i < n ; i ++ ){
    scanf( "%d" , &x );
    for( auto dd : di[ x ] )
      a[ dd ] ++;
  }
  for( int i = 1 ; i < N ; i ++ )
    a[ i ] = sub( two[ a[ i ] ] , 1 );
  for( int i = N - 1 ; i >= 1 ; i -- )
    for( int mm : mu[ i ] )
      if( mm > i )
        a[ i ] = sub( a[ i ] , a[ mm ] );
  printf( "%d\n" , a[ 1 ] );
}