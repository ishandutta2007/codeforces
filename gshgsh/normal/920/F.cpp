#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define MAXN 1000001
int N,M,a[MAXN],d[MAXN],f[MAXN];ll c[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
void upd(int x,int v){for(int i=x;i<=N;i+=lowbit(i))c[i]+=v;}ll ask(int x){ll ans=0;for(int i=x;i;i-=lowbit(i))ans+=c[i];return ans;}
int main()
{
	For(i,1,MAXN-1)for(int j=i;j<MAXN;j+=i)d[j]++;N=get(),M=get();For(i,1,N)a[i]=get();
	For(i,1,N)f[i]=i;f[N+1]=N+1;For(i,1,N)if(d[a[i]]==a[i])f[getf(i)]=getf(i+1);For(i,1,N)upd(i,a[i]);
	For(i,1,M){int opt=get(),l=get(),r=get();if(opt==1)for(int j=getf(l);j<=r;j=getf(j+1)){upd(j,d[a[j]]-a[j]),a[j]=d[a[j]];if(d[a[j]]==a[j])f[getf(j)]=getf(j+1);}else cout<<ask(r)-ask(l-1)<<'\n';}return 0;
}