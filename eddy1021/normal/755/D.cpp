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
#define N 1010101
int n , k , BIT[ N ] , lb[ N ];
inline void modify( int pos ){
  for( int i = pos ; i <= n ; i += lb[ i ] )
    BIT[ i ] ++;
}
inline int query( int pos ){
  int sum = 0;
  for( int i = pos ; i ; i -= lb[ i ] )
    sum += BIT[ i ];
  return sum;
}
void build(){
  for( int i = 0 ; i < N ; i ++ )
    lb[ i ] = i & (-i);
}
void init(){
  n = getint();
  k = getint();
  if( n - k < k ) k = n - k;
}
LL ans[ N ];
inline int cal( int lft , int rgt ){
  //printf( "%d %d\n" , lft , rgt );
  vector< pair<int,int> > vv;
  for( int dlt = -1 ; dlt <= 1 ; dlt ++ ){
    int tlft = 1 + dlt * n;
    int trgt = n + dlt * n;
    tlft = max( tlft , lft );
    trgt = min( trgt , rgt );
    if( tlft <= trgt ){
      vv.push_back( { tlft - dlt * n , trgt - dlt * n } );
    }
  }
  sort( vv.begin() , vv.end() );
  if( vv.empty() ) return 0;
  size_t sz = 1;
  for( size_t i = 1 ; i < vv.size() ; i ++ )
    if( vv[ i ].first <= vv[ sz - 1 ].second )
      vv[ sz - 1 ].second = max( vv[ sz - 1 ].second , vv[ i ].second );
    else
      vv[ sz ++ ] = vv[ i ];
  vv.resize( sz );
  int tsum = 0;
  for( auto i : vv ){
    //printf( "asking %d %d\n" , i.first , i.second ); 
    tsum += query( i.second ) - query( i.first - 1 );
  }
  return tsum;
}
void solve(){
  LL area = 1;
  for( int i = 1 , now = 1 ; i <= n ; i ++ , now += k ){
    if( now > n ) now -= n;
    int ln = cal( now - k + 1 , now + k - 1 );
    area += ln + 1;
    modify( now );
    ans[ i ] = area;
  }
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%lld%c" , ans[ i ] , " \n"[ i == n ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}