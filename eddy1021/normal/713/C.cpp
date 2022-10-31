#include <bits/stdc++.h>
using namespace std;
#define N 3030
int n , a[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ ){
    scanf( "%d" , &a[ i ] );
    a[ i ] -= i;
  }
}
long long ans;
void solve(){
  priority_queue< int > heap;
  for( int i = 1 ; i <= n ; i ++ ){
    if( heap.size() && heap.top() > a[ i ] ){
      ans += heap.top() - a[ i ];
      heap.pop(); heap.push( a[ i ] );
    }
    heap.push( a[ i ] );
  }
  cout << ans << endl;
}
int main(){
  init();
  solve();
}