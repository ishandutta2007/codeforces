#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=202020;
int n, k, a[N];
char c[N];
int main(){
  scanf("%d%d", &n, &k);
  for(int i=0; i<n; i++) scanf("%d", &a[i]);
  scanf("%s", c);
  LL ans=0;
  for(int l=0, r=0; l<n; l=r){
    while(r<n and c[l]==c[r]) r++;
    priority_queue<int> heap;
    for(int i=l; i<r; i++) heap.push(a[i]);
    for(int i=0; i<k and heap.size(); i++)
      ans+=heap.top(), heap.pop();
  }
  printf("%lld\n", ans);
}