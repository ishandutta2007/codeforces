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
#define N 20
int bt[ 1 << N ];
void build(){
  for( int i = 1 ; i < ( 1 << N ) ; i ++ )
    bt[ i ] = bt[ i / 2 ] + i % 2;
}
int n , k;
D p[ N ];
void init(){
  n = getint(); k = getint();
  int zr = 0;
  for( int i = 0 ; i < n ; i ++ ){
    scanf( "%lf" , &p[ i ] );
    if( equal( p[ i ] , 0.0 ) )
      zr ++;
  }
  k = min( k , n - zr );
}
D dp[ 1 << N ] , ans[ N ];
void solve(){
  dp[ 0 ] = 1.0;
  for( int i = 0 ; i < ( 1 << n ) ; i ++ ){
    if( dp[ i ] < 1e-20 ) continue;
    if( bt[ i ] < k ){
      D sum = 0.0;
      for( int j = 0 ; j < n ; j ++ )
        if( ( i >> j ) & 1 )
          sum += p[ j ];
      for( int j = 0 ; j < n ; j ++ )
        if( ( ( i >> j ) & 1 ) == 0 )
          dp[ i | ( 1 << j ) ] += dp[ i ] * p[ j ] / ( 1.0 - sum );
    }
    if( bt[ i ] == k ){
      for( int j = 0 ; j < n ; j ++ )
        if( ( i >> j ) & 1 )
          ans[ j ] += dp[ i ];
    }
  }
  for( int i = 0 ; i < n ; i ++ )
    printf( "%.9f%c" , ans[ i ] , " \n"[ i + 1 == n ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}