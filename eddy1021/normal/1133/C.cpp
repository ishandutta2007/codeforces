#include <bits/stdc++.h>
using namespace std;
const int N=202020;
int n, a[N], ans;
int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &a[i]);
  sort(a, a+n);
  int ptr=0;
  for(int i=0; i<n; i++){
    while(ptr<n and a[ptr]<=a[i]+5) ptr++;
    ans=max(ans, ptr-i);
  }
  printf("%d\n", ans);
}