// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
ll getint(){
    ll _x=0,_tmp=1; char _tc=getchar();    
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
    if( _x == 0 ) return 1ll;
    ll _tmp = mypow( _a , _x / 2 , _mod );
    _tmp = ( _tmp * _tmp ) % _mod;
    if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
    return _tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 9
#define P 1000010
ll n , a[ N ] , f[ N ];
bool p[ P ];
vector<ll> pset;
void build(){
  for( ll i = 2 ; i < P ; i ++ ) if( !p[ i ] ){
    pset.PB( i );
    for( ll j = P / i ; j >= i ; j -- )
      p[ i * j ] = true;
  }
}
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = getint();
  sort( a , a + n );
  for( int i = 0 ; i < n ; i ++ ){
    ll ta = a[ i ];
    for( ll j = 0 ; j < (int)pset.size() &&
                  pset[ j ] * pset[ j ] <= a[ i ] ; j ++ )
      while( ta % pset[ j ] == 0 ) f[ i ] ++, ta /= pset[ j ];
    if( ta > 1 ) f[ i ] ++;
  }
}
ll ans;
void DFS( ll idx , ll cnt , ll bonus ){
  if( idx < 0 ){
    ans = min( ans , cnt + ( bonus > 1 ) );
    return;
  }
  if( f[ idx ] > 1 ) cnt ++;
  DFS( idx - 1 , cnt + f[ idx ] , bonus + 1 );
  for( int i = n - 1 ; i > idx ; i -- )
    if( a[ i ] % a[ idx ] == 0 ){
      a[ i ] /= a[ idx ];
      DFS( idx - 1 , cnt , bonus );
      a[ i ] *= a[ idx ];
    }
}
void solve(){
  ans = INF;
  DFS( n - 1 , 0 , 0 );
  cout << ans << endl;
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}