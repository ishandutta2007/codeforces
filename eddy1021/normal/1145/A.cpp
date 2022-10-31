#include <bits/stdc++.h>
using namespace std;
int a[100], n, ans;
void sorted(int l, int r){
  bool ok=true;
  for(int i=l+1; i<r; i++)
    if(a[i] < a[i-1])
      ok=false;
  if(ok){
    ans=max(ans, r-l);
    return;
  }
  sorted(l, (l+r)>>1);
  sorted((l+r)>>1, r);
}
int main(){
  cin>>n;
  for(int i=0; i<n; i++)
    cin>>a[i];
  sorted(0, n);
  cout<<ans<<endl;
}