
// default code for competitive programming
// c2251393 ver 3.141 {{{

// Includes
#include <bits/stdc++.h>

// Defines
#define NAME(x) #x
#define SZ(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
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

// }}}
// start ~~QAQ~~

const int MAXN = 1010;
const int MAXK = 110;

int n , k;
ll L[ MAXN ] , R[ MAXN ];
double pr[ MAXN ]; 
double dp[ MAXN ][ MAXN ];

int main()
{
  cin >> n;
  REP( i , 1 , n ) cin >> L[ i ] >> R[ i ];
  cin >> k;
  REP( i , 1 , n )
  {
    ll tot = R[ i ] - L[ i ] + 1;
    ll cnt = 0ll;
    ll base = 1ll;
    while( base <= R[ i ] )
    {
      ll tl = base , tr = base * 2 - 1ll;
      tl = max( tl , L[ i ] );
      tr = min( tr , R[ i ] );
      cnt += max( 0ll , tr - tl + 1 );
      if( base == 1000000000000000000ll ) break ;
      base *= 10ll;
    }
    pr[ i ] = (long double)cnt / (long double)tot;
  }
  dp[ 0 ][ 0 ] = 1.0;
  REP( i , 1 , n )
  {
    REP( j , 0 , i )
    {
      dp[ i ][ j ] = ( 1. - pr[ i ] ) * dp[ i - 1 ][ j ];
      if( j > 0 ) dp[ i ][ j ] += pr[ i ] * dp[ i - 1 ][ j - 1 ];
    }
  }
  double ans = 0.0;
  REP( j , 0 , n )
  {
    if( j * 100 >= k * n ) ans += dp[ n ][ j ];
  }
  printf( "%.20f\n" , ans );
}