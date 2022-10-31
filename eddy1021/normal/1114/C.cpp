#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, b, ans=-1;
void go(LL val, LL dv){
  LL tcnt=0;
  LL cur=n;
  while(cur>=val){
    tcnt+=cur/val;
    cur/=val;
  }
  tcnt/=dv;
  if(ans == -1) ans=tcnt;
  else ans=min(ans, tcnt);
}
int main(){
  cin>>n>>b;
  for(LL i=2; i*i<=b; i++){
    if(b%i) continue;
    int cnt=0;
    while(b%i == 0){
      cnt++;
      b/=i;
    }
    go(i, cnt);
  }
  if(b > 1) go(b, 1);
  printf("%lld\n", ans);
}