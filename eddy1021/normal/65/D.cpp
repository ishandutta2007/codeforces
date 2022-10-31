// default code for competitive programming
// ver 3.141 {{{

// Includes
#include <bits/stdc++.h>

// Defines
#define NAME(x) #x
#define SZ(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()
#define FOR(i, e) for( int i = 0 ; i < (e) ; i++ )
#define ITER(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define REP(i, s, e) for(int i = (s); i <= (e); i++)
#define REPD(i, s, e) for(int i = (s); i >= (e); i--)
#define IOS ios_base::sync_with_stdio( 0 )
#define DEBUG 1
#define fst first
#define snd second
#ifdef ONLINE_JUDGE
#define FILE( fn ) \
    freopen(fn".in","r",stdin); \
    freopen(fn".out","w",stdout);
#else
#define FILE( fn )
#endif

#ifdef AKAI
#define debug( ... ) fprintf( stderr , __VA_ARGS__ )
#else
#define debug( ... )
#endif

using namespace std;

// Typedefs
typedef double real;
typedef long long ll;
typedef pair<ll, int> pli;
typedef tuple<ll, int> tli;
typedef pair<int, int> pii;
typedef tuple<int, int> tii;
typedef unsigned long long ull;

// Some common const.
const double EPS = -1e8;
const double Pi = acos(-1);

// Equal for double
bool inline equ(double a, double b)
{return fabs(a - b) < EPS;}

void R() {}

template< typename... T >
void R( int& x , T&... tail )
{
  assert( scanf( "%d" , &x ) == 1 );
  R( tail... );
}

template< typename Iter , typename F >
inline void out( Iter s , Iter e , F of )
{
  bool flag = 0;
  for( Iter it = s ; it != e ; it++ )
  {
    if( flag ) printf( " " );
    else flag = 1;
    of( *it );
  }
  puts( "" );
}

// }}}
// start ~~QAQ~~

const int MAXN = 10010;

struct ST
{
  int cnt[ 4 ];
  int operator[]( int id ) const { return cnt[ id ]; }
  int& operator[]( int id ){ return cnt[ id ]; }
  bool operator==( const ST& rhs ) const
  {
    FOR( i , 4 ) if( cnt[ i ] != rhs[ i ] ) return 0;
    return 1;
  }
  bool operator<( const ST& rhs ) const
  {
    FOR( i , 4 )
    {
      if( cnt[ i ] < rhs[ i ] ) return 1;
      if( cnt[ i ] > rhs[ i ] ) return 0;
    }
    return 0;
  }
  ST gao()
  {
    ST res;
    int mn = MAXN;
    FOR( i , 4 ) mn = min( mn , cnt[ i ] );
    FOR( i , 4 ) res[ i ] = cnt[ i ] - mn;
    return res;
  }
};

int n;
char s[ MAXN ];
vector< ST > sts[ 2 ];

inline int enc( char c )
{
  switch( c )
  {
    case 'G':
      return 0;
    case 'H':
      return 1;
    case 'R':
      return 2;
    case 'S':
      return 3;
    case '?':
      return -1;
  }
}

bool good[ 4 ];
char ans[ 4 ][ 13 ] = { "Gryffindor" , "Hufflepuff" , "Ravenclaw" , "Slytherin" };

int main()
{
  scanf( "%d%s" , &n , s+1 );
  sts[ 0 ].push_back( { { 0 , 0 , 0 , 0 } } );
  REP( i , 1 , n )
  {
    sts[ i&1 ].clear();
    for( ST st : sts[ (i&1)^1 ] )
    {
      if( enc( s[ i ] ) >= 0 )
      {
        ST tmp = st;
        tmp[ enc( s[ i ] ) ]++;
        sts[ i&1 ].push_back( tmp.gao() );
      }
      else
      {
        FOR( j , 4 ) if( st[ j ] == 0 )
        {
          ST tmp;
          FOR( k , 4 ) tmp[ k ] = st[ k ];
          tmp[ j ]++;
          sts[ i&1 ].push_back( tmp.gao() );
        }
      }
    }
    sort( ALL( sts[ i&1 ] ) );
    sts[ i&1 ].resize( unique( ALL( sts[ i&1 ] ) ) - sts[ i&1 ].begin() );
  }
  for( ST st : sts[ n&1 ] )
  {
    FOR( i , 4 ) if( st[ i ] == 0 )
    {
      good[ i ] = 1;
    }
  }
  FOR( i , 4 ) if( good[ i ] )
  {
    printf( "%s\n" , ans[ i ] );
  }
}