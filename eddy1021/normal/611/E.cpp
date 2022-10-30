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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
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
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 202020
int n;
int a[ 3 ] , t[ N ];
void build(){

}
void init(){
  n = getint();
  for( int i = 0 ; i < 3 ; i ++ )
    a[ i ] = getint();
  for( int i = 0 ; i < n ; i ++ )
    t[ i ] = getint();
  sort( a , a + 3 );
  sort( t , t + n );
}
multiset<int> S;
typedef multiset<int>::iterator si;
void solve(){
  if( t[ n - 1 ] > a[ 0 ] + a[ 1 ] + a[ 2 ] ){
    puts( "-1" );
    exit( 0 );
  }
  int ans = 0;
  for( int i = 0 ; i < n ; i ++ )
    S.insert( t[ i ] );
  while( S.size() ){
    int xi = *--S.end();
    if( xi <= a[ 0 ] ){
      int sz = (int)S.size();
      ans += sz / 3 + ( sz % 3 != 0 );
      break;
    }
    S.erase( S.find( xi ) );
    ans ++;
    if( xi > a[ 1 ] + a[ 2 ] ) continue;
    if( (int)S.size() == 0 ) break;
    if( xi > a[ 2 ] ){
      if( xi <= a[ 0 ] + a[ 1 ] ){
        si it = S.upper_bound( a[ 2 ] );
        if( it != S.begin() ){
          it --;
          S.erase( it );
        }
      }else if( xi <= a[ 0 ] + a[ 2 ] ){
        si it = S.upper_bound( a[ 1 ] );
        if( it != S.begin() ){
          it --;
          S.erase( it );
        } 
      }else{
        si it = S.upper_bound( a[ 0 ] );
        if( it != S.begin() ){
          it --;
          S.erase( it );
        } 
      }
    }else{
      bool flag0 = false;
      bool flag1 = false;
      si it = S.upper_bound( a[ 1 ] );
      if( it != S.begin() ){
        it --;
        flag1 = true;
        S.erase( it );
      } 
      it = S.upper_bound( a[ 0 ] );
      if( it != S.begin() ){
        it --;
        flag0 = true;
        S.erase( it );
      } 
      if( !flag0 && !flag1 ){
        it = S.upper_bound( a[ 0 ] + a[ 1 ] );
        if( it != S.begin() ){
          it --;
          S.erase( it );
        }   
      }
    }
  }
  printf( "%d\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}