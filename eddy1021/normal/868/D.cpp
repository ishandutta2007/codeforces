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
#define N 514
void build(){

}
#define MAGIC 12
struct S{
  set<string> st[ MAGIC ];
  string ls , rs;
  int len;
  S(){}
  S( const string& ss ){
    len = ss.length();
    ls = rs = ss;
    for( int i = 1 ; i < MAGIC ; i ++ )
      for( int j = 0 ; j + i <= len ; j ++ )
        st[ i ].insert( ss.substr( j , i ) );
    trim();
  }
  void trim(){
    ls = ls.substr( 0 , MAGIC );
    rs = rs.substr( max( 0 , (int)rs.length() - MAGIC ) , MAGIC );
  }
  S operator+( const S& he ) const{
    S ret;
    ret.ls = ls; ret.rs = he.rs;
    if( (int)ls.length() == len )
      ret.ls = ls + he.ls;
    if( (int)he.rs.length() == he.len )
      ret.rs = rs + he.rs;
    for( int i = 0 ; i < MAGIC ; i ++ ){
      for( auto x : st[ i ] )
        ret.st[ i ].insert( x );
      for( auto x : he.st[ i ] )
        ret.st[ i ].insert( x );
    }
    string ss = rs + he.ls;
    int tlen = ss.length();
    for( int i = 1 ; i < MAGIC ; i ++ )
      for( int j = 0 ; j + i <= tlen ; j ++ )
        ret.st[ i ].insert( ss.substr( j , i ) );
    ret.trim();
    return ret;
  }
  int find_k(){
    int ret = 0;
    for( int i = 1 ; i < MAGIC ; i ++ )
      if( (int)st[ i ].size() == (1 << i) )
        ret = i;
      else break;
    return ret;
  }
} r[ 514 ];
int n;
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    string ss; cin >> ss;
    r[ i ] = S( ss );
  }
}
void solve(){
  int m = getint();
  for( int i = n + 1 ; i <= n + m ; i ++ ){
    int lid = getint();
    int rid = getint();
    r[ i ] = r[ lid ] + r[ rid ];
    printf( "%d\n" , r[ i ].find_k() );
  }
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}