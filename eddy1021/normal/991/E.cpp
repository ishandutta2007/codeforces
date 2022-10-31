#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, ans, fac[20];
int cnt[10], xcnt[10];
void cal(){
  int tot=accumulate(xcnt, xcnt+10, 0);
  if(tot == 0) return;
  for(int i=1; i<10; i++){
    if(!xcnt[i]) continue;
    xcnt[i]--;
    LL way=fac[tot-1];
    for(int j=0; j<10; j++)
      way/=fac[xcnt[j]];
    ans+=way;
    xcnt[i]++;
  }
}
void go(int dgt){
  if(dgt == 10){
    cal();
    return;
  }
  for(int i=cnt[dgt]?1:0; i<=cnt[dgt]; i++){
    xcnt[dgt]=i;
    go(dgt+1);
  }
}
int main(){
  fac[0]=1;
  for(int i=1; i<20; i++)
    fac[i]=fac[i-1]*i;
  cin>>n;
  while(n){
    cnt[n%10]++;
    n/=10;
  }
  go(0);
  cout<<ans<<endl;
}