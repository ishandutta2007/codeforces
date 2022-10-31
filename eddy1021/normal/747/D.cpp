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
void build(){

}
#define N 201010
int n , k , a[ N ] , nd;
void init(){
  n = getint();
  k = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    a[ i ] = getint();
    if( a[ i ] < 0 )
      nd ++;
  }
}
void solve(){
  if( k < nd ){
    puts( "-1" );
    exit( 0 );
  }
  vector< int > v;
  int tms = 0 , sum = 1 , con = 0;
  bool first = true;
  int fst = 0;
  for( int i = 1 ; i <= n ; i ++ )
    if( a[ i ] < 0 ){
      if( sum ){
        if( first ){
          fst = con;
          first = false;
        }else
          v.push_back( con );
        tms ++;
        sum = 0;
        con = 1;
      }else{
        con ++;
      }
    }else{
      if( !sum ){
        tms ++;
        sum = 1;
        con = 1;
      }else{
        con ++;
      }
    }
  int lst = 0;
  bool last = false;
  if( sum ){
    lst = con;
    last = true;
  }
  sort( v.begin() , v.end() );
  k -= nd;
  int sk = k , ans1 = tms;
  for( auto i : v ){
    if( k >= i ){
      k -= i;
      tms -= 2;
    }else break;
  }
  if( last && sk >= lst ){
    sk -= lst; ans1 --;
    for( auto i : v ){
      if( sk >= i ){
        sk -= i;
        ans1 -= 2;
      }else break;
    }
    tms = min( tms , ans1 );
  }
  printf( "%d\n" , max( 0 , tms ) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}