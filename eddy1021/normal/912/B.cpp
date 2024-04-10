#include <bits/stdc++.h>
using namespace std;
long long n , k , ans;
int main(){
  cin >> n >> k;
  k = min( k , 100LL );
  while( k -- ){
    long long cur = 0;
    for( int i = 62 ; i >= 0 ; i -- ){
      if( (ans >> i) & 1LL ) continue;
      if( (cur | (1LL << i)) <= n )
        cur |= (1LL << i);
    }
    ans ^= cur;
  }
  cout << ans << endl;
}