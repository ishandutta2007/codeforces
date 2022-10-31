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
#define N 101010
int n , k , m;
int tar;
struct L{
  vector<int> v;
  LL bns;
  L(){
    bns = 0;
  }
  void init( int _n ){
    v.resize( _n );
    for( int i = 0 ; i < _n ; i ++ )
      v[ i ] = getint();
  }
  void norm(){
    int con = 0 , pre = -1;
    vector< pair<int,int> > vv;
    for( size_t i = 0 ; i < v.size() ; i ++ ){
      if( v[ i ] == pre ){
        con ++;
        if( con == k ){
          con = 0;
          pre = -1;
        }
        continue;
      }
      if( con ){
        if( vv.size() and pre == vv.back().second )
          vv.back().first += con;
        else
          vv.push_back( { con , pre } );
        vv.back().first %= k;
        if( vv.back().first == 0 )
          vv.pop_back();
      }
      con = 1;
      pre = v[ i ];
    }
    if( con ){
      if( vv.size() and pre == vv.back().second )
        vv.back().first += con;
      else
        vv.push_back( { con , pre } );
      vv.back().first %= k;
      if( vv.back().first == 0 )
        vv.pop_back();
    }
    v.clear();
    for( auto i : vv )
      while( i.first -- )
        v.push_back( i.second );
    if( (int)v.size() > 4 * n ){
      bns += (int)v.size() - 4 * n;
      size_t sz = 0;
      for( int i = 0 ; i < n + n ; i ++ )
        v[ sz ++ ] = v[ i ];
      for( int i = n + n ; i ; i -- )
        v[ sz ++ ] = v[ (int)v.size() - i ];
      v.resize( sz );
    }
  }
  L operator+( const L& he ) const{
    L ret;
    ret.v.resize( v.size() + he.v.size() );
    for( size_t i = 0 ; i < v.size() ; i ++ )
      ret.v[ i ] = v[ i ];
    for( size_t i = 0 ; i < he.v.size() ; i ++ )
      ret.v[ (int)v.size() + i ] = he.v[ i ];
    ret.norm();
    ret.bns = bns + he.bns;
    return ret;
  }
  L operator^( int tk ) const{
    L ret , A;
    A.v.resize( v.size() );
    for( size_t i = 0 ; i < v.size() ; i ++ )
      A.v[ i ] = v[ i ];
    while( tk ){
      if( tk & 1 ) ret = ret + A;
      A = A + A;
      tk >>= 1;
    }
    ret.norm();
    return ret;
  }
} a;
void build(){

}
void init(){
  n = getint();
  k = getint();
  m = getint();
  a.init( n );
  a.norm();
}
void solve(){
  LL rem = (LL)a.v.size() * m;
  vector< pair<int,int> > vv;
  int pre = -1 , cnt = 0;
  for( auto i : a.v )
    if( i == pre ) cnt ++;
    else{
      if( cnt )
        vv.push_back( { pre , cnt } );
      pre = i;
      cnt = 1;
    }
  if( cnt )
    vv.push_back( { pre , cnt } );
  for( auto i : vv )
    assert( i.second % k and i.second < k );
  for( int l = 0 , r = (int)vv.size() - 1 ; l <= r ; l ++ , r -- )
    if( vv[ l ].first != vv[ r ].first ) break;
    else{
      if( l == r ){
        if( (LL)vv[ l ].second * m % k )
          rem -= (LL)vv[ l ].second * m / k * k;
        else
          rem = 0;
        break;
      }
      rem -= (LL)( vv[ l ].second + vv[ r ].second ) / k * k * ( m - 1 );
      if( ( vv[ l ].second + vv[ r ].second ) % k ) break;
    }
  printf( "%lld\n" , rem );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}