// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
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
int __ = 1 , _cs;
/*********default*********/
void build(){

}
int n , a[ 3 ];
void init(){
  scanf( "%d" , &n );
}
map< pair<int,int> , pair<int,int> > M;
void solve(){
  int ans = -1;
  vector< int > va = { 1 };
  for( int i = 1 ; i <= n ; i ++ ){
    for( int j = 0 ; j < 3 ; j ++ )
      a[ j ] = getint();
    int mn = min( a[ 0 ] , min( a[ 1 ] , a[ 2 ] ) );
    if( mn > ans ){
      ans = mn;
      va = { i };
    }
    for( int j1 = 0 ; j1 < 3 ; j1 ++ )
      for( int j2 = j1 + 1 ; j2 < 3 ; j2 ++ )
        if( M.count( { a[ j1 ] , a[ j2 ] } ) ){
          int res = a[ 3 - j1 - j2 ] + M[ { a[ j1 ] , a[ j2 ] } ].first;
          int tmn = min( res , min( a[ j1 ] , a[ j2 ] ) );
          if( tmn > ans ){
            ans = tmn;
            va = { M[ { a[ j1 ] , a[ j2 ] } ].second , i };
          }
        }
    for( int j1 = 0 ; j1 < 3 ; j1 ++ )
      for( int j2 = j1 + 1 ; j2 < 3 ; j2 ++ )
        if( M.count( { a[ j1 ] , a[ j2 ] } ) == 0 ){
          M[ { a[ j1 ] , a[ j2 ] } ] = { a[ 3 - j1 - j2 ] , i };
          M[ { a[ j2 ] , a[ j1 ] } ] = { a[ 3 - j1 - j2 ] , i };
        }
        else if( a[ 3 - j1 - j2 ] > M[ { a[ j1 ] , a[ j2 ] } ].first ){
          M[ { a[ j1 ] , a[ j2 ] } ] = { a[ 3 - j1 - j2 ] , i };
          M[ { a[ j2 ] , a[ j1 ] } ] = { a[ 3 - j1 - j2 ] , i };
        }
  }
  printf( "%d\n" , (int)va.size() );
  for( size_t i = 0 ; i < va.size() ; i ++ )
    printf( "%d%c" , va[ i ] , " \n"[ i + 1 == va.size() ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}