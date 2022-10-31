#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  scanf("%d%d", &n, &k);
  if(__builtin_popcount(n) > k or n<k){
    puts("NO");
    return 0;
  }
  puts("YES");
  priority_queue<int> heap;
  k-=__builtin_popcount(n);
  while(n){
    int val=n&(-n);
    heap.push(val);
    n-=val;
  }
  while(k--){
    int val=heap.top(); heap.pop();
    assert(val>1);
    heap.push(val>>1);
    heap.push(val>>1);
  }
  while(heap.size()){
    printf("%d ", heap.top());
    heap.pop();
  }
  puts("");
}