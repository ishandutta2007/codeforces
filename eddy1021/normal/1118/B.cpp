#include <bits/stdc++.h>
using namespace std;
const int N=202020;
int n, a[N], s[N];
int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%d", &a[i]);
  for(int i=1; i<=n; i++)
    s[i]=s[i-1]+(i%2?1:-1)*a[i];
  int ans=0;
  for(int i=1; i<=n; i++)
    if(s[i-1]-s[n]+s[i]==0)
      ans++;
  printf("%d\n", ans);
}