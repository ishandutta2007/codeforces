// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
void sleep( double sec = 1021 ){
  clock_t s = clock();
  while( clock() - s < CLOCKS_PER_SEC * sec );
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 2000001
int mu[ N ] , p_tbl[ N ];
vector<int> primes;
void build() {
  mu[ 1 ] = p_tbl[ 1 ] = 1;
  for( int i = 2 ; i < N ; i ++ ){
    if( !p_tbl[ i ] ){
      p_tbl[ i ] = i;
      primes.push_back( i );
      mu[ i ] = -1;
    }
    for( int p : primes ){
      LL x = (LL)i * p;
      if( x >= N ) break;
      p_tbl[ x ] = p;
      mu[ x ] = -mu[ i ];
      if( i % p == 0 ){
        mu[ x ] = 0;
        break;
      }
    }
  }
  for( int i = 0 ; i < N ; i ++ )
    mu[ i ] = (mu[ i ] + mod7) % mod7;
  //for( int i = 1 ; i < N ; i ++ ) if( mu[ i ] )
    //for( int j = i ; j < N ; j += i )
      //di[ j ].push_back( i );
}
int n , k , v[ N ];
int np( int vv ){
  if( !vv ) return 0;
  if( v[ vv ] ) return v[ vv ];
  return v[ vv ] = mypow( vv , n , mod7 );
}
void init(){
  n = getint();
  k = getint();
}
int df[ N ];
void solve(){
  for( int i = 1 ; i <= k ; i ++ ) if( mu[ i ] )
    for( int j = i , tms = 1 ; j < N ; j += i , tms ++ )
      df[ j ] = add( df[ j ] , mul( mu[ i ] , sub( np( tms ) , np( tms - 1 ) ) ) );

  int ans = 1;
  LL xans = ans ^ 1;
  for( int i = 2 ; i <= k ; i ++ ){
    ans = add( ans , df[ i ] );
    //for( int j : di[ i ] ){
      //int tms = i / j;
      //ans = add( ans , mul( mu[ j ] , sub( np( tms ) , np( tms - 1 ) ) ) );
    //}
    xans += ans ^ i;
    xans %= mod7;
  }
  printf( "%lld\n" , xans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}