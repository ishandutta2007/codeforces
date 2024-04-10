#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 1000000007;
LL add( LL a , LL b ){
  a += b;
  return a >= mod ? a - mod : a;
}
LL sub( LL a , LL b ){
  a -= b;
  return a < 0 ? a + mod : a;
}
LL mul( LL a , LL b ){
  a *= b;
  return a >= mod ? a % mod : a;
}
#define N 1000001
int n , a[ N ] , x , c[ N ] , two[ N ] , ans;
int main(){
  two[ 0 ] = 1;
  for( int i = 1 ; i < N ; i ++ )
    two[ i ] = add( two[ i - 1 ] , two[ i - 1 ] );
  cin >> n;
  while( n -- ){
    cin >> x;
    a[ x ] ++;
  }
  for( int i = 2 ; i < N ; i ++ )
    for( int j = i ; j < N ; j += i )
      c[ i ] += a[ j ];
  for( int i = 2 ; i < N ; i ++ )
    if( c[ i ] )
      a[ i ] = mul( two[ c[ i ] - 1 ] , c[ i ] );
  for( int i = N - 1 ; i > 1 ; i -- ){
    for( int j = i + i ; j < N ; j += i )
      a[ i ] = sub( a[ i ] , a[ j ] );
    ans = add( ans , mul( i , a[ i ] ) );
  }
  cout << ans << endl;
}