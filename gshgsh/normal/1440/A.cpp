#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N,x[2],w;int main(){cin>>T;while(T--){cin>>N>>x[0]>>x[1]>>w;int ans=0;For(i,1,N){char c;cin>>c;int t=c-'0';ans+=min(x[t],x[t^1]+w);}cout<<ans<<endl;}return 0;}