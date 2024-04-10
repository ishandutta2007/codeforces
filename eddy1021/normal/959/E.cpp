#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ans;
void cal( LL n ){
  if( n <= 1 ) return;
  if( n == (n & (-n)) ){
    int bt = __lg( n );
    ans += bt * (1LL << (bt - 1));
    return;
  }
  int hgh = 0;
  for( int i = 0 ; i < 45 ; i ++ )
    if( (n >> i) & 1LL )
      hgh = i;
  ans += (1LL << hgh);
  cal( 1LL << hgh );
  cal( n - (1LL << hgh) );
}
int main(){
  LL n; cin >> n;
  cal( n );
  cout << ans << endl;
}