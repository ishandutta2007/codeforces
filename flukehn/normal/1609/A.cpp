#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> a(n);
    long long p=1;
    for(int i=0;i<n;++i){
      int x;
      cin>>x;
      while(x%2==0)x/=2,p<<=1;
      a[i]=x;
    }
    sort(a.begin(),a.end());
    long long ans=0;
    for(int i=0;i<n;++i){
      if(i<n-1)ans+=a[i];
      else ans+=a[i]*p;
    }
    cout<<ans<<"\n";
  }
}