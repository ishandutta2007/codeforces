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
typedef long long LL;
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
#define N 101010
LL n , m , q;
LL a[ N ] , b[ N ];
void init(){
  n = getint();
  m = getint();
  q = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  for( int i = 1 ; i <= m ; i ++ )
    b[ i ] = getint();
}
set<LL> s[ 2 ];
LL ans( LL xx ){
  LL ret = 1000000000000000000LL;
  for( int i = 0 ; i < 2 ; i ++ ){
    auto it = s[ i ].lower_bound( xx );
    if( it != s[ i ].end() )
      ret = min( ret , *it - xx );
    if( it != s[ i ].begin() ){
      it --;
      ret = min( ret , xx - *it );
    }
  }
  return ret;
}
void solve(){
  LL sa = 0;
  for( int i = 1 ; i <= n ; i ++ )
    if( i & 1 ) sa += a[ i ];
    else sa -= a[ i ];
  LL sb = 0;
  for( int i = 1 ; i <= n ; i ++ )
    if( i & 1 ) sb += b[ i ];
    else sb -= b[ i ];
  for( int i = n ; i <= m ; i ++ ){
    if( (i & 1) == (n & 1) )
      s[ i & 1 ].insert( sa - sb );
    else
      s[ i & 1 ].insert( sa + sb );
    if( (i - n + 1) & 1 ) sb -= b[ i - n + 1 ];
    else sb += b[ i - n + 1 ];
    if( (i + 1 ) & 1 ) sb += b[ i + 1 ];
    else sb -= b[ i + 1 ];
  }
  printf( "%lld\n" , ans( 0 ) );
  LL dlt = 0;
  while( q -- ){
    LL li = getint();
    LL ri = getint();
    LL xi = getint();
    if( (ri - li + 1) & 1 ){
      if( li & 1 )
        dlt -= xi;
      else
        dlt += xi;
    }
    printf( "%lld\n" , ans( dlt ) );  
  }
}
int main(){
  init();
  solve();
}