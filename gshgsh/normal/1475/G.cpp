#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,M,a[MAXN],cnt[MAXN],f[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main(){T=get();while(T--){N=get(),M=0;For(i,1,N)cnt[a[i]=get()]++,M=max(M,a[i]);f[1]=cnt[1];int ans=f[1];For(i,1,M)for(int j=i*2;j<=M;j+=i)ans=max(ans,f[j]=max(f[j],f[i]+cnt[j]));cout<<N-ans<<endl;For(i,1,M)f[i]=cnt[i]=0;}return 0;}