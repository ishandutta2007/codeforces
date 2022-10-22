#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 20000001
int T,N,tot,prm[MAXN],cnt[MAXN],c,d,x;bool Not[MAXN];ll ans;
void init(){N=MAXN-1;For(i,2,N){if(!Not[i])prm[++tot]=i,cnt[i]=1;for(int j=1;j<=tot&&i*prm[j]<=N;j++){Not[i*prm[j]]=1;if(i%prm[j]==0){cnt[i*prm[j]]=cnt[i];break;}cnt[i*prm[j]]=cnt[i]+1;}}}
void sol(int k){if((x/k+d)%c)return;int y=(x/k+d)/c;ans+=1<<cnt[y];}
int main(){init();cin>>T;while(T--){cin>>c>>d>>x;ans=0;for(int i=1;i*i<=x;i++)if(x%i==0)sol(i),i*i!=x?sol(x/i),0:0;cout<<ans<<endl;}return 0;}