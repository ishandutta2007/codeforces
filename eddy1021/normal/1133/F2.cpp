#include <bits/stdc++.h>
using namespace std;
const int N=202020;
void no(){
  puts("NO");
  exit(0);
}
int n, m, d, p[N];
int f(int x){
  return x==p[x]?x:p[x]=f(p[x]);
}
void uni(int x, int y){
  p[f(x)]=f(y);
}
vector<int> v[N];
bool tk[N];
int main(){
  scanf("%d%d%d", &n, &m, &d);
  while(m --){
    int x, y; scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  if((int)v[1].size() < d) no();
  for(int i=1; i<=n; i++) p[i]=i;
  int res=n-1;
  for(int i=2; i<=n; i++)
    for(int j: v[i]){
      if(j == 1) continue;
      if(f(i) == f(j)) continue;
      uni(i, j);
      res--;
    }
  if(d < res) no();
  for(int j: v[1]){
    if(f(1) == f(j)) continue;
    uni(1, j);
    res--;
    tk[j]=true;
  }
  vector<pair<int,int>> a;
  for(int i=1; i<=n; i++) p[i]=i;
  for(int j: v[1]) if(tk[j]){
    uni(1, j);
    a.push_back({1, j});
    d--;
  }
  for(int j: v[1]){
    if(d == 0) break;
    if(f(1) == f(j)) continue;
    d--;
    uni(1, j);
    a.push_back({1, j});
  }
  for(int i=2; i<=n; i++)
    for(int j: v[i]){
      if(j == 1) continue;
      if(f(i) == f(j)) continue;
      uni(i, j);
      a.push_back({i, j});
    }
  assert((int)a.size() == n-1);
  puts("YES");
  for(auto e: a)
    printf("%d %d\n", e.first, e.second);
}