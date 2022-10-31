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
set<int> st[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void modify( int no , int l , int r , int p , int x ){
  st[ no ].insert( x );
  if( l == r ) return;
  if( p <= mid ) modify( L( no ) , l , mid , p , x );
  else modify( R( no ) , mid + 1 , r , p , x );
}
int query( int no , int l , int r , int ql , int qr , int rr ){
  if( r < ql or l > qr or ql > qr ) return -1;
  if( ql <= l and r <= qr ){
    auto it = st[ no ].upper_bound( rr );
    if( it == st[ no ].begin() ) return -1;
    return *--it;
  }
  return max( query( L( no ) , l , mid , ql , qr , rr ),
              query( R( no ) , mid + 1 , r , ql , qr , rr ) );
}
void build(){

}
int n , m , qc;
vector<int> r[ N ];
vector<pair<int,int>> q[ N ];
int ans[ N ];
void init(){
  n = getint();
  m = getint();
  while( m -- ){
    int li = getint();
    int ri = getint();
    r[ li ].push_back( ri );
  }
  qc = getint();
  for( int i = 0 ; i < qc ; i ++ ){
    int li = getint();
    int ri = getint();
    q[ li ].push_back( { ri , i } );
  }
}
void solve(){
  for( int i = n ; i >= 1 ; i -- ){
    for( auto rr : r[ i ] )
      modify( 1 , 1 , n , i , rr );
    for( auto qq : q[ i ] ){
      int mst = qq.first;
      int now = i;
      while( true ){
        int nxt = query( 1 , 1 , n , i , now , mst );
        if( nxt <= now ) break;
        modify( 1 , 1 , n , i , nxt );
        now = nxt;
      }
      ans[ qq.second ] = now;
    }
  }
  for( int i = 0 ; i < qc ; i ++ )
    printf( "%d\n" , ans[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}