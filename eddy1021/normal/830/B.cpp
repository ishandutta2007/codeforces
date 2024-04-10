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
LL st[ N << 2 ] , tg[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void push( int no , int l , int r ){
  if( tg[ no ] == 0 ) return;
  st[ L( no ) ] += ( mid - l + 1 ) * tg[ no ];
  tg[ L( no ) ] += tg[ no ];
  st[ R( no ) ] += ( r - mid ) * tg[ no ];
  tg[ R( no ) ] += tg[ no ];
  tg[ no ] = 0;
}
void modify( int no , int l , int r , int ql , int qr ){
  if( r < ql or l > qr ) return;
  if( ql <= l and r <= qr ){
    st[ no ] += r - l + 1;
    tg[ no ] ++;
    return;
  }
  push( no , l , r );
  modify( L( no ) , l , mid , ql , qr );
  modify( R( no ) , mid + 1 , r , ql , qr );
  st[ no ] = st[ L( no ) ] + st[ R( no ) ];
}
LL query( int no , int l , int r , int p ){
  if( l == r ) return st[ no ];
  push( no , l , r );
  if( p <= mid ) return query( L( no ) , l , mid , p );
  return query( R( no ) , mid + 1 , r , p );
}
void build(){

}
int n , a[ N ];
vector<int> pos[ N ];
vector<int> cand;
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    a[ i ] = getint();
    pos[ a[ i ] ].push_back( i );
    cand.push_back( a[ i ] );
  }
  sort( cand.begin() , cand.end() );
  cand.resize( unique( cand.begin() , cand.end() ) - cand.begin() );
}
int go_find( int ql , int qr , int who ){
  if( ql > qr ) return -1;
  int iterl = lower_bound( pos[ who ].begin() , pos[ who ].end() , ql ) -
    pos[ who ].begin();
  if( iterl == (int)pos[ who ].size() ) return -1;
  if( pos[ who ][ iterl ] > qr ) return -1;
  int iterr = upper_bound( pos[ who ].begin() , pos[ who ].end() , qr ) -
    pos[ who ].begin();
  return pos[ who ][ iterr - 1 ];
}
void mod( int ql , int qr ){
  //printf( "mod %d %d\n" , ql , qr );
  if( ql > n ) ql -= n;
  if( ql <= qr )
    modify( 1 , 1 , n , ql , qr );
  else{
    modify( 1 , 1 , n , ql , n );
    modify( 1 , 1 , n , 1 , qr );
  }
}
void solve(){
  LL ans = n , pre = 0;
  for( auto i : cand ){
    int pr = go_find( pre + 1 , n , i );
    int pl = go_find( 1 , pre - 1 , i );
    //printf( "%d : %lld %d %d\n" , i , pre , pr , pl );
    for( auto pp : pos[ i ] )
      ans += query( 1 , 1 , n , pp );
    if( pl == -1 and pr == -1 )
      assert( false );
    else if( pl == -1 or pr == -1 ){
      mod( pre + 1 , max( pl , pr ) );
      pre = max( pl , pr );
    }else{
      mod( pre + 1 , pl );
      pre = pl;
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