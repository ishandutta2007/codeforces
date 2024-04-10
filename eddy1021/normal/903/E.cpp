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
#define N 5050
int n , k;
vector<string> v;
int cnt[ 26 ] , tcnt[ 26 ];
bool gd;
void no(){
  puts( "-1" );
  Bye;
}
void init(){
  cin >> k >> n;
  v.resize( k );
  for( int i = 0 ; i < k ; i ++ )
    cin >> v[ i ];
  for( int i = 0 ; i < n ; i ++ )
    cnt[ v[ 0 ][ i ] - 'a' ] ++;
  for( int i = 0 ; i < 26 ; i ++ )
    if( cnt[ i ] > 1 )
      gd = true;
  for( int i = 1 ; i < k ; i ++ ){
    for( int j = 0 ; j < 26 ; j ++ )
      tcnt[ j ] = 0;
    for( int j = 0 ; j < n ; j ++ )
      tcnt[ v[ i ][ j ] - 'a' ] ++;
    for( int j = 0 ; j < 26 ; j ++ )
      if( cnt[ j ] != tcnt[ j ] )
        no();
  }
}
vector<int> dif[ N ];
void gogo( int c1 , int c2 ){
  swap( v[ 0 ][ c1 ] , v[ 0 ][ c2 ] );
  bool ok = true;
  for( int i = 1 ; i < k ; i ++ ){
    vector<int> tdif = dif[ i ];
    tdif.push_back( c1 );
    tdif.push_back( c2 );
    sort( tdif.begin() , tdif.end() );
    tdif.resize( unique( tdif.begin() , tdif.end() ) - tdif.begin() );
    int dif_cnt = 0;
    for( int j : tdif )
      if( v[ 0 ][ j ] != v[ i ][ j ] )
        dif_cnt ++;
    if( dif_cnt == 2 ) continue;
    if( dif_cnt == 0 and gd ) continue;
    ok = false;
    break;
  }
  if( ok ){
    cout << v[ 0 ] << endl;
    Bye;
  }
  swap( v[ 0 ][ c1 ] , v[ 0 ][ c2 ] );
}
void solve(){
  if( k == 1 ){
    swap( v[ 0 ][ 0 ] , v[ 0 ][ 1 ] );
    cout << v[ 0 ] << endl;
    Bye;
  }
  for( int i = 1 ; i < k ; i ++ ){
    for( int j = 0 ; j < n ; j ++ )
      if( v[ 0 ][ j ] != v[ i ][ j ] ){
        dif[ i ].push_back( j );
        if( dif[ i ].size() > 4u )
          no();
      }
  }
  for( int i = 0 ; i < n ; i ++ )
    for( int j = i + 1 ; j < n ; j ++ )
      gogo( i , j );
  no();
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}