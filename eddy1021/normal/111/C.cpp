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
void build(){

}
int n , m;
void init(){
  n = getint();
  m = getint();
  if( n > m ) swap( n , m );
}
inline int magic( int x ){
  return x + ( x < 3 );
}
inline int cal3( int x ){
  if( x == 13 ) return 10;
  if( x <= 5 )
    return ( x - 1 ) / 5 * 4 + ( x - 1 ) % 5 + ( ( x - 1 ) % 5 < 4 );
  else
    return ( x - 1 ) / 5 * 4 + magic( ( x - 1 ) % 5 );
}
inline int cal4( int x ){
  if( x >= 9 ) return 10;
  return ( x - 1 ) / 4 * 4 + ( x - 1 ) % 4 + 1 + ( ( x - 1 ) % 4 < 2 );
}
inline int cal5( int x ){
  if( x == 5 ) return 7;
  if( x == 6 ) return 8;
  if( x == 7 ) return 9;
  if( x == 8 ) return 11;
  assert( false );
  return -1;
}
void solve(){
  if( n == 1 ){
    printf( "%d\n" , n * m - ( ( m - 1 ) / 3 + 1 ) );
  }else if( n == 2 ){
    printf( "%d\n" , n * m - ( m / 2 + 1 ) );
  }else if( n == 3 ){
    printf( "%d\n" , n * m - cal3( m ) );
  }else if( n == 4 ){
    printf( "%d\n" , n * m - cal4( m ) );
  }else if( n == 5 ){
    printf( "%d\n" , n * m - cal5( m ) );
  }else if( n == 6 )
    printf( "%d\n" , 26 );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}