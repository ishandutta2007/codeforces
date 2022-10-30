#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, w, a[1021];
int main(){
  cin>>n>>w;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  LL l=0, r=w;
  for(int i=n; i>=1; i--){
    l-=a[i];
    r-=a[i];
    l=max(l, 0LL);
    r=min(r, w);
  }
  cout<<max(0LL, r-l+1)<<endl;
}