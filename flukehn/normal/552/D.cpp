#include<bits/stdc++.h>
using namespace std;
const int N=12000;
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while(cin>>n){
    int ans=1ll*n*(n-1)*(n-2)/6;
    vector<int> x(n),y(n);
    for(int i=0;i<n;++i)cin>>x[i]>>y[i];
    for(int i=0;i<n;++i){
      map<pair<int,int>, int> f;
      for(int j=i+1;j<n;++j){
        int a=x[j]-x[i];
        int b=y[j]-y[i];
        
        if(b==0)a=1;
        else{
          if(b<0)b=-b,a=-a;
          int g=__gcd(a,b);
          a/=g;
          b/=g;
        }
        //if(i==0)cerr<<a<<" "<<b<<endl;
        f[make_pair(a,b)]+=1;
      }
      for(auto x:f) ans-=x.second*(x.second-1)/2;
    }
    cout<<ans<<"\n";
  }
}