#include <cmath>
#include <cstdio>
#include <cstring>

#include <set>
#include <vector>
#include <algorithm>

using namespace std;
const double eps = 1e-9;

#define MAXN 505

bool lt( double a, double b ) { return a + eps < b; }
bool gt( double a, double b ) { return lt( b, a ); }
bool eq( double a, double b ) { return !lt( a, b ) && !gt( a, b ); }
bool lte( double a, double b ) { return lt( a, b ) || eq( a, b ); }
bool gte( double a, double b ) { return gt( a, b ) || eq( a, b ); }

double dmin( double a, double b ) { return lt( a, b ) ? a : b; }
double dmax( double a, double b ) { return gt( a, b ) ? a : b; }

double sq( double d ) { return d*d; }

int N;
int x[ 4 ][ MAXN ];
int y[ 4 ][ MAXN ];

struct point {
  double x, y;
  point() { x = y = 0.0; }
  point( double X, double Y ) { x = X; y = Y; }
};

bool operator<( point a, point b ) {
  if( eq( a.x, b.x ) ) return lt( a.y, b.y );
  return lt( a.x, b.x );
}
bool operator==( point a, point b ) {
  return eq( a.x, b.x ) && eq( a.y, b.y );
}

double d( point a, point b ) { return sqrt( sq( a.x-b.x ) + sq( a.y-b.y ) ); }

struct segment {
  point a, b;
  segment() { a = point(); b = point(); }
  segment( point A, point B ) { a = A; b = B; }
  double len() { return d( a, b ); }
  double k() { return ( a.y - b.y ) / ( a.x - b.x ); }
  double l() { return a.y - k()*a.x; }
};

double Total;
double Union;

struct line {
  double a, b, c;
  line( point p ) {
    a = p.x;
    b = -1.0;
    c = -p.y;
  }
  line( point p, point q ) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = a*p.x + b*p.y;
  }
};

bool ccutl( line p, line q ) {
  if( eq( p.a*q.b - q.a*p.b, 0.0 ) ) return 0;
  return 1;
}

point cutl( line p, line q ) {
  double x = ( p.c*q.b - q.c*p.b ) / ( p.a*q.b - q.a*p.b );
  double y = ( p.c*q.a - q.c*p.a ) / ( p.b*q.a - q.b*p.a );
  return point( x, y );
}

bool onseg( point p, segment s ) {
  if( lt( p.x, dmin( s.a.x, s.b.x ) ) || gt( p.x, dmax( s.a.x, s.b.x ) ) ) return 0;
  if( lt( p.y, dmin( s.a.y, s.b.y ) ) || gt( p.y, dmax( s.a.y, s.b.y ) ) ) return 0;
  return 1;
}

bool ccut( segment p, segment q ) {
  if( !ccutl( line( p.a, p.b ), line( q.a, q.b ) ) ) return 0;

  point r = cutl( line( p.a, p.b ), line( q.a, q.b ) );

  if( !onseg( r, p ) || !onseg( r, q ) ) return 0;
  return 1;
}

point cut( segment p, segment q ) {
  return cutl( line( p.a, p.b ), line( q.a, q.b ) );
}

struct event {
  double x; int type;
  event() { x = 0.0; type = 0; }
  event( double X, int T ) { x = X; type = T; }
};

bool operator<( event a, event b ) {
  return lt( a.x, b.x );
}

vector< segment > s, A, B;

double solve( vector< segment > *v ) {
  double ret = 0;
  
  vector< point > lines;

  for( int i = 0; i < v->size(); ++i ) 
    lines.push_back( point( (*v)[i].k(), (*v)[i].l() ) );

  sort( lines.begin(), lines.end() );
  lines.resize( unique( lines.begin(), lines.end() )-lines.begin() );

  for( int i = 0; i < lines.size(); ++i ) {
    vector< event > e;

    for( int j = 0; j < s.size(); j += 4 ) {
      bool touch = 0;

      for( int k = 0; k < 4; ++k ) 
	if( lines[i] == point( s[j+k].k(), s[j+k].l() ) ) touch = 1;

      if( touch ) continue;

      vector< point > cuts;

      for( int k = 0; k < 4; ++k ) {
	if( !ccutl( line( lines[i] ), line( s[j+k].a, s[j+k].b ) ) ) continue;
	point r = cutl( line( lines[i] ), line( s[j+k].a, s[j+k].b ) );
	if( onseg( r, s[j+k] ) ) cuts.push_back( r );
      }

      sort( cuts.begin(), cuts.end() );
      cuts.resize( unique( cuts.begin(), cuts.end() ) - cuts.begin() );
      
      if( cuts.size() == 2 ) {
	e.push_back( event( cuts[0].x, 0 ) );
	e.push_back( event( cuts[1].x, 1 ) );
      }
    }

    for( int j = 0; j < v->size(); ++j ) {
      if( lines[i] == point( (*v)[j].k(), (*v)[j].l() ) ) {
	e.push_back( event( dmin( (*v)[j].a.x, (*v)[j].b.x ), 2 ) );
	e.push_back( event( dmax( (*v)[j].a.x, (*v)[j].b.x ), 3 ) );
      }
    }

    sort( e.begin(), e.end() );
    double last = e[0].x;

    int cntg = 0;
    int cntb = 0;

    for( int j = 0; j < e.size(); ++j ) {
      double y0 = lines[i].x*last + lines[i].y;
      double y1 = lines[i].x*e[j].x + lines[i].y;

      if( cntb == 0 && cntg ) ret += ( y0 + y1 ) * ( e[j].x - last ) * 0.5;
      last = e[j].x;

      if( e[j].type == 0 ) ++cntb;
      if( e[j].type == 1 ) --cntb;
      if( e[j].type == 2 ) ++cntg;
      if( e[j].type == 3 ) --cntg;
    }
  }

  return ret;
}

int main( void )
{
  scanf( "%d", &N );

  for( int i = 0; i < N; ++i ) {
    for( int j = 0; j < 4; ++j ) {
      scanf( "%d%d", x[j]+i, y[j]+i );
    }

    double area = 0.0;

    for( int j = 0; j < 4; ++j ) {
      point p0( x[j][i], y[j][i] );
      point p1( x[(j+1)&3][i], y[(j+1)&3][i] );
      area += p0.x*p1.y - p0.y*p1.x;
    }

    if( gt( area, 0.0 ) ) {
      for( int j = 0; j < 2; ++j ) {
	swap( x[j][i], x[3-j][i] );
	swap( y[j][i], y[3-j][i] );
      }
    }

    for( int j = 0; j < 4; ++j ) {
      point p0( x[j][i], y[j][i] );
      point p1( x[(j+1)&3][i], y[(j+1)&3][i] );
      s.push_back( segment( p0, p1 ) );
    }

    Total += s[s.size()-2].len() * s[s.size()-1].len();
  }

  for( int i = 0; i < s.size(); ++i ) {
    if( eq( s[i].a.x, s[i].b.x ) ) continue;
    if( lt( s[i].a.x, s[i].b.x ) ) A.push_back( s[i] );
    if( gt( s[i].a.x, s[i].b.x ) ) B.push_back( s[i] );
  }

  printf( "%.8lf\n", Total / ( solve( &A ) - solve( &B ) ) );

  return 0;
}