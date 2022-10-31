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
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
unordered_map<int, int> v;
int val( int t ){
  if( !t ) return 0;
  auto it = v.find( t );
  if( it != v.end() ) return v[ t ];
  int ss = 0 , til = (int)__lg( t );
  for( int i = 1 ; i <= til ; i ++ ){
    int tmp = 0;
    for( int j = 1 ; j <= til ; j ++ )
      if( j != i and (t >> j) & 1 ){
        int ttt = j > i ? j - i : j;
        tmp |= (1 << ttt);
      }
    ss |= (1 << val( tmp ));
  }
  int ret = 0;
  while( (ss >> ret) & 1 ) ret ++;
  return v[ t ] = ret;
}
#define P 40000
bool p[ P ];
vector<int> pset;
void build(){
  for( int i = 2 ; i < P ; i ++ ) if( !p[ i ] ){
    pset.push_back( i );
    for( int j = i ; j < P ; j += i )
      p[ j ] = true;
  }
}
vector<int> cand;
void factor( int x ){
  for( auto i : pset ){
    if( i * i > x ) break;
    if( x % i ) continue;
    cand.push_back( i );
    while( x % i == 0 )
      x /= i;
  }
  if( x > 1 )
    cand.push_back( x );
}
#define N 111
int n , a[ N ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = getint();
  for( int i = 0 ; i < n ; i ++ )
    factor( a[ i ] );
  sort( cand.begin() , cand.end() );
  cand.resize( unique( cand.begin() , cand.end() ) - cand.begin() );
}
int go( int pp ){
  int cur = 0;
  for( int i = 0 ; i < n ; i ++ ){
    int cc = 0;
    while( a[ i ] % pp == 0 )
      cc ++ , a[ i ] /= pp;
    if( cc )
      cur |= (1 << cc);
  }
  return val( cur );
}
void solve(){
  int vv = 0;
  for( int i : cand )
    vv ^= go( i );
  puts( vv ? "Mojtaba" : "Arpa" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}