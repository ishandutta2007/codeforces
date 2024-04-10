#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n , m , seed , vmax;
inline int mul( LL a , LL b , int mod ){
  a *= b;
  return a >= mod ? a % mod : a;
}
inline int mpow( LL a , LL b , int mod ){
  if( !b ) return 1 % mod;
  int ret = mpow( mul( a , a , mod ) , b >> 1 , mod );
  if( b & 1LL ) ret = mul( ret , a , mod );
  return ret;
}
inline int rnd(){
  int ret = seed;
  seed = (seed * 7LL + 13) % 1000000007;
  return ret;
}
set< pair< pair<int,int> ,LL> > a;
void add( int l , int r , int dlt ){
  auto it = --a.upper_bound( { { l , n } , 0 } );
  vector< pair< pair<int,int> , LL > > vv;
  while( it != a.end() and it->first.first <= r ){
    vv.push_back( *it );
    it ++;
  }
  for( auto x : vv )
    a.erase( x );
  for( auto x : vv ){
    {
      int lb = x.first.first , rb = min( x.first.second , l - 1 );
      if( lb <= rb )
        a.insert( { { lb , rb } , x.second } );
    }
    {
      int lb = max( x.first.first , r + 1 ) , rb = x.first.second;
      if( lb <= rb )
        a.insert( { { lb , rb } , x.second } );
    }
    {
      int lb = max( l , x.first.first );
      int rb = min( r , x.first.second );
      if( lb <= rb )
        a.insert( { { lb , rb } , x.second + dlt } );
    }
  }
}
void ass( int l , int r , int dlt ){
  auto it = --a.upper_bound( { { l , n } , 0 } );
  vector< pair< pair<int,int> , LL > > vv;
  while( it != a.end() and it->first.first <= r ){
    vv.push_back( *it );
    it ++;
  }
  for( auto x : vv )
    a.erase( x );
  for( auto x : vv ){
    {
      int lb = x.first.first , rb = min( x.first.second , l - 1 );
      if( lb <= rb )
        a.insert( { { lb , rb } , x.second } );
    }
    {
      int lb = max( x.first.first , r + 1 ) , rb = x.first.second;
      if( lb <= rb )
        a.insert( { { lb , rb } , x.second } );
    }
  }
  a.insert( { { l , r } , dlt } );
}
void xth( int l , int r , int dlt ){
  vector< pair<LL,int> > vv;
  auto it = --a.upper_bound( { { l , n } , 0 } );
  while( it != a.end() and it->first.first <= r ){
    int lb = max( l , it->first.first );
    int rb = min( r , it->first.second );
    if( lb <= rb )
      vv.push_back( { it->second , rb - lb + 1 } );
    it ++;
  }
  sort( vv.begin() , vv.end() );
  for( auto i : vv ){
    dlt -= i.second;
    if( dlt <= 0 ){
      cout << i.first << "\n";
      return;
    }
  }
  assert( false );
}
void ppp( int l , int r , int x , int y ){
  int ans = 0;
  auto it = --a.upper_bound( { { l , n } , 0 } );
  while( it != a.end() and it->first.first <= r ){
    int lb = max( l , it->first.first );
    int rb = min( r , it->first.second );
    if( lb <= rb )
      ans = ( ans + mul( rb - lb + 1 , mpow( it->second % y , x , y ) , y ) ) % y;
    it ++;
  }
  cout << ans << "\n";
}
int main(){
  cin >> n >> m >> seed >> vmax;
  for( int i = 1 ; i <= n ; i ++ )
    a.insert( { { i , i } , rnd() % vmax + 1 } );
  while( m -- ){
    int op = rnd() % 4 + 1;
    int l = rnd() % n + 1;
    int r = rnd() % n + 1;
    if( l > r ) swap( l , r );
    int x , y = 0;
    if( op == 3 )
      x = rnd() % (r - l + 1) + 1;
    else
      x = rnd() % vmax + 1;
    if( op == 4 )
      y = rnd() % vmax + 1;
    if( op == 1 ) add( l , r , x );
    if( op == 2 ) ass( l , r , x );
    if( op == 3 ) xth( l , r , x );
    if( op == 4 ) ppp( l , r , x , y );
  }
}