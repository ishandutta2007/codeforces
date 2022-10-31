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
//#define SZ(x) (int)(x).size()
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
int p[ N ];
int f( int x ){
  return x == p[ x ] ? x : p[ x ] = f( p[ x ] );
}
void uni( int x , int y ){
  p[ f( x ) ] = f( y );
}
void build(){

}
int n , m , q;
vector<int> v[ N ];
void init(){
  n = getint();
  m = getint();
  q = getint();
  while( m -- ){
    int ai = getint();
    int bi = getint();
    v[ ai ].push_back( bi );
    v[ bi ].push_back( ai );
  }
  for( int i = 1 ; i <= n ; i ++ )
    p[ i ] = i;
}
bool vst[ N ];
int mxd[ N ];
vector<int> mxl[ N ] , mxr[ N ];
void go( int now , int prt ){
  vst[ now ] = true;
  uni( now , prt );
  for( int son : v[ now ] ){
    if( son == prt ){
      mxl[ now ].push_back( 0 );
      mxr[ now ].push_back( 0 );
      continue;
    }
    go( son , now );
    mxl[ now ].push_back( mxd[ son ] + 1 );
    mxr[ now ].push_back( mxd[ son ] + 1 );
  }
  for( size_t i = 1 ; i < mxl[ now ].size() ; i ++ )
    mxl[ now ][ i ] = max( mxl[ now ][ i ] ,
                           mxl[ now ][ i - 1 ] );
  for( int i = (int)mxr[ now ].size() - 2 ; i >= 0 ; i -- )
    mxr[ now ][ i ] = max( mxr[ now ][ i ] ,
                           mxr[ now ][ i + 1 ] );
  if( mxl[ now ].empty() ) mxd[ now ] = 0;
  else mxd[ now ] = *max_element( mxl[ now ].begin() , mxl[ now ].end() );
}
int dd[ N ];
vector<LL> ret[ N ] , sum[ N ];
void go2( int now , int prt , int ps ){
  dd[ now ] = max( mxd[ now ] , ps );
  ret[ f( now ) ].push_back( dd[ now ] );
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ ){
    int son = v[ now ][ i ];
    if( son == prt ) continue;
    int bst = ps;
    if( i ) bst = max( bst , mxl[ now ][ i - 1 ] );
    if( i + 1 < v[ now ].size() )
      bst = max( bst , mxr[ now ][ i + 1 ] );
    go2( son , now , bst + 1 );
  }
}
#define SZ 350
vector<int> cand;
double ans[ SZ ][ SZ ];
int at[ N ];
inline LL Sum( const vector<LL>& tv , int l , int r ){
  l = max( l , 0 );
  r = min( r , (int)tv.size() - 1 );
  LL tret = tv[ r ];
  if( l ) tret -= tv[ l - 1 ];
  return tret;
}
double cal( int big , int sml ){
  double tans = 0;
  for( int al = 0 ; al < (int)ret[ sml ].size() ; ){
    int i = ret[ sml ][ al ] , ar = al;
    {
      int bl = al , br = (int)ret[ sml ].size() - 1;
      while( bl <= br ){
        int bmid = ( bl + br ) >> 1;
        if( i == ret[ sml ][ bmid ] )
          ar = bmid , bl = bmid + 1;
        else
          br = bmid - 1;
      }
    }
    double ttans = 0;
    int bl = 0 , br = (int)ret[ big ].size() - 1 , ba = br + 1;
    while( bl <= br ){
      int bmid = ( bl + br ) >> 1;
      if( i + ret[ big ][ bmid ] + 1 >= ret[ big ].back() )
        ba = bmid , br = bmid - 1;
      else
        bl = bmid + 1;
    }
    if( ba <= (int)ret[ big ].size() - 1 ){
      int len = ret[ big ].size() - ba;
      LL xsum = Sum( sum[ big ] , ba , (int)ret[ big ].size() - 1 );
      ttans += ( (double)xsum + (double)( i + 1 ) * ( len ) )
                 / (double)ret[ big ].size();
    }
    if( 0 < ba ){
      ttans += (double)ret[ big ].back() * ba
        / (double)ret[ big ].size();
    }
    ttans /= (double)ret[ sml ].size();
    tans += ttans * ( ar - al + 1 );
    al = ar + 1;
  }
  return tans;
  return tans / (double)ret[ sml ].size();
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    if( not vst[ i ] ){
      go( i , i );
      go2( i , i , 0 );
    }
  for( int i = 1 ; i <= n ; i ++ )
    if( i == f( i ) ){
      sort( ret[ i ].begin() , ret[ i ].end() );
      sum[ i ] = ret[ i ];
      for( size_t j = 1 ; j < sum[ i ].size() ; j ++ )
        sum[ i ][ j ] += sum[ i ][ j - 1 ];
      //printf( "%d\n" , i );
      //for( size_t j = 0 ; j < ret[ i ].size() ; j ++ )
        //printf( "%d " , ret[ i ][ j ] );
      //puts( "" );
      //for( size_t j = 0 ; j < ret[ i ].size() ; j ++ )
        //printf( "%d " , sum[ i ][ j ] );
      //puts( "" );
      if( (int)ret[ i ].back() > SZ ){
        at[ i ] = cand.size();
        cand.push_back( i );
      }
    }
  for( size_t i = 0 ; i < cand.size() ; i ++ )
    for( size_t j = i + 1 ; j < cand.size() ; j ++ ){
      double tans;
      if( ret[ cand[ i ] ].back() > ret[ cand[ j ] ].back() )
        tans = cal( cand[ i ] , cand[ j ] );
      else
        tans = cal( cand[ j ] , cand[ i ] );
      ans[ i ][ j ] = ans[ j ][ i ] = tans;
    }
  while( q -- ){
    int ui = f( getint() );
    int vi = f( getint() );
    if( ui == vi ) puts( "-1" );
    else{
      if( ret[ ui ].back() > ret[ vi ].back() )
        swap( ui , vi );
      double pans = 0;
      if( (int)ret[ ui ].back() > SZ )
        pans = ans[ at[ ui ] ][ at[ vi ] ];
      else
        pans = cal( vi , ui );
      printf( "%.12f\n" , pans );
    }
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