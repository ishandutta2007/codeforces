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
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 200020
int n , a[ N ] , lft[ N ] , rgt[ N ];
vector<int> fac[ N ];
ll st[ N << 2 ];
int tag[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
inline void push( int no , int l , int r ){
  if( tag[ no ] != -1 ){
    st[ L( no ) ] = (ll)tag[ no ] * ( mid - l + 1 );
    st[ R( no ) ] = (ll)tag[ no ] * ( r - mid );
    tag[ L( no ) ] =
    tag[ R( no ) ] = tag[ no ];
  }
  tag[ no ] = -1;
}
inline void pull( int no ){
  st[ no ] = st[ L( no ) ] + st[ R( no ) ];
}
void modify( int no , int l , int r , int pl , int pr , ll vl ){
  if( l > pr || r < pl ) return;
  if( pl <= l && r <= pr ){
    st[ no ] = vl * ( r - l + 1 );
    tag[ no ] = vl;
    return;
  }
  push( no , l , r );
  modify( L( no ) , l , mid , pl , pr , vl );
  modify( R( no ) , mid + 1 , r , pl , pr , vl );
  pull( no );
}
ll query( int no , int l , int r , int ql , int qr ){
  if( l > qr || r < ql ) return 0;
  if( ql <= l && r <= qr ) return st[ no ];
  push( no , l , r );
  return query( L( no ) , l , mid , ql , qr ) +
         query( R( no ) , mid + 1 , r , ql , qr );
}
ll query( int no , int l , int r , int ps ){
  if( l == r ) return st[ no ];
  push( no , l , r );
  if( ps <= mid ) return query( L( no ) , l , mid , ps );
  return query( R( no ) , mid + 1 , r , ps );
}
void build(){
  for( int i = 1 ; i < N ; i ++ )
    lft[ i ] = N;
  for( int i = 1 ; i < ( N << 2 ) ; i ++ )
    tag[ i ] = -1;
  for( int i = 2 ; i < N ; i ++ )
    for( int j = i ; j < N ; j += i )
      fac[ j ].PB( i );
}
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  for( int i = 1 ; i <= n ; i ++ )
    for( size_t j = 0 ; j < fac[ a[ i ] ].size() ; j ++ ){
      lft[ fac[ a[ i ] ][ j ] ] = min( lft[ fac[ a[ i ] ][ j ] ] , i );
      rgt[ fac[ a[ i ] ][ j ] ] = max( rgt[ fac[ a[ i ] ][ j ] ] , i );
    }
}
ll ans;
int tdp[ N ] , rdp[ N ];
void solve(){
  tdp[ 0 ] = 1;
  for( int i = 1 ; i <= n ; i ++ ){
    tdp[ i ] = tdp[ i - 1 ];
    int vl = a[ i ];
    for( size_t j = 0 ; j < fac[ vl ].size() ; j ++ )
      if( lft[ fac[ vl ][ j ] ] < i )
        tdp[ i ] = max( tdp[ i ] , fac[ vl ][ j ] );
    if( i > 1 && i < n )
      ans += tdp[ i ];
    modify( 1 , 1 , n , i , i , tdp[ i ] );
  }
  rdp[ n + 1 ] = 1;
  for( int i = n ; i >= 2 ; i -- ){
    rdp[ i ] = rdp[ i + 1 ];
    int vl = a[ i ];
    for( size_t j = 0 ; j < fac[ vl ].size() ; j ++ )
      if( rgt[ fac[ vl ][ j ] ] > i )
        rdp[ i ] = max( rdp[ i ] , fac[ vl ][ j ] );
    for( size_t j = 0 ; j < fac[ vl ].size() ; j ++ )
      if( lft[ fac[ vl ][ j ] ] < i ){
        int nvl = fac[ vl ][ j ];
        if( query( 1 , 1 , n , lft[ nvl ] ) >= nvl ) continue;
        int bl = lft[ nvl ] + 1 , br = i - 1 , bmid , ba = lft[ nvl ];
        while( bl <= br ){
          bmid = ( bl + br ) >> 1;
          if( query( 1 , 1 , n , bmid ) < nvl ) ba = bmid , bl = bmid + 1;
          else br = bmid - 1;
        }
        modify( 1 , 1 , n , lft[ nvl ] , ba , nvl );
      }
    if( i != n ) ans += rdp[ i ];
    if( i >= 3 ){
      int bl = 2 , br = i - 2 , bmid , ba = -1;
      if( query( 1 , 1 , n , 1 ) < rdp[ i ] ){
        ba = 1;
        while( bl <= br ){
          bmid = ( bl + br ) >> 1;
          if( query( 1 , 1 , n , bmid ) < rdp[ i ] ) ba = bmid , bl = bmid + 1;
          else br = bmid - 1;
        }
      }
      if( ba == -1 ) ans += query( 1 , 1 , n , 1 , i - 2 );
      else{
        ans += (ll)rdp[ i ] * ba;
        if( ba + 1 <= i - 2 )
          ans += query( 1 , 1 , n , ba + 1 , i - 2 );
      }
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