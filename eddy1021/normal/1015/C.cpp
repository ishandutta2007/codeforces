#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=101010;
LL n, m, a[N], b[N];
int main(){
  scanf("%lld%lld", &n, &m);
  for(int i=0; i<n; i++)
    scanf("%lld%lld", &a[i], &b[i]);
  vector<LL> dlt;
  LL sz=accumulate(a, a+n, 0LL);
  for(int i=0; i<n; i++)
    dlt.push_back(a[i]-b[i]);
  sort(dlt.begin(), dlt.end());
  reverse(dlt.begin(), dlt.end());
  LL ans=0;
  for(LL d: dlt){
    if(sz <= m) break;
    ans++;
    sz -= d;
  }
  if(sz > m) puts("-1");
  else printf("%lld\n", ans);
}