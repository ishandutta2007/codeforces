#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=202020;
vector<int> v[N];
int n, q, in[N], out[N], a[N], stmp;
void go(int now, int prt){
  in[now]=++stmp;
  a[stmp]=now;
  for(int son: v[now]){
    if(son == prt) continue;
    go(son, now);
  }
  out[now]=stmp;
}
int main(){
  scanf("%d%d", &n, &q);
  for(int i=2; i<=n; i++){
    int pi; scanf("%d", &pi);
    v[pi].push_back(i);
  }
  go(1, 1);
  while(q--){
    int ui, ki; scanf("%d%d", &ui, &ki);
    if(out[ui]-in[ui]+1<ki) puts("-1");
    else printf("%d\n", a[in[ui]+ki-1]);
  }
}