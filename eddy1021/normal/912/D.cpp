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
LL n , m , r , k;
void init(){
  n = getint();
  m = getint();
  r = getint();
  k = getint();
}
LL ans;
LL cal( LL i , LL j ){
  LL gt = 1;
  {
    LL bl = max( 0LL , i - r + 1 );
    LL br = min( i , n - r );
    if( bl > br ) return 0;
    gt *= (br - bl + 1);
  }
  {
    LL bl = max( 0LL , j - r + 1 );
    LL br = min( j , m - r );
    if( bl > br ) return 0;
    gt *= (br - bl + 1);
  }
  return gt;
  //ans += gt;
}
typedef pair<LL, pair<int,int>> dat;
priority_queue< dat > heap;
inline LL enc( const pair<int,int>& pp ){
  return ( (LL)pp.first << 20 ) | pp.second;
}
unordered_set<LL> gt;
int di[]={0,0,1,-1};
int dj[]={1,-1,0,0};
void solve(){
  for( LL i = (n - 1) / 2 ; i <= n / 2 ; i ++ )
    for( LL j = (m - 1) / 2 ; j <= m / 2 ; j ++ )
      heap.push( { cal( i , j ) , { i , j } } );
  while( k -- ){
    dat who = heap.top(); heap.pop();
    LL e = enc( who.second );
    if( gt.find( e ) != gt.end() ){
      k ++;
      continue;
    }
    ans += who.first;
    gt.insert( e );
    for( int dir = 0 ; dir < 4 ; dir ++ ){
      int nxti = who.second.first + di[ dir ];
      int nxtj = who.second.second + dj[ dir ];
      if( nxti < 0 or nxti >= n or
          nxtj < 0 or nxtj >= m )
        continue;
      e = enc( { nxti , nxtj } );
      if( gt.find( e ) != gt.end() ) continue;
      heap.push( { cal( nxti , nxtj ) , { nxti , nxtj } } );
    }
  }
  LL tot = (n - r + 1) * (m - r + 1);
  printf( "%.12f\n" , (double)ans / tot );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}