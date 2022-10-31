#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=303030;
int p[N];
int f(int x){
  return x==p[x]?x:p[x]=f(p[x]);
}
void uni(int x, int y){
  p[f(x)]=f(y);
}
int n, m, dep[N], low[N], stmp;
vector<int> v[N];
void go(int now, int prt){
  dep[now]=low[now]=++stmp;
  for(int son: v[now]){
    if(son == prt) continue;
    if(dep[son]){
      low[now]=min(low[now], dep[son]);
      continue;
    }
    go(son, now);
    if(low[son]<=dep[now]) uni(now, son);
    low[now]=min(low[now], low[son]);
  }
}
vector<int> g[N];
int ans, who;
void gogo(int now, int prt, int tdep){
  if(tdep>ans)
    ans=tdep, who=now;
  for(int son: g[now]){
    if(son == prt) continue;
    gogo(son, now, tdep+1);
  }
}
int main(){
  scanf("%d%d", &n, &m);
  while(m--){
    int a, b;
    scanf("%d%d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(int i=1; i<=n; i++)
    p[i]=i;
  go(1, 1);
  for(int i=1; i<=n; i++)
    for(int j: v[i])
      if(f(i) != f(j))
        g[f(i)].push_back(f(j));
  int s=1;
  for(int i=1; i<=n; i++)
    if(i == f(i))
      s=i;
  ans=-1;
  gogo(s, s, 0);
  gogo(who, who, 0);
  printf("%d\n", ans);
}