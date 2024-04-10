#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n , s , ans;
LL d( LL x ){
  LL ret = 0;
  while( x ){
    ret += x % 10;
    x /= 10;
  }
  return ret;
}
int main(){
  cin >> n >> s;
  ans = max( 0LL , n - s + 1 );
  for( LL i = s ; i <= min( n , s + 101010LL ) ; i ++ )
    if( i - d( i ) < s )
      ans --;
  cout << ans << endl;
}