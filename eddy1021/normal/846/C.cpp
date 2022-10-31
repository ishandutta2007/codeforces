#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 5140
LL n , a[ N ] , s[ N ] , ss[ N ];
LL lb[ N ] , rb[ N ];
LL ls[ N ] , rs[ N ];
int main(){
  cin >> n;
  for( int i = 0 ; i < n ; i ++ ){
    cin >> a[ i ];
    ss[ i ] = s[ i ] = a[ i ];
    if( i ) s[ i ] += s[ i - 1 ];
  }
  for( int i = n - 2 ; i >= 0 ; i -- )
    ss[ i ] += ss[ i + 1 ];
  LL ans = s[ n - 1 ] , b[ 3 ] = { n , n , n };
  LL bst = -1 , bs = 0;
  for( int i = 0 ; i < n ; i ++ ){
    if( s[ i ] > bs ) bs = s[ i ] , bst = i;
    ls[ i ] = bs + bs - s[ i ];
    lb[ i ] = bst;
  }
  if( ls[ n - 1 ] > ans ){
    ans = ls[ n - 1 ];
    b[ 0 ] = lb[ n - 1 ] + 1;
    b[ 1 ] = n;
    b[ 2 ] = n;
  }
  bst = n , bs = 0;
  for( int i = n - 1 ; i >= 0 ; i -- ){
    if( ss[ i ] < bs ) bs = ss[ i ] , bst = i;
    rs[ i ] = ss[ i ] - bs - bs;
    rb[ i ] = bst;
  }
  for( int i = 0 ; i + 1 < n ; i ++ ){
    LL tans = ls[ i ] + rs[ i + 1 ];
    if( tans <= ans ) continue;
    ans = tans;
    b[ 0 ] = lb[ i ] + 1;
    b[ 1 ] = i + 1;
    b[ 2 ] = rb[ i + 1 ];
  }
  cout << b[ 0 ] << " ";
  cout << b[ 1 ] << " ";
  cout << b[ 2 ] << endl;
}