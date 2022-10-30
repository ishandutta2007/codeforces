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
void build(){

}
#define N 101010
int a , b;
LL c;
char cc[ N ] , bb[ N ];
int trans( char ctmp ){
  if( ctmp >= '0' && ctmp <= '9' ) return ctmp - '0';
  return ctmp - 'A' + 10;
}
char rtrans( int x ){
  if( x < 10 ) return x + '0';
  return x - 10 + 'A';
}
void init(){
  a = getint();
  scanf( "%s" , bb );
  scanf( "%s" , cc );
  if( bb[ 0 ] == 'R' ) b = -1;
  else sscanf( bb , "%d" , &b );
  int len = strlen( cc );
  for( int i = 0 ; i < len ; i ++ )
    c = c * a + trans( cc[ i ] );
}
char rm[]="IVXLCDMGGGGG";
inline void W( int xx , int kk ){
  if( xx == 0 ) return;
  if( xx == 9 ){
    putchar( rm[ kk + 0 ] );
    putchar( rm[ kk + 2 ] );
  }else if( xx == 4 ){
    putchar( rm[ kk + 0 ] );
    putchar( rm[ kk + 1 ] );
  }else{
    if( xx >= 5 )
      putchar( rm[ kk + 1 ] );
    xx %= 5;
    for( int i = 0 ; i < xx ; i ++ )
      putchar( rm[ kk + 0 ] );
  }
}
void R(){
  W( c / 1000 , 6 ); c %= 1000;
  W( c / 100 , 4 ); c %= 100;
  W( c / 10 , 2 ); c %= 10;
  W( c , 0 );
  puts( "" );
}
void solve(){
  if( b == -1 ) R();
  else{
    string ans = "";
    if( c == 0 ) ans = "0";
    while( c ){
      ans += rtrans( c % b );
      c /= b;
    }
    reverse( ALL( ans ) );
    cout << ans << endl;
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