#include <bits/stdc++.h>
#define X 505050
#define N 1510101
char c[ N ];
int n , nt , st[ X ] , len[ X ];
void init(){
  scanf( "%d" , &n );
  for( int i = 0 ; i < n ; i ++ ){
    scanf( "%s" , c + nt );
    st[ i ] = nt;
    len[ i ] = strlen( c + nt );
    nt += len[ i ] + 1;
  }
}
int dp[ N ] , fr[ N ] , bst[ N ];
void go( int nn , int til ){
  if( nn < 0 ) return;
  go( nn - 1 , fr[ til ] );
  for( int i = st[ nn ] ; i <= til ; i ++ )
    putchar( c[ i ] );
  puts( "" );
}
void solve(){
  for( int i = 0 ; i < nt ; i ++ )
    dp[ i ] = N;
  for( int i = st[ 0 ] ; i < st[ 0 ] + len[ 0 ] ; i ++ )
    dp[ i ] = len[ 0 ] - i - 1 , bst[ i ] = i;
  for( int i = 1 ; i < n ; i ++ ){
    int lcp = 0;
    while( lcp < len[ i ] and lcp < len[ i - 1 ] and 
           c[ st[ i - 1 ] + lcp ] == c[ st[ i ] + lcp ] )
      lcp ++;
    bool gr = false;
    if( c[ st[ i ] + lcp ] > c[ st[ i - 1 ] + lcp ] ) gr = true;
    for( int j = st[ i ] , bye = len[ i ] - 1 ; j < st[ i ] + len[ i ] ; j ++ , bye -- ){
      int bdp;
      if( j < st[ i ] + lcp )
        bdp = bst[ st[ i - 1 ] + j - st[ i ] ];
      else if( gr )
        bdp = bst[ st[ i - 1 ] + len[ i - 1 ] - 1 ];
      else
        bdp = bst[ st[ i - 1 ] + lcp - 1 ];
      if( dp[ bdp ] + bye < dp[ j ] ){
        dp[ j ] = dp[ bdp ] + bye;
        fr[ j ] = bdp;
      }
    }
    bst[ st[ i ] ] = st[ i ];
    for( int j = st[ i ] + 1 ; j < st[ i ] + len[ i ] ; j ++ ){
      bst[ j ] = j;
      if( dp[ bst[ j - 1 ] ] < dp[ j ] )
        bst[ j ] = bst[ j - 1 ];
    }
  }
  int ans = st[ n - 1 ];
  for( int i = st[ n - 1 ] ; i < st[ n - 1 ] + len[ n - 1 ] ; i ++ )
    if( dp[ i ] < dp[ ans ] )
      ans = i;
  go( n - 1 , ans );
}
int main(){
  init();
  solve();
}