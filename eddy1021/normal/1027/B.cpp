#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, q, x, y;
int main(){
  scanf("%lld%lld", &n, &q);
  LL tot=n*n;
  LL fst=(tot+1)/2;
  while(q--){
    scanf("%lld%lld", &x, &y);
    LL pre=0;
    if((x+y)&1LL){
      if(x&1LL){
        pre+=(x/2)*n;
        pre+=y/2;
      }else{
        pre+=(x/2-1)*n+n/2;
        pre+=(y+1)/2;
      }
      pre+=fst;
    }else{
      if(x&1LL){
        pre+=(x/2)*n;
        pre+=(y+1)/2;
      }else{
        pre+=(x/2-1)*n+(n+1)/2;
        pre+=y/2;
      }
    }
    printf("%lld\n", pre);
  }
}