#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 101010
bool p[ N ];
vector<LL> pri;
const int mod = 1000000007;
inline int mul( LL x , int y ){
  x *= y;
  return x >= mod ? x % mod : x;
}
int mypow( int a , int b ){
  if( !b ) return 1;
  int ret = mypow( mul( a , a ) , b >> 1 );
  if( b & 1 ) ret = mul( ret , a );
  return ret;
}
vector<int> f;
void factor( int n ){
  for( LL y : pri ){
    if( y * y > n ) break;
    if( n % y ) continue;
    while( n % y == 0 )
      n /= y;
    f.push_back( y );
  }
  if( n > 1 )
    f.push_back( n );
}
int ans;
void go( size_t cur , int v , int r ){
  if( cur == f.size() ){
    ans += r * mypow( 2 , v - 1 );
    ans = (ans % mod + mod) % mod;
    return;
  }
  for( int i = 0 ; i <= 1 ; i ++ ){
    go( cur + 1 , v , i ? -r : r );
    v /= f[ cur ];
  }
}
int cal( int n ){
  factor( n );
  go( 0 , n , 1 );
  return ans;
}
int main(){
  for( int i = 2 ; i < N ; i ++ ) if( !p[ i ] ){
    pri.push_back( i );
    for( int j = i ; j < N ; j += i )
      p[ j ] = true;
  }
  int x , y;
  cin >> x >> y;
  if( y % x ) cout << 0 << endl;
  else cout << cal( y / x ) << endl;
}