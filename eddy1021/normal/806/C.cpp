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
#define N 101010
LL two[ 50 ];
void build(){
  two[ 0 ] = 1;
  for( int i = 1 ; i < 50 ; i ++ )
    two[ i ] = (two[ i - 1 ] << 1);
}
LL n , cnt[ N ];
vector<LL> other;
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ ){
    LL a = getint();
    bool got = false;
    for( int j = 0 ; j < 40 ; j ++ )
      if( a == two[ j ] ){
        cnt[ j ] ++;
        got = true;
        break;
      }
    if( got ) continue;
    other.push_back( a );
  }
}
LL ok[ N ];
int rsum[ N ];
void solve(){
  for( int i = 39 ; i >= 0 ; i -- ){
    LL mst = cnt[ i ];
    for( int j = i ; j >= 0 ; j -- )
      mst = min( mst , cnt[ j ] );
    ok[ i ] += mst;
    for( int j = i ; j >= 0 ; j -- )
      cnt[ j ] -= mst;
  }
  for( int i = 0 ; i < 40 ; i ++ )
    while( cnt[ i ] -- )
      other.push_back( two[ i ] );
  LL bs = 0;
  sort( other.begin() , other.end() );
  vector<LL> res;
  for( int i = 39 ; i >= 0 ; i -- ){
    while( ok[ i ] and other.size() and other.back() < two[ i + 1 ] ){
      ok[ i ] --;
      other.pop_back();
      bs ++;
    }
    while( other.size() and other.back() >= two[ i ] ){
      res.push_back( other.back() );
      other.pop_back();
    }
  }
  if( not res.empty() ){
    puts( "-1" );
    Bye;
  }
  vector<int> ans;
  int sum = 0;
  for( int i = 0 ; i < 40 ; i ++ )
    sum += ok[ i ];
  ans.push_back( sum );

  for( int i = 39 ; i >= 0 ; i -- )
    rsum[ i ] = rsum[ i + 1 ] + ok[ i ];

  for( int i = 0 , p = 0 ; i < 40 ; i ++ ){
    if( p > rsum[ i ] ) break;
    ans.push_back( rsum[ i ] );
    for( int j = 1 ; j <= ok[ i ] ; j ++ ){
      p += i + 1;
      if( p > rsum[ i ] - j ) break;
      ans.push_back( rsum[ i ] - j );
    }
  }

  sort( ans.begin() , ans.end() );
  ans.resize( unique( ans.begin() , ans.end() ) - ans.begin() );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%lld%c" , ans[ i ] + bs , " \n"[ i + 1 == ans.size() ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}