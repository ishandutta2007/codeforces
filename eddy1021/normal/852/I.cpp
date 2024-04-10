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
int p[ N ];
int fa( int x ){
  return x == p[ x ] ? x : p[ x ] = fa( p[ x ] );
}
void uni( int x , int y ){
  p[ fa( x ) ] = fa( y );
}
int n , g[ N ] , f[ N ] , q , qa[ N ] , qb[ N ] , qlca[ N ];
vector<int> v[ N ];
vector< pair<int,int> > qq[ N ];
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    g[ i ] = getint();
  vector<int> li;
  for( int i = 1 ; i <= n ; i ++ ){
    f[ i ] = getint();
    li.push_back( f[ i ] );
  }
  sort( li.begin() , li.end() );
  li.resize( unique( li.begin() , li.end() ) - li.begin() );
  for( int i = 1 ; i <= n ; i ++ )
    f[ i ] = lower_bound( li.begin() , li.end() , f[ i ] ) - li.begin();
  for( int i = 1 ; i < n ; i ++ ){
    int a = getint();
    int b = getint();
    v[ a ].push_back( b );
    v[ b ].push_back( a );
  }
  q = getint();
  for( int i = 0 ; i < q ; i ++ ){
    qa[ i ] = getint();
    qb[ i ] = getint();
    qq[ qa[ i ] ].push_back( { qb[ i ] , i } );
    qq[ qb[ i ] ].push_back( { qa[ i ] , i } );
  }
}
bool vst[ N ];
int st[ N ] , ed[ N ] , ar[ N + N ] , stmp;
void go( int now , int prt ){
  vst[ now ] = true;
  for( auto i : qq[ now ] ){
    if( not vst[ i.first ] ) continue;
    qlca[ i.second ] = fa( i.first );
  }
  st[ now ] = stmp;
  ar[ stmp ++ ] = now;
  for( auto son : v[ now ] ){
    if( son == prt ) continue;
    go( son , now );
    uni( son , now );
  }
  ed[ now ] = stmp;
  ar[ stmp ++ ] = now;
}
LL ans[ N ] , tans;
#define K 514
vector< pair<pair<int,int> , int> > od;
int cnt[ N ][ 2 ];
int tms[ N ];
void real_add( int who ){
  tans += cnt[ f[ who ] ][ 1 - g[ who ] ];
  cnt[ f[ who ] ][ g[ who ] ] ++;
}
void real_sub( int who ){
  tans -= cnt[ f[ who ] ][ 1 - g[ who ] ];
  cnt[ f[ who ] ][ g[ who ] ] --;
}
void Add( int who ){
  if( tms[ who ] == 0 ) real_add( who );
  else real_sub( who );
  tms[ who ] ++;
}
void Sub( int who ){
  if( tms[ who ] == 2 ) real_add( who );
  else real_sub( who );
  tms[ who ] --;
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    p[ i ] = i;
  go( 1 , 1 );
  for( int i = 0 ; i < q ; i ++ ){
    if( st[ qa[ i ] ] > st[ qb[ i ] ] )
      swap( qa[ i ] , qb[ i ] );
    if( qa[ i ] == qlca[ i ] )
      od.push_back( { { st[ qa[ i ] ] / K , st[ qb[ i ] ] } , i } );
    else
      od.push_back( { { ed[ qa[ i ] ] / K , st[ qb[ i ] ] } , i } );
  }
  sort( od.begin() , od.end() );
  int curl = 0 , curr = -1;
  for( auto _ : od ){
    int i = _.second;
    int tarl , tarr;
    if( qa[ i ] == qlca[ i ] )
      tarl = st[ qa[ i ] ] , tarr = st[ qb[ i ] ];
    else
      tarl = ed[ qa[ i ] ] , tarr = st[ qb[ i ] ];
    while( curr < tarr ) Add( ar[ ++ curr ] );
    while( curl > tarl ) Add( ar[ -- curl ] );
    while( curr > tarr ) Sub( ar[ curr -- ] );
    while( curl < tarl ) Sub( ar[ curl ++ ] );
    if( qa[ i ] != qlca[ i ] )
      Add( qlca[ i ] );
    ans[ i ] = tans;
    if( qa[ i ] != qlca[ i ] )
      Sub( qlca[ i ] );
  }
  for( int i = 0 ; i < q ; i ++ )
    printf( "%lld\n" , ans[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}