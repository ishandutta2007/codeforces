#include <bits/stdc++.h>
using namespace std;
const int N=101010;
multiset<int> M;
int p[N], sz[N], tot;
int f(int x){
  return x == p[x] ? x : p[x]=f(p[x]);
}
void uni(int x, int y){
  x=f(x);
  y=f(y);
  if(x == y) return;
  M.erase(M.find(sz[x]));
  M.erase(M.find(sz[y]));
  tot --;
  p[x]=y;
  sz[y]+=sz[x];
  M.insert(sz[y]);
}
int n, a[N];
bool in[N];
int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    scanf("%d", &a[i]);
  vector< pair<int,int> > v;
  for(int i=1; i<=n; i++)
    v.push_back({a[i], i});
  sort(v.begin(), v.end());
  int ans=v[0].first+1;
  int cans=1;
  for(size_t _=0; _<v.size(); _++){
    int who=v[_].second;
    tot++;
    sz[who]=1;
    p[who]=who;
    in[who]=true;
    M.insert(1);
    for(int d=-1; d<=1; d+=2){
      int he=who+d;
      if(not in[he]) continue;
      uni(who, he);
    }
    if(_ + 1 < v.size() and v[_].first == v[_+1].first)
      continue;
    if(*M.begin() == *M.rbegin()){
      if(tot > cans){
        cans=tot;
        ans=v[_].first+1;
      }
    }
  }
  printf("%d\n", ans);
}