#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL x , d;
vector<LL> ans;
int main(){
  cin >> x >> d;
  LL pre = 1;
  for( int i = 31 ; i >= 1 and x > 0 ; i -- )
    while( x >= (1LL << i) - 1 ){
      for( int j = 0 ; j < i ; j ++ )
        ans.push_back( pre );
      pre += d + 2;
      x -= (1LL << i) - 1;
    }
  printf( "%d\n" , (int)ans.size() );
  for( size_t i = 0 ; i < ans.size() ; i ++ )
    printf( "%lld%c" , ans[ i ] , " \n"[ i + 1 == ans.size() ] );
}