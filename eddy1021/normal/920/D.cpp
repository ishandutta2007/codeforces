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
#define N 5050
void build(){

}
LL n , k , v;
LL a[ N ];
void init(){
  n = getint();
  k = getint();
  v = getint();
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = getint();
}
void no(){
  puts( "NO" );
  Bye;
}
vector< tuple<LL,LL,LL> > va;
bool ok[ N ][ N ][ 2 ];
int bk[ N ][ N ][ 2 ];
int cand[ N ] , ct;
int other[ N ] , ot;
void output(){
  puts( "YES" );
  for( auto i : va )
    printf( "%lld %lld %lld\n" , get<0>( i ) ,
             get<1>( i ) + 1 ,
             get<2>( i ) + 1 );
  Bye;

}
void construct(){
  int master = cand[ 0 ];
  for( int _ = 1 ; _ < ct ; _ ++ ){
    int i = cand[ _ ];
    va.push_back( make_tuple( 1e6 , i , master ) );
    a[ master ] += a[ i ];
  }
  for( int _ = 1 ; _ < ot ; _ ++ ){
    int i = other[ _ ];
    va.push_back( make_tuple( 1e6 , i , other[ 0 ] ) );
    a[ other[ 0 ] ] += a[ i ];
  }
  if( a[ master ] > v ){
    LL dlt = (a[ master ] - v) / k;
    va.push_back( make_tuple( dlt , master , master == n - 1 ? 0 : master + 1 ) );
  }
  if( a[ master ] < v ){
    LL nd = (v - a[ master ]) / k;
    if( ot == 0 ) no();
    if( a[ other[ 0 ] ] < nd * k ) no();
    va.push_back( make_tuple( nd , other[ 0 ] , master ) );
  }
  output();
}
void solve(){
  if( accumulate( a , a + n , 0LL ) < v ) no();
  if( v % k == 0 ){
    for( int i = 1 ; i < n ; i ++ )
      va.push_back( make_tuple( 1e6 , i , 0 ) );
    if( v / k > 0 )
      va.push_back( make_tuple( v / k , 0 , 1 ) );
    output();
  }
  ok[ 0 ][ 0 ][ 0 ] = true;
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < k ; j ++ )
      for( int gt = 0 ; gt < 2 ; gt ++ )
        if( ok[ i ][ j ][ gt ] ){
          ok[ i + 1 ][ j ][ gt ] = true;
          bk[ i + 1 ][ j ][ gt ] = (j << 1) | gt;
          ok[ i + 1 ][ (j + a[ i ]) % k ][ 1 ] = true;
          bk[ i + 1 ][ (j + a[ i ]) % k ][ 1 ] = (j << 1) | gt;
        }
  if( not ok[ n ][ v % k ][ 1 ] ) no();
  int now = v % k , ngt = 1;
  for( int i = n ; i ; i -- ){
    int pre = bk[ i ][ now ][ ngt ];
    if( ((pre >> 1) + a[ i - 1 ]) % k == now )
      cand[ ct ++ ] = i - 1;
    else
      other[ ot ++ ] = i - 1;
    now = pre >> 1;
    ngt = pre & 1;
  }
  assert( ct > 0 );
  construct();
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}