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
void build(){

}
#define N 201010
int p[ N ];
int f( int x ){
  return x == p[ x ] ? x : p[ x ] = f( p[ x ] );
}
void uni( int x , int y ){
  p[ f( x ) ] = f( y );
}
struct Nd{
  Nd *t[ 2 ];
  Nd(){
    t[ 0 ] = t[ 1 ] = NULL;
  }
};
void modify( Nd* now , int vl , int bt ){
  if( bt < 0 ) return;
  int son = (vl >> bt) & 1;
  if( !now->t[ son ] )
    now->t[ son ] = new Nd();
  modify( now->t[ son ] , vl , bt - 1 );
}
int n , a[ N ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = getint();
  sort( a , a + n );
  n = unique( a , a + n ) - a;
}
LL ans;
unordered_map<int,int> id;
vector< pair<int,pair<int,int>> > e;
void add_edge( int i1 , int i2 , int c ){
  e.push_back( { c , { i1 , i2 } } );
}
void gogo( Nd* now , int vl , int bt , int cur , bool same ){
  if( bt < 0 ){
    if( same ) return;
    //cerr << vl << " " << cur << endl;
    add_edge( id[ vl ] , id[ cur ] , vl ^ cur );
    return;
  }
  if( same ){
    for( int i = 0 ; i < 2 ; i ++ )
      if( now->t[ i ] )
        gogo( now->t[ i ] , vl , bt - 1 , cur + i * (1 << bt) , 
              i == ((vl >> bt) & 1));
  }else{
    int nd = (vl >> bt) & 1;
    for( int i = 0 ; i < 2 ; i ++ )
      if( now->t[ i ^ nd ] ){
        gogo( now->t[ i ^ nd ] , vl , bt - 1 , 
              cur + (i ^ nd) * (1 << bt) ,
              false );
        break;
      }
  }
}
void solve(){
  Nd *root = new Nd();
  for( int i = 0 ; i < n ; i ++ ){
    modify( root , a[ i ] , 29 );
    id[ a[ i ] ] = i;
  }
  for( int i = 0 ; i < n ; i ++ )
    gogo( root , a[ i ] , 29 , 0 , true );
  sort( e.begin() , e.end() );
  ans = 0;
  for( int i = 0 ; i < n ; i ++ )
    p[ i ] = i;
  for( auto i : e )
    if( f( i.second.first ) !=
        f( i.second.second ) ){
      ans += i.first;
      uni( i.second.first ,
           i.second.second );
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