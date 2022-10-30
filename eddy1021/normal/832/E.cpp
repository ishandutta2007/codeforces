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
#define N 514
void build(){

}
struct For{
  vector< vector<int> > f;
  void push( vector<int> tf ){
    f.push_back( tf );
  }
  vector< pair<int,int> > vv;
  void print(){
    int n = f.size();
    int m = f[ 0 ].size();
    for( int ii = 0 ; ii < n ; ii ++ )
      for( int jj = 0 ; jj < m ; jj ++ )
        printf( "%d%c" , f[ ii ][ jj ] , " \n"[ jj + 1 == m ] );
  }
  int solve(){
    if( f.empty() ) return 0;
    int n = (int)f.size();
    int m = (int)f[ 0 ].size() , gt = 0;
    for( int j = 0 ; j < m ; j ++ ){
      int who = -1;
      for( int i = gt ; i < n ; i ++ )
        if( f[ i ][ j ] ){
          who = i;
          break;
        }
      if( who == -1 ) continue;
      swap( f[ gt ] , f[ who ] );
      vv.push_back( { gt , j } );
      int inv = mypow( f[ gt ][ j ] , 3 , 5 );
      for( int jj = 0 ; jj < m ; jj ++ )
        f[ gt ][ jj ] = mul( f[ gt ][ jj ] , inv , 5 );
      for( int i = 0 ; i < n ; i ++ ){
        if( i == gt ) continue;
        int bns = f[ i ][ j ];
        for( int jj = 0 ; jj < m ; jj ++ )
          f[ i ][ jj ] = sub( f[ i ][ jj ] , mul( f[ gt ][ jj ] , bns , 5 ) , 5 );
      }
      gt ++;
    }
    int cc = 0;
    for( int i = 0 ; i < n ; i ++ ){
      int s = 0;
      for( int j = 0 ; j < m ; j ++ )
        s += f[ i ][ j ];
      if( s > 0 ) cc ++;
    }
    return cc;
  }
  bool okay( const vector<int>& tar ){
    vector<int> ret;
    for( size_t i = 0 ; i < tar.size() ; i ++ )
      ret.push_back( 0 );
    for( auto i : vv ){
      int pos = i.second;
      int who = i.first;
      int nd = tar[ pos ];
      for( size_t j = 0 ; j < tar.size() ; j ++ )
        ret[ j ] = add( ret[ j ] , (int)mul( nd , f[ who ][ j ] , 5 ) , 5 );
    }
    for( size_t i = 0 ; i < tar.size() ; i ++ )
      if( tar[ i ] != ret[ i ] )
        return false;
    return true;
  }
} solver;
int n , m , zer;
char c[ N ][ N ];
bool o[ N ];
set< vector<int> > M;
void norm( vector<int>& vv ){
  for( int i = 0 ; i < m ; i ++ )
    if( vv[ i ] ){
      int tmp = mypow( vv[ i ] , 3 , 5 );
      for( int ii = 0 ; ii < m ; ii ++ )
        vv[ ii ] = mul( vv[ ii ] , tmp , 5 );
      return;
    }
}
void init(){
  n = getint();
  m = getint();
  for( int i = 0 ; i < n ; i ++ ){
    scanf( "%s" , c[ i ] );
    o[ i ] = true;
    for( int j = 0 ; j < m ; j ++ )
      if( c[ i ][ j ] != 'a' )
        o[ i ] = false;
    if( o[ i ] ) zer ++;
    else{
      vector<int> tmp;
      for( int j = 0 ; j < m ; j ++ )
        tmp.push_back( c[ i ][ j ] - 'a' );
      norm( tmp );
      M.insert( tmp );
    }
  }
}
char t[ N ];
void solve(){
  for( auto i : M )
    solver.push( i );
  int ans = mypow( 5 , n - solver.solve() , mod7 );
  int q = getint(); while( q -- ){
    scanf( "%s" , t );
    vector<int> tmp;
    for( int i = 0 ; i < m ; i ++ )
      tmp.push_back( t[ i ] - 'a' );
    printf( "%d\n" , solver.okay( tmp ) ? ans : 0 );
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