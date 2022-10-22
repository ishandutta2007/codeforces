#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N,p[30],c[30];ll a,b;ll calc(int x,int tot){int cnt=0;ll tmp=a,ans=a;while(tmp%x==0)cnt++,tmp/=x;while(cnt>=tot)ans/=x,cnt--;return ans;}
int main(){cin>>T;while(T--){cin>>a>>b;if(a%b){cout<<a<<endl;continue;}N=0;for(int i=2;i*i<=b;i++)if(b%i==0){p[++N]=i,c[N]=0;while(b%i==0)c[N]++,b/=i;}if(b!=1)p[++N]=b,c[N]=1;ll ans=0;For(i,1,N)ans=max(ans,calc(p[i],c[i]));cout<<ans<<endl;}return 0;}