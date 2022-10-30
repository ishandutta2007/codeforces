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
struct Nd{
  Nd *tl , *tr;
  int sum;
  Nd(){
    tl = tr = NULL;
    sum = 0;
  }
};
Nd* copy( Nd* t ){
  Nd* ret = new Nd();
  if( t ){
    ret->tl = t->tl;
    ret->tr = t->tr;
    ret->sum = t->sum;
  }
  return ret;
}
int Sum( Nd* t ){
  return t ? t->sum : 0;
}
#define mid ((l+r)>>1)
void modify( Nd* t , int l , int r , int p , int dlt ){
  if( l == r ){
    t->sum += dlt;
    return;
  }
  if( p <= mid ){
    t->tl = copy( t->tl );
    modify( t->tl , l , mid , p , dlt );
  }else{
    t->tr = copy( t->tr );
    modify( t->tr , mid + 1 , r , p , dlt );
  }
  t->sum = Sum( t->tl ) + Sum( t->tr );
}
int query( Nd* t , int l , int r , int ql , int qr ){
  if( !t or r < ql or l > qr ) return 0;
  if( ql <= l and r <= qr ) return t->sum;
  return query( t->tl , l , mid , ql , qr ) +
         query( t->tr , mid + 1 , r , ql , qr );
}
void build(){

}
#define N 101021
int n , k;
queue<int> q[ N ];
Nd* root[ N ];
void init(){
  n = getint();
  k = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    int ai = getint();
    root[ i ] = copy( root[ i - 1 ] );
    modify( root[ i ] , 1 , n , i , +1 );
    q[ ai ].push( i );
    if( (int)q[ ai ].size() > k ){
      modify( root[ i ] , 1 , n , q[ ai ].front() , -1 );
      q[ ai ].pop();
    }
  }
}
void solve(){
  int last = 0;
  int qq = getint(); while( qq -- ){
    int ql = ( getint() + last ) % n + 1;
    int qr = ( getint() + last ) % n + 1;
    if( ql > qr ) swap( ql , qr );
    last = query( root[ qr ] , 1 , n , ql , qr );
    printf( "%d\n" , last );
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