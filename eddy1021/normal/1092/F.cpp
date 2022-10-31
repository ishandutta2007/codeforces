#include <bits/stdc++.h>
using namespace std;
const int N=202020;
typedef long long LL;
int n;
vector<int> v[N];
LL a[N], ans, s[N];
void go(int now, int prt, LL dep){
  ans+=a[now]*dep;
  s[now]=a[now];
  for(int son: v[now]){
    if(son == prt) continue;
    go(son, now, dep+1);
    s[now]+=s[son];
  }
}
void go2(int now, int prt, LL cans){
  ans=max(ans, cans);
  for(int son: v[now]){
    if(son == prt) continue;
    go2(son, now, cans+s[1]-2*s[son]);
  }
}
int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
  for(int i=1; i<n; i++){
    int x, y; scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  go(1, 1, 0);
  go2(1, 1, ans);
  printf("%lld\n", ans);
}