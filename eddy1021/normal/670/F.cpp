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
#define N 2010101
void build(){

}
char c[ N ] , c2[ N ];
int cnt[ 10 ] , cnt2[ 10 ] , tmp[ 10 ];
int n , n2 ;
int ord[ 10 ] , oc;
bool tag[ 10 ];
void init(){
  scanf( "%s" , c );
  scanf( "%s" , c2 );
  n = strlen( c );
  n2 = strlen( c2 );
  for( int i = 0 ; i < n ; i ++ )
    cnt[ c[ i ] - '0' ] ++;
  for( int i = 0 ; i < n2 ; i ++ ){
    cnt2[ c2[ i ] - '0' ] ++;
    if( !tag[ c2[ i ] - '0' ] ){
      ord[ oc ++ ] = c2[ i ] - '0';
      tag[ c2[ i ] - '0' ] = true;
    }
  }
}
inline bool worse( int st ){
  if( st != c2[ 0 ] - '0' ) return st > c2[ 0 ] - '0';
  tmp[ st ] --;
  int pp = 1;
  for( int i = 0 ; i <= ord[ 0 ] && pp < n2 ; i ++ )
    for( int j = 0 ; j < tmp[ i ] && pp < n2 ; j ++ ){
      if( i < c2[ pp ] - '0' ){
        tmp[ st ] ++;
        return false;
      }
      if( i > c2[ pp ] - '0' ){
        tmp[ st ] ++;
        return true;
      }
      pp ++;
    }
  tmp[ st ] ++;
  return st >= c2[ 0 ] - '0';
}
void test( int bt ){
  for( int i = 0 ; i < 10 ; i ++ )
    tmp[ i ] = cnt[ i ];
  int tbt = bt , tcnt = 0;
  while( tbt ){
    if( tmp[ tbt % 10 ] <= 0 ) return;
    tmp[ tbt % 10 ] --;
    tcnt ++;
    tbt /= 10;
  }
  if( tcnt + bt != n ) return;
  for( int i = 0 ; i < 10 ; i ++ ){
    if( tmp[ i ] < cnt2[ i ] )
      return;
    else tmp[ i ] -= cnt2[ i ];
  }
  bool pt = false;
  if( c2[ 0 ] == '0' || tmp[ 0 ] > 0 ){
    int got = -1;
    for( int i = 1 ; i < 10 ; i ++ )
      if( tmp[ i ] ){
        got = i;
        break;
      }
    if( got == -1 || ( c2[ 0 ] != '0' && worse( got ) ) ){
      if( c2[ 0 ] == '0' ) return;
      printf( "%s" , c2 );
      pt = true;
    }else{
      putchar( (char)(got + '0') );
      tmp[ got ] --;
    }
  }
  for( int i = 0 ; i < ord[ 0 ] ; i ++ )
    while( tmp[ i ] -- )
      putchar( (char)( i + '0' ) );
  int nxt = ord[ 0 ];
  if( oc <= 1 || ord[ 0 ] < ord[ 1 ] ){
    while( tmp[ nxt ] -- )
      putchar( (char)( nxt + '0' ) );
    nxt ++;
  }
  if( !pt ) printf( "%s" , c2 );
  for( int i = nxt ; i < 10 ; i ++ )
    while( tmp[ i ] -- )
      putchar( (char)( i + '0' ) );
  puts( "" );
  exit( 0 );
}
void solve(){
  if( n <= 2 ){
    puts( c2 );
    exit( 0 );
  }
  for( int i = n2 ; i <= n ; i ++ )
    test( i );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}