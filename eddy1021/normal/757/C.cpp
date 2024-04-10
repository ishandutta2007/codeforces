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
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 1010101
int fac[ N ];
void build(){
  fac[ 0 ] = 1;
  for( int i = 1 ; i < N ; i ++ )
    fac[ i ] = mul( fac[ i - 1 ] , i );
}
int n , m , id[ N ] , f;
void init(){
  n = getint();
  m = getint();
}
void solve(){
  while( n -- ){
    int gi = getint();
    map<int,int> M;
    for( int i = 0 ; i < gi ; i ++ )
      M[ getint() ] ++;
    vector< pair<int,int> > v;
    for( auto it = M.begin() ; it != M.end() ; it ++ )
      v.push_back( { it->second , it->first } );
    sort( v.begin() , v.end() );
    for( size_t l = 0 , r = 0 ; l < v.size() ; l = r ){
      while( r < v.size() && v[ l ].first == v[ r ].first ) r ++;
      vector< pair<int,int> > tv;
      for( size_t i = l ; i < r ; i ++ )
        tv.push_back( { id[ v[ i ].second ] , v[ i ].second } );
      sort( tv.begin() , tv.end() );
      for( size_t il = 0 , ir = 0 ; il < tv.size() ; il = ir ){
        while( ir < tv.size() && tv[ il ].first == tv[ ir ].first ) ir ++;
        f ++;
        for( size_t i = il ; i < ir ; i ++ )
          id[ tv[ i ].second ] = f;
      }
    }
  }
  map<int,int> M;
  for( int i = 1 ; i <= m ; i ++ )
    M[ id[ i ] ] ++;
  int ans = 1;
  for( auto it = M.begin() ; it != M.end() ; it ++ )
    ans = mul( ans , fac[ it->second ] );
  printf( "%d\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}