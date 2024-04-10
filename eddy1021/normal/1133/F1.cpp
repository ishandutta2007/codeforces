#include <bits/stdc++.h>
using namespace std;
const int N=202020;
int p[N];
int f(int x){
  return x==p[x]?x:p[x]=f(p[x]);
}
void uni(int x, int y){
  p[f(x)]=f(y);
}
vector<pair<int,int>> a;
vector<int> v[N];
int n, m;
int main(){
  scanf("%d%d", &n, &m); while(m --){
    int x, y; scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for(int i=1; i<=n; i++) p[i]=i;
  int bst=1;
  for(int i=1; i<=n; i++)
    if(v[i].size() > v[bst].size())
      bst=i;
  for(auto x: v[bst]){
    uni(bst, x);
    a.push_back({bst, x});
  }
  for(int i=1; i<=n; i++)
    for(auto j: v[i])
      if(f(i) != f(j)){
        uni(i, j);
        a.push_back({i, j});
      }
  for(auto e: a)
    printf("%d %d\n", e.first, e.second);
}