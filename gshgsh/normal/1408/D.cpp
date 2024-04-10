#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 2001
#define MAXM 1000001
int N,M,K,a[MAXN],b[MAXN],c[MAXN],d[MAXN],f[MAXM],ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get(),M=get();For(i,1,N)a[i]=get(),b[i]=get();For(i,1,M)c[i]=get(),d[i]=get();
	For(i,1,N)For(j,1,M)if(d[j]>=b[i])K=max(K,d[j]-b[i]),f[d[j]-b[i]]=max(f[d[j]-b[i]],c[j]-a[i]+1);
	ans=K+1;int mx=0;FOR(i,K,0)mx=max(mx,f[i]),ans=min(ans,mx+i);cout<<ans<<endl;return 0;
}