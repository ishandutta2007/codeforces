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
pair<LL,LL> gcd(LL a, LL b){
	if(b == 0) return {1, 0};
  pair<LL,LL> q = gcd(b, a % b);
  return {q.second, q.first - q.second * (a / b)};
}
LL solve(LL x1, LL m1, LL x2, LL m2) {
  assert( __gcd( m1 , m2 ) == 1 );
  pair<LL,LL> p = gcd(m1, m2);
  // m1 * p.first + m2 * p.second = 1
  LL lcm = m1 * m2;
  LL res = p.first * (x2 - x1) * m1 + x1;
  return (res % lcm + lcm) % lcm;
}
void build(){

}
#define N 1010101
LL a , b , p , x , lg[ N ] , sz;
void init(){
  cin >> a >> b >> p >> x;
  for( int i = 0 ; i < p ; i ++ )
    lg[ i ] = -1;
  for( int i = 0 , ai = 1 ; lg[ ai ] == -1 ; i ++ , ai = mul( ai , a , p ) ){
    lg[ ai ] = i;
    sz ++;
  }
}
LL ans;
void cal( LL i , LL j ){
  // x mod p = i
  // x mod sz = j
  LL rx = solve( i , p , j , sz );
  //printf( "i = %lld p = %lld j = %lld sz = %lld rx = %lld\n" , i , p , j , sz , rx );
  LL bs = p * sz;
  if( rx == 0 ) rx += bs;
  if( rx <= x )
    ans += (x - rx) / bs + 1;
}
void solve(){
  for( int i = 1 ; i < p ; i ++ ){
    LL goal = mul( b , mypow( i , p - 2 , p ) , p );
    if( lg[ goal ] == -1 ) continue;
    cal( i , lg[ goal ] );
  }
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}