#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n , f , k , l , ans;
vector<LL> a;
int main(){
  cin >> n >> f;
  while( n -- ){
    cin >> k >> l;
    ans += min( k , l );
    a.push_back( max( 0ll , min( k , l - k ) ) );
  }
  sort( a.begin() , a.end() );
  while( f -- )
    ans += a.back(), a.pop_back();
  cout << ans << endl;
}