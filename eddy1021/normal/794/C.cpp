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
#define N 303030
void build(){

}
int n;
char c[ N ];
deque<int> v[ 2 ];
void init(){
  for( int i = 0 ; i < 2 ; i ++ ){
    scanf( "%s" , c );
    n = strlen( c );
    for( int j = 0 ; c[ j ] ; j ++ )
      v[ i ].push_back( c[ j ] - 'a' );
    sort( v[ i ].begin() , v[ i ].end() );
    int nd = n / 2;
    if( ( n & 1 ) and i == 0 ) nd ++;
    if( i == 0 ){
      while( (int)v[ i ].size() > nd ) v[ i ].pop_back();
    }else{
      while( (int)v[ i ].size() > nd ) v[ i ].pop_front();
    }
  }
}
char ans[ N ];
void solve(){
  int al = 0 , ar = n - 1 , who = 0;
  while( al <= ar ){
    if( who == 0 ){   
      if( v[ who ][ 0 ] >= v[ 1 - who ].back() ){
        ans[ ar ] = v[ who ].back() + 'a';
        v[ who ].pop_back();
        ar --;
      }else{
        ans[ al ] = v[ who ].front() + 'a';
        v[ who ].pop_front();
        al ++;
      }
    }else{
      if( v[ who ].back() <= v[ 1 - who ][ 0 ] ){
        ans[ ar ] = v[ who ][ 0 ] + 'a';
        v[ who ].pop_front();
        ar --;
      }else{
        ans[ al ] = v[ who ].back() + 'a';
        v[ who ].pop_back();
        al ++;
      } 
    }
    who = 1 - who;
  }
  ans[ n ] = '\0';
  puts( ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}