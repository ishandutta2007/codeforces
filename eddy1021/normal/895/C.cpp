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
void build(){

}
#define N 101010
int n;
int p[] = {2, 3, 5, 7};
pair<int,int> fac( int x ){
  int msk = 0 , res = x;
  for( int i = 0 ; i < 4 ; i ++ ){
    int c = 0;
    while( res % p[ i ] == 0 ){
      c = 1 - c;
      res /= p[ i ];
    }
    if( c )
      msk |= (1 << i);
  }
  return {res, msk};
}
vector<pair<int,int>> v;
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    v.push_back( fac( getint() ) );
  sort( v.begin() , v.end() );
}
int odp[ 1 << 4 ];
int dp[ 2 ][ 1 << 4 ][ 2 ];
void go_dp( size_t l , size_t r ){
  memset( dp , 0 , sizeof( dp ) );
  for( int i = 0 ; i < (1 << 4) ; i ++ )
    dp[ 0 ][ i ][ 0 ] = odp[ i ];
  int now = 0 , pre = 1;
  for( size_t _ = l ; _ < r ; _ ++ ){
    swap( now , pre );
    for( int i = 0 ; i < (1 << 4) ; i ++ )
      for( int j = 0 ; j < 2 ; j ++ )
        dp[ now ][ i ][ j ] = dp[ pre ][ i ][ j ];
    int msk = v[ _ ].second;
    for( int i = 0 ; i < (1 << 4) ; i ++ )
      for( int j = 0 ; j < 2 ; j ++ ){
        int pj = v[ _ ].first > 1 ? 1 - j : j;
        dp[ now ][ i ][ j ] = add( dp[ now ][ i ][ j ] ,
                                   dp[ pre ][ i ^ msk ][ pj ] );
      }
  }
  for( int i = 0 ; i < (1 << 4) ; i ++ )
    odp[ i ] = dp[ now ][ i ][ 0 ];
}
void solve(){
  odp[ 0 ] = 1;
  for( size_t l = 0 , r = 0 ; l < v.size() ; l = r ){
    while( r < v.size() and v[ l ].first == v[ r ].first ) r ++;
    go_dp( l , r );
  }
  printf( "%d\n" , odp[ 0 ] - 1 );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}