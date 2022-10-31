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
void build(){

}
void init(){

}
vector< pair<pair<string,string>,bool> > vv;
string to_str( int d ){
  string ret = "";
  ret += (char)( d + '0' );
  return ret;
}
void solve(){
  vv.push_back( { { "" , "?" } , false } ); // 123 -> ?123
  vv.push_back( { { "?" , "??" } , false } );
  // 123? -> 123??
  for( int i = 0 ; i < 10 ; i ++ )
    vv.push_back( { { "?" + to_str( i ) , to_str( i ) + "?" } , false } );
    // ?123 -> 1?23 -> 12?3 -> 123?
  vv.push_back( { { "??" , "1" } , true } );
  // ??000 -> 1000
  for( int i = 0 ; i < 9 ; i ++ )
    vv.push_back( { { to_str( i ) + "??" ,
                      to_str( i + 1 ) } , true } );
    // 123?? -> 124
  vv.push_back( { { to_str( 9 ) + "??" ,
                    "??" + to_str( 0 ) } , false } );
    // 199?? -> 19??0 -> 1??00 -> 200
    // 999?? -> 99??0 -> 9??00 -> ??000
  reverse( vv.begin() , vv.end() );
  assert( vv.size() <= 50u );
  for( auto i : vv ){
    cout << i.first.first;
    if( i.second ) cout << "<>";
    else cout << ">>";
    cout << i.first.second;
    cout << endl;
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