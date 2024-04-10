// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define INF18 1000000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define P 101010
bool pri[ P ];
vector< LL > pset;
void build(){
  for( LL i = 2 ; i < P ; i ++ ) if( !pri[ i ] ){
    pset.push_back( i );
    for( LL j = P / i ; j >= i ; j -- )
      pri[ i * j ] = true;
  }
}
inline LL Mod( LL x , LL y ){
  x %= y;
  return x < 0 ? x + y : x;
}
LL a1 , b1 , a2 , b2 , L , R;
PLL gcd( LL a , LL b ){
  if( b == 0 ) return make_pair(1, 0);
  else{
    LL p = a / b;
    PLL q = gcd(b, a % b);
    return make_pair( q.second, q.first - q.second * p);
  }
}
inline LL solve( LL r1 , LL m1 , LL r2 , LL m2 ){
  assert( __gcd( m1 , m2 ) == 1 );
  PLL var = gcd( m1 , m2 );
  LL lcm = m1 * m2;
  LL res1 = mymul( mymul( r1 , m2 , lcm ) , Mod( var.SE , lcm ) , lcm );
  LL res2 = mymul( mymul( r2 , m1 , lcm ) , Mod( var.FI , lcm ) , lcm );
  LL res = ( res1 + res2 ) % lcm;
  return res;
}
inline LL solve2( LL r1 , LL m1 , LL r2 , LL m2 ){
  if( m1 < m2 ){
    swap( r1 , r2 );
    swap( m1 , m2 );
  }
  if( Mod( r1 , m2 ) != r2 ){
    puts( "0" );
    exit( 0 );
  }
  return r1;
}
inline LL Ceil( LL a , LL b ){
  if( b < 0 ) a *= -1 , b *= -1;
  if( a >= 0 ) return ( a + b - 1 ) / b;
  return a / b;
}
inline LL Flor( LL a , LL b ){
  if( b < 0 ) a *= -1 , b *= -1;
  if( a >= 0 ) return a / b;
  return ( a - b + 1 ) / b;
}
void go(){
  LL lbnd = INF18 , rbnd = -INF18 , x = 0 , lcm;
  if( __gcd( a1 , a2 ) == 1 ){
    x = solve( Mod( b1 , a1 ) , a1 , Mod( b2 , a2 ) , a2 );
    lcm = a1 * a2;
  }else{
    vector< PLL > eq;
    lcm = a1 * a2 / __gcd( a1 , a2 );
    LL ia1 = a1 , ia2 = a2;
    for( LL pr : pset ){
      LL pa1 = 1 , pa2 = 1;
      while( ia1 % pr == 0 )
        ia1 /= pr, pa1 *= pr;
      while( ia2 % pr == 0 )
        ia2 /= pr, pa2 *= pr;
      if( pa1 == 1 && pa2 == 1 ) continue;
      if( pa1 == 1 )
        eq.push_back( { Mod( b2 , pa2 ) , pa2 } );
      else if( pa2 == 1 )
        eq.push_back( { Mod( b1 , pa1 ) , pa1 } );
      else{
        LL vv = solve2( Mod( b1 , pa1 ) , pa1 , Mod( b2 , pa2 ) , pa2 );
        eq.push_back( { vv , max( pa1 , pa2 ) } );
      }
    }
    if( ia1 > 1 && ia2 > 1 ){
      if( ia1 == ia2 )
        eq.push_back( { solve2( Mod( b1 , ia1 ) , ia1 , Mod( b2 , ia2 ) , ia2 ) ,
          ia1 } );
      else{
        eq.push_back( { Mod( b1 , ia1 ) , ia1 } );
        eq.push_back( { Mod( b2 , ia2 ) , ia2 } );
      }
    }else if( ia1 > 1 )
      eq.push_back( { Mod( b1 , ia1 ) , ia1 } );
    else if( ia2 > 1 )
      eq.push_back( { Mod( b2 , ia2 ) , ia2 } );
    for( PLL tp : eq ){
      LL mad = lcm / tp.SE;
      PLL var = gcd( mad , tp.SE );
      if( var.FI < 0 ) var.FI += lcm;
      LL res = mymul( mymul( tp.FI , mad , lcm ) , var.FI , lcm );
      x = ( x + res ) % lcm;
    }
    //printf( "%lld %lld\n" , x , lcm );
  }
  lbnd = Ceil( ( L - x ) , lcm );
  rbnd = Flor( ( R - x ) , lcm );
  printf( "%lld\n" , max( rbnd - lbnd + 1 , 0ll ) );
}
void init(){
  a1 = getint();
  b1 = getint();
  a2 = getint();
  b2 = getint();
  L  = getint();
  R  = getint();
}
void solve(){
  L = max( L , b1 );
  L = max( L , b2 );
  if( a1 == 0 && a2 == 0 ){
    if( b1 == b2 && L <= b1 && b1 <= R )
      puts( "1" );
    else puts( "0" );
    exit( 0 );
  }
  if( a2 == 0 ){
    swap( a1 , a2 );
    swap( b1 , b2 );
  }
  if( a1 == 0 ){
    if( ( b1 - b2 ) % a2 ) puts( "0" );
    else if( L <= b1 && b1 <= R ) puts( "1" );
    else puts( "0" );
    exit( 0 );
  }
  go();
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}