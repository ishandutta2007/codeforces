// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
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
#define N 202020
void build(){

}
LL n , w , k , a[ N ] , t[ N ] , sa[ N ] , st[ N ];
void init(){
  n = getint();
  w = getint();
  k = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    a[ i ] = getint();
    sa[ i ] = sa[ i - 1 ] + a[ i ];
  }
  for( int i = 1 ; i <= n ; i ++ ){
    t[ i ] = getint();
    st[ i ] = st[ i - 1 ] + t[ i ];
  }
}
LL ans , bye;
multiset< int > big , small;
inline void balance(){
  while( (int)big.size() > w ){
    int x = *big.begin();
    big.erase( big.find( x ) );
    small.insert( x );
    bye -= x;
  }
  while( (int)big.size() < w ){
    if( small.empty() ) return;
    int x = *--small.end();
    small.erase( small.find( x ) );
    big.insert( x );
    bye += x;
  }
}
void Add( int idx ){
  big.insert( t[ idx ] / 2 );
  bye += t[ idx ] / 2;
  balance();
}
void Sub( int idx ){
  if( small.count( t[ idx ] / 2 ) )
    small.erase( small.find( t[ idx ] / 2 ) );
  else if( big.count( t[ idx ] / 2 ) ){
    big.erase( big.find( t[ idx ] / 2 ) );
    bye -= t[ idx ] / 2;
  }else
    assert( false );
  balance();
}
void solve(){
  int ptr = 1;
  for( int i = 1 ; i <= n ; i ++ ){
    if( ptr <= i ){
      small.clear();
      big.clear();
      bye = 0;
      ptr = i;
    }
    while( ptr <= n ){
      Add( ptr );
      if( st[ ptr ] - st[ i - 1 ] - bye > k ){
        Sub( ptr );
        break;
      }
      ptr ++;
    }
    //printf( "%d %d %lld %lld\n" , i , ptr , bye , sa[ ptr - 1 ] - sa[ i - 1 ] );
    ans = max( ans , sa[ ptr - 1 ] - sa[ i - 1 ] );
    if( i < ptr ) Sub( i );
  }
  printf( "%lld\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}