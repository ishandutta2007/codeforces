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
#define N 101010
void build(){

}
int n , a[ N ];
unordered_map<int, int> s[ 11 ];
unordered_set<int> gg[ 11 ];
int mod[ 11 ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = getint();
  mod[ 1 ] = 10;
  for( int i = 2 ; i < 11 ; i ++ )
    mod[ i ] = mod[ i - 1 ] * 10;
  for( int i = 0 ; i < n ; i ++ ){
    for( int j = 1 ; j < 10 ; j ++ ){
      int tmp = a[ i ];
      if( j < 9 ) tmp = tmp % mod[ j ];
      for( int k = j ; k ; k -- ){
        auto it = s[ k ].find( tmp );
        if( it != s[ k ].end() and it->second != i ){
          //cout << k << " " << tmp << " " << i << endl;
          gg[ k ].insert( tmp );
        }else
          s[ k ][ tmp ] = i;
        tmp /= 10;
      }
    }
  }
}
void print( int vl , int len ){
  string ss;
  for( int i = 0 ; i < len ; i ++ ){
    ss += '0' + (vl % 10);
    vl /= 10;
  }
  reverse( ss.begin() , ss.end() );
  printf( "%s\n" , ss.c_str() );
}
void solve(){
  for( int i = 0 ; i < n ; i ++ ){
    int ans = a[ i ] , len = 9;
    for( int j = 1 ; j < 10 ; j ++ ){
      int tmp = a[ i ];
      if( j < 9 ) tmp = tmp % mod[ j ];
      for( int k = j ; k ; k -- ){
        auto it = gg[ k ].find( tmp );
        if( it == gg[ k ].end() ){
          if( k < len ){
            len = k;
            ans = tmp;
          }
        }
        tmp /= 10;
      }
    }
    print( ans , len );
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