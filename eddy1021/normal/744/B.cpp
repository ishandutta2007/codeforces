// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
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
#define N 1021
void build(){

}
int n , res[ N ] , ans[ N ];
bool tag[ N ];
void query( const vector<int>& v ){
  if( v.empty() ) return;
  //cerr << "asking ";
  //for( auto i : v ) cerr << i << " ";
  //cerr << endl;
  printf( "%d\n" , (int)v.size() );
  for( size_t i = 0 ; i < v.size() ; i ++ )
    printf( "%d%c" , v[ i ] , " \n"[ i + 1 == v.size() ] );
  fflush( stdout );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &res[ i ] );
  for( int i = 1 ; i <= n ; i ++ )
    tag[ i ] = false;
  for( int x : v ) tag[ x ] = true;
  for( int i = 1 ; i <= n ; i ++ )
    if( !tag[ i ] )
      ans[ i ] = min( ans[ i ] , res[ i ] );
}
int hf;
void init(){
  scanf( "%d" , &n );
  hf = n >> 1;
  for( int i = 1 ; i <= n ; i ++ )
    ans[ i ] = 1000000000;
}
vector< pair<int,int> > vv;
void solve(){
  vv.push_back( { 1 , hf } );
  vv.push_back( { hf + 1 , n } );
  for( int _ = 0 ; _ < 10 ; _ ++ ){
    vector< int > tmp1;
    for( size_t j = 0 ; j < vv.size() ; j += 2 )
      for( int k = vv[ j ].first ; k <= vv[ j ].second ; k ++ )
        tmp1.push_back( k );
    query( tmp1 );
    tmp1.clear();
    for( size_t j = 1 ; j < vv.size() ; j += 2 )
      for( int k = vv[ j ].first ; k <= vv[ j ].second ; k ++ )
        tmp1.push_back( k );
    query( tmp1 );
    vector< pair<int,int> > nxtv;
    for( auto i : vv ){
      int lft = i.first , rgt = i.second;
      if( lft > rgt ){
        nxtv.push_back( { lft , rgt } );
        nxtv.push_back( { lft , rgt } );
        continue;
      }
      int mid = ( lft + rgt ) >> 1;
      nxtv.push_back( { lft , mid } );
      nxtv.push_back( { mid + 1 , rgt } );
    }
    vv.swap( nxtv );
  }
  printf( "-1\n" );
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%d%c" , ans[ i ] , " \n"[ i == n ] );
  fflush( stdout );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}