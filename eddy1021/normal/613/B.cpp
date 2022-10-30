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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
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
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 101010
void build(){

}
ll n , a , cf , cm , m;
vector<PLL> v;
void init(){
  n = getint();
  a = getint();
  cf = getint();
  cm = getint();
  m = getint();
  for( int i = 1 ; i <= n ; i ++ )
    v.PB( MP( getint() , i ) );
  sort( ALL( v ) );
}
ll psum[ N ];
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    psum[ i ] = psum[ i - 1 ] + v[ i - 1 ].FI;

  ll ans = cm * v[ 0 ].FI;
  ll ansp = 1 , ansf = 0;
  ll ansm = v[ 0 ].FI;

  ll res = m;
  for( int i = n - 1 ; i >= 0 ; i -- )
    if( res >= a - v[ i ].FI ){
      res -= a - v[ i ].FI;
      ll tans = cf * ( n - i );
      ll bl = 0 , br = a , bmid , ba = 0 , bb = 0;
      while( bl <= br ){
        bmid = ( bl + br ) >> 1;

        ll bl2 = 0 , br2 = i - 1 , bmid2 , ba2 = -1;
        while( bl2 <= br2 ){
          bmid2 = ( bl2 + br2 ) >> 1;
          if( v[ bmid2 ].FI < bmid ) ba2 = bmid2 , bl2 = bmid2 + 1;
          else br2 = bmid2 - 1;
        }
        if( ba2 == -1 || ( res >= bmid * ( ba2 + 1 ) - psum[ ba2 + 1 ] ) )
          bl = bmid + 1 , ba = bmid , bb = ba2 + 1;
        else br = bmid - 1;
      }
      tans += cm * ba;
      if( tans > ans ){
        ans = tans;
        ansp = bb;
        ansf = n - i;
        ansm = ba;
      }
    }else break;
  if( m >= a * n - psum[ n ] ){
    ll tans = cm * a + cf * n;
    if( tans > ans ){
      ans = tans;
      ansp = n;
      ansf = 0;
      ansm = a;
    }
  }
  {
    ll bl = 0 , br = a , bmid , ba = 0 , bb = 0;
    while( bl <= br ){
      bmid = ( bl + br ) >> 1;

      ll bl2 = 0 , br2 = n - 1 , bmid2 , ba2 = -1;
      while( bl2 <= br2 ){
        bmid2 = ( bl2 + br2 ) >> 1;
        if( v[ bmid2 ].FI < bmid ) ba2 = bmid2 , bl2 = bmid2 + 1;
        else br2 = bmid2 - 1;
      }
      if( ba2 == -1 || ( m >= bmid * ( ba2 + 1 ) - psum[ ba2 + 1 ] ) )
        bl = bmid + 1 , ba = bmid , bb = ba2 + 1;
      else br = bmid - 1;
    }
    ll tans = cm * ba;
    if( tans > ans ){
      ans = tans;
      ansp = bb;
      ansf = 0;
      ansm = ba;
    }
  }
  for( int i = 0 ; i < ansp ; i ++ )
    v[ i ].FI = ansm;
  for( int i = n - 1 ; i > n - ansf - 1 ; i -- )
    v[ i ].FI = a;
  for( int i = 0 ; i < n ; i ++ )
    swap( v[ i ].FI , v[ i ].SE );
  sort( ALL( v ) );
  printf( "%lld\n" , ans );
  for( int i = 0 ; i < n ; i ++ )
    printf( "%lld " , v[ i ].SE );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}