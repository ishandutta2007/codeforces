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
#define N 202020
void build(){

}
LL n , t;
vector< pair<pair<LL,LL>,int> > v;
#define A first.first
#define T first.second
#define ID second
void init(){
  n = getint();
  t = getint();
  v.resize( n );
  for( int i = 0 ; i < n ; i ++ ){
    v[ i ].A = getint();
    v[ i ].T = getint();
    v[ i ].ID = i + 1;
  }
  sort( v.begin() , v.end() );
  reverse( v.begin() , v.end() );
}
int ans;
void find_ans(){
  set< pair<LL,int> > s;
  LL sumt = 0;
  for( size_t l = 0 , r = 0 ; l < v.size() ; l = r ){
    while( r < v.size() and v[ l ].A == v[ r ].A ) r ++;
    for( size_t i = l ; i < r ; i ++ ){
      s.insert( { v[ i ].T , v[ i ].ID } );
      sumt += v[ i ].T;
    }
    while( (int)s.size() > v[ l ].A or sumt > t ){
      sumt -= s.rbegin()->first;
      s.erase( --s.end() );
    }
    ans = max( ans , (int)s.size() );
  }
}
vector<int> va;
void find_who(){
  set< pair<LL,int> > s;
  LL sumt = 0;
  for( size_t l = 0 , r = 0 ; l < v.size() ; l = r ){
    while( r < v.size() and v[ l ].A == v[ r ].A ) r ++;
    for( size_t i = l ; i < r ; i ++ ){
      s.insert( { v[ i ].T , v[ i ].ID } );
      sumt += v[ i ].T;
    }
    while( (int)s.size() > v[ l ].A or sumt > t ){
      sumt -= s.rbegin()->first;
      s.erase( --s.end() );
    }
    if( (int)s.size() == ans ){
      for( auto i : s )
        va.push_back( i.second );
      return;
    }
  }
}
void solve(){
  find_ans();
  find_who();
  printf( "%d\n" , ans );
  printf( "%d\n" , ans );
  for( int i = 0 ; i < ans ; i ++ )
    printf( "%d " , va[ i ] );
  puts( "" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}