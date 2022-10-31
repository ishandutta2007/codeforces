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
int st[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void build_st( int no , int l , int r ){
  st[ no ] = r - l + 1;
  if( l == r ) return;
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
}
void modify( int no , int l , int r , int p ){
  if( l == r ){
    st[ no ] = 0;
    return;
  }
  if( p <= mid ) 
    modify( L( no ) , l , mid , p );
  else
    modify( R( no ) , mid + 1 , r , p );
  st[ no ] = st[ L( no ) ] + st[ R( no ) ];
}
int kth( int no , int l , int r , int k ){
  if( l == r ) return l;
  if( k <= st[ L( no ) ] ) return kth( L( no ) , l , mid , k );
  return kth( R( no ) , mid + 1 , r , k - st[ L( no ) ] );
}
void build(){

}
int n , m;
char c[ N ];
set<int> at[ 256 ];
void init(){
  n = getint();
  m = getint();
  scanf( "%s" , c + 1 );
  for( int i = 1 ; i <= n ; i ++ )
    at[ (int)c[ i ] ].insert( i );
  build_st( 1 , 1 , n );
}
void go( int no , int l , int r ){
  if( st[ no ] == 0 ) return;
  if( l == r ){
    putchar( c[ l ] );
    return;
  }
  go( L( no ) , l , mid );
  go( R( no ) , mid + 1 , r );
}
void solve(){
  char buf[ 256 ];
  while( m -- ){
    int l = kth( 1 , 1 , n , getint() );
    int r = kth( 1 , 1 , n , getint() );
    scanf( "%s" , buf );
    int who = buf[ 0 ];
    vector<int> bye;
    auto it = at[ who ].lower_bound( l );
    while( it != at[ who ].end() and *it <= r ){
      bye.push_back( *it );
      it ++;
    }
    for( int v : bye ){
      at[ who ].erase( v );
      modify( 1 , 1 , n , v );
    }
  }
  go( 1 , 1 , n );
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