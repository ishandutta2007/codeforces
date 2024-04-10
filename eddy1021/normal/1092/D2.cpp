#include <bits/stdc++.h>
using namespace std;
const int N=202020;
typedef long long LL;
int p[N], sz[N], l[N], r[N];
int f(int x){
  return x==p[x]?x:p[x]=f(p[x]);
}
void uni(int x, int y){
  x=f(x); y=f(y);
  if(x==y) return;
  p[x]=y;
  sz[y]+=sz[x];
  l[y]=min(l[y], l[x]);
  r[y]=max(r[y], r[x]);
}
int n, a[N];
void no(){
  puts("NO");
  exit(0);
}
int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%d", &a[i]);
  for(int i=1; i<=n; i++) p[i]=l[i]=r[i]=i, sz[i]=1;
  set< pair<int,int> > cand;
  for(int i=1; i<=n; i++)
    if(i==n or a[i]!=a[i+1])
      cand.insert({a[i], f(i)});
    else
      uni(i, i+1);
  while(cand.size() > 1u){
    auto it=cand.begin();
    int who=it->second;
    cand.erase(it);

    int len=sz[who];
    if(len&1) no();
    int goal=2e9;
    if(l[who]>1) goal=min(goal, a[f(l[who] - 1)]);
    if(r[who]<n) goal=min(goal, a[f(r[who] + 1)]);
    assert(goal > a[who]);
    a[who]=goal;
    if(l[who]>1 and a[who]==a[f(l[who] - 1)]){
      cand.erase({a[f(l[who] - 1)], f(l[who] - 1)});
      uni(who, l[who]-1);
    }
    if(r[who]<n and a[who]==a[f(r[who] + 1)]){
      cand.erase({a[f(r[who] + 1)], f(r[who] + 1)});
      uni(who, r[who]+1);
    }
    cand.insert({goal, f(who)});
  }
  puts("YES");
}