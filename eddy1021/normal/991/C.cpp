#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
bool good(LL k){
  LL res=n, eat=0;
  while(res){
    LL tk=min(res, k);
    eat+=tk;
    res-=tk;
    res-=res/10;
  }
  return eat+eat>=n;
}
int main(){
  cin>>n;
  LL bl=1, br=n, ba=n;
  while(bl <= br){
    LL bmid=(bl+br)>>1;
    if(good(bmid)) ba=bmid, br=bmid-1;
    else bl=bmid+1;
  }
  cout<<ba<<endl;
}