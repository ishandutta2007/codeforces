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
#define N 101010
int n , m;
vector< vector<int> > ans;
void init(){
  n = getint();
  m = getint();
}
int dn[]={0,0,1,-1};
int dm[]={1,-1,0,0};
bool check(){
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < m ; j ++ ){
      int now = ans[ i ][ j ];
      set<int> gg;
      if( now % m != 1 )
        gg.insert( now - 1 );
      if( now % m != 0 )
        gg.insert( now + 1 );
      gg.insert( now - m );
      gg.insert( now + m );
      for( int k = 0 ; k < 4 ; k ++ ){
        int nxti = i + dn[ k ];
        int nxtj = j + dm[ k ];
        if( 0 <= nxti and nxti < n and
            0 <= nxtj and nxtj < m and
            gg.find( ans[ nxti ][ nxtj ] ) != gg.end() ){
          if( n * m > 16 ){
            for( int ii = 0 ; ii < n ; ii ++ )
              for( int jj = 0 ; jj < m ; jj ++ )
                printf( "%d%c" , ans[ ii ][ jj ] , " \n"[ jj + 1 == m ] );
            cerr << ans[ i ][ j ] << " " << ans[ nxti ][ nxtj ] << endl;
          }
          return false;
          //assert( false );
        }
      }
    }
  return true;
}
void go(){
  ans.resize( n );
  for( int i = 0 ; i < n ; i ++ )
    ans[ i ].resize( m );
  for( int i = 0 ; i < n ; i ++ ){
    int l = i * m + 1;
    int r = i * m + 2;
    int lst = i % m;
    int rst = (lst + ((m + 1) / 2)) % m;
    for( int j = 0 ; j < m ; j ++ ){
      if( j & 1 ){
        ans[ i ][ rst ] = r;
        r += 2;
        rst ++;
        if( rst >= m ) rst = 0;
      }else{
        ans[ i ][ lst ] = l;
        l += 2;
        lst ++;
        if( lst >= m ) lst = 0;
      }
    }
  }
  //int vl = 0;
  //for( int i = 0 ; i < n ; i += 2 ){
    //if( i % 4 == 0 ){
      //for( int j = 0 ; j < m ; j ++ )
        //ans[ i + (j & 1) ][ j ] = ++ vl;
      //for( int j = m - 1 ; j >= 0 ; j -- )
        //if( ans[ i ][ j ] )
          //ans[ i + 1 ][ j ] = ++ vl;
        //else
          //ans[ i     ][ j ] = ++ vl;
    //}else{
      //for( int j = 0 ; j < m ; j ++ )
        //ans[ i + 1 - (j & 1) ][ j ] = ++ vl;
      //for( int j = m - 1 ; j >= 0 ; j -- )
        //if( ans[ i ][ j ] )
          //ans[ i + 1 ][ j ] = ++ vl;
        //else
          //ans[ i     ][ j ] = ++ vl;
    //}
  //}
}
void fuck(){
  vector<int> ind;
  for( int i = 1 ; i <= n * m ; i ++ )
    ind.push_back( i );
  ans.resize( n );
  for( int i = 0 ; i < n ; i ++ )
    ans[ i ].resize( m );
  do{
    int ptr = 0;
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < m ; j ++ )
        ans[ i ][ j ] = ind[ ptr ++ ];
    if( check() ){
      puts( "YES" );
      for( int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < m ; j ++ )
          printf( "%d%c" , ans[ i ][ j ] , " \n"[ j + 1 == m ] );
      Bye;
    }
  }while( next_permutation( ind.begin() , ind.end() ) );
  puts( "NO" );
  Bye;
}
void solve(){
  if( n == 4 and m == 4 ){
    ans.resize( 4 );
    ans[ 0 ] = { 5 , 4 , 7 , 2 };
    ans[ 1 ] = { 3 , 6 , 1 , 8 };
    ans[ 2 ] = { 11 , 14 , 9 , 16 };
    ans[ 3 ] = { 13 , 12 , 15 , 10 };
    assert( check() );
    puts( "YES" );
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < m ; j ++ )
        printf( "%d%c" , ans[ i ][ j ] , " \n"[ j + 1 == m ] );
    Bye;
  }
  if( max( n , m ) <= 4 )
  //if( n * m <= 12 )
    fuck();
  //return;
  //if( n % 2 == 0 or m % 2 == 0 ){
    bool swp = false;
    if( m <= 4 ){
      swp = true;
      swap( n , m );
    }
    go();
    assert( check() );
    puts( "YES" );
    if( swp ){
      vector< vector<int> > ori;
      ori.resize( m );
      for( int i = 0 ; i < m ; i ++ )
        ori[ i ].resize( n );
      int qq = 0;
      for( int i = 0 ; i < m ; i ++ )
        for( int j = 0 ; j < n ; j ++ )
          ori[ i ][ j ] = ++ qq;
      for( int i = 0 ; i < m ; i ++ )
        for( int j = 0 ; j < n ; j ++ ){
          int row = (ans[ j ][ i ] - 1) % m;
          int col = (ans[ j ][ i ] - 1) / m;
          int ggg = ori[ row ][ col ];
          printf( "%d%c" , ggg , " \n"[ j + 1 == n ] );
        }
    }else{
      for( int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < m ; j ++ )
          printf( "%d%c" , ans[ i ][ j ] , " \n"[ j + 1 == m ] );
    }
    Bye;
  //}
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}