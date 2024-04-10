#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=202020;
int n, m, p[N];
LL a[N];
int f(int x){
  return x==p[x]?x:p[x]=f(p[x]);
}
void uni(int x, int y){
  int xx=f(x);
  int yy=f(y);
  if(a[xx] < a[yy]) p[yy]=xx;
  else p[xx]=yy;
}
vector<pair<LL, pair<int,int>>> e;
int main(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
  for(int i=0; i<m; i++){
    int x, y; LL w;
    scanf("%d%d%lld", &x, &y, &w);
    e.push_back({w, {x, y}});
  }
  sort(e.begin(), e.end());
  for(int i=1; i<=n; i++) p[i]=i;
  set<pair<LL, int>> cand;
  for(int i=1; i<=n; i++) cand.insert({a[i], i});
  LL ans=0;
  size_t eptr=0;
  for(int _=1; _<n; _++){
    LL tkaa=1e18, x=0, y=0;
    if(cand.size() > 1u){
      auto it=cand.begin();
      x=it->second;
      it++;
      y=it->second;
      tkaa=a[x]+a[y];
    }
    while(eptr<e.size() and
          f(e[eptr].second.first)==
          f(e[eptr].second.second)) eptr++;
    if(eptr<e.size() and e[eptr].first < tkaa){
      tkaa=e[eptr].first;
      x=e[eptr].second.first;
      y=e[eptr].second.second;
    }
    ans+=tkaa;
    x=f(x); y=f(y);
    if(a[x] < a[y]) swap(x, y);
    cand.erase({a[x], x});
    uni(x, y);
  }
  printf("%lld\n", ans);
}