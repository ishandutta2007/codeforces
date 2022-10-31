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
void build(){

}
int n;
void init(){
  scanf( "%d" , &n );
}
inline int query( int lx , int ly , int rx , int ry ){
  printf( "? %d %d %d %d\n" , lx , ly , rx , ry );
  fflush( stdout );
  int num; scanf( "%d" , &num );
  return num;
}
int ax1[ 2 ] , ay1[ 2 ];
int ax2[ 2 ] , ay2[ 2 ];
inline bool cover( int num , int bx1 , int by1 , int bx2 , int by2 ){
  if( num == 0 ) return false;
  return bx1 <= ax1[ 0 ] && ax2[ 0 ] <= bx2 &&
         by1 <= ay1[ 0 ] && ay2[ 0 ] <= by2;
}
inline void find_ans( int num ){
  ax1[ num ] = 1; ax2[ num ] = n;
  ay1[ num ] = 1; ay2[ num ] = n;
  {
    int bl = 1 , br = n; 
    while( bl <= br ){
      int mid = ( bl + br ) >> 1;
      int ret = query( 1 , 1 , mid , n );
      if( cover( num , 1 , 1 , mid , n ) )
        ret --;
      if( ret ) ax2[ num ] = mid , br = mid - 1;
      else bl = mid + 1;
    }
  }
  {
    int bl = 1 , br = ax2[ num ];
    while( bl <= br ){
      int mid = ( bl + br ) >> 1;
      int ret = query( mid , 1 , ax2[ num ] , n );
      if( cover( num , mid , 1 , ax2[ num ] , n ) )
        ret --;
      if( ret ) ax1[ num ] = mid , bl = mid + 1;
      else br = mid - 1;
    }
  }
  {
    int bl = 1 , br = n; 
    while( bl <= br ){
      int mid = ( bl + br ) >> 1;
      int ret = query( ax1[ num ] , 1 , ax2[ num ] , mid );
      if( cover( num , ax1[ num ] , 1 , ax2[ num ] , mid ) )
        ret --;
      if( ret ) ay2[ num ] = mid , br = mid - 1;
      else bl = mid + 1;
    }
  }
  {
    int bl = 1 , br = ay2[ num ];
    while( bl <= br ){
      int mid = ( bl + br ) >> 1;
      int ret = query( ax1[ num ] , mid , ax2[ num ] , ay2[ num ] );
      if( cover( num , ax1[ num ] , mid , ax2[ num ] , ay2[ num ] ) )
        ret --;
      if( ret ) ay1[ num ] = mid , bl = mid + 1;
      else br = mid - 1;
    }
  }
}
void solve(){
  find_ans( 0 );
  find_ans( 1 );
  printf( "!" );
  for( int i = 0 ; i < 2 ; i ++ )
    printf( " %d %d %d %d" , ax1[ i ] , ay1[ i ] , ax2[ i ] , ay2[ i ] );
  puts( "" );
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