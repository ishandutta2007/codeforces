#include <bits/stdc++.h>
using namespace std;
long long ans;
const int N=(1<<20);
int n, a[N], cnt[N][2];
int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    scanf("%d", &a[i]);
  for(int i=1; i<=n; i++){
    cnt[a[i-1]][(i-1)&1]++;
    a[i]^=a[i-1];
    ans+=cnt[a[i]][i&1];
  }
  printf("%lld\n", ans);
}