#include <bits/stdc++.h>
using namespace std;
const int N=1021;
int n, m;
vector<int> v[N];
vector<pair<int, int>> cand;
bool vst[N];
int dia, who, cen, val, a, b;
void gogo(int now, int prt, int dst){
  if(dst > dia) dia=dst, who=now;
  vst[now]=true;
  for(int son: v[now]){
    if(son == prt) continue;
    gogo(son, now, dst+1);
  }
}
bool gogo2(int now, int prt, int dst){
  if(now == b) return true;
  for(int son: v[now]){
    if(son == prt) continue;
    if(gogo2(son, now, dst+1)){
      if(dst==dia/2) cen=now, val=max(dst, dia-dst);
      return true;
    }
  }
  return false;
}
void go(int now){
  dia=-1;
  gogo(now, now, 0); a=who;
  dia=-1;
  gogo(who, who, 0); b=who;
  val=0; cen=a;
  assert(gogo2(a, a, 0));
  //printf("now=%d, dia=%d, a=%d, b=%d, val=%d, cen=%d\n", 
         //now, dia, a, b, val, cen);
  cand.push_back({val, cen});
}
int main(){
  scanf("%d%d", &n, &m);
  while(m --){
    int x, y;
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for(int i=1; i<=n; i++){
    if(vst[i]) continue;
    go(i);
  }
  sort(cand.begin(), cand.end());
  vector<pair<int,int>> e;
  for(size_t i=0; i+1<cand.size(); i++)
    e.push_back({cand[i].second, cand.back().second});
  for(auto ee: e){
    v[ee.first].push_back(ee.second);
    v[ee.second].push_back(ee.first);
  }
  dia=-1;
  gogo(1, 1, 0);
  gogo(who, who, 0);
  printf("%d\n", dia);
  for(auto ee: e)
    printf("%d %d\n", ee.first, ee.second);
}