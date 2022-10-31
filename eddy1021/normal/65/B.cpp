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

const int MAXN = 1010;
typedef tuple< int , int , int > ST;

int n;
string s[ MAXN ];
string st[ MAXN ][ 5 ][ 10 ];
bool vis[ MAXN ][ 5 ][ 10 ];
ST prv[ MAXN ][ 5 ][ 10 ];

int main()
{
  cin >> n;
  REP( i , 1 , n ) cin >> s[ i ];
  REP( i , 1 , n )
  {
    FOR( j , 5 ) FOR( k , 10 )
    {
      st[ i ][ j ][ k ] = s[ i ];
      if( j < 4 ) st[ i ][ j ][ k ][ j ] = '0' + k;
      if( j == 0 && k == 0 )
      {
        continue ;
      }
      if( st[ i ][ j ][ k ] > string( "2011" ) )
      {
        continue ;
      }
      if( i == 1 )
        vis[ i ][ j ][ k ] = 1;
    }
  }
  REP( i , 1 , n-1 )
  {
    FOR( j , 5 ) FOR( k , 10 )
    {
      if( !vis[ i ][ j ][ k ] )
      {
        continue ;
      }
      //printf( "vis %d %d %d\n" , i , j , k );
      FOR( jj , 5 ) FOR( kk , 10 )
      {
        if( jj == 0 && kk == 0 )
        {
          continue ;
        }
        if( st[ i+1 ][ jj ][ kk ] > string( "2011" ) )
        {
          continue ;
        }
        if( st[ i ][ j ][ k ] <= st[ i+1 ][ jj ][ kk ] )
        {
          //printf( "  goto %d %d %d\n" , i+1 , jj , kk );
          vis[ i+1 ][ jj ][ kk ] = 1;
          prv[ i+1 ][ jj ][ kk ] = ST( i , j , k );
        }
      }
    }
  }
  vector< string > ans;
  FOR( j , 5 ) FOR( k , 10 )
  {
    if( vis[ n ][ j ][ k ] )
    {
      ST now = ST( n , j , k );
      while( 1 )
      {
        int ii , jj , kk;
        tie( ii , jj , kk ) = now;
        //printf( "now %d %d %d\n" , ii , jj , kk );
        ans.push_back( st[ ii ][ jj ][ kk ] );
        if( ii <= 1 )
        {
          break ;
        }
        now = prv[ ii ][ jj ][ kk ];
      }
      reverse( ALL( ans ) );
      for( const string& ss : ans )
        cout << ss << endl;
      return 0;
    }
  }
  puts( "No solution" );
}