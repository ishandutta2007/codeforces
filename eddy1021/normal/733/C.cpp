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
int __ = 1 , _cs;
/*********default*********/
#define N 514
void build(){

}
int n , a[ N ] , k , b[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &a[ i ] );
  scanf( "%d" , &k );
  for( int i = 1 ; i <= k ; i ++ )
    scanf( "%d" , &b[ i ] );
}
vector< pair<int,int> > ans;
bool fix( int l , int r ){
  if( l == r ) return true;
  int mx = 0;
  for( int i = l ; i <= r ; i ++ )
    mx = max( mx , a[ i ] );
  for( int rgt = l ; rgt <= r ; rgt ++ ){
    if( a[ rgt ] != mx ) continue;
    if( rgt < r && a[ rgt ] > a[ rgt + 1 ] ){
      for( int i = rgt + 1 ; i <= r ; i ++ )
        ans.push_back( { rgt , 1 } );
      for( int i = rgt ; i > l ; i -- )
        ans.push_back( { i , 0 } );
      return true;
    }
    if( rgt > l && a[ rgt ] > a[ rgt - 1 ] ){
      for( int i = rgt ; i > l ; i -- )
        ans.push_back( { i , 0 } );
      for( int i = rgt + 1 ; i <= r ; i ++ )
        ans.push_back( { l , 1 } );
      return true;
    }
  }
  return false;
}
void solve(){
  int lst = n;
  for( int i = k ; i >= 1 ; i -- ){
    int sum = 0 , til = lst;
    while( lst > 0 && sum < b[ i ] ){
      sum += a[ lst ];
      lst --;
    }
    if( sum != b[ i ] || !fix( lst + 1 , til ) ){
      puts( "NO" );
      exit( 0 );
    }
  }
  if( lst ){
    puts( "NO" );
    exit( 0 );
  }
  puts( "YES" );
  for( auto i : ans )
    printf( "%d %c\n" , i.first , "LR"[ i.second ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}