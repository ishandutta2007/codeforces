#include <cmath>
#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;

int n, w, m;
vector< pair< int, double > > v[ 55 ];

int main( void )
{
  scanf( "%d%d%d", &n, &w, &m );

  double cup = double( w * n ) / double( m );
  double left = 0.0;
  int curr = 0;
  bool bad = 0;

  for( int i = 0; i < m; ++i ) {
    double now = min( left, cup );
    if( fabs( now ) > 1e-9 ) v[i].push_back( make_pair( curr, now ) );

    left = 0.0;

    for( ++curr; now + 1e-9 < cup && curr <= n; ++curr ) {
      double take = min( double( w ), cup - now );
      v[i].push_back( make_pair( curr, take ) );
      left = ( w - take );
      now += take;
    }

    if( now + 1e-9 < cup ) bad = 1;

    --curr;
  }

  if( bad ) puts( "NO" );
  else {
    puts( "YES" );

    for( int i = 0; i < m; ++i ) {
      for( int j = 0; j < v[i].size(); ++j )
	printf( "%d %.6lf ", v[i][j].first, v[i][j].second );
      putchar( '\n' );
    }
  }

  


  return 0;
}