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
//int k , pw[ 10 ];
//LL ans;
//void go( int cur , int gt ){
  //if( cur == 0 ){
    //if( gt == 0 ) return;
    //ans += pw[ gt ];
    //return;
  //}
  //go( cur - 1 , gt     );
  //go( cur - 1 , gt + 1 );
//}
void build(){
  //cin >> k;
  //for( int i = 1 ; i <= 5 ; i ++ ){
    //pw[ i ] = 1;
    //for( int j = 0 ; j < k ; j ++ )
      //pw[ i ] *= i;
  //}
  //for( int i = 1 ; i <= 5 ; i ++ ){
    //ans = 0;
    //go( i , 0 );
    //printf( "%d %lld\n" , i , ans );
  //}
}
#define N 5140
int n , k , f[ N ];
void init(){
  cin >> n >> k;
}
int dp[ 2 ][ N ] , pw[ N ] , inv[ N ] , iinv[ N ];
int two[ N ] , itwo[ N ];
void find_ans(){
  two[ 0 ] = itwo[ 0 ] = 1;
  itwo[ 1 ] = (mod7 + 1) / 2;
  for( int i = 1 ; i <= k + 1 ; i ++ )
    two[ i ] = add( two[ i - 1 ] , two[ i - 1 ] );
  for( int i = 2 ; i <= k + 1 ; i ++ )
    itwo[ i ] = mul( itwo[ i - 1 ] , itwo[ 1 ] );
  for( int i = 1 ; i <= k + 1 ; i ++ ){
    if( i <= k )
      f[ i ] = mul( f[ i ] , two[ k - i ] );
    else
      f[ i ] = mul( f[ i ] , itwo[ i - k ] );
  }
  for( int i = 1 ; i <= k + 1 ; i ++ )
     inv[ i ] = mypow( i ,            mod7 - 2 , mod7 );
  for( int i = 1 ; i <= k + 1 ; i ++ )
    iinv[ i ] = mypow( sub( 0 , i ) , mod7 - 2 , mod7 );
  int ans = 0;
  for( int i = 1 ; i <= k + 1 ; i ++ ){
    int tans = f[ i ];
    for( int j = 1 ; j <= k + 1 ; j ++ ){
      if( i == j ) continue;
      tans = mul( tans , sub( n , j ) );
      if( j < i ) tans = mul( tans ,  inv[ i - j ] );
      if( j > i ) tans = mul( tans , iinv[ j - i ] );
    }
    ans = add( ans , tans );
  }
  ans = mul( ans , mypow( 2 , n - k , mod7 ) );
  printf( "%d\n" , ans );
  exit(0);
}
void solve(){
  for( int i = 1 ; i <= k + 1 ; i ++ ){
    pw[ i ] = 1;
    for( int j = 0 ; j < k ; j ++ )
      pw[ i ] = mul( pw[ i ] , i );
  }
  dp[ 0 ][ 0 ] = 1;
  for( int i = 1 ; i <= k + 1 ; i ++ ){
    int now = (i & 1) , pre = 1 ^ now;
    for( int j = 0 ; j <= i ; j ++ )
      dp[ now ][ j ] = 0;
    for( int j = 0 ; j <= i ; j ++ ){
      dp[ now ][ j ] = dp[ pre ][ j ];
      if( j )
        dp[ now ][ j ] = add( dp[ now ][ j ] , 
                              dp[ pre ][ j - 1 ] );
    }
    for( int j = 1 ; j <= i ; j ++ )
      f[ i ] = add( f[ i ] ,
                    mul( dp[ now ][ j ] , pw[ j ] ) );
  }
  if( n <= k + 1 ){
    printf( "%d\n" , f[ n ] );
    exit(0);
  }
  find_ans();
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}