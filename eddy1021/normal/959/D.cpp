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
#define N 101010
#define K (N * 50)
bitset<K> np;
bitset<K> used , block;
vector<int> pset;
void build(){
  for( int i = 2 ; i < K ; i ++ ) if( !np[ i ] ){
    pset.push_back( i );
    for( int j = i ; j < K ; j += i )
      np[ j ] = true;
  }
  //cerr << pset.size() << endl;
  //exit(0);
}
LL n , a[ N ] , b[ N ];
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ ){
    bool ok = true;
    int ai = a[ i ];
    for( int j : pset ){
      if( j * j > ai ) break;
      if( ai % j ) continue;
      if( used[ j ] ){
        ok = false;
        break;
      }
      while( ai % j == 0 )
        ai /= j;
    }
    if( ai > 1 ){
      if( used[ ai ] )
        ok = false;
    }
    if( ok ){
      ai = b[ i ] = a[ i ];
      for( int j : pset ){
        if( j * j > ai ) break;
        if( ai % j ) continue;
        used[ j ] = true;
        for( int ii = j ; ii < K ; ii += j )
          block[ ii ] = true;
        while( ai % j == 0 )
          ai /= j;
      }
      if( ai > 1 ){
        used[ ai ] = true;
        for( int ii = ai ; ii < K ; ii += ai )
          block[ ii ] = true;
      }
      continue;
    }
    for( int ii = a[ i ] ; ; ii ++ ){
      if( block[ ii ] ) continue;
      ai = b[ i ] = ii;

      for( int j : pset ){
        if( j * j > ai ) break;
        if( ai % j ) continue;
        used[ j ] = true;
        while( ai % j == 0 )
          ai /= j;
      }
      if( ai > 1 )
        used[ ai ] = true;

      break;
    }
    int ptr = 0;
    for( int j = i + 1 ; j <= n ; j ++ ){
      while( used[ pset[ ptr ] ] ) ptr ++;
      b[ j ] = pset[ ptr ];
      used[ b[ j ] ] = true;
    }
    break;
  }
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%lld%c" , b[ i ] , " \n"[ i == n ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}