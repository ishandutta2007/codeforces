#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=202020;
LL n, ans[N];
map<LL,int> p;
int main(){
  scanf("%lld", &n);
  vector<LL> v;
  for(int i=0; i<n; i++){
    LL li, ri;
    scanf("%lld%lld", &li, &ri);
    p[li]++;
    p[ri+1]--;
    v.push_back(li);
    v.push_back(ri+1);
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end())-v.begin());
  LL ps=0;
  for(size_t i=0; i+1<v.size(); i++){
    ps+=p[v[i]];
    ans[ps]+=v[i+1]-v[i];
  }
  for(int i=1; i<=n; i++)
    printf("%lld%c", ans[i], " \n"[i==n]);
}