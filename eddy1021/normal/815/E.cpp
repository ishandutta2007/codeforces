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
void build(){

}
LL n , k;
void init(){
  n = getint();
  k = getint();
}
vector<LL> cand;
int dep;
LL gt , pre;
map<LL,LL> dp;
LL ltar , rtar;
LL DP( LL x ){
  if( x < ltar ) return 0;
  if( x <= rtar ) return 1;
  if( rtar == 1 and x == 2 ) return 2;
  if( dp.count( x ) ) return dp[ x ];
  LL lvl = ( x - 1 ) / 2 , rvl = ( x - 1 ) - lvl;
  return dp[ x ] = DP( lvl ) + DP( rvl );
}
LL pos( LL l , LL r ){
  return l + ( r - l ) / 2;
}
void go( LL l , LL r , int cur_dep ){
  LL wid = r - l + 1;
  if( ltar <= wid and wid <= rtar ){
    printf( "%lld\n" , pos( l , r ) );
    Bye;
  }
  if( rtar == 1 and r - l + 1 == 2 ){
    if( k == 1 )
      go( l , l , cur_dep + 1 );
    go( r , r , cur_dep + 1 );
  }
  LL pp = pos( l , r );
  LL lc = DP( pp - 1 - l + 1 );
  //printf( "l = %lld r = %lld , pp = %lld, lc = %lld\n" , 
          //l , r , pp , lc );
  //printf( "%lld %lld %d pp = %lld, lc = %lld, k=%lld\n" ,
          //l , r , cur_dep , pp , lc , k );
  if( k <= lc ) go( l , pp - 1 , cur_dep + 1 );
  k -= lc;
  go( pp + 1 , r , cur_dep + 1 );
}
void solve(){
  if( k == 1 ){
    printf( "%d\n" , 1 );
    exit( 0 );
  }
  if( k == 2 ){
    printf( "%lld\n" , n );
    exit( 0 );
  }
  k -= 2;
  map<LL,LL> M;
  M[ n - 2 ] = 1;
  LL non1 = 0 , non2 = 0;
  for( int dd = 1 ; ; dd ++ ){
    map<LL,LL> M2;
    pre = gt;
    for( auto i : M ){
      if( i.first == 2 ){
        gt += 2;
        M2[ 1 ] += i.second * 2;
        continue;
      }
      gt += i.second;
      LL vl = i.first;
      if( vl > 1 ) non1 += i.second;
      if( vl > 2 ) non2 += i.second;
      vl --;
      LL lvl = vl / 2 , rvl = vl - lvl;
      if( lvl ) M2[ lvl ] += i.second;
      if( rvl ) M2[ rvl ] += i.second;
    }
    if( gt >= k ){
      for( auto i : M )
        if( i.first == 2 )
          cand.push_back( 1 );
        else
          cand.push_back( i.first );
      dep = dd;
      break;
    }
    M = M2;
  }
  if( cand.size() == 1u ){
    ltar = rtar = cand[ 0 ];
    if( cand[ 0 ] == 2 ){
      dep ++;
      ltar = rtar = 1;
      k -= non2;
    }else if( rtar == 1 )
      k -= non1;
    else
      k -= pre;
    //printf( "k = %lld\n" , k );
    go( 2 , n - 1 , 1 );
    Bye;
  }
  k -= pre;
  if( cand[ 1 ] & 1 ){
    ltar = rtar = cand[ 1 ];
    LL vl = DP( n - 2 );
    if( k <= vl ){
      go( 2 , n - 1 , 1 );
      Bye;
    }
    k -= vl;
    dp.clear();
    ltar = rtar = cand[ 0 ];
    go( 2 , n - 1 , 1 );
  }
  ltar = cand[ 0 ];
  rtar = cand[ 1 ];
  go( 2 , n - 1 , 1 );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}