#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool check( LL n , LL k ){
  unordered_set<LL> s;
  for( LL i = 1 ; i <= k ; i ++ ){
    if( s.find( n % i ) != s.end() )
      return false;
    s.insert( n % i );
  }
  return true;
}
int main(){
  LL n , k;
  cin >> n >> k;
  puts( check( n , k ) ? "Yes" : "No" );
}