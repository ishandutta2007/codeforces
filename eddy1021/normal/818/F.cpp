#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL C2( LL x ){ return x * ( x - 1 ) / 2; }
int main(){
  int q; cin >> q; while( q -- ){
    LL n , a = 0; cin >> n;
    LL bl = 1 , br = n - 1;
    while( bl <= br ){
      LL mid = (bl + br) >> 1;
      LL res = C2( n - mid );
      if( res < mid ){
        a = max( a , mid + res );
        br = mid - 1;
      }else{
        a = max( a , mid + mid );
        bl = mid + 1;
      }
    }
    cout << a << endl;
  }
}