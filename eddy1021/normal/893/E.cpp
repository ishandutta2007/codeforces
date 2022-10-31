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
#define N 1000001
vector<int> f[ N ];
int fac[ N ] , inv[ N ] , two[ N ];
bool p[ N ];
void build(){
  for( int i = 2 ; i < N ; i ++ ) if( !p[ i ] )
    for( int j = i ; j < N ; j += i ){
      int cc = 0 , tmp = j;
      while( tmp % i == 0 ){
        tmp /= i;
        cc ++;
      }
      f[ j ].push_back( cc );
      p[ j ] = true;
    }
  two[ 0 ] = fac[ 0 ] = inv[ 0 ] = 1;
  for( int i = 1 ; i < N ; i ++ ){
    fac[ i ] = mul( fac[ i - 1 ] , i );
    inv[ i ] = mypow( fac[ i ] , mod7 - 2 , mod7 );
    two[ i ] = add( two[ i - 1 ] , two[ i - 1 ] );
  }
}
inline int C( int a , int b ){
  return mul( fac[ a ] , mul( inv[ b ] , inv[ a - b ] ) );
}
int x , y;
map< vector<int> , int > dp[ N ];
void init(){
  x = getint();
  y = getint();
}
inline int DP( vector<int> msk , int len );
void gogo( const vector<int>& omsk , int len ,
           vector<int>& msk , size_t cur , bool gt ){
  if( cur == msk.size() ){
    if( !gt ) return;
    int tmp = DP( msk , len - 1 );
    auto it = dp[ len ].find( omsk );
    if( it == dp[ len ].end() )
      dp[ len ][ omsk ] = tmp;
    else
      it->second = add( it->second , tmp );
    return;
  }
  for( int tk = 0 ; tk <= msk[ cur ] ; tk ++ ){
    msk[ cur ] -= tk;
    gogo( omsk , len , msk , cur + 1 , gt or tk > 0 );
    msk[ cur ] += tk;
  }
}
inline int DP( vector<int> msk , int len ){
  if( len == 1 ){
    if( accumulate( msk.begin() , msk.end() , 0 ) == 0 )
      return 0;
    return 1;
  }
  sort( msk.begin() , msk.end() );
  auto it = dp[ len ].find( msk );
  if( it != dp[ len ].end() ) return it->second;
  vector<int> tmsk = msk;
  gogo( msk , len , tmsk , 0 , false );
  return dp[ len ][ msk ];
}
void solve(){
  if( x == 1 ){
    printf( "%d\n" , two[ y - 1 ] );
    return;
  }
  int ans = 0;
  for( int i = 1 ; i <= min( y , 19 ) ; i ++ ){
    int ret = DP( f[ x ] , i );
    ret = mul( ret , C( y , i ) );
    //cerr << i << " " << ret << endl;
    ans = add( ans , ret );
  }
  ans = mul( ans , two[ y - 1 ] );
  printf( "%d\n" , ans );
}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}