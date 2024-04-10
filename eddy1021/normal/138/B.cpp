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
#define N 1010101
int c[ 2 ][ 10 ];
char ch[ N ];
void build(){

}
void init(){
  scanf( "%s" , ch );
  int len = strlen( ch );
  for( int i = 0 ; i < len ; i ++ ){
    c[ 0 ][ ch[ i ] - '0' ] ++;
    c[ 1 ][ ch[ i ] - '0' ] ++;
  }
}
int tcnt[ 10 ];
void solve(){
  int mx = -1 , kb = -1;
  for( int i = 1 ; i <= 9 ; i ++ )
    if( c[ 0 ][ i ] && c[ 1 ][ 10 - i ] ){
      int cnt = 1;
      c[ 0 ][ i ] --; c[ 1 ][ 10 - i ] --;
      for( int j = 0 ; j <= 9 ; j ++ ){
        tcnt[ j ] = min( c[ 0 ][ j ] , c[ 1 ][ 9 - j ] );
        c[ 0 ][ j ] -= tcnt[ j ];
        c[ 1 ][ 9 - j ] -= tcnt[ j ];
        cnt += tcnt[ j ];
      }
      cnt += min( c[ 0 ][ 0 ] , c[ 1 ][ 0 ] );
      if( cnt > mx ){
        mx = cnt;
        kb = i;
      }
      for( int j = 0 ; j <= 9 ; j ++ ){
        c[ 0 ][ j ] += tcnt[ j ];
        c[ 1 ][ 9 - j ] += tcnt[ j ];
      }
      c[ 0 ][ i ] ++; c[ 1 ][ 10 - i ] ++;
    }
  string s[ 2 ] = { "" , "" };
  if( kb == -1 ){
    while( c[ 0 ][ 0 ] && c[ 1 ][ 0 ] ){
      s[ 0 ] += "0";
      s[ 1 ] += "0";
      c[ 0 ][ 0 ] --;
      c[ 1 ][ 0 ] --;
    }
    for( int i = 0 ; i < 10 ; i ++ )
      while( c[ 0 ][ i ] ){
        s[ 0 ] = (char)( i + '0' ) + s[ 0 ];
        c[ 0 ][ i ] --;
      }
    for( int i = 0 ; i < 10 ; i ++ )
      while( c[ 1 ][ i ] ){
        s[ 1 ] = (char)( i + '0' ) + s[ 1 ];
        c[ 1 ][ i ] --;
      }
    printf( "%s\n%s\n" , s[ 0 ].c_str() , s[ 1 ].c_str() );
  }else{
    c[ 0 ][ kb ] --; c[ 1 ][ 10 - kb ] --;
    for( int j = 0 ; j <= 9 ; j ++ ){
      tcnt[ j ] = min( c[ 0 ][ j ] , c[ 1 ][ 9 - j ] );
      c[ 0 ][ j ] -= tcnt[ j ];
      c[ 1 ][ 9 - j ] -= tcnt[ j ];
    }
    while( c[ 0 ][ 0 ] && c[ 1 ][ 0 ] ){
      s[ 0 ] += "0";
      s[ 1 ] += "0";
      c[ 0 ][ 0 ] --;
      c[ 1 ][ 0 ] --;
    }
    s[ 0 ] = (char)( kb + '0' ) + s[ 0 ];
    s[ 1 ] = (char)( 10 - kb + '0' ) + s[ 1 ];
    for( int i = 0 ; i <= 9 ; i ++ )
      while( tcnt[ i ] ){
        s[ 0 ] = (char)( i + '0' ) + s[ 0 ];
        s[ 1 ] = (char)( 9 - i + '0' ) + s[ 1 ];
        tcnt[ i ] --;
      }
    for( int i = 0 ; i < 10 ; i ++ )
      while( c[ 0 ][ i ] ){
        s[ 0 ] = (char)( i + '0' ) + s[ 0 ];
        c[ 0 ][ i ] --;
      }
    for( int i = 0 ; i < 10 ; i ++ )
      while( c[ 1 ][ i ] ){
        s[ 1 ] = (char)( i + '0' ) + s[ 1 ];
        c[ 1 ][ i ] --;
      }
    printf( "%s\n%s\n" , s[ 0 ].c_str() , s[ 1 ].c_str() );
  }
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}