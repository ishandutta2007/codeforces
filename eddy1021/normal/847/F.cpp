/*********************************************/
/*            _     _       _  ___ ____  _   */
/*    ___  __| | __| |_   _/ |/ _ \___ \/ |  */
/*   / _ \/ _` |/ _` | | | | | | | |__) | |  */
/*  |  __/ (_| | (_| | |_| | | |_| / __/| |  */
/*   \___|\__,_|\__,_|\__, |_|\___/_____|_|  */
/*                    |___/                  */
/*                                           */
/*********************************************/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define N 111
int n , k , m , a , g[ N ] , v[ N ];
bool ok[ N ] , gg[ N ];
int lst[ N ] , vv[ N ];
bool cmp( pair< pair<int,int> , int > p1,
          pair< pair<int,int> , int > p2 ){
  if( p1.first.first !=
      p2.first.first )
    return p1.first.first > p2.first.first;
  return p1.first.second < p2.first.second;
}
bool win( int he , int me ){
  if( vv[ he ] > vv[ me ] ) return true;
  if( vv[ he ] == vv[ me ] and
      lst[ he ] < lst[ me ] )
    return true;
  return false;
}
bool okay( int who ){
  if( v[ who ] == 0 ) return false;
  if( k == n ) return true;
  for( int i = 1 ; i <= n ; i ++ )
    lst[ i ] = -1 , vv[ i ] = 0;
  for( int i = 0 ; i < a ; i ++ ){
    vv[ g[ i ] ] ++;
    lst[ g[ i ] ] = i;
  }
  vector< pair<pair<int,int>,int> > wt;
  for( int i = 1 ; i <= n ; i ++ ){
    if( i == who ) continue;
    wt.push_back( { { vv[ i ] , lst[ i ] } , i } );
  }
  sort( wt.begin() , wt.end() , cmp );
  size_t iter = 0;
  for( int i = a ; i <= m ; i ++ ){
    while( iter < wt.size() and win( wt[ iter ].second , who ) )
      iter ++;
    if( i == m or iter >= wt.size() ) break;
    vv[ wt[ iter ].second ] ++;
    lst[ wt[ iter ].second ] = i;
  }
  return (int)iter < k;
}
bool gggg( int who ){
  for( int i = 1 ; i <= n ; i ++ )
    lst[ i ] = -1 , vv[ i ] = 0;
  for( int i = 0 ; i < a ; i ++ ){
    vv[ g[ i ] ] ++;
    lst[ g[ i ] ] = i;
  }
  for( int i = a ; i < m ; i ++ ){
    vv[ who ] ++;
    lst[ who ] = i;
  }
  vector< pair<pair<int,int>,int> > wt;
  for( int i = 1 ; i <= n ; i ++ )
    wt.push_back( { { vv[ i ] , lst[ i ] } , i } );
  sort( wt.begin() , wt.end() , cmp );
  for( size_t i = 0 ; i < wt.size() ; i ++ )
    if( wt[ i ].second == who ){
      if( (int)i < k and vv[ who ] == 0 )
        return true;
      return (int)i >= k;
    }
  return false;
}
int main(){
#ifdef ONLINE_JUDGE
  //freopen( "" , "r" , stdin );
  //freopen( "" , "w" , stdout );
#endif
  cin >> n >> k >> m >> a;
  for( int i = 0 ; i < a ; i ++ ){
    cin >> g[ i ];
    v[ g[ i ] ] ++;
  }
  for( int i = 1 ; i <= n ; i ++ )
    ok[ i ] = okay( i );
  for( int i = 1 ; i <= n ; i ++ )
    gg[ i ] = gggg( i );
  for( int i = 1 ; i <= n ; i ++ ){
    int x = 2;
    if( ok[ i ] ) x = 1;
    if( gg[ i ] ) x = 3;
    printf( "%d%c" , x , " \n"[ i == n ] );
  }
}