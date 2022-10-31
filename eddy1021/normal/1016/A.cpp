#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=202020;
LL n, m, a[N];
int main(){
  scanf("%lld%lld", &n, &m);
  for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
  LL cur=0;
  for(int i=1; i<=n; i++){
    cur+=a[i];
    LL ans=cur/m;
    cur%=m;
    printf("%lld%c", ans, " \n"[i==n]);
  }
}