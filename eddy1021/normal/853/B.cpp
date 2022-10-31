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
#define N 1048576
void build(){

}
LL n , m , k;
vector< pair<int,int> > ar[ N ] , dp[ N ];
void init(){
  n = getint();
  m = getint();
  k = getint();
  while( m -- ){
    LL di = getint();
    LL fi = getint();
    LL ti = getint();
    LL ci = getint();
    if( fi == 0 )
      dp[ di ].push_back( { ti , ci } );
    else
      ar[ di ].push_back( { fi , ci } );
  }
}
LL bstl[ N ] , bstr[ N ];
bool got[ N ];
int pc[ N ];
void solve(){
  {
    int gt = 0;
    LL tcst = 0;
    for( int i = 0 ; i < N ; i ++ ){
      bstl[ i ] = INF16;
      for( auto ff : ar[ i ] ){
        int fr = ff.first;
        int cc = ff.second;
        if( !got[ fr ] ){
          got[ fr ] = true;
          gt ++;
          pc[ fr ] = cc;
          tcst += cc;
        }else if( cc < pc[ fr ] ){
          tcst -= pc[ fr ];
          pc[ fr ] = cc;
          tcst += cc;
        }
      }
      if( gt >= n )
        bstl[ i ] = tcst;
    }
  }
  {
    int gt = 0;
    for( int i = 0 ; i <= n ; i ++ )
      got[ i ] = false;
    LL tcst = 0;
    for( int i = N - 1 ; i >= 0 ; i -- ){
      bstr[ i ] = INF16;
      for( auto ff : dp[ i ] ){
        int fr = ff.first;
        int cc = ff.second;
        if( !got[ fr ] ){
          got[ fr ] = true;
          gt ++;
          pc[ fr ] = cc;
          tcst += cc;
        }else if( cc < pc[ fr ] ){
          tcst -= pc[ fr ];
          pc[ fr ] = cc;
          tcst += cc;
        }
      }
      if( gt >= n )
        bstr[ i ] = tcst;
    }
  }
  LL ans = INF16;
  for( int i = k + 1 ; i < N ; i ++ )
    ans = min( ans , bstl[ i - k - 1 ] + bstr[ i ] );
  printf( "%lld\n" , ans == INF16 ? -1LL : ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}