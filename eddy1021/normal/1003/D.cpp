#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int K=30;
int n, q, cnt[K];;
int main(){
  scanf("%d%d", &n, &q);
  while(n--){
    int x;
    scanf("%d", &x);
    cnt[int(__lg(x))]++;
  }
  while(q--){
    int goal; scanf("%d", &goal);
    int ans=0;
    for(int i=K-1; i>=0; i--){
      if((1<<i) > goal) continue;
      if(cnt[i]==0) continue;
      int tk=min(cnt[i], goal>>i);
      goal-=(tk<<i);
      ans+=tk;
    }
    if(goal) puts("-1");
    else printf("%d\n", ans);
  }
}