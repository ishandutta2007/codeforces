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

struct Pt
{
  typedef ll T;
  T x , y;
  Pt operator+(Pt a){return Pt{x+a.x,y+a.y};}
  Pt operator-(Pt a){return Pt{x-a.x,y-a.y};}
  T operator%(Pt a){return x*a.y-y*a.x;}
  T operator*(Pt a){return x*a.x+y*a.y;}
  void input(){cin >> x >> y;}
};

const int MAXN = 40010;
const ll  INF  = 10000000000000ll;

int n;
Pt p[ MAXN ];

inline int nxt( int id ){return id==n?1:id+1;}
inline int prv( int id ){return id==1?n:id-1;}

ll sum[ MAXN ];

inline ll sq( ll x ){return x*x;}

inline ll get_sum( int l , int r )
{
  if( l <= r ) return sum[ r ] - sum[ l - 1 ];
  return sum[ r ] + sum[ n ] - sum[ l - 1 ];
}

double solve()
{
  sum[ 0 ] = 0ll;
  REP( i , 1 , n )
    sum[ i ] = sum[ i - 1 ] + ( p[ i ] % p[ nxt( i ) ] );
  int j = 1;
  double res = 1e15;
  //printf( "area %lld\n" , sum[ n ] );
  REP( i , 1 , n )
  {
    //printf( "  now %d %lld %lld\n" , i , p[i].x , p[i].y );
    while( ( p[ nxt( i ) ] - p[ i ] ) * ( p[ nxt( j ) ] - p[ j ] ) > 0ll )
      j = nxt( j );
    //printf( "    j %d\n" , j );
    //printf( "    get sum %d %d %lld\n" , i , prv( j ) , get_sum( i , prv( j ) ) );
    if( i == j ) return 0.0;
    Pt a = p[ nxt( i ) ] - p[ i ];
    Pt b = p[ j ] - p[ i ];
    double an = sqrt(sq(a.x)+sq(a.y));
    double adb = a * b;
    double acb = a % b;
    res = min( res , ( adb / an ) * ( acb / an ) - ( get_sum( i , prv( j ) ) + p[ j ] % p[ i ] ) );
  }
  return res * 0.5;
}

int main()
{
  //IOS;
  cin >> n;
  REP( i , 1 , n ) p[ i ].input();
  if( ( p[ 2 ] - p[ 1 ] ) % ( p[ 3 ] - p[ 2 ] ) < 0ll )
    reverse( p + 1 , p + 1 + n );
  double ans1 = solve();
  REP( i , 1 , n ) p[ i ].x *= -1ll;
  reverse( p + 1 , p + 1 + n );
  double ans2 = solve();
  double ac = min( ans1 , ans2 );
  //cout << ac << '\n';
  printf( "%.10f\n" , ac );
}