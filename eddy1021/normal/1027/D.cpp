#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=202020;
int n, c[N], a[N], ind[N];
int vst[N], stmp;
LL ans;
void go(int i){
  ++ stmp;
  int cur=i;
  while(vst[cur] == 0){
    vst[cur]=stmp;
    cur=a[cur];
  }
  if(vst[cur] != stmp) return;
  LL bst=1e6;
  int now=cur;
  do{
    bst=min(bst, (LL)c[now]);
    now=a[now];
  }while(now != cur);
  ans+=bst;
}
int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%d", &c[i]);
  for(int i=1; i<=n; i++) scanf("%d", &a[i]);
  for(int i=1; i<=n; i++) ind[a[i]]++;
  for(int i=1; i<=n; i++) if(ind[i] == 0) go(i);
  for(int i=1; i<=n; i++) if(vst[i] == 0) go(i);
  printf("%lld\n", ans);
}