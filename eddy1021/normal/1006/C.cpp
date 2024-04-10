#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=202020;
LL n, a[N];
int main(){
  scanf("%lld", &n);
  for(int i=0; i<n; i++) scanf("%lld", &a[i]);
  LL l=-1, r=n;
  LL ls=0, rs=0;
  LL ans=0;
  while(l<r){
    if(ls == rs){
      ans=max(ans, ls);
      ++l; ls+=a[l];
      --r; rs+=a[r];
      continue;
    }
    if(ls < rs){
      ++l; ls+=a[l];
      continue;
    }
    --r; rs+=a[r];
  }
  cout<<ans<<endl;
}