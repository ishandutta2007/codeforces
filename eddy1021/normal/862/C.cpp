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
int n , x;
int main(){
  cin >> n >> x;
  vector<int> vv;
  if( n == 2 and x == 0 ){
    puts( "NO" );
    exit( 0 );
  }
  if( n == 1 ) vv = { x };
  else{
    int sx = x;
    for( int st = 0 ; ; st ++ ){
      vv.clear();
      x = sx;
      for( int i = 0 ; i < n - 2 ; i ++ ){
        vv.push_back( st + i );
        x ^= (st + i);
      }
      if( x == 0 ) continue;
      vv.push_back( (1 << 18) ^ x );
      vv.push_back( (1 << 18)     );
      sort( vv.begin() , vv.end() );
      if( vv.back() <= 1000000 ) break;
    }
  }
  puts( "YES" );
  for( size_t i = 0 ; i < vv.size() ; i ++ )
    printf( "%d%c" , vv[ i ] , " \n"[ i + 1 == vv.size() ] );
}