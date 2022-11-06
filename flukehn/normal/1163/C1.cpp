#include<bits/stdc++.h>
using namespace std;

int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int n;
  while(cin>>n){
    vector<int> x(n),y(n);
    for(int i=0;i<n;++i)cin>>x[i]>>y[i];
    using E=tuple<int,int,int>;
    vector<E> p;
    for(int i=0;i<n;++i)
      for(int j=i+1;j<n;++j){
        int u=x[i]-x[j];
        int v=y[i]-y[j];
        if(v<0)u=-u,v=-v;
        if(!v)u=1;
        else{
          int g=__gcd(abs(u),v);
          u/=g,v/=g;
        }

        int w=v*x[i]-u*y[i];
        p.emplace_back(u,v,w);
      }
    sort(p.begin(),p.end());
    p.resize(unique(p.begin(),p.end())-p.begin());
    int m=p.size();
    //cerr<<"m="<<m<<endl;
    long long ans=1ll*m*(m-1)/2;
    for(int i=0,j;i<m;i=j){
      for(j=i;j<m&&get<0>(p[j])==get<0>(p[i])&&get<1>(p[j])==get<1>(p[i]);++j);
      ans-=1ll*(j-i)*(j-i-1)/2;
    }
    cout<<ans<<"\n";
  }
}