#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=303030;
int n, m;
vector<pair<LL,LL>> v[N];
vector<int> cen;
vector<LL> dst;
bool on_cen[N];
bool go(int now, int prt, LL cur=0){
  if(now == n){
    cen.push_back(now);
    dst.push_back(cur);
    return true;
  }
  for(auto e: v[now]){
    int son=e.first;
    if(son == prt) continue;
    if(go(son, now, cur+e.second)){
      cen.push_back(now);
      dst.push_back(cur);
      return true;
    }
  }
  return false;
}
void gogo(int now, int prt, LL cur, int& who, LL& dd){
  if(now != prt){
    if(who){
      who=-1;
      dd=0;
      return;
    }
    who=now;
    dd=cur;
  }
  for(auto e: v[now]){
    int son=e.first;
    if(on_cen[son] or son==prt) continue;
    gogo(son, now, cur+e.second, who, dd);
  }
}
bool flag;
int nei[N];
LL dei[N], bst=-1e16;
void upd(LL con){
  bst=max(bst, con);
}
int main(){
  scanf("%d%d", &n, &m);
  for(int i=1; i<n; i++){
    int ui, vi, wi;
    scanf("%d%d%d", &ui, &vi, &wi);
    v[ui].push_back({vi, wi});
    v[vi].push_back({ui, wi});
  }
  assert(go(1, 1));
  reverse(cen.begin(), cen.end());
  reverse(dst.begin(), dst.end());
  for(int i: cen) on_cen[i]=true;
  for(int i: cen){
    gogo(i, i, 0, nei[i], dei[i]);
    if(nei[i] == -1) flag=true;
  }
  for(size_t i=0; i<cen.size(); i++){
    if(i > 1) upd(-(dst[i]-dst[i-2]));
    if(nei[cen[i]]){
      if(i) upd(dei[cen[i]]-(dst[i]-dst[i-1]));
      if(i+1<cen.size()) upd(dei[cen[i]]-(dst[i+1]-dst[i]));
      if(i and nei[cen[i-1]])
        upd(dei[cen[i]]+dei[cen[i-1]]-(dst[i]-dst[i-1]));
    }
  }
  while(m --){
    LL x; scanf("%lld", &x);
    LL ans=dst.back();
    if(not flag)
      ans=min(ans, ans+bst+x);
    printf("%lld\n", ans);
  }
}