#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define MAXN 600001
int T,N,K,a[MAXN],f[MAXN],c1[MAXN],c2[MAXN],val[MAXN];ll s[MAXN],s1[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void upd1(int x,int v){for(int i=x;i<=K;i+=lowbit(i))c1[i]=max(c1[i],v);}
void upd2(int x,int v){for(int i=x;i;i-=lowbit(i))c2[i]=max(c2[i],v);}
int ask1(int x){int ans=-1e9;for(int i=x;i;i-=lowbit(i))ans=max(ans,c1[i]);return ans;}
int ask2(int x){int ans=-1e9;for(int i=x;i<=K;i+=lowbit(i))ans=max(ans,c2[i]);return ans;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,0,N+1)a[i]=f[i]=s[i]=s1[i]=0;For(i,1,N)a[i]=get();For(i,1,N)s1[i]=s[i]=s[i-1]+a[i];s1[N+1]=0;
		sort(s1+1,s1+N+2);K=unique(s1+1,s1+N+2)-s1-1;For(i,0,N)s[i]=lower_bound(s1+1,s1+K+1,s[i])-s1;
		For(i,0,K+1)c1[i]=c2[i]=val[i]=-1e9;f[0]=0;upd1(s[0],0);upd2(s[0],0);val[s[0]]=0;
		For(i,1,N)f[i]=max(ask1(s[i]-1)+i,ask2(s[i]+1)-i),f[i]=max(f[i],val[s[i]]),upd1(s[i],f[i]-i),upd2(s[i],f[i]+i),val[s[i]]=max(val[s[i]],f[i]);
		cout<<f[N]<<'\n';
	}
}