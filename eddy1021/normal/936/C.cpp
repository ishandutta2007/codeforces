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
#define N 2048
void build(){

}
int n;
char s[ N ] , t[ N ];
vector<char> ss , tt;
void no(){
  puts( "-1" );
  Bye;
}
void init(){
  n = getint();
  scanf( "%s" , s );
  scanf( "%s" , t );
  for( int i = 0 ; i < n ; i ++ )
    ss.push_back( s[ i ] );
  for( int i = 0 ; i < n ; i ++ )
    tt.push_back( t[ i ] );
  sort( ss.begin() , ss.end() );
  sort( tt.begin() , tt.end() );
  if( ss != tt ) no();
}
vector<int> ans;
void output(){
  printf( "%d\n" , (int)ans.size() );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%d%c" , ans[ i ] , " \n"[ i + 1 == ans.size() ] );
}
int shifted;
char buf[ N ];
void shift( int x ){
  if( x == 0 ) return;
  if( ++ shifted > 6100 ) no();
  ans.push_back( x );
  for( int i = 0 ; i < n ; i ++ )
    buf[ i ] = s[ i ];
  for( int i = 0 ; i < x ; i ++ )
    s[ i ] = buf[ n - i - 1 ];
  for( int i = x ; i < n ; i ++ )
    s[ i ] = buf[ i - x ];
  //printf( "%d\n" , x );
  //puts( s );
  //puts( t );
}
int got( int lb , int rb ){
  return lb <= rb ? rb - lb + 1 : rb + n - lb + 1;
}
void solve(){
  int mid = min( n - 1 , n / 2 + 3 );
  {
    int who = 0 ;
    for( int i = 0 ; i < n ; i ++ )
      if( s[ i ] == t[ mid ] ){
        who = i;
        break;
      }
    shift( n - who - 1 );
    shift( 1 );
  }
  int lb = mid , rb = mid , turn = 0;
  for( int rnd = 1 ; rnd < n ; rnd ++ ){
    if( rnd & 1 ){
      int who = -1;
      for( int i = n - 1 ; i >= 0 ; i -- )
        if( s[ i ] == t[ (lb - 1 + n) % n ] ){
          who = i;
          break;
        }
      assert( who != -1 );
      int rgt = n - who , lft = n - got( lb , rb ) - rgt;
      shift( rgt );
      shift( lft );
      shift( n );
      lb = (lb - 1 + n) % n;
      ++ turn;
    }else{
      int who = -1;
      for( int i = n - 1 ; i >= 0 ; i -- )
        if( s[ i ] == t[ (rb + 1 + n) % n ] ){
          who = i;
          break;
        }
      assert( who != -1 );
      int rgt = n - who , lft = n - got( lb , rb ) - rgt;
      shift( rgt );
      shift( lft );
      shift( n );
      rb = (rb + 1 + n) % n;
      ++ turn;
    }
    //cerr << rnd << " " << lb << " " << rb << endl;
    //puts( s );
    //puts(  )
  }
  //cerr << turn << endl;
  if( turn & 1 ) shift( n );
  while( strcmp( s , t ) ) shift( 1 );
  output();
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}