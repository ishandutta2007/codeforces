#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int n;
  while(cin>>n){
    using P=pair<int,int>;
    vector<int> x(n),y(n);
    for(int i=0;i<n;++i)cin>>x[i]>>y[i];
    map<P,int> f;
    long long ans=0;
    for(int i=0;i<n;++i)
      for(int j=i+1;j<n;++j)
        f[{x[i]+x[j],y[i]+y[j]}]+=1;
    for(auto [x,y]:f){
      ans+=1ll*y*(y-1)/2;
      //cerr<<"+"<<y<<endl;
    }
    cout<<ans<<"\n";
  }
}