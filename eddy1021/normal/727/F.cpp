#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 777
#define M 202020
int n, m, a[N];
void init(){
  scanf("%d%d", &n, &m);
  for(int i = 0 ; i < n ; i ++)
    scanf( "%d" , &a[i] );
}
LL qq[N];
bool okay( LL sum , int bye ){
  priority_queue<int> heap;
  for(int i = 0 ; i < n && bye >= 0 ; i ++){
    sum += a[i];
    if(a[i] < 0) heap.push(-a[i]);
    while(sum < 0){
      bye --;
      sum += heap.top();
      heap.pop();
    }
  }
  return bye >= 0;
}
void solve(){
  for(int i = 0 ; i <= n ; i ++){
    LL bl = 0 , br = 1000000000000000LL , ba = br;
    while( bl <= br ){
      LL mid = ( bl + br ) >> 1;
      if( okay( mid , i ) ) ba = mid , br = mid - 1;
      else bl = mid + 1;
    }
    qq[i] = ba;
  }
  while( m -- ){
    LL qi; scanf( "%lld" , &qi );
    int bl = 0 , br = n , ba = n;
    while( bl <= br ){
      int mid = ( bl + br ) >> 1;
      if( qi >= qq[ mid ] ) ba = mid , br = mid - 1;
      else bl = mid + 1;
    }
    printf( "%d\n" , ba );
  }
}
int main(){
  init();
  solve();
}