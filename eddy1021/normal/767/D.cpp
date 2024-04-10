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
#define N 10000010
void build(){

}
int n , m , k , f[ N ];
vector< pair<int,int> > s;
void init(){
  n = getint();
  m = getint();
  k = getint();
  for( int i = 0 ; i < n ; i ++ )
    f[ getint() ] ++;
  for( int i = 0 ; i < m ; i ++ ){
    int si = getint();
    s.push_back( { si , i + 1 } );
  }
  sort( s.begin() , s.end() , greater< pair<int,int> >() );
}
void solve(){
  for( int i = 1 ; i < N ; i ++ )
    f[ i ] += f[ i - 1 ];
  for( int i = 0 ; i < N ; i ++ )
    if( f[ i ] > (LL)k * ( i + 1 ) ){
      puts( "-1" );
      Bye;
    }
  LL pos = INF16;
  vector<int> ans;
  size_t ptr = 0;
  for( int i = N - 1 ; i >= 0 and pos > 0 ; i -- ){
    pos = min( pos , (LL)k * ( i + 1 ) - f[ i ] );
    while( ptr < s.size() and s[ ptr ].first == i and pos > 0 ){
      ans.push_back( s[ ptr ++ ].second );
      pos --;
    }
    while( ptr < s.size() and s[ ptr ].first == i ) ptr ++;
  }
  printf( "%d\n" , (int)ans.size() );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%d%c" , ans[ i ] , " \n"[ i + 1 == ans.size() ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}