#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int N,a[MAXN],cnt[MAXN],x,tot,ans,pos[MAXN*2],tmp[MAXN];int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void upd1(int y){For(i,-N,N)pos[i+N]=-1;pos[N]=0;int sum=0;For(i,1,N)sum+=a[i]==x?1:a[i]==y?-1:0,pos[sum+N]!=-1?ans=max(ans,i-pos[sum+N]):pos[sum+N]=i;}
void upd2(int x){int l=1,cnt=0;For(i,1,N)tmp[i]=0;For(i,1,N){tmp[a[i]]++;cnt+=tmp[a[i]]==x;while(l<=i&&tmp[a[i]]>x)cnt-=tmp[a[l]]==x,tmp[a[l++]]--;if(cnt>=2)ans=max(ans,i-l+1);}}
int main(){N=get();For(i,1,N)cnt[a[i]=get()]++;For(i,1,N)cnt[i]>cnt[x]?x=i,tot=1:cnt[i]==cnt[x]?tot++:0;if(tot>=2){cout<<N<<endl;return 0;}For(i,1,N)if(i!=x&&1ll*cnt[i]*cnt[i]>N)upd1(i);for(int i=1;i*i<=N;i++)upd2(i);cout<<ans<<endl;return 0;}