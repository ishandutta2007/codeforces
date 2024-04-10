#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=202020;
LL n, m, a[N];
int main(){
  scanf("%lld%lld", &n, &m);
  for(int i=1; i<=n; i++)
    scanf("%lld", &a[i]);
  int cur=1;
  LL pre=0;
  while(m --){
    LL bi;
    scanf("%lld", &bi);
    bi -= pre;
    while(bi > a[cur]){
      pre+=a[cur];
      bi-=a[cur];
      cur++;
    }
    printf("%d %lld\n", cur, bi);
  }
}