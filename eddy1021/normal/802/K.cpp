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
#define N 101010
void build(){

}
int n , k , ans;
vector< pair<int,int> > v[ N ];
void init(){
  n = getint();
  k = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int ai = getint();
    int bi = getint();
    int ci = getint();
    v[ ai ].push_back( { bi , ci } );
    v[ bi ].push_back( { ai , ci } );
  }
}
void go( int now , int prt , int dep ){
  ans = max( ans , dep );
  for( auto i : v[ now ] ){
    if( i.first == prt ) continue;
    go( i.first , now , dep + i.second );
  }
}
int dp[ N ][ 2 ];
void DP( int now , int prt ){
  vector< int > vv;
  for( auto i : v[ now ] ){
    if( i.first == prt ) continue;
    DP( i.first , now );
    vv.push_back( dp[ i.first ][ 1 ] + i.second );
  }
  sort( vv.begin() , vv.end() );
  reverse( vv.begin() , vv.end() );
  for( int i = 0 ; i < min( k - 1 , (int)vv.size() ) ; i ++ )
    dp[ now ][ 1 ] += vv[ i ];
  dp[ now ][ 0 ] = dp[ now ][ 1 ];
  set< pair<int,int> > S;
  int sum = 0;
  for( auto i : v[ now ] ){
    if( i.first == prt ) continue;
    S.insert( { dp[ i.first ][ 1 ] + i.second , i.first } );
    sum += dp[ i.first ][ 1 ] + i.second;
    if( (int)S.size() > k ){
      auto it = S.begin();
      sum -= it->first;
      S.erase( it );
    }
  }
  for( auto i : v[ now ] ){
    if( i.first == prt ) continue;
    pair<int,int> wt = {-1 , -1};
    if( S.count( { dp[ i.first ][ 1 ] + i.second , i.first } ) ){
      wt = { dp[ i.first ][ 1 ] + i.second , i.first };
      S.erase( wt );
      sum -= wt.first;
    }else if( (int)S.size() >= k ){
      wt = *S.begin();
      S.erase( wt );
      sum -= wt.first;
    }
    dp[ now ][ 0 ] = max( dp[ now ][ 0 ] ,
                          sum + dp[ i.first ][ 0 ] + i.second );
    if( wt.second != -1 ){
      S.insert( wt );
      sum += wt.first;
    }
  }
}
void solve(){
  if( k == 1 ){
    go( 0 , 0 , 0 );
    printf( "%d\n" , ans );
    exit(0);
  }
  DP( 0 , 0 );
  printf( "%d\n" , dp[ 0 ][ 0 ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}