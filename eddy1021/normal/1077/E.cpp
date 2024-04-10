#include <bits/stdc++.h>
using namespace std;
const int N=202020;
typedef long long LL;
int n, a[N];
int main(){
  cin>>n;
  for(int i=0; i<n; i++)
    cin>>a[i];
  sort(a, a+n);
  vector<LL> v;
  for(int l=0, r=0; l<n; l=r){
    while(r<n and a[l]==a[r]) r++;
    v.push_back(r-l);
  }
  sort(v.begin(), v.end());
  LL ans=0;
  for(LL bns=0; bns<min((int)v.size(), 32); bns++){
    LL mx=1e9;
    for(int i=0; i<=bns; i++)
      mx=min(mx, v[v.size()-i-1]>>(bns-i));
    ans=max(ans, mx*((1LL<<(bns+1))-1));
  }
  cout<<ans<<endl;
}