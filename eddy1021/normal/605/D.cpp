// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<LD,LD> Pt;
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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
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
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 202020
int lb[ N ];
void build(){
  for( int i = 1 ; i < N ; i ++ )
    lb[ i ] = i & (-i);
}
set<PII> BIT[ N ];
int n , a[ N ][ 4 ];
bool got[ N ];
void modify( int ai , int bi , int idx ){
  for( int i = ai ; i < N ; i += lb[ i ] )
    BIT[ i ].insert( MP( bi , idx ) );
}
int query( int ai , int bi ){
  for( int i = ai ; i ; i -= lb[ i ] )
    while( BIT[ i ].size() && BIT[ i ].begin()->FI <= bi ){
      int tmp = BIT[ i ].begin()->SE;
      BIT[ i ].erase( BIT[ i ].begin() );
      if( !got[ tmp ] ) return tmp;
    }
  return 0;
}
void init(){
  n = getint();
  vector<int> li1 , li2;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 0 ; j < 4 ; j ++ ){
      a[ i ][ j ] = getint();
      if( j & 1 ) li1.PB( a[ i ][ j ] );
      else li2.PB( a[ i ][ j ] );
    }
  li1.PB( 0 );
  li2.PB( 0 );
  sort( ALL( li1 ) );
  sort( ALL( li2 ) );
  li1.resize( unique( ALL( li1 ) ) - li1.begin() );
  li2.resize( unique( ALL( li2 ) ) - li2.begin() );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 0 ; j < 4 ; j ++ ){
      if( j & 1 )
        a[ i ][ j ] = lower_bound( ALL( li1 ) , a[ i ][ j ] ) - li1.begin() + 1;
      else
        a[ i ][ j ] = lower_bound( ALL( li2 ) , a[ i ][ j ] ) - li2.begin() + 1;
    }
  for( int i = 1 ; i <= n ; i ++ )
    modify( a[ i ][ 0 ] , a[ i ][ 1 ] , i );
}
int bk[ N ];
queue< pair<PII,int> > Q;
void solve(){
  Q.push( MP( MP( 1 , 1 ) , 0 ) );
  while( Q.size() ){
    pair<PII,int> tp = Q.front(); Q.pop();
    int ai = tp.FI.FI;
    int bi = tp.FI.SE;
    int noi = tp.SE;
    while( true ){
      int idx = query( ai , bi );
      if( idx == 0 ) break;
      got[ idx ] = true;
      bk[ idx ] = noi;
      Q.push( MP( MP( a[ idx ][ 2 ] , a[ idx ][ 3 ] ) , idx ) );
    }
  }
  if( !got[ n ] ){
    puts( "-1" );
  }else{
    vector<int> vans;
    int now = n;
    while( now ){
      vans.PB( now );
      now = bk[ now ];
    }
    reverse( ALL( vans ) );
    printf( "%d\n" , (int)vans.size() );
    for( int i = 0 ; i < (int)vans.size() ; i ++ )
      printf( "%d%c" , vans[ i ] , " \n"[ i == (int)vans.size() - 1 ] );
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