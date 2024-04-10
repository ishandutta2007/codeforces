#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 202020
const LL inf = 1e12;
int n;
vector< pair<int,int> > v;
LL ans;
void go( LL ptr ){
  while( true ){
    LL nptr = ptr + 1;
    while( nptr < n and v[ nptr ].second ) nptr ++;
    if( nptr == n ){
      LL p[ 3 ] = {v[ ptr ].first , v[ ptr ].first , v[ ptr ].first};
      for( LL _ = ptr + 1 ; _ < n ; _ ++ ){
        if( p[ v[ _ ].second ] != -inf )
          ans += v[ _ ].first - p[ v[ _ ].second ];
        p[ v[ _ ].second ] = v[ _ ].first;
      }
      break;
    }
    vector<LL> f[ 3 ];
    f[ 1 ].push_back( v[ ptr ].first );
    f[ 2 ].push_back( v[ ptr ].first );
    for( LL i = ptr + 1 ; i < nptr ; i ++ )
      f[ v[ i ].second ].push_back( v[ i ].first );
    f[ 1 ].push_back( v[ nptr ].first );
    f[ 2 ].push_back( v[ nptr ].first );
    
    LL dlt = v[ nptr ].first - v[ ptr ].first;
    if( f[ 1 ].size() == 2u and
        f[ 2 ].size() == 2u )
      ans += dlt;
    else{
      LL tans = dlt + dlt;
      LL xans = dlt + dlt + dlt;
      LL mx[ 3 ] = {};
      for( size_t i = 1 ; i < f[ 1 ].size() ; i ++ )
        mx[ 1 ] = max( mx[ 1 ] , f[ 1 ][ i ] - f[ 1 ][ i - 1 ] );
      for( size_t i = 1 ; i < f[ 2 ].size() ; i ++ )
        mx[ 2 ] = max( mx[ 2 ] , f[ 2 ][ i ] - f[ 2 ][ i - 1 ] );
      xans -= mx[ 1 ] + mx[ 2 ];
      ans += min( tans , xans );
    }
    ptr = nptr;
  }
  cout << ans << endl;
}
int main(){
  scanf( "%d" , &n );
  for( int i = 0 ; i < n ; i ++ ){
    int xi , tp; char buf[ 9 ];
    scanf( "%d%s" , &xi , buf );
    if( buf[ 0 ] == 'P' ) tp = 0;
    if( buf[ 0 ] == 'R' ) tp = 1;
    if( buf[ 0 ] == 'B' ) tp = 2;
    v.push_back( {xi, tp} );
  }
  sort( v.begin() , v.end() );
  int ptr = 0;
  while( ptr < n and v[ ptr ].second ) ptr ++;
  if( ptr == n ){
    LL p[ 3 ] = { -inf , -inf , -inf };
    for( auto i : v ){
      if( p[ i.second ] != -inf )
        ans += i.first - p[ i.second ];
      p[ i.second ] = i.first;
    }
    cout << ans << endl;
    exit(0);
  }
  for( int i = 0 ; i < ptr ; i ++ )
    if( v[ i ].second == 1 ){
      ans += v[ ptr ].first - v[ i ].first;
      break;
    }
  for( int i = 0 ; i < ptr ; i ++ )
    if( v[ i ].second == 2 ){
      ans += v[ ptr ].first - v[ i ].first;
      break;
    }
  go( ptr );
}