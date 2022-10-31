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
#define N 100001
void build(){

}
int n;
vector<int> vx[ N ] , vy[ N ];
void init(){
  n = getint();
  //n = 300 * 300;
  for( int i = 0 , x , y ; i < n ; i ++ ){
    x = getint();
    y = getint();
    //x = i / 300;
    //y = i % 300;
    vx[ x ].push_back( y );
    vy[ y ].push_back( x );
  }
  for( int i = 0 ; i < N ; i ++ ){
    sort( vx[ i ].begin() , vx[ i ].end() );
    sort( vy[ i ].begin() , vy[ i ].end() );
  }
}
int ans;
vector<int> cand[ N ];
void solve(){
  for( int x = 0 ; x < N ; x ++ )
    for( int y : vx[ x ] ){
      size_t xptr = upper_bound( vx[ x ].begin() , vx[ x ].end() , y ) - vx[ x ].begin();
      size_t yptr = upper_bound( vy[ y ].begin() , vy[ y ].end() , x ) - vy[ y ].begin();
      while( xptr < vx[ x ].size() and yptr < vy[ y ].size() ){
        if( vx[ x ][ xptr ] - y ==
            vy[ y ][ yptr ] - x ){
          if( not vx[ vy[ y ][ yptr ] ].empty() )
            cand[ vy[ y ][ yptr ] ].push_back( vx[ x ][ xptr ] );
          xptr ++;
          yptr ++;
        }else if( vx[ x ][ xptr ] - y <
                  vy[ y ][ yptr ] - x )
          xptr = lower_bound( vx[ x ].begin() , vx[ x ].end() ,
                              y + ( vy[ y ][ yptr ] - x ) ) - vx[ x ].begin();
        else
          yptr = lower_bound( vy[ y ].begin() , vy[ y ].end() ,
                              x + ( vx[ x ][ xptr ] - y ) ) - vy[ y ].begin();
      }
    }
  for( int x = 0 ; x < N ; x ++ ){
    sort( cand[ x ].begin() , cand[ x ].end() );
    size_t ptr = 0;
    for( int y : cand[ x ] ){
      while( ptr < vx[ x ].size() and
             vx[ x ][ ptr ] < y ) ptr ++;
      if( ptr == vx[ x ].size() ) break;
      ans += (vx[ x ][ ptr ] == y);
    }
  }
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}