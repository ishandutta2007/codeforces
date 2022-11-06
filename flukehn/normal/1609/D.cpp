#include<bits/stdc++.h>
using namespace std;
const int N=1011;
int f[N],g[N];
int fa(int i){return f[i]==i?i:f[i]=fa(f[i]);}
int n,d;
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>n>>d;
  for(int i=1;i<=n;++i)f[i]=i,g[i]=1;
  int tot=1;
  for(int i=1;i<=d;++i){
    int x,y;
    cin>>x>>y;
    x=fa(x),y=fa(y);
    if(x!=y){
      f[y]=x;
      g[x]+=g[y];
    }else{
      tot+=1;
    }
    vector<int> p;
    for(int i=1;i<=n;++i)if(fa(i)==i)p.push_back(i);
    sort(p.begin(),p.end(),[](int i,int j){return g[i]>g[j];});
    int ans=0;
    for(int i=0;i<tot&&i<p.size();++i)
      ans+=g[p[i]];
    cout<<ans-1<<"\n";
  }
}