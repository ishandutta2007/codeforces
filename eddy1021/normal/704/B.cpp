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
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 5140
void build(){

}
LL n , s , e;
LL x[ N ] , a[ N ] , b[ N ] , c[ N ] , d[ N ];
LL lin[ N ] , lout[ N ];
LL rin[ N ] , rout[ N ];
void init(){
  n = getint();
  s = getint();
  e = getint();
  for( int i = 1 ; i <= n ; i ++ ) x[ i ] = getint();
  for( int i = 1 ; i <= n ; i ++ ) a[ i ] = getint();
  for( int i = 1 ; i <= n ; i ++ ) b[ i ] = getint();
  for( int i = 1 ; i <= n ; i ++ ) c[ i ] = getint();
  for( int i = 1 ; i <= n ; i ++ ) d[ i ] = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    lin[ i ]  = +x[ i ] + a[ i ];
    rin[ i ]  = -x[ i ] + b[ i ];
    lout[ i ] = +x[ i ] + c[ i ];
    rout[ i ] = -x[ i ] + d[ i ];
  }
}
LL dp[ 2 ][ N ];
bool got[ 2 ][ N ];
void solve(){
  dp[ 1 ][ 1 ] = rin[ 1 ] + rout[ 1 ];
  if( s == 1 ) dp[ 1 ][ 1 ] = rout[ 1 ];
  if( e == 1 ) dp[ 1 ][ 1 ] = rin[ 1 ];
  got[ 1 ][ 1 ] = true;
  for( int i = 2 ; i <= n ; i ++ ){
    int now = i & 1 , pre = 1 - now;
    for( int j = 0 ; j <= n ; j ++ )
      got[ now ][ j ] = false;
    if( i == s ){
      if( s < e ){ 
        for( int j = 1 ; j <= n ; j ++ )
          if( got[ pre ][ j ] ){
            got[ now ][ j ] = true;
            dp[ now ][ j ] = dp[ pre ][ j ] + lout[ i ];
          }
        for( int j = 1 ; j < n ; j ++ )
          if( got[ pre ][ j ] ){
            LL tcst = dp[ pre ][ j ] + rout[ i ];
            if( !got[ now ][ j + 1 ] || tcst < dp[ now ][ j + 1 ] ){
              got[ now ][ j + 1 ] = true;
              dp[ now ][ j + 1 ] = tcst;
            }
          }
      }else{
        for( int j = 1 ; j <= n ; j ++ )
          if( got[ pre ][ j ] ){
            got[ now ][ j ] = true;
            dp[ now ][ j ] = dp[ pre ][ j ] + rout[ i ];
          }
        for( int j = 1 ; j <= n ; j ++ )
          if( got[ pre ][ j ] ){
            LL tcst = dp[ pre ][ j ] + lout[ i ];
            if( !got[ now ][ j - 1 ] || tcst < dp[ now ][ j - 1 ] ){
              got[ now ][ j - 1 ] = true;
              dp[ now ][ j - 1 ] = tcst;
            }
          }
      }
    }else if( i == e ){
      if( s < e ){ 
        for( int j = 1 ; j <= n ; j ++ )
          if( got[ pre ][ j ] ){
            got[ now ][ j ] = true;
            dp[ now ][ j ] = dp[ pre ][ j ] + rin[ i ];
          }
        for( int j = 1 ; j <= n ; j ++ )
          if( got[ pre ][ j ] ){
            LL tcst = dp[ pre ][ j ] + lin[ i ];
            if( !got[ now ][ j - 1 ] || tcst < dp[ now ][ j - 1 ] ){
              got[ now ][ j - 1 ] = true;
              dp[ now ][ j - 1 ] = tcst;
            }
          }
      }else{
        for( int j = 1 ; j < n ; j ++ )
          if( got[ pre ][ j ] ){
            got[ now ][ j + 1 ] = true;
            dp[ now ][ j + 1 ] = dp[ pre ][ j ] + rin[ i ];
          }
        for( int j = 1 ; j <= n ; j ++ )
          if( got[ pre ][ j ] ){
            LL tcst = dp[ pre ][ j ] + lin[ i ];
            if( !got[ now ][ j ] || tcst < dp[ now ][ j ] ){
              got[ now ][ j ] = true;
              dp[ now ][ j ] = tcst;
            }
          }
      }
    }else{
      for( int j = 1 ; j <= n ; j ++ )
        if( got[ pre ][ j ] ){
          if( j == 1 && e < i && i < s ) continue;
          got[ now ][ j ] = true;
          dp[ now ][ j ] = dp[ pre ][ j ] + lin[ i ] + rout[ i ];
        }
      for( int j = 1 ; j <= n ; j ++ )
        if( got[ pre ][ j ] ){
          if( j == 1 && s < i && i < e ) continue;
          LL tcst = dp[ pre ][ j ] + rin[ i ] + lout[ i ];
          if( !got[ now ][ j ] || tcst < dp[ now ][ j ] ){
            got[ now ][ j ] = true;
            dp[ now ][ j ] = tcst;
          }
        }
      for( int j = 1 ; j < n ; j ++ )
        if( got[ pre ][ j ] ){
          LL tcst = dp[ pre ][ j ] + rin[ i ] + rout[ i ];
          if( !got[ now ][ j + 1 ] || tcst < dp[ now ][ j + 1 ] ){
            got[ now ][ j + 1 ] = true;
            dp[ now ][ j + 1 ] = tcst;
          }
        }
      for( int j = 1 ; j <= n ; j ++ )
        if( got[ pre ][ j ] ){
          LL tcst = dp[ pre ][ j ] + lin[ i ] + lout[ i ];
          if( !got[ now ][ j - 1 ] || tcst < dp[ now ][ j - 1 ] ){
            got[ now ][ j - 1 ] = true;
            dp[ now ][ j - 1 ] = tcst;
          }
        }
    }
  }
  cout << dp[ n & 1 ][ 0 ] << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}