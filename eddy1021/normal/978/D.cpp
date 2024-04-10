#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=202020;
LL n, a[N], ans;
void cal(LL a0, LL a1, LL cst){
  for(int i=2; i<n; i++){
    LL goal=a1+a1-a0;
    if(abs(goal - a[i]) > 1) return;
    cst+=abs(goal - a[i]);
    a0=a1;
    a1=goal;
  }
  ans=min(ans, cst);
}
void go(){
  for(int d1=-1; d1<=1; d1++)
    for(int d2=-1; d2<=1; d2++)
      cal(a[0]+d1, a[1]+d2, abs(d1)+abs(d2));
}
int main(){
  scanf("%lld", &n);
  for(int i=0; i<n; i++)
    scanf("%lld", &a[i]);
  if(n<3){
    puts("0");
    return 0;
  }
  ans=N;
  go();
  if(ans==N) ans=-1;
  printf("%lld\n", ans);
}