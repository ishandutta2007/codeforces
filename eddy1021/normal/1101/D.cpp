#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200020;
vector<int> dv[N];
void build(){
  for(int i=2; i<N; i++) if(dv[i].empty()){
    for(int j=i; j<N; j+=i)
      dv[j].push_back(i);
  }
}
int n, a[N], ans, tg[N], stmp;
vector<int> v[N];
void mark(int cur, int gg){
  if(a[cur] % gg) return;
  if(tg[cur] == stmp) return;
  tg[cur]=stmp;
  while(a[cur] % gg == 0) a[cur]/=gg;
  for(int son: v[cur])
    mark(son, gg);
}
int far, who;
void gogo(int now, int prt, int dst){
  if(dst > far) far=dst, who=now;
  for(int son: v[now]){
    if(son == prt) continue;
    if(tg[son] != stmp) continue;
    gogo(son, now, dst+1);
  }
}
void go(int cur, int gg){
  ++stmp;
  //cerr<<"  "<<cur<<" "<<gg<<endl;
  mark(cur, gg);
  who=cur; far=0;
  gogo(cur, cur, 0);
  gogo(who, who, 0);
  ans=max(ans, far+1);
}
int main(){
  build();
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    scanf("%d", &a[i]);
  for(int i=1; i<n; i++){
    int x, y;
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for(int i=1; i<=n; i++){
    int val=a[i];
    for(int cand: dv[val])
      go(i, cand);
  }
  cout<<ans<<endl;
}