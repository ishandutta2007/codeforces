#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=101010;
LL n, k, p[N], c[N], ans[N];
int main(){
  scanf("%lld%lld", &n, &k);
  for(int i=0; i<n; i++) scanf("%lld", &p[i]);
  for(int i=0; i<n; i++) scanf("%lld", &c[i]);
  vector<pair<LL,LL>> v;
  for(int i=0; i<n; i++) v.push_back({p[i], i});
  sort(v.begin(), v.end());
  multiset<LL> cc; LL sum=0;
  for(auto _: v){
    int i=_.second;
    ans[i]=c[i]+sum;
    cc.insert(c[i]);
    sum+=c[i];
    while((int)cc.size() > k){
      sum-=*cc.begin();
      cc.erase(cc.begin());
    }
  }
  for(int i=0; i<n; i++) printf("%lld%c", ans[i], " \n"[i+1==n]);
}