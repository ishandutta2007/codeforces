/***********************************************************/
/*       _________________       ________________________  */
/*  ___________  /_____  /____  ___<  /_  __ \_|__ \_<  /  */
/*  _  _ \  __  /_  __  /__  / / /_  /_  / / /___/ /_  /   */
/*  /  __/ /_/ / / /_/ / _  /_/ /_  / / /_/ /_  __/_  /    */
/*  \___/\__,_/  \__,_/  _\__, / /_/  \____/ /____//_/     */
/*                       /____/                            */
/*                                                         */
/***********************************************************/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define N 1021
int n , a[ N ] , asked;
inline int ask( int l , int r ){
  assert( ++ asked <= 15 );
#ifdef TEST
  int ret = 0;
  for( int i = 1 ; i <= n ; i ++ )
    if( i < l or i > r )
      ret += a[ i ] == 1;
    else
      ret += a[ i ] == 0;
  return ret;
#else
  printf( "? " );
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%c" , "01"[ l <= i and i <= r ] );
  puts( "" );
  fflush( stdout );
  int ret; scanf( "%d" , &ret );
  return ret;
#endif
}
int ans[ 2 ];
inline void answer(){
#ifdef TEST
  if( a[ ans[ 0 ] ] or !a[ ans[ 1 ] ] )
    puts( "WA" );
  else
    puts( "AC" );
  exit( 0 );
#else
  assert( ans[ 0 ] and ans[ 1 ] );
  printf( "! %d %d\n" , ans[ 0 ] , ans[ 1 ] );
  fflush( stdout );
  exit( 0 );
#endif
}
int tot1;
void go( int l , int r ){
  int mid = (l + r) >> 1;
  int dlt = ask( l , mid ) - tot1;
  // zer = one + dlt
  // one + one + dlt = all
  int all = mid - l + 1;
  int one = ( all - dlt ) / 2;
  int zer = all - one;
  if( one == all ){
    ans[ 1 ] = l;
    if( ans[ 0 ] and ans[ 1 ] ) return;
    go( mid + 1 , r );
    return;
  }
  if( zer == all ){
    ans[ 0 ] = l;
    if( ans[ 0 ] and ans[ 1 ] ) return;
    go( mid + 1 , r );
    return;
  }
  go( l , mid );
}
int main(){
  scanf( "%d" , &n );
#ifdef TEST
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = rand() & 1;
#endif
  tot1 = ask( 0 , 0 );
  go( 1 , n );
  answer();
}