#include <bits/stdc++.h>
using namespace std;
const int N=303030;
int n, a[N], s[N][3], all[3], ans;
vector<int> v[N];
void go(int now, int prt){
  s[now][a[now]]++;
  for(int son: v[now]){
    if(son == prt) continue;
    go(son, now);
    for(int c=0; c<3; c++)
      s[now][c]+=s[son][c];
  }
  if(now==prt) return;
  if((s[now][1]==all[1] and s[now][2]==0) or
     (s[now][2]==all[2] and s[now][1]==0))
    ans++;
}
int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    all[a[i]]++;
  }
  for(int i=1; i<n; i++){
    int ui, vi;
    scanf("%d%d", &ui, &vi);
    v[ui].push_back(vi);
    v[vi].push_back(ui);
  }
  go(1, 1);
  printf("%d\n", ans);
}